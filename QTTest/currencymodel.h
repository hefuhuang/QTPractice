#ifndef CURRENCYMODEL_H
#define CURRENCYMODEL_H

#include <QAbstractTableModel>

class CurrencyModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	CurrencyModel(QObject *parent=0); 
	~CurrencyModel(); 

	void setCurrencyMap(const QMap<QString, double> &map);   // ��const�ĳ�Ա���������Ա�const�Ķ������ 

	int rowCount(const QModelIndex &parent) const;   // thisָ�볣����  �κ��޸�this��Ա�����Ĳ������ǲ������  ���ɱ�const�������Ҳ���Ա���const�������

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
