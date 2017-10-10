#include <iostream>
# include<map>
using namespace std;

struct pereche{int val;
                   int index;};


void suma1(int a[],int n, int s)
{
    int i,j;
    for(i=0;i<=n-2;i++)
        for(j=i+1;j<=n-1;j++)
          if(a[i]+a[j]==s) {cout<<i<<" "<<j;
                            return;
                            }
cout<<"nu exista 2 numere in vector cu suma "<<s<<endl;
}


void quickSort2(pereche arr[], int left, int right) {
      int i = left, j = right;
      pereche tmp;
      int pivot = arr[(left + right) / 2].val;
      while (i <= j) {
            while (arr[i].val < pivot)
                  i++;
            while (arr[j].val > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
      if (left < j)
            quickSort2(arr, left, j);
      if (i < right)
            quickSort2(arr, i, right);
}

void suma2_var(int a[],int n,int s)
{
    pereche *vect;
    vect=new pereche[n+1];
    for(int i=0;i<n;i++)
               {vect[i].val=a[i];
               vect[i].index=i;}
   quickSort2(vect,0,n-1);
   int i,j;
    i=0;
    j=n-1;
    while(i<j)
        if(vect[i].val+vect[j].val==s) {cout<<vect[i].index<<" "<<vect[j].index;
                                        return;}
             else if(vect[i].val+vect[j].val<s) i++;
                 else j--;
   cout<<"nu exista 2 numere in vector cu suma "<<s<<endl;


}

void suma3(int a[],int n,int s)
{

//pair<int,int>h;
map<int,int>h;
for(int i=0;i<n;i++)
     h.insert({a[i],i});
for(int i=0;i<n;i++)
     if (h.find(s-a[i])!=h.end() && h.find(s-a[i])->second!=i) {cout<<i<<" "<<h[s-a[i]];
                     return;
                     }
 cout<<"nu exista in vector doua numere care sa dea suma "<<s<<endl;
}

int main()
{
     int n,s;
     cout<<"introduceti numarul de elemente ale vectorului: ";
     cin>>n;
     cout<<"introduceti elementele vectorului: "<<endl;
     int *a;
     a=new int[n+1];
     for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"introduceti s: ";
    cin>>s;
     suma1(a,n,s);
     cout<<endl;
     suma2_var(a,n,s);
     cout<<endl;
     suma3(a,n,s);

    return 0;
}
