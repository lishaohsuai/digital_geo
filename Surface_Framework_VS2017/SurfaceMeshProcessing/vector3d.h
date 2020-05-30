#ifndef __VECTOR3D_H__
#define __VECTOR3D_H__
#include <math.h>
class vector3d {
public:
	double x, y, z;
	vector3d() { x = y = z = 0; }
	vector3d(double x_, double y_, double z_) :x(x_), y(y_), z(z_) {}
	vector3d(double p[3]) :x(p[0]), y(p[1]), z(p[2]) {}

	vector3d normalize() {
		double norm = sqrt(x*x + y * y + z * z);
		x = x / norm;
		y = y / norm;
		z = z / norm;
		return *this;
	}

	vector3d operator*(const double d) {
		return vector3d(x*d, y*d, z*d);
	}
	vector3d operator*(const vector3d d) {
		return vector3d(x * d.getx(), y * d.getx(), z * d.getz());
	}
	vector3d operator-(const vector3d d) {
		return vector3d(x - d.getx(), y - d.getx(), z - d.getz());
	}
	double dot(const vector3d d) {
		return x * d.getx() + y * d.gety() + z * d.getz();
	}
	double norm() {
		double rlt = sqrt(x*x + y * y + z * z);
		return rlt;
	}
	double getx() const { return x; }//声明一个成员函数的时候用const关键字是用来说明这个函数是
									 //"只读(read-only)"函数，也就是说明这个函数不会修改任何数据成员(object)。 为了声明一个const成员函数， 把const关键字放在函数括号的后面。声明和定义的时候都应该放const关键字。
	double gety() const { return y; }
	double getz() const { return z; }
	// 两个向量的叉乘
	vector3d crossp(const vector3d &v) const {
		return vector3d(y*v.z - z * v.y,
			z*v.x - x * v.z,
			x*v.y - y * v.x);
	}
};



#endif
