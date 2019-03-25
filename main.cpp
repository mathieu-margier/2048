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

    // TODO Test, enlever dès que plus nécessaire
    /*for (int i = 2; i < 4; i++)
    {
        for (int j = 2; j < 4; j++)
        {
            int n = (i-1)*4 + j + 1;
            grille.Set(i, j, static_cast<int>(pow(2, n)));
        }
    }*/


    /*grille.Set(0,0,2);
    grille.Set(0,1,2);
    grille.SommeAdjGauche(0,1);
    grille.Set(1,0,4);
    grille.SommeAdjHaut(1,0);*/

    try {
        grille.AjoutNombreAlea();
        grille.Print();
        grille.AjoutNombreAlea();
        grille.Print();
        grille.AjoutNombreAlea();
        grille.Print();
    } catch (string chaine) {
        cout<<chaine<<endl;
    }



    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("grilleItem", &grilleItem);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
