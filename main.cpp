#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QtQml>
#include "grille.h"
#include "grilleitem.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    Grille grille(4);
    GrilleItem grilleItem(grille);

    // TODO Test, enlever dès que plus nécessaire
    for (int i = 1; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int n = (i-1)*4 + j + 1;
            grille.Set(i, j, static_cast<int>(pow(2, n)));
        }
    }

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("grilleItem", &grilleItem);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
