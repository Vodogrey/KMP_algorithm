#include "MainWindow.h"
#include <qdebug.h>


MainWindow::MainWindow()
{
    kmp = new KMP();

	GUI();
	buttons();

}


MainWindow::~MainWindow()
{
}


void MainWindow::GUI()
{
	m_layout = new QGridLayout();
	m_widget = new QWidget();
	m_pb_start = new QPushButton();
    m_lb_outResults = new QLabel();
	m_le_inputLine = new QLineEdit();
	m_le_inputText = new QLineEdit();

	m_layout->addWidget(m_pb_start, 3, 3, 1, 1);
	m_layout->addWidget(m_lb_outResults, 3, 1, 1, 1);
	m_layout->addWidget(m_le_inputLine, 1, 1, 1, 1);
	m_layout->addWidget(m_le_inputText, 2, 1, 1, 1);

	m_widget->setLayout(m_layout);
	this->setCentralWidget(m_widget);
}

void MainWindow::buttons()
{
	connect(m_pb_start, SIGNAL(clicked()), this, SLOT(slot_start()));
    connect(kmp, SIGNAL(results()), this, SLOT(outResults()));
    connect(m_le_inputLine, SIGNAL(textEdited(QString)), this, SLOT(slot_filtrResults(QString)));
    connect(m_le_inputText, SIGNAL(textEdited(QString)), this, SLOT(slot_filtrResults(QString)));
}
#include <qtoolbutton.h>
void MainWindow::slot_filtrResults(QString input)
{
    input.replace("#", "");
    QObject *obj = QObject::sender();

    if(obj == m_le_inputLine)
        m_le_inputLine->setText(input);
    if(obj == m_le_inputText)
        m_le_inputText->setText(input);

}

void MainWindow::slot_start()
{
	QString tempLine;
	QString tempText;
	tempLine = m_le_inputLine->text();
	tempText = m_le_inputText->text();

    kmp->clear();

    kmp->makeKMP(tempLine, tempText);
}


void MainWindow::outResults()
{
    m_lb_outResults->clear();
    QString tempOut;

    QString suffix;
    if(kmp->getInputsSize() > 1) {
        suffix = "ами";
    }
    else {
        suffix = "ом";
    }

    tempOut = QString("Образец %1 вошел %2 раз со сдвиг%3 ").arg(kmp->getInputLine()).arg(kmp->getInputsSize()).arg(suffix);

    for(int i = 0; i < kmp->getInputsSize(); ++i) {
        tempOut += QString::number(kmp->getInputsElement(i));
        if((kmp->getInputsSize() > 1) && (kmp->getInputsSize() != i+1))
            tempOut += ", ";
        if(kmp->getInputsSize() == i+1)
            tempOut += ".";
    }


    qDebug() <<tempOut;
    m_lb_outResults->setText(tempOut);
}
