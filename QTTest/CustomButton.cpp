#include <qDebug>
#include <QWidget>
#include <QMouseEvent>
#include "CustomButton.h"



CustomButton::CustomButton(QWidget* parent) 
: QPushButton(parent)
{

	connect(this, &CustomButton::clicked,
		this, &CustomButton::onButtonCliecked);      

}

CustomButton::~CustomButton()
{
}


void CustomButton::onButtonCliecked()
{
	qDebug() << "You clicked this!";     

}

void CustomButton::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		qDebug() << "left Press down";
	}
	
	else
	{			
		QPushButton::mousePressEvent(event);
	}

}

bool CustomButton::event(QEvent *e)
{
	if (e->type() == QEvent::KeyPress) {
		QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);
		if (keyEvent->key() == Qt::Key_Tab) {
			qDebug() << "You press tab.";
			return true;
		}
	}
	return QWidget::event(e);
}