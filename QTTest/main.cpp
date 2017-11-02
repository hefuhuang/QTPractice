
#include <QApplication>
#include <QCoreApplication>   //核心应用文件  
#include <QPushButton>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QTime>
#include <QPainter>    // 系统绘制函数 
#include <QWidget>
#include <QEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QFont>
#include <QPainter>
#include <QRadialGradient> 
#include <QBrush>
#include <QDataStream> 
#include <QListWidget>
#include <QTableWidget> 

#include "qttest.h"    // 主窗口的创建 
#include "Newspaper.h"
#include "Reader.h"
#include "CustomButton.h"
#include "label.h"      // 事件响应与过滤的总结 
#include "MyListView.h"
#include "DirctPathViewer.h"
#include "sortview.h"

 
#define  SortAndFilter 
//#define TotalEvent 2 
  
int main(int argc, char *argv[])
{
	QApplication   app(argc, argv);

#ifdef helloWord    

#include <QLabel>
	QLabel *label = new QLabel("Hello, world");
	label->show();

#endif 

#ifdef Signal    //信号槽机制需要使用QT应用的核心文件   QCoreApplication
	// QT5
	QPushButton button("Quit");
	QObject::connect(&button, &QPushButton::clicked, [](bool) {    //lambda 函数 
		qDebug() << "You clicked me!";
	});
	button.show();

#elif 2==Signal
	// QT4 
	QPushButton button("Quit");
	QObject::connect(&button, SIGNAL(clicked()),
		&app,    SLOT(quit()));
	button.show();

#endif

#ifdef SelfDefSignal  
	Newspaper newspaper("_______________________*****************_______________________: "); 
	Reader reader;
	//QObject::connect(&newspaper, (void (Newspaper:: *)(const QString &, const QDate &))&Newspaper::NewPaper,
	//	             &reader, &Reader::receiveNewspaper);

	/*QObject::connect(&newspaper, &Newspaper::NewPaper,           // 重载函数的  信号函数的不一样  
		&reader, &Reader::receiveNewspaper);*/

	QObject::connect(&newspaper,
		static_cast<void (Newspaper:: *)(const QString &)>(&Newspaper::NewPaper),
		&reader,
		static_cast<void (Reader:: *)(const QString &, const QDate&)>(&Reader::receiveNewspaper));


		QObject::connect(&newspaper,
			static_cast<void (Newspaper:: *)(const QString &)>(&Newspaper::NewPaper),
			[=](const QString &name) { qDebug() << QObject::tr("(我的名字是：") << name; });

	 newspaper.send();


#endif

#ifdef QT4SelfDefineSiginal
	Newspaper newspaper("_______________________*****************_______________________: "); 
	Reader reader;
	QObject::connect(&newspaper, SIGNAL(NewPaper(QString)),
		             &reader, SLOT(receiveNewspaper(QString)));
	newspaper.send();

#endif

#ifdef slider_spin    //mian windows  

	QWidget window;
	window.setWindowTitle("Enter your age");

	QSpinBox *spinBox = new QSpinBox(&window);
	QSlider *slider = new QSlider(Qt::Horizontal, &window);
	spinBox->setRange(0, 130);
	slider->setRange(0, 130);

	QObject::connect(slider, &QSlider::valueChanged, 
		spinBox, &QSpinBox::setValue);
	void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;
	QObject::connect(spinBox, spinBoxSignal,
		slider, &QSlider::setValue);
	spinBox->setValue(35);

	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(spinBox);
	layout->addWidget(slider);
	window.setLayout(layout);
	window.show();

#endif

#ifdef Menu_TOOL_STATUS  // 包含事件 的忽略与接受 以及事件的忽略  
	QTTest win; 
	win.show();

#endif

#ifdef  EVENTLEARN

	CustomButton btn;
	btn.setText("This is a Button!");
	btn.show();

#endif   

#ifdef TotalEvent    // 事件总结  QApplivation event filterEvent PressButton 
	Label label;
	app.installEventFilter(new EventFilter(&label, &label));
	label.show();

#elif 2==TotalEvent   // 自定定义事件  
	 // QEvent::Type  ;
	 // QEvent::User 
	// static int QEvent::registerEventType ( int hint = -1 );   //事件注册  
	//static bool QCoreApplication::sendEvent(QObject *receiver,QEvent *event);
	//QMouseEvent event(QEvent::MouseButtonPress, pos, 0, 0, 0);
	//QApplication::sendEvent(mainWindow, &event); 
	//static void QCoreApplication::postEvent(QObject *receiver,QEvent *event); 

#endif

#ifdef SystemPainter

	PaintedWidget  painter;
	painter.show();

#endif
#ifdef GraphicSeceneAndView 
    
	QGraphicsScene scene;
	scene.setSceneRect(0, 0, 500, 500);   //sceneRect属性供QGraphicsView确定视图默认的滚动条区域，并且协助QGraphicsScene管理元素索引
	scene.addLine(0, 0, 150, 150);
	QString text = "maybe I have get the key of QT5";
	scene.addText(text);

	QGraphicsView view(&scene);
	view.setWindowTitle("Graphics View");      // 窗口命名
	//view.resize(500, 500);   // 居中显示  
	view.show();

  
#endif 
#ifdef DrawBushAndQpen 

	QRadialGradient gradient(50, 50, 50, 50, 50);
	gradient.setColorAt(0, QColor::fromRgbF(0, 1, 0, 1));
	gradient.setColorAt(1, QColor::fromRgbF(0, 0, 0, 0));
	QBrush brush(gradient);

	QPainter painter;
	QPen pen(Qt::green, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
	painter.setPen(pen);

	painter.setBrush(brush);
	painter.drawEllipse(50,150,200,150);

	painter.setRenderHint(QPainter::Antialiasing, true);    // 反走样 
	painter.setPen(QPen(Qt::black, 5, Qt::DashDotLine, Qt::RoundCap));
	painter.setBrush(Qt::yellow);
	painter.drawEllipse(300, 150, 200, 150);

#endif

#ifdef LinearGradient  

	void paintEvent(QPaintEvent *)
	{
		QPainter painter(this);

		painter.setRenderHint(QPainter::Antialiasing, true);
		QLinearGradient linearGradient(60, 50, 200, 200);
		linearGradient.setColorAt(0.2, Qt::white);
		linearGradient.setColorAt(0.6, Qt::green);
		linearGradient.setColorAt(1.0, Qt::black);
		painter.setBrush(QBrush(linearGradient));
		painter.drawEllipse(50, 50, 200, 150);
	} 


	void ColorWheel::paintEvent(QPaintEvent *)   // 颜色轮 
	{
		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing);

		const int r = 150;
		QConicalGradient conicalGradient(0, 0, 0);

		conicalGradient.setColorAt(0.0, Qt::red);      // 0 度角设置为红色
		conicalGradient.setColorAt(60.0 / 360.0, Qt::yellow);
		conicalGradient.setColorAt(120.0 / 360.0, Qt::green);
		conicalGradient.setColorAt(180.0 / 360.0, Qt::cyan);
		conicalGradient.setColorAt(240.0 / 360.0, Qt::blue);
		conicalGradient.setColorAt(300.0 / 360.0, Qt::magenta);
		conicalGradient.setColorAt(1.0, Qt::red);

		painter.translate(r, r);

		QBrush brush(conicalGradient);
		painter.setPen(Qt::NoPen);
		painter.setBrush(brush);
		painter.drawEllipse(QPoint(0, 0), r, r);
	}

	void ColorWheel::paintEvent(QPaintEvent *)   // 颜色轮 
	{
		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing);

		const int r = 150;
		QConicalGradient conicalGradient(r, r, 0);

		conicalGradient.setColorAt(0.0, Qt::red);
		conicalGradient.setColorAt(60.0 / 360.0, Qt::yellow);
		conicalGradient.setColorAt(120.0 / 360.0, Qt::green);
		conicalGradient.setColorAt(180.0 / 360.0, Qt::cyan);
		conicalGradient.setColorAt(240.0 / 360.0, Qt::blue);
		conicalGradient.setColorAt(300.0 / 360.0, Qt::magenta);
		conicalGradient.setColorAt(1.0, Qt::red);

		QBrush brush(conicalGradient);
		painter.setPen(Qt::NoPen);
		painter.setBrush(brush);
		painter.drawEllipse(QPoint(r, r), r, r);
	}

