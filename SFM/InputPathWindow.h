#pragma once
#include <QtWidgets/QDialog>
#include <QLineEdit>
#include <QtWidgets/Qlabel>
#include <QtWidgets/qpushbutton.h>
#include <QHBoxLayout>
#include <QVboxLayout>
class InputPathWindow : public QDialog
{
	Q_OBJECT
public:
	InputPathWindow(QWidget *parent = 0);
	//¶¨Òå¿Ø¼þ
	QLabel* label1,*label2;
	QLineEdit* edit1,*edit2;
	QPushButton* btn1,*btn2,*btnok;
	QString path_input, path_output;
signals:
	void sendData(QString in,QString out);

	public slots:
	void clickOK();
	void chooseInputPath();
	void chooseOutputPath();
	void changeInputPath();
	void changeOutputPath();
};