#ifndef __POINT3D_H__
#define __POINT3D_H__
#include <iostream>
class Point3d {
public:
	double x;
	double y;
	double z;
public:
	Point3d(double _x, double _y, double _z) :x(_x), y(_y), z(_z) {};
	Point3d() { x = 0; y = 0; z = 0; };
	//getters
	double getX() const { return x; }
	double getY() const { return y; }
	double getZ() const { return z; }
	//operator
	Point3d operator*(double n) { return Point3d(x*n, y*n, z*n); }
	Point3d operator+(Point3d p) { return Point3d(x + p.x, y + p.y, z + p.z); }
	Point3d operator-(Point3d p) { return Point3d(x - p.x, y - p.y, z - p.z); }
	double distence(Point3d p) {
		return sqrt((this->x - p.x)*(this->x - p.x) + (this->y - p.y)*(this->y - p.y) + (this->z - p.z)*(this->z - p.z));
	}

	void scaleX(double s) { x = x / s; }
	void scaleY(double s) { y = y / s; }
	void scaleZ(double s) { z = z / s; }

	void print() { std::cout << "(" << x << "," << y << "," << z << ")" << std::endl; }
};
#endif