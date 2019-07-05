#pragma once

#include <QObject>

#include "abilitiesmanager.h"

class Dollar: public AbilityInterface
{
    Q_OBJECT
public:
    /**
     * @brief Create new Dollar Plugin
     */
    Dollar() = default;
    ~Dollar() = default;

    /**
     * @brief Return Plugin name
     * @return Dollar
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
};
