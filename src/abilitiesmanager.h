#pragma once

#include <QLoggingCategory>

#include "abilityinterface.h"

class QJSEngine;
class QQmlEngine;

Q_DECLARE_LOGGING_CATEGORY(ABILITIESMANAGER)

/**
 * @brief Manage the project AbilitiesManager
 *
 */
class AbilitiesManager : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Return AbilitiesManager pointer
     *
     * @return AbilitiesManager*
     */
    static AbilitiesManager* self();

    /**
     * @brief Return a pointer of this singleton to the qml register function
     *
     *
     * @param engine
     * @param scriptEngine
     * @return QObject*
     */
    static QObject* qmlSingletonRegister(QQmlEngine* engine, QJSEngine* scriptEngine);

    /**
     * @brief Register a new ability
     *
     * @param ability
     */
    void registerAbility(const AbilityInterface* ability);

    /**
     * @brief Provide answer from input
     *
     * @param input
     * @return QString
     */
    QString onAnyMessage(QString input);

private:
    Q_DISABLE_COPY(AbilitiesManager)

    /**
     * @brief Construct a new Network Manager object
     *
     */
    AbilitiesManager();

    QMap<QString, const AbilityInterface*> _abilities;
};

/**
 * @brief Register categories
 *
 */
struct AbilitiesManagerRegister
{
    /**
     * @brief Register a new ability
     *
     * @param ability
     */
    AbilitiesManagerRegister(const AbilityInterface* ability) {
        AbilitiesManager::self()->registerAbility(ability);
    }
};

#define REGISTER_ABILITY(ability) \
    static AbilitiesManagerRegister _abilitiesManagerRegister ## ability(new ability());
