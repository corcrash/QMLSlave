#include "theaplication.h"

TheAplication::TheAplication(QObject *parent) :
    QObject(parent)
{
    this->server_p = new QMLServer(this);

    this->messageHandler_p = new MessageHandler(this->server_p, this);

    connect(this->server_p, SIGNAL(newQMLCodeRequest()), this, SLOT(QMLCodeRequest()));
    //connect(this->server_p, SIGNAL(newEventMessage(QString)), this, SLOT(newEventMessage(QString)));

    this->messageHandler_p->registerEvent("newMessage", this->newMessage);

    this->server_p->listen(QHostAddress::Any, 3210);
}

void TheAplication::QMLCodeRequest()
{
    this->server_p->sendQMLCode("import QtQuick 2.0; import QtQuick.Controls 1.1;  Button { text: 'This is just a test'; onClicked: { console.log('Test!'); client.emitSignal('newMessage', 'Works!');} }");
}

void TheAplication::newEventMessage(const QString &message)
{
    //qDebug() << message;
}

void TheAplication::newMessage(const QVariant &message)
{
    qDebug() << "We got the message: " << message.toString();
}
