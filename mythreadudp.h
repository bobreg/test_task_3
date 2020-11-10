#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include "myudp.h"

class MyThreadUdp : public QThread
{
    Q_OBJECT
public:
    explicit MyThreadUdp(QObject *parent = nullptr);
    void run();

public slots:

signals:
    void message_port1(QByteArray);
    void message_port2(QByteArray);

private:


};

#endif // MYTHREAD_H
