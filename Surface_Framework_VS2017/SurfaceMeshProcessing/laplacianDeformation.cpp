#include "laplacianDeformation.h"


/**************************************************
@brief   : 构造函数
@author  : lee
@input   ：none
@output  ：none
@time    : none
**************************************************/
LaplacianDeformation::LaplacianDeformation(Mesh *m) {
	mesh = m;
	lamda = 0.01;//步进的长度
	for (auto it = mesh->vertices_begin(); it != mesh->vertices_end(); it++) {
		mapVec[it->idx()] = mesh->point(*it);
	}
	verticesNum = mesh->n_vertices();
}


/**************************************************
@brief   : 设置相关信息 类似构造函数
@author  : lee
@input   ：none
@output  ：none
@time    : none
**************************************************/
void LaplacianDeformation::setMeshInfo(Mesh *m) {
	mesh = m;
	lamda = 0.01;//步进的长度
	mapVec.clear();
	for (auto it = mesh->vertices_begin(); it != mesh->vertices_end(); it++) {
		mapVec[it->idx()] = mesh->point(*it);
	}
	verticesNum = mesh->n_vertices();
}


/**************************************************
@brief   : 析构函数
@author  : lee
@input   ：none
@output  ：none
@time    : none
**************************************************/
LaplacianDeformation::~LaplacianDeformation() {}

/**************************************************
@brief   : 从json文件中读取固定点  未来会加上？ 编辑点？
@author  : lee
@input   ：none
@output  ：none
@time    : none
**************************************************/
bool LaplacianDeformation::ReadAnchorPoints() {
	QString fileName = QFileDialog::getOpenFileName(NULL,
		QObject::tr("Open fixPoint file"),
		QObject::tr(""),
		QObject::tr("txt Files (*.txt);;"
			"All Files (*)"));
	std::string strFileName = fileName.toStdString();
	std::ifstream inFile;
	if (strFileName != "") {
		inFile.open(strFileName.c_str());
	}
	else {
		return false;
	}
	int tmp;
	while (inFile >> tmp) {
		fixPointIdx.push_back(tmp);
	}
	anchorVerticesNum = fixPointIdx.size() + 1; // 增加了固定点 & 编辑点
	editPointIdx = 240; // 默认编辑点
	return true;
}

/**************************************************
@brief   : 整个算法流
@author  : lee
@input   ：none
@output  ：none
@time    : none
**************************************************/
void LaplacianDeformation::smoothFunc() {
	//if (!ReadAnchorPoints()) {
	//	std::cout << "Error not choose fix point" << std::endl;
	//	exit(0);
	//}
	GenerateLaplacianMatrix();
	GenerateAnchorUnitMatrixAndAnchorPosition();
	calcNewPoint();
	updatePoint();
}

/**************************************************
@brief   : 生成拉普拉斯矩阵
@author  : lee
@input   ：none
@output  ：none
@time    : none
**************************************************/
void LaplacianDeformation::GenerateLaplacianMatrix() {
	laplacianMatrix.resize(verticesNum, verticesNum);//矩阵缩放大小
	for (Mesh::VertexIter vertexIter = mesh->vertices_begin(); vertexIter != mesh->vertices_end(); vertexIter++) {
		for (Mesh::VertexIter vertexIter1 = mesh->vertices_begin(); vertexIter1 != mesh->vertices_end(); vertexIter1++) {
			if (vertexIter->idx() == vertexIter1->idx()) {
				laplacianMatrix(vertexIter->idx(), vertexIter1->idx()) = 1;
			}
			else {
				bool connected = false;
				int count = 0;
				for (Mesh::VertexVertexIter vv_it = mesh->vv_iter(*vertexIter); vv_it.is_valid(); vv_it++) {
					if (vv_it->idx() == vertexIter1->idx()) {//说明两点连通
						connected = true;
					}
					count++;//邻接点的个数
				}
				if (connected) {
					laplacianMatrix(vertexIter->idx(), vertexIter1->idx()) = -1.0 / (double)count;
				}
				else {
					laplacianMatrix(vertexIter->idx(), vertexIter1->idx()) = 0;
				}
			}
		}
	}
	std::cout << "GenerateLaplacianMatrix finish\n";
}

