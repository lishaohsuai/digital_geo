#ifndef __MYALGORITHM_H__
#define __MYALGORITHM_H__
#include <Eigen/Core>
#include <iostream>
#include <vector>
#include "point3d.h"
#include "vector3d.h"
class MeshAlgorithm {
public:
	MeshAlgorithm() {}
	~MeshAlgorithm() {}
public:
	double vector3fAngle(vector3d a, vector3d b);
	double areaUseThreePoints(Point3d a, Point3d b, Point3d c);
	double areaUseVector(vector3d a, vector3d b);
	Point3d calPointCircumcircle(Point3d a, Point3d b, Point3d c);
	Point3d calPointVoronoiMixed(Point3d a, Point3d b, Point3d c);
	bool isInTriangle(Point3d a, Point3d b, Point3d c, Point3d p);
	void calCotAlphaCotBeta(Point3d p, Point3d a, Point3d b, Point3d c, double &cotAlpha, double &cotBeta);
};


class ImageAlgorithm {
public:
	ImageAlgorithm(){}
	~ImageAlgorithm() {}
public:
	void normalize(std::vector<double> & val);
	void colorMap(double gaussCur, double &r, double &g, double &b);
};

#endif