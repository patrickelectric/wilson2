#pragma once

#include <QObject>

class AbilityInterface : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
public:
    /**
     * @brief Construct a new Ability Interface object
     *
     */
    AbilityInterface() = default;

    /**
     * @brief Destroy the Ability Interface object
     *
     */
    ~AbilityInterface() = default;

    /**
     * @brief Get ability name
     *
     * @return QString
     */
    virtual QString name() const = 0;

    /**
     * @brief Get ability command
     *
     * @return QString
     */
    virtual QString command() const = 0;

    /**
     * @brief process user input
     *
     * @param input
     * @return QString
     */
    virtual QString process(const QString& input) const = 0;
};
