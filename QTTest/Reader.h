
#include <QObject>
#include <QDebug>
#include <QTime>

class Reader :
	public QObject
{
	Q_OBJECT
public:
	Reader(){}

	void receiveNewspaper(const QString &name){
		qDebug() << "receivenewspaper: " << name;
	}
	void receiveNewspaper(const QString &name, const QDate &date = QDate::currentDate());

	~Reader(){}


};

