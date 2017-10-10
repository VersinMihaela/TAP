#include <iostream>
# include<map>
using namespace std;

struct pereche{int val;
                   int index;};

void suma1(int a[],int n,int s)
{
    int i,j,k;
    for(i=0;i<=n-3;i++)
        for(j=i+1;j<=n-2;j++)
           for(k=j+1;k<=n-1;k++)
               if(a[i]+a[j]+a[k]==s) {cout<<i<<" "<<j<<" "<<k;
                                      return;}
   cout<<"nu exista 3 numere in vector cu suma "<<s<<endl;
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
   int i,j,k;
   for(i=0;i<n-2;i++)
    {
    j=i+1;
    k=n-1;
    while(j<k)
        if(vect[i].val+vect[j].val+vect[k].val==s) { cout<<vect[i].index<<" "<<vect[j].index<<" "<<vect[k].index;
                                                    return;}
             else if(vect[i].val+vect[j].val+vect[k].val<s) j++;
                 else k--;

    }
   cout<<"nu exista 3 numere in vector cu suma "<<s<<endl;


}
void suma3(int a[],int n,int s)
{
map<int,int>h;
for(int i=0;i<n;i++)
     h.insert({a[i],i});
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if(i!=j) if (h.find(s-a[i]-a[j])!=h.end()&& h.find(s-a[i]-a[j])->second!=i && h.find(s-a[i]-a[j])->second!=j) {cout<<i<<" "<<j<<" "<<h[s-a[i]-a[j]];
                                                                                                                    return;
                                                                                                                    }
 cout<<"nu exista in vector doua numere care sa dea suma "<<s<<endl;
}

int main()
{
    int *a,n;
    cout<<"introduceti numarul de elemente ale vectorului ";
    cin>>n;
    a=new int[n+1];
    cout<<"introduceti elementele vectorului: "<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"introduceti valoarea sumei: ";
    int s;
    cin>>s;
    suma1(a,n,s);
    cout<<endl;
    suma2_var(a,n,s);
    cout<<endl;
    suma3(a,n,s);
    return 0;
}
