/********************************************************************************
** Form generated from reading UI file 'qttest.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTTEST_H
#define UI_QTTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTTestClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QTTestClass)
    {
        if (QTTestClass->objectName().isEmpty())
            QTTestClass->setObjectName(QStringLiteral("QTTestClass"));
        QTTestClass->resize(600, 400);
        menuBar = new QMenuBar(QTTestClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QTTestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QTTestClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QTTestClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QTTestClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QTTestClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QTTestClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QTTestClass->setStatusBar(statusBar);

        retranslateUi(QTTestClass);

        QMetaObject::connectSlotsByName(QTTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *QTTestClass)
    {
        QTTestClass->setWindowTitle(QApplication::translate("QTTestClass", "QTTest", 0));
    } // retranslateUi

};

namespace Ui {
    class QTTestClass: public Ui_QTTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTTEST_H
