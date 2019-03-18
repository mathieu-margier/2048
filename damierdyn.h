#ifndef DAMIERDYN_H
#define DAMIERDYN_H

#include <iostream>
using namespace std;

class DamierDyn
{
public:
    DamierDyn(int l, int c, int vd=9);
    DamierDyn(const DamierDyn &D);
    ~DamierDyn();

    DamierDyn& operator=  (const DamierDyn &D); // opérateur d'affectation
    DamierDyn& operator+= (const DamierDyn &D);
    DamierDyn& operator+= (int c);
    DamierDyn  operator+  (const DamierDyn &D);
    friend ostream& operator<< (ostream& sortie, DamierDyn& V);

    void Print();
    void Init(int value);
    void Set(int x, int y, int value);
    void ReDim(int l, int c, int vd = 0);

private:
    int L;
    int C;
    int** T;

    // Méthode privée (factorisation  de code)
    void Alloc(int l, int c);
    void Free();
    bool sameDimensions (const DamierDyn &D);
};

#endif // DAMIERDYN_H
