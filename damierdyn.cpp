#include "damierdyn.h"
#include <string>
#include <sstream>

DamierDyn::DamierDyn(int l, int c, int vd)
{
    Alloc(l, c);
    Init(vd);
}

DamierDyn::DamierDyn(const DamierDyn &D)
{
    Alloc(D.L, D.C);

    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            T[i][j] = D.T[i][j];
}


DamierDyn::~DamierDyn(){
    if (T != NULL) {
        Free();
        T = NULL;
    }
}

void DamierDyn::Free(){
    for (int i=0; i<L; i++) {
        delete [] T[i];
    }
    delete [] T;
}

void DamierDyn::Alloc(int l, int c){
    L = l;
    C = c;
    T = new int*[L];
    for(int i=0; i<L; i++)
        T[i] = new int[C];
}

void DamierDyn::Print(){
    cout << endl;
    for(int i=0; i<L; i++) {
        cout << endl;
        for(int j=0; j<C; j++)
            cout << T[i][j] << " ";
    }
}

void DamierDyn::Init(int value){
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            T[i][j]=value;
}

void DamierDyn::Set(int i, int j, int value) {
    T[i][j]=value;
}

int DamierDyn::Get(int i, int j)
{
    if ((j < 0 || j >= C) || (i < 0 || i >= L))
    {
        std::ostringstream error;
        error << "Exception dans la fonction " << __PRETTY_FUNCTION__ << " :" << std::endl;
        error << "Index en dehors du tableau" << std::endl;
        error << "i : " << i << ", j : " << j << ", L : " << L << ", C : " << C;

        throw error.str();
    }

    return T[i][j];
}

int DamierDyn::GetLines()
{
    return L;
}

int DamierDyn::GetColumns()
{
    return C;
}

void DamierDyn::ReDim(int l, int c, int vd) {
    Free();
    Alloc(l, c);
    Init(vd);
}

DamierDyn& DamierDyn::operator= (const DamierDyn &D){
    if ( this != &D) { // protection autoréférence
        Free();
        Alloc(D.L, D.C);
        for(int i=0; i<L; i++)
            for(int j=0; j<C; j++)
                T[i][j] = D.T[i][j];
    }
    return *this;
}

bool DamierDyn::sameDimensions (const DamierDyn &D) {
    if ((L == D.L) && (C == D.C))
        return true;
    return false;
}

DamierDyn& DamierDyn::operator+= (int c)
{
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            T[i][j] += c;
    return *this;
}

DamierDyn& DamierDyn::operator+= (const DamierDyn &D)
{
    if (!sameDimensions(D)){
        cerr << endl << __PRETTY_FUNCTION__ << " - Dimensions différentes !\n";
        exit(1);
    }
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            T[i][j] += D.T[i][j];
    return *this;
}


DamierDyn DamierDyn::operator+ (const DamierDyn &D1)
{
    if (!sameDimensions(D1)){
        cerr << endl << __PRETTY_FUNCTION__ << " - Dimensions différentes !\n";
        exit(1);
    }

    DamierDyn D(D1.L, D1.C);
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            D.T[i][j] = T[i][j]+D1.T[i][j];

    return D;
}

ostream& operator<< (ostream& sortie, DamierDyn& V)
{
    for(int i=0; i<V.L; i++) {
        for(int j=0; j<V.C; j++)
            sortie << V.T[i][j] << " ";
        sortie << endl;
    }

    return sortie;
}
