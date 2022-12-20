#include<bits/stdc++.h>
using namespace std;

void print (set<string> &s){
    cout<<s.size()<<endl;
    for(auto &i:s){     // O(n(log(n))) each iteration of log(n)
        cout<<i<<endl;
    }
}

int main(){
    
    // Declaration 

    set<string> s;
    s.insert("abc");  //log(n)
    s.insert("cde");
    s.insert("efg");
    s.insert("cde");

    // Functions

    auto it = s.find("abc"); //log(n)
    s.erase("cde");
    s.erase(it); //returns s.end() if no element is present 
    print(s);

    // unordered set 

    unordered_set<string> us; // all time complexities average is O(1);

    // multiset set

    multiset<string> ms; //log(n) operation
    auto it = ms.find("cde");
    ms.erase("cde"); // erases every occurence of cde
    ms.erase(it); // erases a single occurence available at that "it"  

    return 0;
}
