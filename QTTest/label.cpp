#include "label.h"
Label::Label(QWidget *parent)
	: QWidget(parent)
{
	installEventFilter(this);
}

Label::~Label()
{
}
bool Label::eventFilter(QObject *watched, QEvent *event)
{
	if (watched == this) {
		if (event->type() == QEvent::MouseButtonPress) {
			qDebug() << "eventFilter";
		}
	}
	return false;
}

void Label::mousePressEvent(QMouseEvent *)
{
	qDebug() << "mousePressEvent";
}

bool Label::event(QEvent *e)
{
	if (e->type() == QEvent::MouseButtonPress) {
		qDebug() << "event";
	}
	return QWidget::event(e);
}