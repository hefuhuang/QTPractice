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
	DirctPathViewer(QWidget  *parent = 0 );    // ����Ĭ��ֵ�����Ĺ��캯�� 
 	~DirctPathViewer();


private slots:     // �ۺ���
	void remove();
	void createDirctPath();  

	void mkdir();
	void rm();

private:
	QFileSystemModel *model;
	QTreeView *treeView;

};
#endif 