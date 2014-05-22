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
    static void newMessage(const QVariant &message);

signals:

private slots:
    void QMLCodeRequest();
    void newEventMessage(const QString &message);


public slots:

};

#endif // THEAPLICATION_H
