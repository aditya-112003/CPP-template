#define ll long long
const int N=1e3+10;
int arr[N][N];
ll pf[N][N];

//making the prefix array from the given array

for(int i=1;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>arr[i][j];
        pf[i][j]=arr[i][j]+pf[i-1][j]+pf[i][j-1]-pf[i-1][j-1];
    }
}

//eg. to implement the sum until given a,b to c,d

cout<<pf[c][d]-pf[c][b-1]-pf[a-1][d]+pf[a-1][b-1];
