#ifndef MYSERIAL_H
#define MYSERIAL_H

#include <QObject>
#include <QTimer>
#include <QSerialPort>
#include <QDebug>

class MySerial : public QObject
{
    Q_OBJECT
public:
    explicit MySerial(QString port = nullptr, unsigned char len = 0 ,QObject *parent = nullptr);
    QSerialPort * serial_port;

signals:
    void message(QByteArray);

public slots:
    void new_data();

private:
    quint16 crc16_modbus(const QByteArray &);
    void check_data();
    QByteArray arr;
    QString name_port;
    bool flag_new_codogramm;
    unsigned char len_codogramm;
    QTimer timer;

private slots:
    void error_port();
    void restart_port();

};

#endif // MYSERIAL_H
