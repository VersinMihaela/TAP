#include <iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
ifstream f("acoperire.in");
ofstream g("acoperire.out");

struct interval
{
    int inc;
    int sf;
};

int compare(const void* a, const void* b)
{

    interval* A=(interval*)a;
    interval* B=(interval*)b;
    if(A->inc<B->inc) return -1;
    if(A->inc==B->inc) if(A->sf<=B->sf) return -1;
                            else return 1;
    if(A->inc>B->inc) return 1;

}

int main()
{
    interval a;
    int nr;
    interval *vect;
    f>>a.inc>>a.sf;
    f>>nr;
    vect=new interval[nr+1];
    int dim=-1;
    ///verific de la citire daca exista intervale care includ partial sau total intervalul a
    ///cele care nu se intersecteaza cu [a,b] nu le memorez
        for(int i=0;i<nr;i++)
        {    int x,y;
            f>>x>>y;
            if(y>=a.inc && x<=a.sf) {dim++;
                                   vect[dim].inc=x;
                                   vect[dim].sf=y;
                                    }
        }

    if(dim==-1) {g<<-1;
                 delete[] vect;
                 f.close();
                 g.close();
                 return 0;
                 }
           else dim++;
     ///ordonez intervalele crescator dupa capatul de inceput
    qsort(vect,dim,sizeof(interval),compare);

    interval *vect_nou;
    vect_nou=new interval[dim+1];
    int k=-1;
    interval ultim;

    for(int i=0;i<dim;i++)
    {   ///daca gasesc un interval care include total intervalul a ma opresc si il afisez
        if(vect[i].inc<=a.inc && vect[i].sf>=a.sf) { //g<<1;
                                                    g<<vect[i].inc<<" "<<vect[i].sf;
                                                    delete[] vect;
                                                    delete[] vect_nou;
                                                    f.close();
                                                    g.close();
                                                    return 0;
                                                    }
        if(k==-1) { if(vect[i].inc<=a.inc && vect[i].sf>=a.inc) {k++;
                                                               vect_nou[k]=vect[i];
                                                               ultim=vect[i];}
                  }
            else {   if(vect[i].inc>ultim.inc  &&  vect[i].sf>ultim.sf && vect[i].inc<=a.inc) {vect_nou[k]=vect[i];
                                                                                               ultim=vect[i];}
                    if(vect[i].inc>ultim.inc && vect[i].inc<=vect_nou[k-1].sf && k>=1 && vect[i].sf>ultim.sf){
                                                                                             vect_nou[k]=vect[i];
                                                                                             ultim=vect[i];}

                      else if(vect[i].inc<=ultim.sf && vect[i].sf>ultim.sf)
                                                                            {k++;
                                                                             vect_nou[k]=vect[i];
                                                                             ultim=vect[i];}
            }
       if(ultim.sf>=a.sf) break;
    }

    ///verific daca am putut crea o submultime de intervale care sa includa [a,b]
    if(k==-1) {g<<-1;
               delete[] vect;
               delete[] vect_nou;
               f.close();
               g.close();
               return 0;
               }
    ///verific daca submultimea creata include total intervalul [a,b]
    if(ultim.sf<a.sf)  {g<<-1;
                        delete[] vect;
                        delete[] vect_nou;
                        f.close();
                        g.close();
                        return 0;}
           else {//g<<k+1;
                 for(int i=0;i<=k;i++)
                    g<<vect_nou[i].inc<<" "<<vect_nou[i].sf<<endl;
                }


    delete[] vect;
    delete[] vect_nou;
    f.close();
    g.close();

    return 0;
}