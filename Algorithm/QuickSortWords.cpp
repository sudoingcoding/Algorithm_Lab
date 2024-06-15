#include<iostream>
#include<vector>
using namespace std;
int part1(string&v,int l,int h)
{
    int x= v[h];
    int i=l-1;
    for(int j=l; j<=h; j++)
    {
        if(v[j]<x)
        {
            i+=1;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[h]);
    return i+1;

}
void QuickSort(string&v,int l,int h)
{
    if(l<h)
    {
        int r = part1(v,l,h);
        QuickSort(v,l,r-1);
        QuickSort(v,r+1,h);
    }
}
int main()
{

    cout<<"Enter your string:"<<"\n";
    string a;
    while(cin>>a)
    {
        QuickSort(a,0,a.size()-1);
        cout<<"Sorted string :"<<"\n";
        for(auto&c:a)
        {
            cout<<c<<"";
        }
        cout<<"\n";
        cout<<"Enter your string:"<<"\n";
    }
}
