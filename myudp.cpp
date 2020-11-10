#include "myudp.h"

MyUDP::MyUDP(QObject *parent) : QObject(parent)
{
    socket.bind(QHostAddress::LocalHost, 7755);
    connect(&timer, &QTimer::timeout, this, &MyUDP::Send_data);

}

void MyUDP::Send_data(){
    qDebug() << "re-re udp";
}

void MyUDP::get_message_port1(QByteArray arr){
    qDebug() << arr.toHex(':');
}

void MyUDP::get_message_port2(QByteArray arr){
    qDebug() << arr.toHex(':');
}
