#ifndef MYTHREADSOCKED_H
#define MYTHREADSOCKED_H

#include <QObject>
#include <QThread>
#include "myserial.h"

class MyThreadSocked : public QThread
{
    Q_OBJECT
public:
    explicit MyThreadSocked(QString port = nullptr, unsigned char len = 0, QObject *parent = nullptr);
    void run();

signals:
    void message(QByteArray);

private:
    QString name_port;
    unsigned char len_codogramm;



};

#endif // MYTHREADSOCKED_H
