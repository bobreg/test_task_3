#include "mythreadudp.h"

MyThreadUdp::MyThreadUdp(QObject *parent) : QThread(parent)
{

}

void MyThreadUdp::run(){
    MyUDP udp;
    connect(this, &MyThreadUdp::message_port1, &udp, &MyUDP::get_message_port1);
    connect(this, &MyThreadUdp::message_port2, &udp, &MyUDP::get_message_port2);
    udp.timer.start(1000);
    exec();
}
