#ifndef CURRENCYMODEL_H
#define CURRENCYMODEL_H

#include <QAbstractTableModel>

class CurrencyModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	CurrencyModel(QObject *parent=0); 
	~CurrencyModel(); 

	void setCurrencyMap(const QMap<QString, double> &map);   // 非const的成员函数不可以被const的对象访问 

	int rowCount(const QModelIndex &parent) const;   // this指针常量化  任何修改this成员变量的操作都是不允许的  即可被const对象访问也可以被非const对象访问

	int columnCount(const QModelIndex &parent) const;

	QVariant data(const QModelIndex &index, int role) const;

	QVariant headerData(int section, Qt::Orientation orientation, int role) const;

	bool setData( const QModelIndex &index, const QVariant &value,int role); 

	Qt::ItemFlags flags(const QModelIndex &index) const; 

private:

	QString currencyAt(int offset) const;

	QMap<QString, double> currencyMap;
	
};

#endif // CURRENCYMODEL_H	
