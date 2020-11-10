#ifndef MYUDP_H
#define MYUDP_H

#include <QObject>
#include <QUdpSocket>
#include <QTimer>

class MyUDP : public QObject
{
    Q_OBJECT
public:
    explicit MyUDP(QObject *parent = nullptr);
    QTimer timer;

signals:

public slots:
    void get_message_port1(QByteArray);
    void get_message_port2(QByteArray);

private:
    QUdpSocket socket;
    void Send_data();

};

#endif // MYUDP_H