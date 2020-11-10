#ifndef MYTHREADSOCKED_H
#define MYTHREADSOCKED_H

#include <QObject>
#include <QThread>
#include "myserial.h"

class MyThreadSocked : public QThread
{
    Q_OBJECT
public:
    explicit MyThreadSocked(QString port = "COM4", QObject *parent = nullptr);
    void run();

signals:
    void message(QByteArray);

private:
    QString name_port;

};

#endif // MYTHREADSOCKED_H
