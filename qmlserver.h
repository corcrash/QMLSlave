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
    static QMLServer *instance;

public:
    explicit QMLServer(QObject *parent = 0);
    void sendQMLCode(const QString &QMLCode);
    static QMLServer *getInstance();

protected:
    void incomingConnection(qintptr handle);

signals:
    void newQMLCodeRequest();
    void newEventMessage(const QString &identifier, const QVariant &message);

private slots:
    void QMLCodeRequest();
    void transferEventMessage(const QString &identifier, const QVariant &message);

public slots:

};

#endif // QMLSERVER_H
