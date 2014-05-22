#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <QObject>
#include <QMap>
#include "qmlserver.h"

class MessageHandler : public QObject
{
    Q_OBJECT
private:
    QMap<QString, void(*)(const QVariant &message)> eventMap;
    QMLServer *server;

public:
    explicit MessageHandler(QObject *parent = 0);
    MessageHandler(QMLServer *server, QObject *parent);
    void registerEvent(const QString &event_descriptor, void (*event)(const QVariant &message));
    void unRegisterEvent(const QString &event_descriptor);

signals:

private slots:
    void handleNewEvent(const QString &identifier, const QVariant &message);

public slots:

};

#endif // MESSAGEHANDLER_H
