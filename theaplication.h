#ifndef THEAPLICATION_H
#define THEAPLICATION_H

#include <QObject>
#include "qmlserver.h"

class TheAplication : public QObject
{
    Q_OBJECT

private:
    QMLServer *server_p;

public:
    explicit TheAplication(QObject *parent = 0);

signals:

private slots:
    void QMLCodeRequest();
    void newEventMessage(const QString &message);

public slots:

};

#endif // THEAPLICATION_H
