#include <QApplication>
#include <QQmlApplicationEngine>
#include <randomstringmodel.h>
#include <gui.h>
#include <qstringlistmodel.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<RandomStringModel>("com.kuende.cosmin.kuende101", 1, 0, "RandomStringModel");

    QQmlApplicationEngine engine;

    QStringListModel randomStringModel;
    QStringList randomList;
    randomList << "element 1" << "element 2" << "element 3";
    randomStringModel.setStringList(randomList);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    GUI g;

    return app.exec();
}
