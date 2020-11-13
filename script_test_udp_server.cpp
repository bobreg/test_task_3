#include <QCoreApplication>
#include <QUdpSocket>
#include <QDebug>

QUdpSocket c;

void datas(){
    QByteArray datagram;
    datagram.resize(c.pendingDatagramSize());
    c.readDatagram(datagram.data(), datagram.size());
    qDebug() << datagram.toHex(':');
    datagram.clear();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    c.bind(QHostAddress::LocalHost, 5577);

    QCoreApplication::connect(&c, &QUdpSocket::readyRead, [=](){datas();});


    return a.exec();
}


