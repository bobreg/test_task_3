#ifndef MYSERIAL_H
#define MYSERIAL_H

#include <QObject>
#include <QSerialPort>
#include <QDebug>

class MySerial : public QObject
{
    Q_OBJECT
public:
    explicit MySerial(QString port = nullptr, QObject *parent = nullptr);
    QSerialPort serial_port;

signals:
    void message(QByteArray);

public slots:
    void new_data();

private:
    quint16 crc16_modbus(const QByteArray &);

};

#endif // MYSERIAL_H