#endif
#ifdef  FilePath 
	QString filestr ;
	filestr = app.applicationFilePath();
	QFile file("in.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qDebug() << "Open file failed.";
		return -1;
	}
	else {
		while (!file.atEnd()) {
			qDebug() << file.readLine();
		}
	}

	QFileInfo info(file);
	qDebug() << info.isDir();
	qDebug() << info.isExecutable();
	qDebug() << info.baseName();
	qDebug() << info.completeBaseName();
	qDebug() << info.suffix();
	qDebug() << info.completeSuffix();
#endif
#ifdef  FileWriteAndRead  // binary file read 
	QFile file("file.dat");
	file.open(QIODevice::ReadWrite);

	QDataStream stream(&file);
	QString str = "the answer is 42";
	QString strout;

	stream << str;
	file.flush();
	stream >> strout;  

	stream << str;
	stream.device()->seek(0);
	stream >> strout;
	
	file.close();
#endif 

#ifdef ViewList   // 9.27 

	QStringList list;
	list << QObject::tr("hello")
		<< QObject::tr("hello2")
		<< QObject::tr("hello3")
		<< QObject::tr("5")
		<< QObject::tr("6");
	MyListView w2(list);
	MyListView w;
	w.show();
	w2.show();

#endif

#ifdef QFileSystemModel   // 9.27 
	DirctPathViewer wFile; 
	wFile.show();
	wFile.setWindowTitle("QFileSystemModel ");
#endif 

#ifdef QModelView
	MyListView view;
	view.show();

#endif  

#ifdef  ViewChioce    // 视图选择  
	QTableWidget m_tableWigrt(8,4);    // 表格的创建 
	QItemSelectionModel *selectionModel = m_tableWigrt.selectionModel();
	QModelIndex topLeft = m_tableWigrt.model()->index(0, 0, QModelIndex());
	QModelIndex bottomRight = m_tableWigrt.model()->index(5, 2, QModelIndex());  // 设置出事选定区

	QItemSelection selection(topLeft, bottomRight);
	selectionModel->select(selection, QItemSelectionModel::Select);

	//  获取选择区发的数据 
	QModelIndexList indexes = selectionModel->selectedIndexes();
	QModelIndex index;

	m_tableWigrt.show();

#endif 

#ifdef SortAndFilter 

	SortView m_SortFilter; 
	m_SortFilter.show();

#endif 
	return app.exec();



}

