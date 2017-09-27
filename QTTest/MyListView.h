#pragma once

#include <QDialog>
#include <QStringListModel>
#include <QListView>
#include <QDialogButtonBox> 

class MyListView : public QDialog
{
	Q_OBJECT

public:

	MyListView(const QStringList &leaders, QWidget *parent = 0);

	MyListView();
	~MyListView();

private slots:

	void insertData();
	void showData();
	void deleteData();

	//bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
private:

	QStringListModel* model;
	QListView* listView;
	QDialogButtonBox *buttonBox;

};
