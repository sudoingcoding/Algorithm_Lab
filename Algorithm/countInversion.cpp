#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int>&arr,int l,int mid,int r)
{
    int inv_count=0;
    int n1=mid-l+1;
    int n2=r-mid;
    int arr1[n1];
    int arr2[n2];
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
            inv_count +=(n1-i);
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
    return inv_count ;
}

int merge_sort(vector<int>&arr,int l,int r)
{
    int inv_count=0;
    if(l<r)
    {
        int mid=(l+r)/2;
        inv_count+=  merge_sort(arr,l,mid);
        inv_count+=merge_sort(arr,mid+1,r);
        inv_count+= merge(arr,l,mid,r);

    }
    return inv_count;
}
int main()
{
    int n;
    cout<<"Enter number of input size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int result=merge_sort(arr,0,n-1);


    cout << "Number of inversions are " << result;
    return 0;
}
