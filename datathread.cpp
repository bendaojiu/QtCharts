#include "datathread.h"
#include <QDebug>

DataThread::DataThread(QString name)
{
    this->name = name;
}

void DataThread::run()
{
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(Emit()), Qt::DirectConnection);
    timer->start(1000);
    exec();
}

void DataThread::Emit()
{
    emit TimeToGetData(name);
}
