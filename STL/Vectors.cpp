#include<bits/stdc++.h>
using namespace std;
#define ll long long

//printing vector
void printvector(vector<int> &v){
    cout<<"size :"<<v.size()<<endl;  //time complexity O(1)
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}

//printing vector of pair
void printvector(vector<pair<int , int> > &v3){
    cout<<"size :"<<v3.size()<<endl;  //time complexity O(1)
    for(int i=0;i<v3.size();i++){
        cout<<v3[i].first<<" "<<v3[i].second<<endl;
    }cout<<endl;
}

int main(){

    //declaration(vectors are of dynamic size so no need to size declaration )
    vector<int> v;
    vector<string> s;
    vector<int> v(10); // 0 vector of size 10(still dynamic size)
    vector<int> v(10,3); // 3 vector(every element 3 prefilled) of size 10
    
    //insertion 
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        printvector(v); // shows the dynamic property of the vector
        v.push_back(x); 
    }
    printvector(v);

    //Functions
    v.push_back(7); // appends the element at the end of vector
    v.pop_back(); // removes the last element of the vector
    vector<int> v2=v; // creates a copy of v by value not by address
    vector<int> &v2=v; // copies the actual vector by address
    vector<int> v2=v; //time complexity O{n}
    // try to pass the actual vector in function by reference so that O{n} time complexity is reduced to O{1}
    
    //Vector of Pairs
    vector<pair<int , int> > v3;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v3.push_back({x,y});
    }

    //Array of vectors
    vector<int> v[10]; //denotes 10 vectors of size 0
    int N;
    cin>>N;
    vector<int>v4[N]; //declaration of N vectors user defined
    for(int i=0;i<N;i++){ //input of N Arrays 
        int x;
        cin>>x;
        for(int i=0;i<x;i++){
            int a;
            cin>>a;
            v4[i].push_back(a);
        }
    }for(int i=0;i<N;i++){ //printing N vectors
        printvector(v4[i]);
    }
    cout<<v4[0][0]; //kind of 2D array with fixed rows but variable column

    //Vectors of vectors
    int N;
    cin>>N;
    vector<vector<int>>v5; 
    for(int i=0;i<N;i++){ //input of N Vectors 
        int x;
        cin>>x;
        vector<int> temp; //we using temp bcz we cannot pushback into a non-existent vector
        for(int i=0;i<x;i++){
            int a;
            cin>>a;
            temp.push_back(a);
        }v5.push_back(temp);
    }for(int i=0;i<v.size();i++){ //printing N vectors
        printvector(v5[i]);
    }
    cout<<v5[0][0]; //kind of 2D array with variable rows and column    

    return 0;
}
