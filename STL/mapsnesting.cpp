#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    map<pair<int,int> , int > m; // pairs are stored in sorted order in maps    
    map<set<int>,int> m1;        // sets are similaraly stored in maps

    map<pair<string,string>,vector<int>> marks;
    ll n;
    cin>>n;
    while(n--){
        string a,b;
        cin>>a>>b;
        ll c;
        cin>>c;
        while(c--){
            ll x;
            cin>>x;
            marks[{a,b}].push_back(x);
        }
    }for(auto &t : marks){
        cout<<t.first.first<<" "<<t.first.second<<endl;
        for(auto &i:t.second){
            cout<<i<<" ";
        }cout<<endl;
    }
    return 0;
}
