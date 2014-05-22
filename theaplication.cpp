#include "theaplication.h"
#include <QFile>
#include <QCoreApplication>

TheAplication::TheAplication(QObject *parent) :
    QObject(parent)
{
    this->server_p = QMLServer::getInstance();

    this->messageHandler_p = new MessageHandler(this->server_p, this);

//    connect(this->server_p, SIGNAL(newQMLCodeRequest()), this, SLOT(QMLCodeRequest()));

    this->messageHandler_p->registerEvent("QMLRequest", this->QMLCodeRequest);
    this->messageHandler_p->registerEvent("newMessage", this->newMessage);

    QMLServer::getInstance()->listen(QHostAddress::Any, 3210);
}

void TheAplication::QMLCodeRequest(const QVariant &message)
{
    QFile file(QCoreApplication::applicationDirPath() + "/qml/" + message.toString() + ".qml");

    if(!file.open(QIODevice::ReadOnly))
        return;

    QString dataRead = file.readAll();

    QMLServer::getInstance()->sendQMLCode(dataRead.replace("\"", "'"));

    file.close();
}

void TheAplication::newMessage(const QVariant &message)
{
    qDebug() << "We got the message: " << message.toString();
}
