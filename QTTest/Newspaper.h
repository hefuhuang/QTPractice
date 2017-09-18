#include <QTime>
//Qt5 
#include <QObject>
class Newspaper :
	public QObject
{ 
	Q_OBJECT           //宏的声明很重要的一步
public:
	Newspaper(const QString& name) :
		m_name(name){}
	
	void send()
	{
		emit NewPaper(m_name);
	}

	~Newspaper(){}
signals:

	void NewPaper(const QString &name);
	void NewPaper(const QString &name, const QDate &date);

private:
	QString m_name;

};

