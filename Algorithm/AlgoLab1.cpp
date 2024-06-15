#include <iostream>
#include <vector>
using namespace std;

//time:O(y)
int pow(int x,int y)
{
    int r=1;
    for(int i=0; i<y; i++)
    {
        r*=x;
    }
    return r;
}

//time:O(y)
int pow1(int x,int y)
{
    if(y==0)
    {
        return 1;
    }
    else
    {
        return x*pow1(x,y-1);
    }
}

//time:O(Log(y))
int pow2(int x,int y)
{
    if(y==0)return 1;
    if(y%2==0) return pow2(x,y/2)*pow2(x,y/2);
    else return x*pow2(x,y/2)*pow2(x,y/2);
}

int binarySearch(vector<int>arr,int item,int l,int h)
{
    if(h>=l)
    {
        int mid=(int)l+(h-l)/2;
        if(arr[mid]==item) return mid;

        if(item<arr[mid])return binarySearch(arr,item,l,mid-1);
        else return binarySearch(arr,item,mid+1,h);
    }
    return -1;
}
int main()
{
    cout<<pow(5,12)<<"\n";
    cout<<pow1(5,12)<<"\n";
    cout<<pow2(5,12)<<"\n";
    vector<int>arr= {1,5,10,20,50,67,70,100,234};
    cout<<binarySearch(arr,234,0,8)<<"\n";
    cout<<binarySearch(arr,35,0,8)<<"\n";
}

