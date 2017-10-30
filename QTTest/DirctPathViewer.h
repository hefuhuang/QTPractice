#pragma once

#ifndef DIRECTPATH_H
#define DIRECTPATH_H
#include <QDialog>
#include <QFileSystemModel>
#include <QTreeView> 



#define treeViewer 
class DirctPathViewer : public QDialog
{
	Q_OBJECT

public:
	DirctPathViewer(QWidget  *parent = 0 );    // 带有默认值参数的构造函数 
 	~DirctPathViewer();


private slots:     // 槽函数
	void remove();
	void createDirctPath();  

	void mkdir();
	void rm();

private:
	QFileSystemModel *model;
	QTreeView *treeView;

};
#endif 