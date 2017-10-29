#include <iostream>
#include<fstream>
#include<stack>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");

//cautare binara ca sa gasesc indicele stivei in care ar trebui inserat elementul de la pasul curent
int caut(int s, int d,stack<int> *stiva,int x)
{

    if(s>d) return d+1;
      else
        {int m =(s+d)/2;
         if(m>0){
                  if(stiva[m-1].top()<x && x<stiva[m].top())
                         return m;
                   if (x<stiva[m-1].top())
                         return caut(s,m-1,stiva,x);
                      else
                         return caut(m+1,d,stiva,x);
                }
            else if(x<stiva[0].top()) return 0;
                else if(!stiva[1].empty()){ if(x<stiva[1].top()) return 1;
                                                  else return 2;}
                   else return 1;

        }
}


int main()
{

    int nr;
    int *sir;
    f>>nr;
    int val_maxima;
    sir=new int[nr+1];
    f>>sir[0];
    val_maxima=sir[0];
    for(int i=1;i<nr;i++)
        {f>>sir[i];
          if(sir[i]>val_maxima) val_maxima=sir[i];}


    stack<int> *stiva;
    stiva=new stack<int>[nr+1];
    stiva[0].push(sir[0]);
    int dim=1;

    //formez stivele, cu ajutorul cautarii binare caut stiva cu proprietatea ca vf ei este mai mare decat elementul de adaugat si vf stivei precedente este mai mic decat elementul de adaugat
     //daca cautarea binara nu a gasit o stiva care sa indeplineasca conditia, creez o noua stiva in care adaug elementul curent

    for(int i=1;i<nr;i++)
    {
       int aux=caut(0,dim-1,stiva,sir[i]);
       if(aux==dim) {stiva[dim].push(sir[i]);
                     dim++;
                     }
           else stiva[aux].push(sir[i]);
    }

    //pornesc din stanga si compar vf de stiva curent cu cel al stivei urmatoare
    //daca vf stivei curente este mai mic decat cel al stivei urmatoare il afisez si il elimin din stiva
    //altfel afisez vf stivei urmatoare si il elimin din stiva
    //daca am ramas doar cu o stiva nevida, afisez si elimin pe rand restul elementelor care au mai ramas
    //ma opresc cand toate stivele au ajuns sa fie vide

    int stg;
    stg=0;
    int ok=1;
    while(ok)
    {
        int dr=stg+1;
        while(stiva[dr].empty()&& dr<dim) dr++;
        if(!stiva[dr].empty()) if(stiva[stg].top()<stiva[dr].top()) {g<<stiva[stg].top()<<" ";
                                                                         stiva[stg].pop();}
                                                             else {g<<stiva[dr].top()<<" ";
                                                                    stiva[dr].pop();}
                  else {g<<stiva[stg].top()<<" ";
                       stiva[stg].pop();}
          if(stiva[stg].empty()) {stg++;
                                   if(stiva[stg].empty()) ok=0;}

    }



    delete[] stiva;
    delete[] sir;
    f.close();
    g.close();

    return 0;
}