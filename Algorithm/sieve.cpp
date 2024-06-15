#include <iostream>
#include <vector>
#define n 1000
using namespace std;

vector<bool> isPrime(n + 1, true);
vector<int> PrimeList;

void sieve()
{
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            PrimeList.push_back(i);
            cout << i << " ";
        }
    }
    cout << "\n";
}

vector<int> factorize(int k)
{
    vector<int> ans;
    for (int i = 0; i < PrimeList.size() && PrimeList[i] * PrimeList[i] <= k; i++)
    {
        while (k % PrimeList[i] == 0)
        {
            ans.push_back(PrimeList[i]);
            k /= PrimeList[i];
        }
    }
    if (k > 1)
        ans.push_back(k);
    cout<<"Prime Factorization of "<<k<<": \n";
    for (auto &c : ans)
    {
        cout << c << " ";
    }
    cout << "\n";
    return ans;
}

int gcd(int a, int b)
{
    int ans = 1;

    vector<int> aL = factorize(a);
    vector<int> bL = factorize(b);

    int i = 0, j = 0;

    while (i < aL.size() && j < bL.size())
    {
        if (aL[i] == bL[j])
        {
            ans *= aL[i];
            i++;
            j++;
        }
        else if (aL[i] < bL[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return ans;
}

int lcm(int a,int b)
{
     return (a * b) / gcd(a, b);
}
int main()
{
    sieve();
    cout<<"Enter Two Numbers:\n";
    int a,b;
    cin>>a>>b;
    cout<<"GCD:\n";
    cout<<gcd(a,b)<<"\n";
    cout<<"LCD:\n";
    cout<<lcm(a,b)<<"\n";

    return 0;
}

