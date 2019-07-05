#include "dollar.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

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
    // Create manager and request
    auto manager = new QNetworkAccessManager;
    QNetworkRequest request({"http://api.github.com/repos/bluerobotics/ping-firmware/contents/ping1d"});
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Take care of manager
    connect(manager, &QNetworkAccessManager::finished, this, [this, message](QNetworkReply* reply) {
        reply->manager()->deleteLater();
        qDebug() << "OUTPUT";
        if(!reply) {
            QString output = "Invalid answer from server.";
            qWarning() << output;
            emit finished(message, output);
            return;
        }
        emit finished(message, reply->readAll());
    });

    qDebug() << "REQUEST";
    connect(manager, &QNetworkAccessManager ::sslErrors, this, [](QNetworkReply *reply, const QList<QSslError> &errors){
        qDebug() << reply << errors;
    });

    auto reply = manager->get(request);

    connect(reply, QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error), this, [](QNetworkReply::NetworkError code) { qDebug() << code; });

    qDebug() << reply;
    connect(reply, &QNetworkReply::downloadProgress, this, [](qint64 received, qint64 total) {
        qDebug() << "progress" << received << total;
        if(total) {
            float percent = -1;
            if(total > 0) {
                percent = 100*received/total;
            }
            qDebug() << QStringLiteral("Download [%1] %2 (%3KB)").arg("url").arg(percent).arg(
                                        received >> 10);

        }
    });
    connect(reply, &QNetworkReply::finished, this, [manager, reply] {
        qDebug() << QStringLiteral("Download %1 finished").arg("url");
        qDebug() << reply->readAll();
        manager->deleteLater();
    });
}

REGISTER_ABILITY(Dollar)
