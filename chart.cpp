#include "chart.h"
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QLineSeries>
#include <QDebug>

Chart::Chart()
{
    x_start = QDateTime::currentDateTime();
    x_max = x_start.addSecs(5);
    y_max = 20;
    xAxis = new QDateTimeAxis();
    xAxis->setTickCount(10);
    xAxis->setTitleText(tr("时间"));
    xAxis->setFormat("h:mm:ss");
    xAxis->setRange(x_start, x_max);
//    this->addAxis(xAxis, Qt::AlignBottom);
//    createDefaultAxes();

    yAxis = new QValueAxis();
    yAxis->setTitleText(tr("数量"));
    yAxis->setLabelFormat("%i");
    yAxis->setRange(0, y_max);
//    this->addAxis(yAxis, Qt::AlignLeft);

//    series = new QLineSeries(this);
//    qDebug() << series->attachAxis(xAxis);
//    qDebug() << series->attachAxis(yAxis);
//    series->attachAxis(xAxis);
//    series->attachAxis(yAxis);
//    addSeries(series);
    setAxisX(xAxis);
    setAxisY(yAxis);
}

void Chart::addSeriesToMap(QString name)
{
    QLineSeries *series = new QLineSeries();
    series->setName(name);
    addSeries(series);
    setAxisX(xAxis, series);
    setAxisY(yAxis, series);
    seriesMap.insert(name, series);
}

void Chart::addPoint(QString name, QDateTime time, qreal y)
{
    seriesMap.value(name)->append(time.toMSecsSinceEpoch(), y);
    resizeXY(time, y);
}

void Chart::resizeXY(QDateTime time, qreal y)
{
    while (time > x_max)
        x_max = x_max.addSecs(2);
    while (y > y_max)
        y_max += 20;

    xAxis->setRange(x_start, x_max);
    yAxis->setRange(0, y_max);
}
