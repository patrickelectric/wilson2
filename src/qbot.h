#pragma once

#include <QObject>

class QBot : public QObject
{
    Q_OBJECT
public:
    QBot(QObject* parent = nullptr);
    void start();
};
