#include<iostream>
#include<vector>
using namespace std;
int part1(vector<int>&v,int l,int h)
{
    int x= v[h];
    int i=l-1;
    for(int j=l; j<=h; j++)
    {
        if(v[j]>x)
        {
            i+=1;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[h]);
    return i+1;

}
void QuickSort(vector<int>&v,int l,int h)
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
    cout<<"Enter how many numbers :"<<"\n";
    int a;
    cin>>a;
    vector<int>v(a);
    cout<<"Enter your numbers :"<<"\n";
    for(int i=0; i<a; i++)
    {
        cin>>v[i];
    }
    QuickSort(v,0,a-1);
    cout<<"Sorted numbers :"<<"\n";
    for(auto&c:v)
    {
        cout<<c<<"\n";
    }
}
