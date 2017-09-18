#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QVBoxLayout>
#include "qttest.h" 
#include "CustomButton.h"

QTTest::QTTest(QWidget *parent)
	: QMainWindow(parent)
{
	setWindowTitle(tr("little handsome"));
#ifdef  SaveAndOpen 
	openAction = new QAction(QIcon(":/images/ICon"),tr("&Open..."), this);
	openAction->setShortcut(QKeySequence::Open);
	openAction->setStatusTip(tr(" Open existed file "));
	
	saveAction = new QAction(QIcon(":/images/file-save"), tr("&Save..."), this);  // 菜单栏与工具栏设定
	saveAction->setShortcuts(QKeySequence::Save);
	saveAction->setStatusTip(tr("Save a new file"));

	QMenu *file = menuBar()->addMenu(tr("&File"));
	file->addAction(openAction);
	file->addAction(saveAction);

	QMenu *file2 = menuBar()->addMenu(tr("&HELLO"));
	file2->addAction(openAction);
	

	QToolBar *toolBar = addToolBar(tr("&File"));  
	toolBar->addAction(openAction);
	toolBar->addAction(saveAction); 

	connect(openAction, &QAction::triggered, this, &QTTest::Open);
	connect(openAction, &QAction::triggered, this, &QTTest::OpenFile);
	connect(saveAction, &QAction::triggered, this, &QTTest::SaveFile);

	textEdit = new QTextEdit(this);
	setCentralWidget(textEdit);
	statusBar(); 
#endif 

#ifdef Eventfilter     // 过滤键盘的输入 
	textEdit = new QTextEdit;
	setCentralWidget(textEdit);
	textEdit->installEventFilter(this);


#endif 

#ifdef   eventAccptAndIgnore

	CustomWidget *widget = new CustomWidget(this);
	CustomButton *cbex = new CustomButton(widget);
	cbex->setText(tr("CustomButton")); 

	CustomButtonEx *cb = new CustomButtonEx(widget);
	cb->setText(tr("CustomButtonEx"));

	QVBoxLayout *widgetLayout = new QVBoxLayout(widget);
	widgetLayout->addWidget(cbex);
	widgetLayout->addWidget(cb);
	this->setCentralWidget(widget);


#endif


	//ui.setupUi(this);
}

QTTest::~QTTest()
{

}

bool QTTest::eventFilter(QObject *obj, QEvent *event)
{
	if (obj == textEdit) {
		if (event->type() == QEvent::KeyPress) {
			QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
			qDebug() << "Ate key press" << keyEvent->key();
			return true;
		}
		else {
			return false;
		}
	}
	else {
		// pass the event on to the parent class
		return QMainWindow::eventFilter(obj, event);
	}

}


void QTTest::mousePressEvent(QMouseEvent* event)
{
	qDebug() << "mianwindow response flag!" ;

}

void QTTest::OpenFile()
{
	QString path = QFileDialog::getOpenFileName(this,
		tr("Open File"),
		".",
		tr("Text Files(*.txt)"));
	if (!path.isEmpty()) {
		QFile file(path);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QMessageBox::warning(this, tr("Read File"),
				tr("Cannot open file:\n%1").arg(path));
			return;
		}
		QTextStream in(&file);
		textEdit->setText(in.readAll());
		file.close();
	}
	else {
		QMessageBox::warning(this, tr("Path"),
			tr("You did not select any file."));
	}

}

void QTTest::SaveFile()
{
	QString path = QFileDialog::getSaveFileName(this,
												tr("open file"),
												".",
												tr("Text file(*.txt)"));
	if (!path.isEmpty()) {
		QFile file(path);
		if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
			QMessageBox::warning(this, tr("Write File"),
				tr("Cannot open file:\n%1").arg(path));
			return;
		}
		QTextStream out(&file);
		out << textEdit->toPlainText();
		file.close();
	}
	else
	{
		QMessageBox::warning(this,tr("Path"),tr("you do not select any file"));
	}

}

void QTTest::Open()
{
	QDialog dialog(this);
	dialog.setWindowTitle(tr("Hello, dialog!"));
	dialog.exec();
	qDebug() << dialog.result();
	QMessageBox::information(this, tr("Information"), tr("Open"));

	if (QMessageBox::Yes == QMessageBox::question(this,
		tr("Question"),
		tr("Are you OK?"),
		QMessageBox::Yes | QMessageBox::No,
		QMessageBox::Yes)) {
		QMessageBox::information(this, tr("Hmmm..."), tr("I'm glad to hear that!"));
	}
	else {
		QMessageBox::information(this, tr("Hmmm..."), tr("I'm sorry!"));
	}

	QMessageBox msgBox;
	msgBox.setText(tr("The document has been modified."));
	msgBox.setInformativeText(tr("Do you want to save your changes?"));
	msgBox.setDetailedText(tr("Differences here..."));
	msgBox.setStandardButtons(QMessageBox::Save
		| QMessageBox::Discard
		| QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Save);
	int ret = msgBox.exec();
	switch (ret) {
	case QMessageBox::Save:
		qDebug() << "Save document!";
		break;
	case QMessageBox::Discard:
		qDebug() << "Discard changes!";
		break;
	case QMessageBox::Cancel:
		qDebug() << "Close document!";
		break;
	}


}

//void QTTest::showUserAgeDialog()
//{
//	QDialog *dialog = new QDialog(this);
//	connect(dialog, &UserAgeDialog::userAgeChanged, this, &QTTest::setUserAge);
//	dialog->show();
//}

void QTTest::setUserAge(int age)
{
	userAge = age;
}

void QTTest::closeEvent(QCloseEvent *event)
{
	if (isWindowModified()) {
		bool exit = QMessageBox::question(this,
			tr("Quit"),
			tr("Are you sure to quit this application?"),
			QMessageBox::Yes | QMessageBox::No,
			QMessageBox::No) == QMessageBox::Yes;
		if (exit) {
			event->accept();
		}
		else {
			event->ignore();
		}
	}
	else {
		event->accept();
	}
}
