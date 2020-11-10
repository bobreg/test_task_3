#include "mythreadsocked.h"

MyThreadSocked::MyThreadSocked(QString port, QObject *parent) : QThread(parent)
{   
    name_port = port;
    //qDebug() << name_port;
}

void MyThreadSocked::run(){
    MySerial serial(name_port);
    connect(&serial, &MySerial::message, this, &MyThreadSocked::message);
    exec();
}
