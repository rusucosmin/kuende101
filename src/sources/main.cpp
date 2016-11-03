#include <QApplication>
#include <QQmlApplicationEngine>
#include <randomstringmodel.h>
#include <gui.h>
#include <qstringlistmodel.h>
#include <redditpostmodel.h>
#include <QtCore>
#include <QWidget>
#include <QtCore/Qt>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<RandomStringModel>("com.kuende.cosmin.kuende101", 1, 0, "RandomStringModel");
    qmlRegisterType<RedditPostModel>("com.kuende.cosmin.kuende101", 1, 0, "RedditPostModel");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    GUI g;

    return app.exec();
}
