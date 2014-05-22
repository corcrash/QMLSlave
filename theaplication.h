#ifndef THEAPLICATION_H
#define THEAPLICATION_H

#include <QObject>
#include "qmlserver.h"
#include "messagehandler.h"

class TheAplication : public QObject
{
    Q_OBJECT

private:
    QMLServer *server_p;
    MessageHandler *messageHandler_p;

public:
    explicit TheAplication(QObject *parent = 0);

signals:

private slots:
    static void QMLCodeRequest(const QVariant &message);
    static void newMessage(const QVariant &message);


public slots:

};

#endif // THEAPLICATION_H
