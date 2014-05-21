#ifndef QMLSERVER_H
#define QMLSERVER_H

#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QDebug>
#include "connection.h"

class QMLServer : public QTcpServer
{
    Q_OBJECT
private:
    Connection connection;

public:
    explicit QMLServer(QObject *parent = 0);
    void sendQMLCode(const QString &QMLCode);


protected:
    void incomingConnection(qintptr handle);

signals:
    void newQMLCodeRequest();
    void newEventMessage(const QString &message);

private slots:
    void QMLCodeRequest();
    void transferEventMessage(const QString &message);

public slots:

};

#endif // QMLSERVER_H
