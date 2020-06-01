#ifndef __LAPLACIANDEFORMATION_H__
#define __LAPLACIANDEFORMATION_H__

#include <Eigen/Dense>
#include "MeshDefinition.h"
#include <map>
#include <QFileDialog>
#include <fstream>
#include <iostream>
#include "point3d.h"

class LaplacianDeformation{
public:
	LaplacianDeformation(Mesh *m);
	~LaplacianDeformation();

	void GenerateLaplacianMatrix();
	//void GenerateLaplacianMatrix2();
	void delta(Mesh::VertexIter vertexIndex, Point3d &position);
	void GenerateAnchorUnitMatrixAndAnchorPosition();
	void calcNewPoint();
	void updatePoint();
	bool ReadAnchorPoints();
	void setMeshInfo(Mesh *m);
	void smoothFunc();

private:
	double lamda;
	Mesh *mesh;
	Eigen::MatrixXd laplacianMatrix;//拉普拉斯矩阵
	Eigen::MatrixXd AnchorUnitMatrix;//选择的点的01
	Eigen::MatrixXd AnchorPosition;//选约束的点的坐标
	Eigen::MatrixXd V_dNew;//新的坐标点向量
	Eigen::MatrixXd A;//论文中的A矩阵
	Eigen::MatrixXd b;//论文中的b矩阵
	std::map<int, OpenMesh::Vec3d> mapVec;//顶点 idx 对应的坐标
	std::vector<int> fixPointIdx; // 固定点 bumpy
	int editPointIdx; // 移动点 默认为 240 idx
	int anchorVerticesNum;
	int verticesNum;// 整个网格拥有的点的个数

	//测试新的拉普拉斯矩阵
	Eigen::MatrixXd AL;
	Eigen::MatrixXd IL;
	Eigen::MatrixXd DL;
};

#endif
