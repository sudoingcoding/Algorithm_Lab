#include<bits/stdc++.h>
using namespace std;

bool coinCng(vector<int>&v,float am)
{
    vector<int>l;
    sort(v.rbegin(),v.rend());
    //for(auto&c:v){cout<<c<<"\n";}
    int i=0;
    for(int i=0; i<v.size(); i++)
    {
        while (am >= v[i]) {
            am -= v[i];
            l.push_back(v[i]);
            if(am<1 && am>0 ) return false;
        }
    }

    for(auto&c:l){cout<<c<<"\n";}
    return true;

}

int main()
{
    int num;
    cout<<"Enter Number of coins:"<<"\n";
    cin>>num;
    vector<int>v(num);
    cout<<"Enter coin list:"<<"\n";
    for(int i=0; i<num; i++)
    {
        cin>>v[i];
    }
    int am;
    cout<<"Enter amount:"<<"\n";
    cin>>am;
    (coinCng(v,am))?"Yes":"No";
}
