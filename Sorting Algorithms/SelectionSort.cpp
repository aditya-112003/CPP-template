#include<bits/stdc++.h>
using namespace std;

int main (){
    int n,minindi;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }for(int i=0;i<n;i++){
        minindi=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minindi]){
                minindi=j;
            }
        }swap(arr[i],arr[minindi]);
    }for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
