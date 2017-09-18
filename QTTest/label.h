#ifndef LABEL_H
#define LABEL_H

#include <qDebug>
#include <QWidget>
#include <QMouseEvent>
#include <QEvent>
#include <QWidget>

class Label : public QWidget
{
	Q_OBJECT

public:
	Label()    // 默认构造函数 
	{
		installEventFilter(this);
	}
	Label(QWidget *parent);    // 带参构造函数 
	~Label();

	bool eventFilter(QObject *watched, QEvent *event);

protected:
	void mousePressEvent(QMouseEvent *);
	bool event(QEvent *e);
private:
	
};

class EventFilter : public QObject
{
public:
	EventFilter(QObject *watched, QObject *parent = 0) :
		QObject(parent),
		m_watched(watched)
	{
	}
	bool eventFilter(QObject *watched, QEvent *event)
	{
		if (watched == m_watched) {
			if (event->type() == QEvent::MouseButtonPress) {
				qDebug() << "QApplication::eventFilter";
			}
		}
		return false;
	}

private:
	QObject *m_watched;
};


#endif // LABEL_H
