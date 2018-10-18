#include "InputPathWindow.h"
#include "qfiledialog.h"
#include "qmessagebox.h"


InputPathWindow::InputPathWindow(QWidget *parent)
	: QDialog(parent)
{
	this->setWindowModality(Qt::ApplicationModal);
	this->setFixedSize(500, 100);
	this->setWindowTitle(QString::fromLocal8Bit("选择路径"));
	//初始化控件
	label1 = new QLabel(QString::fromLocal8Bit("图片集路径"), this);
	edit1 = new QLineEdit(this);
	edit1->setFixedHeight(20);
	btn1 = new QPushButton("...", this);
	label2 = new QLabel(QString::fromLocal8Bit("输出结果路径"), this);
	edit2 = new QLineEdit(this);
	edit2->setFixedHeight(20);
	btn2 = new QPushButton("...", this);
	btnok = new QPushButton(QString::fromLocal8Bit("确定"), this);
	QGridLayout *mainLayout = new QGridLayout(this);
	mainLayout->addWidget(label1, 0, 0);
	mainLayout->addWidget(label2, 1, 0);
	mainLayout->addWidget(edit1, 0, 1);
	mainLayout->addWidget(edit2, 1, 1);
	mainLayout->addWidget(btn1, 0, 2);
	mainLayout->addWidget(btn2, 1, 2);
	mainLayout->addWidget(btnok, 2, 1, Qt::AlignHCenter);
	//mainLayout->setSizeConstraint(QLayout::SetFixedSize);
	this->setLayout(mainLayout);
	//信号和槽函数连接

	connect(btn1, SIGNAL(clicked()), this, SLOT(chooseInputPath()));
	connect(btn2, SIGNAL(clicked()), this, SLOT(chooseOutputPath()));
	connect(btnok,SIGNAL(clicked()), this, SLOT(clickOK()));

	connect(edit1, SIGNAL(textChanged(const QString&)), this, SLOT(changeInputPath()));
	connect(edit2, SIGNAL(textChanged(const QString&)), this, SLOT(changeOutputPath()));
	edit1->setText("F:/ReconstructionDataSet/Sceauxcastle");
	edit2->setText("F:/123");
}

void InputPathWindow::clickOK()
{
	
	if (path_input.isEmpty() || path_output.isEmpty())
		QMessageBox(QMessageBox::NoIcon, QString::fromLocal8Bit("注意!"), QString::fromLocal8Bit("路径非法!")).exec();
	else
	{
		emit sendData(path_input, path_output);//使用emit关键词，发射数据
		QMessageBox(QMessageBox::NoIcon, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("路径选择成功!")).exec();
		this->reject();
	}
}

void InputPathWindow::changeInputPath()
{
	path_input = edit1->text();
}
void InputPathWindow::changeOutputPath()
{
	path_output = edit2->text();
}
void InputPathWindow::chooseInputPath()
{
	//定义文件对话框类  
	QFileDialog *fileDialog = new QFileDialog(this);
	//定义文件对话框标题  
	fileDialog->setWindowTitle(QString::fromLocal8Bit("选择图片集路径"));
	//设置默认文件路径  
	fileDialog->setDirectory(".");
	//设置选择目录
	fileDialog->setFileMode(QFileDialog::Directory);
	//设置视图模式  
	fileDialog->setViewMode(QFileDialog::Detail);
	//打印路径  
	QStringList fileNames;
	if (fileDialog->exec())
		fileNames = fileDialog->selectedFiles();
	if (fileNames.empty())
		QMessageBox(QMessageBox::NoIcon, QString::fromLocal8Bit("注意"), QString::fromLocal8Bit("没有选择路径!")).exec();
	else
		edit1->setText(fileNames.at(0));
}
void InputPathWindow::chooseOutputPath()
{
	//定义文件对话框类  
	QFileDialog *fileDialog = new QFileDialog(this);
	//定义文件对话框标题  
	fileDialog->setWindowTitle(QString::fromLocal8Bit("选择输出路径"));
	//设置默认文件路径  
	fileDialog->setDirectory(".");
	//设置选择目录
	fileDialog->setFileMode(QFileDialog::Directory);
	//设置视图模式  
	fileDialog->setViewMode(QFileDialog::Detail);
	//打印路径  
	QStringList fileNames;
	if (fileDialog->exec())
		fileNames = fileDialog->selectedFiles();
	if (fileNames.empty())
		QMessageBox(QMessageBox::NoIcon, QString::fromLocal8Bit("注意"), QString::fromLocal8Bit("没有选择路径!")).exec();
	else
		edit2->setText(fileNames.at(0));
}
