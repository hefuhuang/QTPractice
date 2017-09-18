#ifndef QTTEST_H
#define QTTEST_H

#include <QtWidgets/QMainWindow>
#include <QDebug>
#include <QTextEdit>
#include <QFileDialog>
#include <QCloseEvent>
#include <QPainter>
#include "ui_qttest.h"

//#define eventAccptAndIgnore       // 2017/9/16 
#define Eventfilter

class QTTest : public QMainWindow
{
	Q_OBJECT

public:
	QTTest(QWidget *parent = 0);
	~QTTest();

	void QTTest::showUserAgeDialog();
	void QTTest::setUserAge(int age);

protected:  
	 
#ifdef  Eventfilter
	bool eventFilter(QObject *obj, QEvent *event);     
#endif

private:
	void Open();
	void OpenFile();
	void SaveFile(); 
	void closeEvent(QCloseEvent *event); 
	void mousePressEvent(QMouseEvent *event);   //÷ÿ‘ÿ∫Ø ˝ 


	int userAge;
	QAction  *openAction; 
	QAction  *saveAction;
	QTextEdit* textEdit;
	Ui::QTTestClass ui;

};


class PaintedWidget : public QWidget
{
	Q_OBJECT
public:
	PaintedWidget(QWidget *parent = 0);
protected:
	void paintEvent(QPaintEvent *);
};




#endif // QTTEST_H
