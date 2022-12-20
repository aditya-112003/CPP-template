#include<bits/stdc++.h>
using namespace std;

void print (map<int,string> &m){
    cout<<m.size()<<endl;
    for(auto &i:m){     // O(n(log(n))) each iteration of log(n)
        cout<<i.first<<" "<<i.second<<endl;
    }
}

int main(){

    //Declaration of maps and insertion 

    map<int,string> m;
    m[1]="abc";      // time complexity is O(log(n))
    m[2]="cdc";
    m[3]="acd";
    m.insert({4,"afg"});
    m["abcd"]="abcd"; // s.size()*O(log(n)) s is the size of string to be inserted 
    m[5];            // time complexity is O(log(n)) with default value of empty string as string 
    
    // Funcions 

    auto it=m.find(4); //O(log(n))
    m.erase(3);        //O(log(n))
    m.erase(it);
    m.clear();

    // unordered maps 

    unordered_map<int,string> mo;
    mo[1]="abc";      // time complexity is O(1) average
    mo[2]="cdc";

    // multimaps
    multimap<int,int> mul;

    return 0;
}
