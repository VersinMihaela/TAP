#include <iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");

struct activitate
{
    int durata;
    int termen;
    int indice;

};

int compare(const void* a, const void* b)
{

    activitate* A=(activitate*)a;
    activitate* B=(activitate*)b;
    if(A->termen<B->termen) return -1;
    if(A->termen==B->termen) return 0;
    if(A->termen>B->termen) return 1;

}

int main()
{
    int nr;
    f>>nr;
    activitate *vect;
    vect=new activitate[nr+1];
    for(int i=0;i<nr;i++)
       {f>>vect[i].durata>>vect[i].termen;
        vect[i].indice=i+1;}

    qsort(vect,nr,sizeof(activitate),compare);


    int intarziere=0;
    int ultim=0;
    for(int i=0;i<nr;i++)
    {   int intarziere1=ultim+vect[i].durata-vect[i].termen;
        g<<"activitatea "<<vect[i].indice<<": intervalul "<<ultim<<" "<<ultim+vect[i].durata<<" intarziere "<<intarziere1<<endl;
        if(intarziere1>intarziere) intarziere=intarziere1;
        ultim=ultim+vect[i].durata;
    }

    g<<"Intarziere planificare: "<<intarziere<<endl;

    delete[] vect;
    f.close();
    g.close();


    return 0;
}