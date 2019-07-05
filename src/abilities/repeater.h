#pragma once

#include <QObject>

#include "abilitiesmanager.h"

class Repeater: public AbilityInterface
{
    Q_OBJECT
public:
    /**
     * @brief Create new Repeater Plugin
     */
    Repeater() = default;
    ~Repeater() = default;

    /**
     * @brief Return Plugin name
     * @return Repeater
     */
    QString name() const override;

    /**
     * @brief
     *
     * @return QString
     */
    QString command() const override;

    /**
     * @brief Process input
     *
     * @param input
     * @return QString
     */
    QString process(const QString& input) const override;

    /**
     * @brief Async process
     *
     * @param message
     */
    void asyncProcess(Message::Ptr message) const override;
};
