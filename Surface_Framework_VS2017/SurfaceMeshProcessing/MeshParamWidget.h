#pragma once

#include <QWidget>
#include <QtGui>
#include <QtWidgets>

class MeshParamWidget : public QWidget
{
	Q_OBJECT

public:
	MeshParamWidget(QWidget *parent = 0);
	~MeshParamWidget(void);
private:
	void CreateTabWidget(void);
	void CreateLayout(void);
signals:
	void PrintInfoSignal();
	void GaussianCurvatureProcessSignal();
	void MeanCurvatureProcessSignal();
private:
	QTabWidget *twParam;
	QWidget *wParam;
	QScrollArea *saParam;
	QPushButton *pbPrintInfo;
	QPushButton *pbGaussianCurvature;
	QPushButton *pbMeanCurvature;
};
