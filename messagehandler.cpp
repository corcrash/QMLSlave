#include "messagehandler.h"

MessageHandler::MessageHandler(QObject *parent) :
    QObject(parent)
{
    this->server = QMLServer::getInstance();
    connect(this->server, SIGNAL(newEventMessage(QString,QVariant)), this, SLOT(handleNewEvent(QString,QVariant)));
}

MessageHandler::MessageHandler(QMLServer *server, QObject *parent) :
    QObject(parent)
{
    this->server = QMLServer::getInstance();
    connect(this->server, SIGNAL(newEventMessage(QString,QVariant)), this, SLOT(handleNewEvent(QString,QVariant)));
}

void MessageHandler::registerEvent(const QString &event_descriptor, void (*event)(const QVariant &message))
{
    if(eventMap.contains(event_descriptor))
    {
        eventMap.remove(event_descriptor);
    }

    eventMap.insert(event_descriptor, event);
}

void MessageHandler::unRegisterEvent(const QString &event_descriptor)
{
    if(eventMap.contains(event_descriptor))
    {
        eventMap.remove(event_descriptor);
    }
}

void MessageHandler::handleNewEvent(const QString &identifier, const QVariant &message)
{

    if(this->eventMap.contains(identifier))
    {
//        typedef void (*fptr)();
//        fptr my_ptr = 0;
//        *reinterpret_cast<void**>(&my_ptr) = this->eventMap.value(event);
//        my_ptr();
//        void (*foo)();
        this->eventMap.value(identifier)(message);
//        foo();
//        //(*temp)();
    }
}
