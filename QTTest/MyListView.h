#pragma once

#include <QStringListModel>
#include <QListView>

class MyListView : public QStringListModel, public QListView
{
	Q_OBJECT

public:
	MyListView(QObject *parent);
	~MyListView();
private:
	QStringListModel* model;
	QListView* listView;
};
