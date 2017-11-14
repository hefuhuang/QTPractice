#include "DirctPathViewer.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QInputDialog>
#include <QMessageBox>

DirctPathViewer::DirctPathViewer(QWidget  *parent)
	: QDialog(parent)
{ 
#ifdef treeViewer
	model = new QFileSystemModel;
	model->setReadOnly(false);            //设置可以修改
	model->setRootPath(QDir::currentPath());

	treeView = new QTreeView;
	treeView->setModel(model);

	treeView->header()->setStretchLastSection(true);
	treeView->header()->setSortIndicator(0, Qt::AscendingOrder);
	treeView->header()->setSortIndicatorShown(true);
	//treeView->header()->s(true);

	QModelIndex index = model->index(QDir::currentPath());
	treeView->expand(index);      //当前项展开
	treeView->scrollTo(index);    //定位到当前项
	treeView->resizeColumnToContents(0);

	QPushButton *createButton = new QPushButton("Create Directory", this);
	QPushButton *removeButton = new QPushButton("Remove", this);

	QHBoxLayout *hlayout = new QHBoxLayout;
	hlayout->addWidget(createButton);
	hlayout->addWidget(removeButton);

	QVBoxLayout *vlayout = new QVBoxLayout;
	vlayout->addWidget(treeView);
	vlayout->addLayout(hlayout);

	setLayout(vlayout);
	connect(createButton, SIGNAL(clicked()), this, SLOT(createDirectory()));
	connect(removeButton, SIGNAL(clicked()), this, SLOT(remove()));
#endif 
#ifdef prallelCat 
	model = new QFileSystemModel;
	model->setRootPath(QDir::currentPath());

	treeView = new QTreeView(this);
	treeView->setModel(model);
	treeView->setRootIndex(model->index(QDir::currentPath()));

	QPushButton *mkdirButton = new QPushButton(tr("Make Directory..."), this);
	QPushButton *rmButton = new QPushButton(tr("Remove"), this);

	QHBoxLayout *buttonLayout = new QHBoxLayout;
	buttonLayout->addWidget(mkdirButton);
	buttonLayout->addWidget(rmButton);

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(treeView);
	layout->addLayout(buttonLayout);

	setLayout(layout);
	setWindowTitle("File System Model");

	connect(mkdirButton, SIGNAL(clicked()),
		this, SLOT(mkdir()));

	connect(rmButton, SIGNAL(clicked()),
		this, SLOT(rm()));
#endif 

}

DirctPathViewer::~DirctPathViewer()
{

}

void DirctPathViewer::createDirctPath()
{
	QModelIndex index = treeView->currentIndex();
	if (!index.isValid())
	{
		return;
	}
	QString dirName = QInputDialog::getText(this, tr("Create Directory"), tr("Directory name"));
	if (!dirName.isEmpty())
	{
		if (!model->mkdir(index, dirName).isValid())
		{
			QMessageBox::information(this, tr("Create Directory"), tr("Failed to create the directory"));
		}
	}
}

void DirctPathViewer::remove()
{
	QModelIndex index = treeView->currentIndex();
	if (!index.isValid())
	{
		return;
	}
	bool ok;
	if (model->fileInfo(index).isDir())
	{
		ok = model->rmdir(index);
	}
	else
	{
		ok = model->remove(index);
	}
	if (!ok)
	{
		QMessageBox::information(this, tr("Remove"), tr("Failed to remove %1").arg(model->fileName(index)));
	}

} 
void DirctPathViewer::mkdir()
{
	QModelIndex index = treeView->currentIndex();
	if (!index.isValid()) {
		return;
	}
	QString dirName = QInputDialog::getText(this,
		tr("Create Directory"),
		tr("Directory name"));

	if (!dirName.isEmpty()) {
		if (!model->mkdir(index, dirName).isValid()) {
			QMessageBox::information(this,
				tr("Create Directory"),
				tr("Failed to create the directory"));
		}
	}
}

void DirctPathViewer::rm()
{
	QModelIndex index = treeView->currentIndex();
	if (!index.isValid()) {
		return;
	}

	bool ok;
	if (model->fileInfo(index).isDir()) {
		ok = model->rmdir(index);
	}
	else {
		ok = model->remove(index);
	}

	if (!ok) {
		QMessageBox::information(this,
			tr("Remove"),
			tr("Failed to remove %1").arg(model->fileName(index)));
	}
}