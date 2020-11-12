#include "myudp.h"

MyUDP::MyUDP(QObject *parent) : QObject(parent)
{
    connect(&timer, &QTimer::timeout, this, &MyUDP::Send_data);
    data_for_recipient.append(0x55);
    data_for_recipient.append(0x78);

}

void MyUDP::Send_data(){
    //qDebug() << "port 1" << data_from_port_1.toHex(':');
    //qDebug() << "port 2" << data_from_port_2.toHex(':');
    data_for_recipient.append(data_from_port_1);
    data_for_recipient.append(data_from_port_2);
    qDebug() << data_for_recipient.toHex(':');
    socket.writeDatagram(data_for_recipient, QHostAddress("192.168.1.100"), 5577);  // отправим данные дальше по сети
    data_from_port_1.clear();
    data_from_port_2.clear();
    data_for_recipient.clear();
    data_for_recipient.append(0x55);
    data_for_recipient.append(0x78);
    data_for_recipient.append(++index);
    //qDebug() << "re-re udp";
}

void MyUDP::get_message_port1(QByteArray arr){
    data_from_port_1.append(arr);
    //qDebug() << arr.toHex(':');
}

void MyUDP::get_message_port2(QByteArray arr){
    data_from_port_2.append(arr);
    //qDebug() << arr.toHex(':');
}
