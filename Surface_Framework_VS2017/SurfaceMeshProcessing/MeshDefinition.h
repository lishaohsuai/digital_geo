#pragma once
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
#ifdef _DEBUG
#pragma comment(lib, "OpenMeshCored.lib")
#pragma comment(lib, "OpenMeshToolsd.lib")
#else
#pragma comment(lib, "OpenMeshCore.lib")
#pragma comment(lib, "OpenMeshTools.lib")
#endif
#include <Eigen/Dense>
struct color {
	int R;
	int G;
	int B;
};
struct MeshTraits : public OpenMesh::DefaultTraits
{
	typedef OpenMesh::Vec3d Point;
	typedef OpenMesh::Vec3d Normal;
	//VertexTraits{
	//	color col; // 存储顶点的颜色
	//};
	VertexAttributes(OpenMesh::Attributes::Status | OpenMesh::Attributes::Normal | OpenMesh::Attributes::Color);
	FaceAttributes(OpenMesh::Attributes::Status | OpenMesh::Attributes::Normal);
	EdgeAttributes(OpenMesh::Attributes::Status);
	HalfedgeAttributes(OpenMesh::Attributes::Status);
	VertexTraits{
		Eigen::MatrixXd Ksum; // store anything you want
		bool deleted;
	};
};
typedef OpenMesh::TriMesh_ArrayKernelT<MeshTraits> Mesh;

class MeshTools
{
public:
	static bool ReadMesh(Mesh & mesh, const std::string & filename);
	static bool ReadOBJ(Mesh & mesh, const std::string & filename);
	//static bool ReadOFF(Mesh & mesh, const std::string & filename);
	static bool WriteMesh(const Mesh & mesh, const std::string & filename, const std::streamsize & precision = 6);
	static bool WriteOBJ(const Mesh & mesh, const std::string & filename, const std::streamsize & precision = 6);
	static double Area(const Mesh & mesh);
	static double AverageEdgeLength(const Mesh & mesh);
	static bool HasBoundary(const Mesh & mesh);
	static bool HasOneComponent(const Mesh & mesh);
	static int Genus(const Mesh & mesh);
	static void BoundingBox(const Mesh & mesh, Mesh::Point & bmax, Mesh::Point & bmin);
	static void Reassign(const Mesh & mesh1, Mesh & mesh2);
};
