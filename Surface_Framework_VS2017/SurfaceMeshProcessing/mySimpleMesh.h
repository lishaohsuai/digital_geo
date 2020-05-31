#ifndef __MYSIMPLEMESH_H__
#define __MYSIMPLEMESH_H__
#include "MeshDefinition.h"
#include "myAlgorithm.h"
#include <QString>
#include <cmath>
#include <set>
#include <sstream>
struct myPair {
	/*myPair(Mesh::Point p1, Mesh::Point p2, double error) {
		this->p1 = p1;
		this->p2 = p2;
		this->error = error;
	}*/
	myPair(Mesh::VertexIter v_it, Mesh::VertexVertexIter vv_it, double error) {
		this->v_it = v_it;
		this->vv_it = vv_it;
		this->error = error;
	}
	myPair(Mesh::VertexVertexIter vv_it, Mesh::VertexIter v_it, double error) {
		this->v_it = v_it;
		this->vv_it = vv_it;
		this->error = error;
	}
	/*Mesh::Point p1;
	Mesh::Point p2;*/
	Mesh::VertexIter v_it;
	Mesh::VertexVertexIter vv_it;

	Mesh::Normal optimal_nrm;
	Mesh::Point optimal_pos; // 这两个点的最优位置
	double error;// error 是这两个点的最优位置的error
};

struct vert_pair_CMP {
	bool operator()(const myPair& a, const myPair& b) {
		return a.error < b.error;
	}
};


class SimpleMesh {
public:
	typedef struct myPair MyPair;
	typedef std::multiset<myPair, vert_pair_CMP> PairHeap;//定义堆
	PairHeap heap;
	SimpleMesh(Mesh *m);
	~SimpleMesh();
	bool simpleMesh(QString str);
	void computeQ();
	void setMesh(Mesh *m);
private:
	double quadric(const Point3d& v, const Eigen::MatrixXd &M_);
	double quadric(const Mesh::Point& v, const Eigen::MatrixXd &M_);

	Mesh * mesh;
	MeshAlgorithm myMeshAlgorithm;

	double norm(const Mesh::Point &point);
	bool deleteOnePoint(Mesh::VertexHandle v_it);
	void chooseOneToDel(Mesh::VertexHandle v_l, Mesh::VertexHandle v_r);
};

#endif
