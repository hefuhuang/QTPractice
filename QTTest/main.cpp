
#include <QApplication>
#include <QCoreApplication>   //����Ӧ���ļ�  
#include <QPushButton>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QTime>
#include <QPainter>    // ϵͳ���ƺ��� 
#include <QWidget>
#include "qttest.h"    // �����ڵĴ��� 
#include "Newspaper.h"
#include "Reader.h"
#include "CustomButton.h"
#include "label.h"      // �¼���Ӧ����˵��ܽ�

#define  SystemPainter 
  
int main(int argc, char *argv[])
{
	QApplication   app(argc, argv);

#ifdef helloWord    

#include <QLabel>
	QLabel *label = new QLabel("Hello, world");
	label->show();

#endif 

#ifdef Signal    //�źŲۻ�����Ҫʹ��QTӦ�õĺ����ļ�   QCoreApplication
	// QT5
	QPushButton button("Quit");
	QObject::connect(&button, &QPushButton::clicked, [](bool) {    //lambda ���� 
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

	/*QObject::connect(&newspaper, &Newspaper::NewPaper,           // ���غ�����  �źź����Ĳ�һ��  
		&reader, &Reader::receiveNewspaper);*/

	QObject::connect(&newspaper,
		static_cast<void (Newspaper:: *)(const QString &)>(&Newspaper::NewPaper),
		&reader,
		static_cast<void (Reader:: *)(const QString &, const QDate&)>(&Reader::receiveNewspaper));


		QObject::connect(&newspaper,
			static_cast<void (Newspaper:: *)(const QString &)>(&Newspaper::NewPaper),
			[=](const QString &name) { qDebug() << QObject::tr("(�ҵ������ǣ�") << name; });

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

#ifdef Menu_TOOL_STATUS  // �����¼� �ĺ�������� �Լ��¼��ĺ���  
	QTTest win; 
	win.show();

#endif

#ifdef  EVENTLEARN

	CustomButton btn;
	btn.setText("This is a Button!");
	btn.show();

#endif   


#ifdef TotalEvent    // �¼��ܽ�  QApplivation event filterEvent PressButton 
	Label label;
	app.installEventFilter(new EventFilter(&label, &label));
	label.show();

#elif 2==TotalEvent   // �Զ������¼�  
	 
#endif

#ifdef SystemPainter

	PaintedWidget  painter;
	painter.show();

#endif

	return app.exec();
}

