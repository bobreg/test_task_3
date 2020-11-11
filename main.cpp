#include <QCoreApplication>
#include "mythreadudp.h"
#include "mythreadsocked.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    QCoreApplication a(argc, argv);
    MyThreadUdp b;
    MyThreadSocked c1("COM4", 14);
    MyThreadSocked c2("COM3", 10);
    QCoreApplication::connect(&c1, &MyThreadSocked::message, &b, &MyThreadUdp::message_port1, Qt::QueuedConnection);
    QCoreApplication::connect(&c2, &MyThreadSocked::message, &b, &MyThreadUdp::message_port2, Qt::QueuedConnection);
    b.start();
    c1.start();
    c2.start();
    return a.exec();
}
