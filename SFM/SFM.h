#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SFM.h"
#include "InputPathWindow.h"
class SFM : public QMainWindow
{
	Q_OBJECT
public slots:

	void showPicture(int);//显示图片
	//sparse
	void InputPath();//输入路径
	void InitImage();//初始化图片
	void ComputeFeatures();//计算特征点
	void ComputeMatches();//计算匹配
	void IncrementalSfM();//增量重建
	void ComputeDataColor();//结构着色
	void OpenMVG2openMVS();//文件转换
	void Sparse();//稀疏重建
	//dense
	void DensifyPointCloud();
	void ReconstructMesh();
	void RefineMesh();
	void TextureMesh();
	void Dense();


	void clearList();

	void ImportCloud();
	void receiveData(QString in,QString out);//接受数据
public:
	SFM(QWidget *parent = Q_NULLPTR);
	InputPathWindow* e;
	QString input_dir, output_dir, matches_dir, 
		 reconstruction_incremental_dir,camera_file_params;
	QString sparse_bin_dir,dense_bin_dir;
private:
	Ui::SFMClass ui;
};
