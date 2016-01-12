#pragma once

#include <qobject.h>
#include <qvector.h>
#include <QString>

class KMP : public QObject
{
	Q_OBJECT

public:
	KMP(QObject* parent = 0);
	~KMP();
    void makeKMP(QString line, QString text);
    int getInputsElement(int pos);
    int getInputsSize();
    QString getInputLine();

    void clear();

signals:
    void results();

private:
    QString str;

    QString inputLine;

    QVector<int> z;
    QVector<int> inputs;
};

