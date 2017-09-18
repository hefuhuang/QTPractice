#pragma once

#include <QPushButton>
#include <QDebug.h>
#include <QEvent>

class CustomButton : public QPushButton
{
	Q_OBJECT

public:
	CustomButton(QWidget *parent = 0);
	~CustomButton();

private:
	void onButtonCliecked();

protected:
	void mousePressEvent(QMouseEvent* event);    //父类的同名函数   
	bool event(QEvent *e);      // 重载函数 

};

class CustomButtonEx : public CustomButton
{
	Q_OBJECT
public:
	CustomButtonEx(QWidget *parent) : CustomButton(parent)
	{
	}
protected:
	void mousePressEvent(QMouseEvent* event)
	{
	
		qDebug() << "CustomButtonEx";
	}
};

class CustomWidget : public QWidget
{
	Q_OBJECT
public:
	CustomWidget(QWidget *parent) : QWidget(parent)
	{
	}
protected:
	void mousePressEvent(QMouseEvent *event)
	{
		qDebug() << "CustomWidget";
	}
};