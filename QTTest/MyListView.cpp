#include "MyListView.h"

MyListView::MyListView(QObject *parent)
	: QStringListModel(parent)
{
	QStringList data;
	data << "Letter A" << "Letter B" << "Letter C";
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
