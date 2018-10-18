#include "SFM.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SFM w;
	w.setFixedSize(1140, 720);
	w.show();
	return a.exec();
}
