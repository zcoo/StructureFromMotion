#include "SFM.h"
#include "qfiledialog.h"
#include <iostream>
#include <string>
#include <qmessagebox.h>
#include <qcheckbox.h>
#include <qlistwidget.h>
#include <windows.h> 




QString getTime();
using namespace std;

SFM::SFM(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	e = new InputPathWindow();

	ui.label_picture->setFixedSize(960,550);
	ui.tabWidget_picture->clear();
	//sparse
	connect(ui.action_InputPath_3, SIGNAL(triggered()), this, SLOT(InputPath()));//菜单点击，子窗体生成
	connect(ui.action_InitImage, SIGNAL(triggered()), this, SLOT(InitImage()));//初始化图像列表
	connect(ui.action_ComputeFeatures, SIGNAL(triggered()), this, SLOT(ComputeFeatures()));//计算特征点
	connect(ui.action_ComputeMatches, SIGNAL(triggered()), this, SLOT(ComputeMatches()));//匹配特征点
	connect(ui.action_IncrementalSfM, SIGNAL(triggered()), this, SLOT(IncrementalSfM()));//增量重建
	connect(ui.action_ComputeDataColor, SIGNAL(triggered()), this, SLOT(ComputeDataColor()));//结构着色
	connect(ui.action_OpenMVG2openMVS, SIGNAL(triggered()), this, SLOT(OpenMVG2openMVS()));//文件转换
	connect(ui.action_Sparse, SIGNAL(triggered()), this, SLOT(Sparse()));//完整稀疏重建
	//dense
	connect(ui.action_DensifyPointCloud, SIGNAL(triggered()), this, SLOT(DensifyPointCloud()));//稠密点云
	connect(ui.action_ReconstructMesh, SIGNAL(triggered()), this, SLOT(ReconstructMesh()));//重建网格
	connect(ui.action_RefineMesh, SIGNAL(triggered()), this, SLOT(RefineMesh()));//细化网格
	connect(ui.action_TextureMesh, SIGNAL(triggered()), this, SLOT(TextureMesh()));//网格加纹理
	connect(ui.action_Dense, SIGNAL(triggered()), this, SLOT(Dense()));//完整稠密重建


	connect(ui.action_ImportCloud, SIGNAL(triggered()), this, SLOT(ImportCloud()));//导入ply点云
	connect(e, SIGNAL(sendData(QString, QString)), this, SLOT(receiveData(QString, QString)));//发射信号和接受槽函数连接

	connect(ui.action_ClearList, SIGNAL(triggered()), this, SLOT(clearList()));//清空输出列表

	ui.tabWidget_picture->hide();
	ui.listWidget->setGeometry(0, 550, 1140, 170);
	ui.listWidget->addItem(getTime()+QString::fromLocal8Bit("----------程序已开始运行----------") + input_dir);
}


