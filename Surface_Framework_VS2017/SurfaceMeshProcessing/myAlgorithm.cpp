#include "myAlgorithm.h"
#define debug 1

/**************************************************
@brief   : 输出弧度制的角度 使用两个向量
@author  : lee
@input   : none
@output  : none
@time    : none
**************************************************/
double MeshAlgorithm::vector3fAngle(vector3d a, vector3d b) {
	double cosTheta = a.dot(b) / (a.norm() * b.norm());
#ifndef debug
	std::cout << "[DEBUG] theta is " << acos(cosTheta) << std::endl;
	std::cout << "[DEBUG] vec a" << a.x << "," << a.y << "," << a.z << std::endl;
	std::cout << "[DEBUG] vec b" << b.x << "," << b.y << "," << b.z << std::endl;
#endif
	return acos(cosTheta);
}


/**************************************************
@brief   : 应用海伦公式计算面积
@author  : lee
@input   : none
@output  : none
@time    : none
**************************************************/
double MeshAlgorithm::areaUseThreePoints(Point3d a, Point3d b, Point3d c) {
	//应用海伦公式   S=1/4sqrt[(a+b+c)(a+b-c)(a+c-b)(b+c-a)]
	double lenA = sqrt(pow(b.x - c.x, 2) + pow(b.y - c.y, 2) + pow(b.z - c.z, 2));// b - c 两点的坐标
	double lenB = sqrt(pow(a.x - c.x, 2) + pow(a.y - c.y, 2) + pow(a.z - c.z, 2));// a - c 两点的坐标
	double lenC = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2));// a - b 两点的坐标
	double Area = 1.0 / 4.0 * sqrt((lenA + lenB + lenC) * (lenA + lenB - lenC) * (lenA + lenC - lenB) * (lenB + lenC - lenA));
#ifndef debug
	std::cout << "[DEBUG] area " << Area << std::endl;
	std::cout << "[DEBUG] a" << a.x << " " << a.y << " " << a.z << std::endl;
	std::cout << "[DEBUG] b" << b.x << " " << b.y << " " << b.z << std::endl;
	std::cout << "[DEBUG] c" << c.x << " " << c.y << " " << c.z << std::endl;
#endif
	return Area;
}


/**************************************************
@brief   : 计算三角形的面积通过两个向量
@author  : lee
@input   : none
@output  : none
@time    : none
***************************************************/
double MeshAlgorithm::areaUseVector(vector3d a, vector3d b) {
	double area = 0.0;
	area = (a.crossp(b)).norm() * 0.5f;
	return fabs(area) > std::numeric_limits<double>::min() ? area : 1e-8;
}


/**************************************************
@brief   : 通过三个点计算其外接圆的圆心的坐标
           参考 https://www.zhihu.com/question/40422123  李玉昆
@author  : lee
@input   : none
@output  : none
@time    : none
**************************************************/
Point3d MeshAlgorithm::calPointCircumcircle(Point3d a, Point3d b, Point3d c) {

	double a1, b1, c1, d1;
	double a2, b2, c2, d2;
	double a3, b3, c3, d3;

	double x1 = a.x, y1 = a.y, z1 = a.z;
	double x2 = b.x, y2 = b.y, z2 = b.z;
	double x3 = c.x, y3 = c.y, z3 = c.z;

	a1 = (y1*z2 - y2 * z1 - y1 * z3 + y3 * z1 + y2 * z3 - y3 * z2);
	b1 = -(x1*z2 - x2 * z1 - x1 * z3 + x3 * z1 + x2 * z3 - x3 * z2);
	c1 = (x1*y2 - x2 * y1 - x1 * y3 + x3 * y1 + x2 * y3 - x3 * y2);
	d1 = -(x1*y2*z3 - x1 * y3*z2 - x2 * y1*z3 + x2 * y3*z1 + x3 * y1*z2 - x3 * y2*z1);

	a2 = 2 * (x2 - x1);
	b2 = 2 * (y2 - y1);
	c2 = 2 * (z2 - z1);
	d2 = x1 * x1 + y1 * y1 + z1 * z1 - x2 * x2 - y2 * y2 - z2 * z2;

	a3 = 2 * (x3 - x1);
	b3 = 2 * (y3 - y1);
	c3 = 2 * (z3 - z1);
	d3 = x1 * x1 + y1 * y1 + z1 * z1 - x3 * x3 - y3 * y3 - z3 * z3;
	Point3d rlt;
	rlt.x = -(b1*c2*d3 - b1 * c3*d2 - b2 * c1*d3 + b2 * c3*d1 + b3 * c1*d2 - b3 * c2*d1)
		/ (a1*b2*c3 - a1 * b3*c2 - a2 * b1*c3 + a2 * b3*c1 + a3 * b1*c2 - a3 * b2*c1);
	rlt.y = (a1*c2*d3 - a1 * c3*d2 - a2 * c1*d3 + a2 * c3*d1 + a3 * c1*d2 - a3 * c2*d1)
		/ (a1*b2*c3 - a1 * b3*c2 - a2 * b1*c3 + a2 * b3*c1 + a3 * b1*c2 - a3 * b2*c1);
	rlt.z = -(a1*b2*d3 - a1 * b3*d2 - a2 * b1*d3 + a2 * b3*d1 + a3 * b1*d2 - a3 * b2*d1)
		/ (a1*b2*c3 - a1 * b3*c2 - a2 * b1*c3 + a2 * b3*c1 + a3 * b1*c2 - a3 * b2*c1);

	return rlt;
}



