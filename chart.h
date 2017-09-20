#ifndef CHART_H
#define CHART_H

#include <QtCharts/QChart>
#include <QDateTime>
#include <QMap>

QT_CHARTS_BEGIN_NAMESPACE
class QDateTimeAxis;
class QValueAxis;
class QLineSeries;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE


class Chart : public QChart
{
public:
    Chart();

    void addSeriesToMap(QString name);
    void addPoint(QString name, QDateTime time, qreal y);
    void resizeXY(QDateTime time, qreal y);

    QDateTime x_start;
    QDateTime x_max;
    qreal y_max;
    QDateTimeAxis *xAxis;
    QValueAxis *yAxis;
    QMap<QString, QLineSeries *> seriesMap;
};

#endif // CHART_H
