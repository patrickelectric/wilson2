#include <QDebug>
#include <QObject>

#include <exception>

#include <tgbot/tgbot.h>

#include "abilitiesmanager.h"
#include "qbot.h"

using namespace std;
using namespace TgBot;

QBot::QBot(QObject* parent) :
    QObject(parent)
{
}

void QBot::start() {
    string token(getenv("TOKEN"));
    printf("Token: %s\n", token.c_str());

    Bot bot(token);

    bot.getEvents().onAnyMessage([&bot](Message::Ptr message) {
        QString answer = AbilitiesManager::self()->onAnyMessage(message->text.c_str());
        bot.getApi().sendMessage(message->chat->id, answer.toStdString());
    });

    signal(SIGINT, [](int s) {
        printf("SIGINT got\n");
        exit(0);
    });

    try {
        qDebug() << QStringLiteral("Bot username: %1\n").arg(bot.getApi().getMe()->username.c_str());
        bot.getApi().deleteWebhook();

        TgLongPoll longPoll(bot);
        while (true) {
            longPoll.start();
        }
    } catch (exception& e) {
        qDebug() << "Error: " << e.what();
    }
}
