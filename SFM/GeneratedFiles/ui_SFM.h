/********************************************************************************
** Form generated from reading UI file 'SFM.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SFM_H
#define UI_SFM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SFMClass
{
public:
    QAction *action_InputPath;
    QAction *action_InitImage;
    QAction *action_ComputeFeatures;
    QAction *action_ComputeMatches;
    QAction *action_IncrementalSfM;
    QAction *action_GlobalSfM;
    QAction *action_ComputeDataColor;
    QAction *action_DensifyPointCloud;
    QAction *action_ReconstructMesh;
    QAction *action_RefineMesh;
    QAction *action_TextureMesh;
    QAction *action_OpenMVG2openMVS;
    QAction *action_InputPath_2;
    QAction *action_InputPath_3;
    QAction *action_Sparse;
    QAction *action_Dense;
    QAction *action_ImportCloud;
    QAction *action_ClearList;
    QWidget *centralWidget;
    QLabel *label_picture;
    QTabWidget *tabWidget_picture;
    QWidget *tab;
    QWidget *tab_2;
    QListWidget *listWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_sparse;
    QMenu *menu_dense;

    void setupUi(QMainWindow *SFMClass)
    {
        if (SFMClass->objectName().isEmpty())
            SFMClass->setObjectName(QStringLiteral("SFMClass"));
        SFMClass->resize(906, 685);
        action_InputPath = new QAction(SFMClass);
        action_InputPath->setObjectName(QStringLiteral("action_InputPath"));
        action_InitImage = new QAction(SFMClass);
        action_InitImage->setObjectName(QStringLiteral("action_InitImage"));
        action_ComputeFeatures = new QAction(SFMClass);
        action_ComputeFeatures->setObjectName(QStringLiteral("action_ComputeFeatures"));
        action_ComputeMatches = new QAction(SFMClass);
        action_ComputeMatches->setObjectName(QStringLiteral("action_ComputeMatches"));
        action_IncrementalSfM = new QAction(SFMClass);
        action_IncrementalSfM->setObjectName(QStringLiteral("action_IncrementalSfM"));
        action_GlobalSfM = new QAction(SFMClass);
        action_GlobalSfM->setObjectName(QStringLiteral("action_GlobalSfM"));
        action_ComputeDataColor = new QAction(SFMClass);
        action_ComputeDataColor->setObjectName(QStringLiteral("action_ComputeDataColor"));
        action_DensifyPointCloud = new QAction(SFMClass);
        action_DensifyPointCloud->setObjectName(QStringLiteral("action_DensifyPointCloud"));
        action_ReconstructMesh = new QAction(SFMClass);
        action_ReconstructMesh->setObjectName(QStringLiteral("action_ReconstructMesh"));
        action_RefineMesh = new QAction(SFMClass);
        action_RefineMesh->setObjectName(QStringLiteral("action_RefineMesh"));
        action_TextureMesh = new QAction(SFMClass);
        action_TextureMesh->setObjectName(QStringLiteral("action_TextureMesh"));
        action_OpenMVG2openMVS = new QAction(SFMClass);
        action_OpenMVG2openMVS->setObjectName(QStringLiteral("action_OpenMVG2openMVS"));
        action_InputPath_2 = new QAction(SFMClass);
        action_InputPath_2->setObjectName(QStringLiteral("action_InputPath_2"));
        action_InputPath_3 = new QAction(SFMClass);
        action_InputPath_3->setObjectName(QStringLiteral("action_InputPath_3"));
        action_Sparse = new QAction(SFMClass);
        action_Sparse->setObjectName(QStringLiteral("action_Sparse"));
        action_Dense = new QAction(SFMClass);
        action_Dense->setObjectName(QStringLiteral("action_Dense"));
        action_ImportCloud = new QAction(SFMClass);
        action_ImportCloud->setObjectName(QStringLiteral("action_ImportCloud"));
        action_ClearList = new QAction(SFMClass);
        action_ClearList->setObjectName(QStringLiteral("action_ClearList"));
        centralWidget = new QWidget(SFMClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_picture = new QLabel(centralWidget);
        label_picture->setObjectName(QStringLiteral("label_picture"));
        label_picture->setGeometry(QRect(170, -10, 431, 311));
        tabWidget_picture = new QTabWidget(centralWidget);
        tabWidget_picture->setObjectName(QStringLiteral("tabWidget_picture"));
        tabWidget_picture->setGeometry(QRect(0, 0, 171, 551));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget_picture->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget_picture->addTab(tab_2, QString());
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(0, 550, 901, 91));
        SFMClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SFMClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 906, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_sparse = new QMenu(menuBar);
        menu_sparse->setObjectName(QStringLiteral("menu_sparse"));
        menu_dense = new QMenu(menuBar);
        menu_dense->setObjectName(QStringLiteral("menu_dense"));
        SFMClass->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_sparse->menuAction());
        menuBar->addAction(menu_dense->menuAction());
        menu->addAction(action_InputPath_3);
        menu->addAction(action_ImportCloud);
        menu->addSeparator();
        menu->addAction(action_ClearList);
        menu_sparse->addAction(action_InitImage);
        menu_sparse->addAction(action_ComputeFeatures);
        menu_sparse->addAction(action_ComputeMatches);
        menu_sparse->addAction(action_IncrementalSfM);
        menu_sparse->addAction(action_ComputeDataColor);
        menu_sparse->addAction(action_OpenMVG2openMVS);
        menu_sparse->addSeparator();
        menu_sparse->addAction(action_Sparse);
        menu_dense->addAction(action_DensifyPointCloud);
        menu_dense->addAction(action_ReconstructMesh);
        menu_dense->addAction(action_RefineMesh);
        menu_dense->addAction(action_TextureMesh);
        menu_dense->addSeparator();
        menu_dense->addAction(action_Dense);

        retranslateUi(SFMClass);

        tabWidget_picture->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SFMClass);
    } // setupUi

    void retranslateUi(QMainWindow *SFMClass)
    {
        SFMClass->setWindowTitle(QApplication::translate("SFMClass", "SFM", Q_NULLPTR));
        action_InputPath->setText(QApplication::translate("SFMClass", "\345\257\274\345\205\245\345\233\276\347\211\207\351\233\206", Q_NULLPTR));
        action_InitImage->setText(QApplication::translate("SFMClass", "\345\210\235\345\247\213\345\214\226\345\233\276\347\211\207\345\210\227\350\241\250", Q_NULLPTR));
        action_ComputeFeatures->setText(QApplication::translate("SFMClass", "\350\256\241\347\256\227\347\211\271\345\276\201\347\202\271", Q_NULLPTR));
        action_ComputeMatches->setText(QApplication::translate("SFMClass", "\345\214\271\351\205\215\347\211\271\345\276\201\347\202\271", Q_NULLPTR));
        action_IncrementalSfM->setText(QApplication::translate("SFMClass", "\345\242\236\351\207\217\351\207\215\345\273\272", Q_NULLPTR));
        action_GlobalSfM->setText(QApplication::translate("SFMClass", "\345\205\250\345\261\200\351\207\215\345\273\272", Q_NULLPTR));
        action_ComputeDataColor->setText(QApplication::translate("SFMClass", "\347\273\223\346\236\204\347\235\200\350\211\262", Q_NULLPTR));
        action_DensifyPointCloud->setText(QApplication::translate("SFMClass", "\347\202\271\344\272\221\347\250\240\345\257\206\345\214\226", Q_NULLPTR));
        action_ReconstructMesh->setText(QApplication::translate("SFMClass", "\347\275\221\346\240\274\351\207\215\345\273\272", Q_NULLPTR));
        action_RefineMesh->setText(QApplication::translate("SFMClass", "\347\272\271\347\220\206\347\273\206\345\214\226", Q_NULLPTR));
        action_TextureMesh->setText(QApplication::translate("SFMClass", "\347\275\221\346\240\274\347\272\271\347\220\206\345\214\226", Q_NULLPTR));
        action_OpenMVG2openMVS->setText(QApplication::translate("SFMClass", "openMVG2openMVS", Q_NULLPTR));
        action_InputPath_2->setText(QApplication::translate("SFMClass", "\345\257\274\345\205\245\345\233\276\347\211\207\351\233\206", Q_NULLPTR));
        action_InputPath_3->setText(QApplication::translate("SFMClass", "\345\257\274\345\205\245\345\233\276\347\211\207\351\233\206", Q_NULLPTR));
        action_Sparse->setText(QApplication::translate("SFMClass", "\347\250\200\347\226\217\351\207\215\345\273\272", Q_NULLPTR));
        action_Dense->setText(QApplication::translate("SFMClass", "\347\250\240\345\257\206\351\207\215\345\273\272", Q_NULLPTR));
        action_ImportCloud->setText(QApplication::translate("SFMClass", "\345\257\274\345\205\245\347\202\271\344\272\221", Q_NULLPTR));
        action_ClearList->setText(QApplication::translate("SFMClass", "\346\270\205\347\251\272\350\276\223\345\207\272\345\210\227\350\241\250", Q_NULLPTR));
        label_picture->setText(QString());
        tabWidget_picture->setTabText(tabWidget_picture->indexOf(tab), QApplication::translate("SFMClass", "Tab 1", Q_NULLPTR));
        tabWidget_picture->setTabText(tabWidget_picture->indexOf(tab_2), QApplication::translate("SFMClass", "Tab 2", Q_NULLPTR));
        menu->setTitle(QApplication::translate("SFMClass", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_sparse->setTitle(QApplication::translate("SFMClass", "\347\250\200\347\226\217\351\207\215\345\273\272", Q_NULLPTR));
        menu_dense->setTitle(QApplication::translate("SFMClass", "\347\250\240\345\257\206\351\207\215\345\273\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SFMClass: public Ui_SFMClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SFM_H
