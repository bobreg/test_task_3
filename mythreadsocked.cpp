#include "mythreadsocked.h"

MyThreadSocked::MyThreadSocked(QString port, unsigned char len, QObject *parent) : QThread(parent)
{   
    name_port = port;
    if(len != 0){
        len_codogramm = len;
    }
    //qDebug() << name_port;
}

void MyThreadSocked::run(){
    MySerial serial(name_port , len_codogramm);
    connect(&serial, &MySerial::message, this, &MyThreadSocked::message);
    exec();
}
