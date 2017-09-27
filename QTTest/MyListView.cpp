#include "MyListView.h"
#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QEvent> 
#include <QObject>
#include <QMessageBox>
#include <QInputDialog>

MyListView::MyListView(const QStringList &leaders, QWidget *parent)
: QDialog(parent)
{
	model = new QStringListModel(this);
	model->setStringList(leaders);

	listView = new QListView;
	listView->setModel(model);
	listView->setEditTriggers(QAbstractItemView::AnyKeyPressed
		| QAbstractItemView::DoubleClicked);

	buttonBox = new QDialogButtonBox;

	QPushButton *insertButton = buttonBox->addButton(
		tr("&Insert"), QDialogButtonBox::ActionRole);
	QPushButton *deleteButton = buttonBox->addButton(
		tr("&Delete"), QDialogButtonBox::ActionRole);
	QPushButton *showButton = buttonBox->addButton(
		tr("&show"), QDialogButtonBox::ActionRole);

	buttonBox->addButton(QDialogButtonBox::Ok);
	buttonBox->addButton(QDialogButtonBox::Cancel);

	connect(insertButton, SIGNAL(clicked()), this, SLOT(insert()));
	connect(showButton, SIGNAL(clicked()), this, SLOT(showData()));  
	connect(deleteButton, SIGNAL(clicked()), this, SLOT(del()));

	connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
	connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(listView);
	layout->addWidget(buttonBox);
	setLayout(layout);

	setWindowTitle(tr("QStringListModel"));

}

MyListView::MyListView()
{
	QStringList data;
	data << "Lett" << "LettB" << "yaya";

	model = new QStringListModel(this);
	model->setStringList(data);

	listView = new QListView(this);
	listView->setModel(model);

	QHBoxLayout *btnLayout = new QHBoxLayout;

	QPushButton *insertBtn = new QPushButton(tr("insert"), this);
	connect(insertBtn, SIGNAL(clicked()), this, SLOT(insertData()));

	QPushButton *delBtn = new QPushButton(tr("Delete"), this);
	connect(delBtn, SIGNAL(clicked()), this, SLOT(deleteData()));

	QPushButton *showBtn = new QPushButton(tr("Show"), this);
	connect(showBtn, SIGNAL(clicked()), this, SLOT(showData()));

	btnLayout->addWidget(insertBtn);
	btnLayout->addWidget(delBtn);
	btnLayout->addWidget(showBtn);

	QVBoxLayout *mainLayout = new QVBoxLayout(this);
	mainLayout->addWidget(listView);
	mainLayout->addLayout(btnLayout);
	setLayout(mainLayout);

}

MyListView::~MyListView()
{
}

void MyListView::insertData()
{
	bool isOK;
	QString text = QInputDialog::getText(this, "Insert",
		"Please input new data:",
		QLineEdit::Normal,
		"You are inserting new data.",
		&isOK);
	if (isOK) {
		int row = listView->currentIndex().row();
		model->insertRows(row, 1);
		QModelIndex index = model->index(row);
		model->setData(index, text);
		listView->setCurrentIndex(index);
		listView->edit(index);
	}
} 


void MyListView::deleteData()
{
	if (model->rowCount() > 1) {
		model->removeRows(listView->currentIndex().row(), 1);
	}
} 

void MyListView::showData()
{
	QStringList data = model->stringList();
	QString str;
	foreach(QString s, data) {
		str += s +"\0" +"\n"   ;
	}
	QMessageBox::information(this, "Data", str);
}