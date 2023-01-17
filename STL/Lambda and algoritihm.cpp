#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool ispositive(int x){
    return x>0;
}

int main(){
    vector<ll> v;
    
    int min=*min_element(v.begin(),v.end());
    int max=*max_element(v.begin(),v.end()); //gives iterator
    int sum=accumulate(v.begin(),v.end(),0); // Gives sum
    int ct=count(v.begin(),v.end(),6); //gives count
    int ele=*find(v.begin(),v.end(),2); //gives iterator
    reverse(v.begin(),v.end());
    string s="absdiwq";
    reverse(s.begin(),s.end()); //reverse without sorting , helps in reversing parts of vector

    //Lambda function 
    
    auto let=[](int x,int y){return x+y;};
    cout<<let(2,3);
    cout<<all_of(v.begin(),v.end(),[](int x){return x>0;}); //checks if all element have the condition if Y then 1 else 0
    cout<<all_of(v.begin(),v.end(),ispositive);
    cout<<any_of(v.begin(),v.end(),ispositive);  // if any element the 1 else 0
    cout<<none_of(v.begin(),v.end(),ispositive); //if none then 1 else 0

    return 0;
}
