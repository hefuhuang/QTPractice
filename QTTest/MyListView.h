#pragma once

#include <QDialog>
#include <QStringListModel>
#include <QListView>
#include <QDialogButtonBox>
#include <QStyledItemDelegate>

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

#include <QSpinBox>
// 对数据的输入格式进行限定  

class SpinBoxDelegate : public QStyledItemDelegate      // 视图与模型 
{
	Q_OBJECT
public:
	SpinBoxDelegate(QObject *parent = 0) : QStyledItemDelegate(parent) {}

	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
		const QModelIndex &index) const;

	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model,
		const QModelIndex &index) const;

	void updateEditorGeometry(QWidget *editor,
		const QStyleOptionViewItem &option,
		const QModelIndex &index) const;
};
