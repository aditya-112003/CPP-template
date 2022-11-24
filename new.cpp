#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n,k,temp;       
    double sum = 0;
    double ans;
    cin>>n>>k;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr, arr + n);
    // for(ll i = 0; i < n; i++){
    //     cout << arr[i] << " ";
    // }
    for(int i=0;i<n;i++){
        if(i>k-1 && i < n-k){
            sum+=arr[i];
        }
    }
    ans=sum/(n-2*k);
    cout<<fixed<<setprecision(6)<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
