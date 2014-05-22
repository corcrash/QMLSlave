#include "qmlserver.h"

QMLServer *QMLServer::instance = 0;

QMLServer::QMLServer(QObject *parent) :
    QTcpServer(parent)
{
    connect(&connection, SIGNAL(newEventMessage(QString,QVariant)), this, SLOT(transferEventMessage(QString,QVariant)));
    connect(&connection, SIGNAL(newQMLCodeRequest()), this, SLOT(QMLCodeRequest()));
}

void QMLServer::sendQMLCode(const QString &QMLCode)
{
    connection.sendQMLCode(QMLCode);
}

QMLServer *QMLServer::getInstance()
{
    if(!instance)
        instance = new QMLServer();

    return instance;
}

void QMLServer::incomingConnection(qintptr handle)
{
    if (!connection.setSocketDescriptor(handle)) {
            qDebug() << connection.error();
            return;
    }
}

void QMLServer::QMLCodeRequest()
{
    emit newQMLCodeRequest();
}

void QMLServer::transferEventMessage(const QString &identifier, const QVariant &message)
{
    emit newEventMessage(identifier, message);
}
