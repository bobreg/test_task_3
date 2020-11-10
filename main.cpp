#include <QCoreApplication>
#include "mythreadudp.h"
#include "mythreadsocked.h"

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    MyThreadUdp b;
    MyThreadSocked c1("COM4");
    MyThreadSocked c2("COM3");
    QCoreApplication::connect(&c1, &MyThreadSocked::message, &b, &MyThreadUdp::message_port1);
    QCoreApplication::connect(&c2, &MyThreadSocked::message, &b, &MyThreadUdp::message_port2);
    c1.start();
    c2.start();
    b.start();
    return a.exec();
}
