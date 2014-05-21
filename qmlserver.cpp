#include "qmlserver.h"

QMLServer::QMLServer(QObject *parent) :
    QTcpServer(parent)
{
    connect(&this->connection, SIGNAL(newEventMessage(QString)), this, SLOT(transferEventMessage(QString)));
    connect(&this->connection, SIGNAL(newQMLCodeRequest()), this, SLOT(QMLCodeRequest()));
}

void QMLServer::sendQMLCode(const QString &QMLCode)
{
    this->connection.sendQMLCode(QMLCode);
}

void QMLServer::incomingConnection(qintptr handle)
{
    if (!this->connection.setSocketDescriptor(handle)) {
            qDebug() << this->connection.error();
            return;
    }
}

void QMLServer::QMLCodeRequest()
{
    emit newQMLCodeRequest();
}

void QMLServer::transferEventMessage(const QString &message)
{
    emit newEventMessage(message);
}
