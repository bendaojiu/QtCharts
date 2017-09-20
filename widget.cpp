#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    chart = new Chart();
    chartView = new QChartView(chart, this);

    chartView->resize(600, 500);
    this->resize(600, 500);
    addTimer();
}

Widget::~Widget()
{

}

void Widget::addTimer()
{
//    int i = 0;
    for (int i = 0; i < 20; ++i)
    {
        chart->addSeriesToMap(QString("data%1").arg(i));
        DataThread *thread0 = new DataThread(QString("data%1").arg(i));
        dataThreadList.append(thread0);
//        connect(thread0, SIGNAL(TimeToGetData()), this, SLOT(addPoint()));
        connect(thread0, SIGNAL(TimeToGetData(QString)), this, SLOT(addPoint(QString)));
        thread0->start();
    }
}

void Widget::addPoint(QString name)
{
    QDateTime time = QDateTime::currentDateTime();
    chart->addPoint(name, time, qrand()%10);
//    qDebug() << QThread::currentThread();
}
