#include <QGuiApplication>
#include <QQmlApplicationEngine>


#include <QtQml>
#include "grille.h"
#include "grilleitem.h"

int main(int argc, char *argv[])
{
    srand(time(NULL));

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    Grille grille(4);
    GrilleItem grilleItem(grille);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("grilleItem", &grilleItem);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
