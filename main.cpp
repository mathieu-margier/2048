#include <QGuiApplication>
#include <QQmlApplicationEngine>


#include <QtQml>
#include "jeu.h"

int main(int argc, char *argv[])
{
    srand(time(NULL));

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    Jeu jeu(4);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("jeu", &jeu);
    engine.rootContext()->setContextProperty("grilleItem", &jeu.getPlateauItem());
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
