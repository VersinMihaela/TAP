#include <iostream>
#include<fstream>
#include<queue>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");

///cautare binara ca sa gasesc indicele cozii in care ar trebui inserat elementul de la pasul curent
int caut(int s, int d,queue<int> *coada,int x)
{

    if(s>d) return d+1;
      else
        {int m =(s+d)/2;
         if(m>0){
                  if(coada[m-1].back()<=x && x<=coada[m].back())
                         return m;
                   if (x<coada[m-1].back())
                         return caut(s,m-1,coada,x);
                      else
                         return caut(m+1,d,coada,x);
                }
            else if(x<=coada[0].back()) return 0;
                else if(!coada[1].empty()){ if(x<=coada[1].back()) return 1;
                                                  else return 2;}
                   else return 1;

        }
}

int main()
{

    int nr;
    int *sir;
    f>>nr;
    sir=new int[nr+1];
    for(int i=0;i<nr;i++)
        f>>sir[i];
    ///folosesc cozi ca sa memorez subsirurile
    queue<int>* coada;
    coada=new queue<int>[nr+1];
    coada[0].push(sir[0]);
    int dim=1;

    for(int i=1;i<nr;i++)
    {
       int aux=caut(0,dim-1,coada,sir[i]);
       if(aux==dim) {coada[dim].push(sir[i]);
                     dim++;
                     }
           else coada[aux].push(sir[i]);
    }

    int i=0;
    while(i<dim)
    {while(!coada[i].empty()) {g<<coada[i].front()<<" ";
                               coada[i].pop();}
    g<<endl;
    i++;
    }

    delete[] coada;
    delete[] sir;
    f.close();
    g.close();

    return 0;
}