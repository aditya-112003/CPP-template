#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    vector<ll> v(1);
    // Kadane's algorithm
    ll maxOfSubarray = 0, curr = 0;
    for (auto &i : v)
    {
        curr += i;
        maxOfSubarray = max(maxOfSubarray, curr);
        curr = max(curr, 0LL);
    }
}