#include <QDebug>
#include <QQmlEngine>

#include "abilitiesmanager.h"

AbilitiesManager::AbilitiesManager()
{
    QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);
}

void AbilitiesManager::registerAbility(const AbilityInterface* ability)
{
    _abilities.insert(ability->command(), ability);
    qDebug() << "New category available:" << ability->name();
}

QString AbilitiesManager::onAnyMessage(QString input) {
    qDebug() << QStringLiteral("User wrote: %1").arg(input);

    // Split input as arguments
    QStringList args = input.simplified().split(' ');
    if(_abilities.contains(args[0])){
        const auto ability = _abilities[args[0]];
        return ability->process(input);
    }
    return QString("Not valid command: %1\nYou can use: %2").arg(args[0], _abilities.keys().join(", "));
}

QObject* AbilitiesManager::qmlSingletonRegister(QQmlEngine* engine, QJSEngine* scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    return self();
}

AbilitiesManager* AbilitiesManager::self()
{
    static AbilitiesManager* self = new AbilitiesManager();
    return self;
}
