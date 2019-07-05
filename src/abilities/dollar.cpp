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

REGISTER_ABILITY(Dollar)
