#include <QCoreApplication>
#include "theaplication.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TheAplication application;

    return a.exec();
}
