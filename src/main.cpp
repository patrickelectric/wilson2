#include <QApplication>
#include <QThread>

#include "abilitiesmanager.h"
#include "qbot.h"

#include "abilities/repeater.h"

Q_DECLARE_METATYPE(Message::Ptr)

int main(int argc, char *argv[])
{
    qRegisterMetaType<Message::Ptr>();

    QCoreApplication app(argc, argv);

    QThread thread;
    QBot qbot;

    QObject::connect(&thread, &QThread::started, &qbot, &QBot::start);
    qbot.moveToThread(&thread);
    thread.start();
    return app.exec();
}
