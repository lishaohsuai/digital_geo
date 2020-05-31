#pragma once
#include <QString>
#include "QGLViewerWidget.h"
#include "myAlgorithm.h"
#include "MeshDefinition.h"
#include "mySimpleMesh.h"
class MeshViewerWidget : public QGLViewerWidget
{
	Q_OBJECT
public:
	MeshViewerWidget(QWidget* parent = 0);
	virtual ~MeshViewerWidget(void);
	bool LoadMesh(const std::string & filename);
	void Clear(void);
	void UpdateMesh(void);
	bool SaveMesh(const std::string & filename);
	bool ScreenShot(void);
	void SetDrawBoundingBox(bool b);
	void SetDrawBoundary(bool b);
	void EnableLighting(bool b);
	void EnableDoubleSide(bool b);
	void ResetView(void);
	void ViewCenter(void);
	void CopyRotation(void);
	void LoadRotation(void);

	double calGaussianCurvature(Mesh::VertexIter vertexIndex);
	double calMeanCurvature(Mesh::VertexIter vertexIndex);
signals:
	void LoadMeshOKSignal(bool, QString);
public slots:
	void PrintMeshInfo(void);
	void GaussianCurvatureProcess(void);
	void MeanCurvatureProcess(void);
	void SimpleMeshProcess(QString);
protected:
	virtual void DrawScene(void) override;
	void DrawSceneMesh(void);

private:
	void DrawPoints(void) const;
	void DrawWireframe(void) const;
	void DrawHiddenLines(void) const;
	void DrawFlatLines(void) const;
	void DrawFlat(void) const;
	void DrawSmooth(void) const;
	void DrawBoundingBox(void) const;
	void DrawBoundary(void) const;
	void DrawGaoSi(void) const;
protected:
	Mesh mesh;
	QString strMeshFileName;
	QString strMeshBaseName;
	QString strMeshPath;
	Mesh::Point ptMin;
	Mesh::Point ptMax;
	bool isEnableLighting;
	bool isTwoSideLighting;
	bool isDrawBoundingBox;
	bool isDrawBoundary;

	MeshAlgorithm myMeshAlgorithm;
	ImageAlgorithm myImageAlgorithm;
	SimpleMesh mySimpleMesh;
};