/**************************************************
@brief   : 生成锚点（固定点）  所有点都是锚点采用 linux 上的程序选出的点的坐标
		   大部分的点都应该是固定点，只有少部分的点才是可以变形的点
@author  : lee
@input   ：none
@output  ：none
@time    : none
**************************************************/
void LaplacianDeformation::GenerateAnchorUnitMatrixAndAnchorPosition() {
	// 选取 距离固定点
	int count = 0;
	int index = 0;
	editPointIdx = 240; // 默认编辑点
	Mesh::Point editPoint = mapVec[240];// 得到编辑点的坐标
	// 计算点与编辑点之间的距离，如果距离大于0.3 那么就是固定点
	std::vector<Mesh::Point> v;
	std::vector<int> cc;// 记录idx
	for (Mesh::VertexIter vertexIter = mesh->vertices_begin(); vertexIter != mesh->vertices_end(); vertexIter++, count++) {
		if ((editPoint - mesh->point(*vertexIter)).length() > 2) {
			v.push_back(mesh->point(*vertexIter));
			cc.push_back(vertexIter->idx());
		}
	}
	anchorVerticesNum = cc.size() + 1;
	AnchorPosition.resize(cc.size() + 1, 3);
	AnchorUnitMatrix.resize(cc.size() + 1, verticesNum);
	for (int i = 0; i < (cc.size() + 1); i++) {
		for (int j = 0; j < verticesNum; j++) {
			AnchorUnitMatrix(i, j) = 0;//矩阵全部初始化为0
		}
	}
	for (int i = 0; i < cc.size(); i++) {
		Mesh::Point tmpP = v[i];
		AnchorUnitMatrix(i, cc[i]) = 1;
		AnchorPosition(i, 0) = tmpP[0];
		AnchorPosition(i, 1) = tmpP[1];
		AnchorPosition(i, 2) = tmpP[2];
	}
	// 编辑点
	AnchorUnitMatrix(cc.size(), editPointIdx) = 1;
	AnchorPosition(cc.size(), 0) = editPoint[0];
	AnchorPosition(cc.size(), 1) = editPoint[1];
	AnchorPosition(cc.size(), 2) = editPoint[2] + 5; // 形变
	std::cout << "GenerateAnchorUnitMatrixAndAnchorPosition finish\n";
}

/**************************************************
@brief   : 计算新的点
@author  : lee
@input   ：none
@output  ：none
@time    : none
**************************************************/
void LaplacianDeformation::calcNewPoint() {
	A.resize(verticesNum + anchorVerticesNum, verticesNum);
	for (int i = 0; i < verticesNum; i++) {
		A.row(i) = laplacianMatrix.row(i);
	}
	for (int i = 0; i < anchorVerticesNum; i++) {
		A.row(i + verticesNum) = AnchorUnitMatrix.row(i);
	}
	b.resize(verticesNum + anchorVerticesNum, 3);
	int index = 0;
	for (auto v_it = mesh->vertices_begin(); v_it != mesh->vertices_end(); v_it++, index++) {
		Point3d position(0, 0, 0);
		delta(v_it, position);
		b(index, 0) = position.getX();
		b(index, 1) = position.getY();
		b(index, 2) = position.getZ();
	}
	for (int i = 0; i < anchorVerticesNum; i++) {
		b(verticesNum + i, 0) = AnchorPosition(i, 0);
		b(verticesNum + i, 1) = AnchorPosition(i, 1);
		b(verticesNum + i, 2) = AnchorPosition(i, 2);
	}
	//开始计算向量新坐标点
	V_dNew.resize(verticesNum, 3);
	V_dNew = (A.transpose()*A).llt().solve(A.transpose()*b);
	std::cout << "calcNewPoint finish\n";
}



/**************************************************
@brief   : 更新点坐标
@author  : lee
@input   ：none
@output  ：none
@time    : none
**************************************************/
void LaplacianDeformation::updatePoint() {
	int count = 0;
	for (Mesh::VertexIter vertexIter = mesh->vertices_begin(); vertexIter != mesh->vertices_end(); vertexIter++, count++) {
		OpenMesh::Vec3d point(V_dNew(count, 0), V_dNew(count, 1), V_dNew(count, 2));
		mesh->set_point(*vertexIter, point);
	}
	std::cout << "updatePoint finish\n";
}

/**************************************************
@brief   : 计算微分坐标
		   默认权重为1
@author  : lee
@input   ：none
@output  ：none
@time    : none
**************************************************/
void LaplacianDeformation::delta(Mesh::VertexIter vertexIndex, Point3d &position) {
	int adjacentPointNum = 0;
	position.x = 0;
	position.y = 0;
	position.z = 0;
	Point3d rlt(0, 0, 0);
	//找到这个点的邻域点的个数
	for (Mesh::VertexVertexIter vv_it = mesh->vv_iter(*vertexIndex); vv_it.is_valid(); ++vv_it) {//这个顶点所带有的半边迭代器
		OpenMesh::Vec3d tmp0 = mesh->point(*vertexIndex);
		OpenMesh::Vec3d tmp1 = mesh->point(*vv_it);
		rlt.x += tmp0[0] - tmp1[0];
		rlt.y += tmp0[1] - tmp1[1];
		rlt.z += tmp0[2] - tmp1[2];
		adjacentPointNum++;
	}
	position.x = rlt.x / adjacentPointNum;
	position.y = rlt.y / adjacentPointNum;
	position.z = rlt.z / adjacentPointNum;
}
