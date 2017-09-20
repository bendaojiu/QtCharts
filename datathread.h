#ifndef DATATHREAD_H
#define DATATHREAD_H

#include <QThread>
#include <QTimer>


class DataThread : public QThread
{
    Q_OBJECT
public:
    DataThread(QString name);

    QString name;
    QTimer *timer;

protected:
    void run();


signals:
    void TimeToGetData(QString name);


private slots:
    void Emit();
};

#endif // DATATHREAD_H