void SFM::showPicture(int row)
{
	QListWidget *list = qobject_cast<QListWidget*>(sender());
	QString path = list->windowIconText() + list->item(row)->text();
	QPixmap pixmap(path);
	QPixmap result = pixmap.scaled(960, 540, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	ui.label_picture->setPixmap(result);

	ui.label_picture->show();

}
QStringList getFileNames(QString &path)
{
	QDir dir(path);
	QStringList nameFilters;
	nameFilters << "*.jpg" << "*.svg";
	QStringList files = dir.entryList(nameFilters, QDir::Files | QDir::Readable, QDir::Name);
	return files;
}


void SFM::clearList()
{
	ui.listWidget->clear();
}

void SFM::InputPath()
{
	//初始化窗体
	e->show();
}
void SFM::InitImage()
{
	ui.listWidget->addItem(getTime()+QString::fromLocal8Bit("----------初始化图片列表开始----------") );


	std::string command = sparse_bin_dir.toStdString()+"openMVG_main_SfMInit_ImageListing.exe -i " + input_dir.toStdString()
		+ " -d " + camera_file_params.toStdString() + " -o " + matches_dir.toStdString() + " -f 5030.4";
	system(command.c_str());

	ui.tabWidget_picture->show();
	QListWidget *listInitImage = new QListWidget();
	connect(listInitImage, SIGNAL(currentRowChanged(int)), this, SLOT(showPicture(int)));  //列表点击与显示图片连接
	QStringList filenamelist = getFileNames(input_dir);
	QString tmp;
	for (int i = 0; i<filenamelist.size(); i++)
		listInitImage->addItem( filenamelist.at(i));
	listInitImage->setWindowIconText(input_dir + "/");

	ui.tabWidget_picture->addTab(listInitImage, QString::fromLocal8Bit("初始图片"));


	ui.listWidget->addItem(getTime()+QString::fromLocal8Bit("----------初始化图片列表完成----------"));
}
void SFM::ComputeFeatures()
{
	ui.listWidget->addItem(getTime()+QString::fromLocal8Bit("----------计算特征点开始----------"));


	std::string command = sparse_bin_dir.toStdString() +"openMVG_main_ComputeFeatures.exe -i " + matches_dir.toStdString() + "/sfm_data.json"
		+ " -o " + matches_dir.toStdString();
	system(command.c_str());
	command = sparse_bin_dir.toStdString() + "openMVG_main_exportKeypoints.exe -i " + matches_dir.toStdString() + "/sfm_data.json"
		+ " -d " + matches_dir.toStdString() + " -o " + matches_dir.toStdString() + "/exportFeatures";
	system(command.c_str());



	QListWidget *listComputeFeatures = new QListWidget();
	connect(listComputeFeatures, SIGNAL(currentRowChanged(int)), this, SLOT(showPicture(int)));  //列表点击与显示图片连接
	QStringList filenamelist = getFileNames(QString(matches_dir+ "/exportFeatures"));
	QString tmp;
	for(int i=0;i<filenamelist.size();i++)
		listComputeFeatures->addItem(filenamelist.at(i));
	listComputeFeatures->setWindowIconText(matches_dir + "/exportFeatures/");
	ui.tabWidget_picture->addTab(listComputeFeatures, QString::fromLocal8Bit("图片特征"));

	ui.listWidget->addItem(getTime()+QString::fromLocal8Bit("----------计算特征点完成----------"));
}
void SFM::ComputeMatches()
{
	ui.listWidget->addItem(getTime()+QString::fromLocal8Bit("----------匹配特征点开始----------"));

	std::string command = sparse_bin_dir.toStdString()+"openMVG_main_ComputeMatches.exe -i " + matches_dir.toStdString() + "/sfm_data.json"
		+ " -o " + matches_dir.toStdString();
	system(command.c_str());
	command = sparse_bin_dir.toStdString() + "openMVG_main_exportMatches.exe -i " + matches_dir.toStdString() + "/sfm_data.json"
		+ " -o " + matches_dir.toStdString() + "/exportMatches" + " -d " + matches_dir.toStdString() + " -m " + matches_dir.toStdString() + "/matches.putative.bin" ;
	system(command.c_str());



	QListWidget *listComputeMatches = new QListWidget();
	connect(listComputeMatches, SIGNAL(currentRowChanged(int)), this, SLOT(showPicture(int)));  //列表点击与显示图片连接
	QStringList filenamelist = getFileNames(QString(matches_dir + "/exportMatches"));
	QString tmp;
	for (int i = 0; i<filenamelist.size(); i++)
		listComputeMatches->addItem(filenamelist.at(i));
	listComputeMatches->setWindowIconText(matches_dir + "/exportMatches/");
	ui.tabWidget_picture->addTab(listComputeMatches, QString::fromLocal8Bit("特征匹配"));

	ui.listWidget->addItem(getTime()+QString::fromLocal8Bit("----------匹配特征点完成----------"));
}
void SFM::IncrementalSfM()
{
	ui.listWidget->addItem(getTime()+QString::fromLocal8Bit("----------增量SFM开始----------"));


	std::string command = sparse_bin_dir.toStdString() +"openMVG_main_IncrementalSfM.exe -i " + matches_dir.toStdString() + "/sfm_data.json"
		+ " -m " + matches_dir.toStdString() + " -o " + reconstruction_incremental_dir.toStdString();
	system(command.c_str());



	ui.listWidget->addItem(getTime()+QString::fromLocal8Bit("----------增量SFM完成----------"));

	command = "D:/MeshLab/meshlab.exe " + reconstruction_incremental_dir.toStdString() + "/cloud_and_poses.ply";
	system(command.c_str());
}

void SFM::ComputeDataColor()
{
	ui.listWidget->addItem(getTime()+QString::fromLocal8Bit("----------结构着色开始----------"));


	std::string command = sparse_bin_dir.toStdString() + "openMVG_main_ComputeSfM_DataColor.exe -i " + reconstruction_incremental_dir.toStdString() + "/sfm_data.bin"
		+ " -o " + reconstruction_incremental_dir.toStdString()+ "/colorized.ply";
	system(command.c_str());


	ui.listWidget->addItem(getTime()+QString::fromLocal8Bit("----------结构着色完成----------"));

	command = "D:/MeshLab/meshlab.exe " + reconstruction_incremental_dir.toStdString() + "/colorized.ply";
	system(command.c_str());
}

void SFM::OpenMVG2openMVS()
{
	ui.listWidget->addItem(getTime()+QString::fromLocal8Bit("----------转换文件类型开始----------"));


	std::string command = sparse_bin_dir.toStdString() + "openMVG_main_openMVG2openMVS.exe -i " + reconstruction_incremental_dir.toStdString() + "/sfm_data.bin"
		+ " -o " + output_dir.toStdString() + "/scene.mvs";
	system(command.c_str());

	ui.listWidget->addItem(getTime()+QString::fromLocal8Bit("----------转换文件类型完成----------"));
}
void SFM::Sparse()
{
	emit ui.action_InitImage->triggered();
	emit ui.action_ComputeFeatures->triggered();
	emit ui.action_ComputeMatches->triggered();
	emit ui.action_IncrementalSfM->triggered();
	emit ui.action_ComputeDataColor->triggered();
	emit ui.action_OpenMVG2openMVS->triggered();
}




void SFM::DensifyPointCloud()
{
	ui.listWidget->addItem(getTime()+QString::fromLocal8Bit("----------点云稠密化开始----------"));

	std::string command = dense_bin_dir.toStdString() + "DensifyPointCloud.exe " + output_dir.toStdString() + "/scene.mvs";
	system(command.c_str());

	ui.listWidget->addItem(getTime()+QString::fromLocal8Bit("----------点云稠密化结束----------"));

	command = "D:/MeshLab/meshlab.exe " + output_dir.toStdString() + "/scene_dense.ply";
	system(command.c_str());
}
void SFM::ReconstructMesh()
{
	ui.listWidget->addItem(getTime()+QString::fromLocal8Bit("----------网格重建完成----------"));

	std::string command = dense_bin_dir.toStdString() + "ReconstructMesh.exe " + output_dir.toStdString() + "/scene_dense.mvs";
	system(command.c_str());

	ui.listWidget->addItem(getTime()+QString::fromLocal8Bit("----------网格重建完成----------"));

	command = "D:/MeshLab/meshlab.exe " + output_dir.toStdString() + "/scene_dense_mesh.ply";
	system(command.c_str());
}
void SFM::RefineMesh()
{
	ui.listWidget->addItem(getTime()+QString::fromLocal8Bit("----------纹理细化开始----------"));

	std::string command = dense_bin_dir.toStdString() + "RefineMesh.exe " + output_dir.toStdString() + "/scene_dense_mesh.mvs";
	system(command.c_str());

	ui.listWidget->addItem(getTime()+QString::fromLocal8Bit("----------纹理细化完成----------"));

	command = "D:/MeshLab/meshlab.exe " + output_dir.toStdString() + "/scene_dense_mesh_refine.ply";
	system(command.c_str());
}
void SFM::TextureMesh()
{
	ui.listWidget->addItem(getTime()+QString::fromLocal8Bit("----------纹理映射完成----------"));

	std::string command = dense_bin_dir.toStdString() + "TextureMesh.exe " + output_dir.toStdString() + "/scene_dense_mesh_refine.mvs";
	system(command.c_str());

	ui.listWidget->addItem(getTime()+QString::fromLocal8Bit("----------纹理映射完成----------"));

	command = "D:/MeshLab/meshlab.exe " + output_dir.toStdString() + "/scene_dense_mesh_refine_texture.ply";
	system(command.c_str());
}
void SFM::Dense()
{
	emit ui.action_DensifyPointCloud->triggered();
	emit ui.action_ReconstructMesh->triggered();
	emit ui.action_RefineMesh->triggered();
	emit ui.action_TextureMesh->triggered();
}



void SFM::ImportCloud()
{
	//定义文件对话框类  
	QFileDialog *fileDialog = new QFileDialog(this);
	//定义文件对话框标题  
	fileDialog->setWindowTitle(tr("select point cloud path"));
	//设置默认文件路径  
	fileDialog->setDirectory(".");
	//设置选择目录
	fileDialog->setFileMode(QFileDialog::ExistingFile);
	//设置视图模式  
	fileDialog->setViewMode(QFileDialog::Detail);
	//打印路径  
	QStringList fileNames;
	if (fileDialog->exec())
		fileNames = fileDialog->selectedFiles();
	if (fileNames.empty())
		QMessageBox(QMessageBox::NoIcon, "Attention!", "No path selected!").exec();
	else
		if(system(("D:/MeshLab/meshlab.exe " + fileNames.at(0).toStdString()).c_str()))
			QMessageBox(QMessageBox::NoIcon, "Attention!", "Path is illegal!").exec();
}

void SFM::receiveData(QString in, QString out)
{
	input_dir = in;
	output_dir = out;
	matches_dir = output_dir + "/matches";
	reconstruction_incremental_dir = output_dir + "/reconstruction_incremental";
	camera_file_params = "E:/sensor_width_camera_database.txt";
	sparse_bin_dir = "E:/buildopenMVG/Windows-AMD64-Release/Release/";
	dense_bin_dir = "E:/openMVS/build/openMVS/bin/vc14/x64/Release/";
	
	ui.listWidget->addItem(getTime()+QString::fromLocal8Bit("图片集路径:") + input_dir);
	ui.listWidget->addItem(getTime()+QString::fromLocal8Bit("输出结果路径:") + output_dir);
	ui.tabWidget_picture->clear();


}


QString getTime()
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	return QString("%1-%2-%3 %4:%5:%6	").arg(sys.wYear).arg(sys.wMonth, 2, 12, QChar('0')).arg(sys.wDay, 2, 10, QChar('0')).arg(sys.wHour, 2, 10, QChar('0')).arg(sys.wMinute, 2, 10, QChar('0')).arg(sys.wSecond,2,10,QChar('0'));
}