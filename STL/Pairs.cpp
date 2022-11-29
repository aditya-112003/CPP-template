#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    //declaration
    pair<int,string> p;

    //insertion
    p=make_pair(2,"abc");
    p={2,"abc"};

    //making a copy by value and by address
    pair<int,string> p1=p;
    pair<int,string> &p1=p;

    //printing the pair
    cout<<p.first<<" "<<p.second<<endl;

    int a[]={1,2,3};
    int b[]={2,3,4};

    pair<int,int> p_array[3]; //pair array
    p_array[0]={1,2};
    p_array[1]={2,3};
    p_array[2]={3,4};
    swap(p_array[0],p_array[2]);
    for(int i=0;i<3;i++){    //priting the array
        cout<<p_array[i].first<<" "<<p_array.second<<endl;
    }
    return 0;
}
