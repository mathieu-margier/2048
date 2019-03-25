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
    /*for (int i = 1; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int n = (i-1)*4 + j + 1;
            grille.Set(i, j, static_cast<int>(pow(2, n)));
        }
    }*/

    grille.Set(0, 0, 2);
    grille.Set(2, 0, 4);
    grille.Set(0, 1, 2);
    grille.Set(3, 1, 4);
    grille.Set(0, 2, 2);
    grille.Set(2, 2, 4);
    grille.Set(3, 2, 8);
    grille.Set(1, 3, 2);
    grille.Set(3, 3, 4);


    /*cout << "Avant : " << endl;
    grille.Print();
    cout << endl;

    grille.deplacer(Grille::DROITE);
    cout << "Après : " << endl;
    grille.Print();
    cout << endl;*/


    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("grilleItem", &grilleItem);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
