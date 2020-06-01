#include "MeshParamWidget.h"

MeshParamWidget::MeshParamWidget(QWidget *parent)
	: QWidget(parent)
{
	CreateTabWidget();
	CreateLayout();
}

MeshParamWidget::~MeshParamWidget()
{
}

void MeshParamWidget::CreateTabWidget(void)
{
	pbPrintInfo = new QPushButton(tr("Print Mesh Info"));
	connect(pbPrintInfo, SIGNAL(clicked()), SIGNAL(PrintInfoSignal()));

	pbGaussianCurvature = new QPushButton(tr("Gaussian Curvature"));
	connect(pbGaussianCurvature, SIGNAL(clicked()), SIGNAL(GaussianCurvatureProcessSignal()));

	pbMeanCurvature = new QPushButton(tr("Mean Curvature"));
	connect(pbMeanCurvature, SIGNAL(clicked()), SIGNAL(MeanCurvatureProcessSignal()));
	
	ptSimpleEdit = new QTextEdit();
	//connect(ptSimpleEdit, )

	pbSimpleMesh = new QPushButton(tr("Simple Mesh"));
	connect(pbSimpleMesh, SIGNAL(clicked()), this, SLOT(buttonProcessSLOT()));
	connect(this, SIGNAL(myStringdd(QString)), SIGNAL(SimpleMeshSignal(QString)));

	pbLaplacianDef = new QPushButton(tr("LaplacianDeformation"));
	connect(pbLaplacianDef, SIGNAL(clicked()), SIGNAL(LaplacianProcessSignal()));

	QVBoxLayout *layout = new QVBoxLayout();
	layout->addWidget(pbPrintInfo);
	layout->addWidget(pbGaussianCurvature);
	layout->addWidget(pbMeanCurvature);
	layout->addWidget(ptSimpleEdit);
	layout->addWidget(pbSimpleMesh);
	layout->addWidget(pbLaplacianDef);
	layout->addStretch();
	wParam = new QWidget();
	wParam->setLayout(layout);
	saParam = new QScrollArea();
	saParam->setFocusPolicy(Qt::NoFocus);
	saParam->setFrameStyle(QFrame::NoFrame);
	saParam->setWidget(wParam);
	saParam->setWidgetResizable(true);
}

void MeshParamWidget::buttonProcessSLOT() {
	emit(myStringdd(ptSimpleEdit->toPlainText()));
}


void MeshParamWidget::CreateLayout(void)
{
	twParam = new QTabWidget();
	twParam->addTab(saParam, "Tab");
	QGridLayout *layout = new QGridLayout();
	layout->addWidget(twParam, 0, 0, 1, 1);
	this->setLayout(layout);
}
