#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QList>
#include <QtCharts/QChartView>
#include "chart.h"
#include "datathread.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void addTimer();


    Chart *chart;
    QChartView *chartView;
    QList<DataThread*> dataThreadList;


private slots:
    void addPoint(QString name);
};

#endif // WIDGET_H
