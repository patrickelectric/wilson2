#include "repeater.h"

QString Repeater::name() const {
    return QStringLiteral("Repeater");
}

QString Repeater::command() const {
    return QStringLiteral("/repeater");
}

QString Repeater::process(const QString& input) const {
    QStringList commands = input.split(' ');
    if(commands.size() > 1) {
        commands.removeFirst();
        return commands.join(' ');
    }

    return "Nothing to repeat :)";
};

REGISTER_ABILITY(Repeater)
