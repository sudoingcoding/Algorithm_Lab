#include<iostream>
#include<vector>
using namespace std;

int findFirstMissing(vector<int>&array,
                    int start, int end)
{
    if (start > end)
        return end + 1;

    if (start != array[start])
        return start;

    int mid = (start + end) / 2;

    if (array[mid] == mid)
        return findFirstMissing(array,
                            mid+1, end);

    return findFirstMissing(array, start, mid);
}

int main()
{
    vector<int>array = {1, 2, 3, 4, 5, 6, 7, 10};
    int n = array.size();
    cout << "Smallest missing element is " <<
        findFirstMissing(array, 0, n-1) << endl;
}

