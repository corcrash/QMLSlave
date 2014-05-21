#include "theaplication.h"

TheAplication::TheAplication(QObject *parent) :
    QObject(parent)
{
    this->server_p = new QMLServer(this);

    connect(this->server_p, SIGNAL(newQMLCodeRequest()), this, SLOT(QMLCodeRequest()));
    connect(this->server_p, SIGNAL(newEventMessage(QString)), this, SLOT(newEventMessage(QString)));

    this->server_p->listen(QHostAddress::Any, 3210);

    qDebug() << "Listening!";
}

void TheAplication::QMLCodeRequest()
{
    qDebug() << "Sending QMLCode!";
    this->server_p->sendQMLCode("import QtQuick 2.0; import QtQuick.Controls 1.1;  Button { text: 'This is just a test'; onClicked: console.log('Test!'); }");
}

void TheAplication::newEventMessage(const QString &message)
{
    qDebug() << message;
}