/**************************************************
@brief   : 根据外接圆的圆心是否要修正，做合理的修正
@author  : lee
@input   : none
@output  : none
@time    : none
**************************************************/
Point3d MeshAlgorithm::calPointVoronoiMixed(Point3d a, Point3d b, Point3d c) {
	Point3d p = calPointCircumcircle(a, b, c);//计算外接圆的圆心
	if (!isInTriangle(a, b, c, p)) {//不在三角形内部的时候 返回bc的中点
		return { (b.x + c.x) / 2.0, (b.y + c.y) / 2.0, (b.z + c.z) / 2.0 };
	}
	return p;
}

/**************************************************
@brief   : 判断两个向量是否同向
@author  : lee
@input   : none
@output  : none
@time    : none
**************************************************/
bool sameSide(Point3d a, Point3d b, Point3d c, Point3d p) {
	vector3d AB(b.x - a.x, b.y - a.y, b.z - a.z);
	vector3d AC(c.x - a.x, c.y - a.y, c.z - a.z);
	vector3d AP(p.x - a.x, p.y - a.y, p.z - a.z);

	vector3d v1 = AB.crossp(AC);
	vector3d v2 = AB.crossp(AP);

	// v1 and v2 should point to the same direction
	return v1.dot(v2) >= 0;
}

/**************************************************
@brief   : 判断点是否在三角形内  参考链接 https://www.cnblogs.com/graphics/archive/2010/08/05/1793393.html
@author  : lee
@input   : none
@output  : none
@time    : none
**************************************************/
bool MeshAlgorithm::isInTriangle(Point3d a, Point3d b, Point3d c, Point3d p) {
	return sameSide(a, b, c, p) &&
		sameSide(b, c, a, p) &&
		sameSide(c, a, b, p);
}



/**************************************************
@brief   : 计算两个三角形的对标 cotalpha cotbelta
@author  : lee
@input   : none
@output  : none
@time    : none
**************************************************/
void MeshAlgorithm::calCotAlphaCotBeta(Point3d p, Point3d a, Point3d b, Point3d c, double &cotAlpha, double &cotBeta) {
	vector3d AP(p.x - a.x, p.y - a.y, p.z - a.z);
	vector3d AB(b.x - a.x, b.y - a.y, b.z - a.z);
	double cosAlpha = cos(vector3fAngle(AP, AB));
	cotAlpha = cosAlpha / sqrt(1 - cosAlpha * cosAlpha);
	vector3d CP(p.x - c.x, p.y - c.y, p.z - c.z);
	vector3d CB(b.x - c.x, b.y - c.y, b.z - c.z);
	double cosBeta = cos(vector3fAngle(CP, CB));
	cotBeta = cosBeta / sqrt(1 - cosBeta * cosBeta);
}


/**************************************************
@brief   : 颜色映射归一化  
@author  : 王丹丹
@input   : none
@output  : none
@time    : none
**************************************************/
void ImageAlgorithm::normalize(std::vector<double> & val) {
	//找到最大值和最小值，然后映射到[0,1]
	double max = -10000.0, min = 10000.0;
	int n = val.size();
	for (int i = 0; i < n; i++){
		if (val[i] > max) max = val[i];
		if (val[i] < min) min = val[i];
	}
	double t = max - min;
	//需要讨论一下相等的情况
	for (int i = 0; i < n; i++){
		val[i] = (val[i] - min) / t;
	}
}


/**************************************************
@brief   : 映射高斯曲率到 r g b 参照libigl中的相关代码
@author  : 王丹丹
@input   : none
@output  : none
@time    : none
**************************************************/
void ImageAlgorithm::colorMap(double gaussCur, double &r, double &g, double &b)
{
	const double rone = 0.8;
	const double gone = 1.0;
	const double bone = 1.0;
	double  x = gaussCur;
	x = (gaussCur < 0 ? 0 : (x > 1 ? 1 : x));
	//可以简单地理解：红色的曲率最大，蓝色的最小
	if (x < 1. / 8.){
		r = 0;
		g = 0;
		b = bone * (0.5 + (x) / (1. / 8.)*0.5);
	}
	else if (x < 3. / 8.){
		r = 0;
		g = gone * (x - 1. / 8.) / (3. / 8. - 1. / 8.);
		b = bone;
	}
	else if (x < 5. / 8.){
		r = rone * (x - 3. / 8.) / (5. / 8. - 3. / 8.);
		g = gone;
		b = (bone - (x - 3. / 8.) / (5. / 8. - 3. / 8.));
	}
	else if (x < 7. / 8.){
		r = rone;
		g = (gone - (x - 5. / 8.) / (7. / 8. - 5. / 8.));
		b = 0;
	}
	else{
		r = (rone - (x - 7. / 8.) / (1. - 7. / 8.)*0.5);
		g = 0;
		b = 0;
	}
}