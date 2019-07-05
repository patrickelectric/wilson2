#include "dollar.h"

QString Dollar::name() const {
    return QStringLiteral("Dollar");
}

QString Dollar::command() const {
    return QStringLiteral("/dollar");
}

QString Dollar::process(const QString& input) const {
    return QStringLiteral("inf");
};

void Dollar::asyncProcess(Message::Ptr message) const {
    emit finished(message, process(message->text.c_str()));
}

REGISTER_ABILITY(Dollar)
