#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&arr,int l,int mid,int r)
{
    int n1=mid-l+1;
    int n2=r-mid;
    vector<int>arr1(n1);
    vector<int>arr2(n2);
    for(int i=0; i<n1; i++)
    {
        arr1[i]=arr[l+i];
    }
    for(int j=0; j<n2; j++)
    {
        arr2[j]=arr[mid+1+j];
    }
    int i=0;
    int j=0;
    int k=l;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j])
        {
            arr[k]=arr1[i];
            i++;
            k++;

        }
        else
        {
            arr[k]=arr2[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=arr2[j];
        j++;
        k++;
    }
}


void merge_sort(vector<int>&arr,int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,mid,r);

    }

}
int main()
{
    int n;
    cout<<"Enter number of input size:"<<"\n";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    merge_sort(arr,0,n-1);

    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;




}
