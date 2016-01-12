#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qapplication.h>
#include <QMainWindow>
#include <QObject>
#include <qwidget.h>
#include <qgridlayout.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qstring.h>

#include "KMP.h"

class MainWindow :public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();
	~MainWindow();

signals:
	void mkKMP(QString, QString);

protected:
	void GUI();
	void buttons();

public slots:
    void outResults();
    void slot_filtrResults(QString input);

protected slots:
	void slot_start();

private:
	QWidget* m_widget;
	QGridLayout* m_layout;
	QPushButton* m_pb_start;
	QLabel* m_lb_outResults;
	QLineEdit* m_le_inputLine;
	QLineEdit* m_le_inputText;

	KMP* kmp;
};

#endif
