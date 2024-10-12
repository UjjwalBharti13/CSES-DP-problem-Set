#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<climits>
#include<stack>
#include<queue>
#include<deque>
#include<unordered_set>
#include<set>
#include<map>
#include<list>
#include<unordered_map>
#include<iomanip>
#include <cstdint>
#define ll long long int
#define pq_min priority_queue<int,vector<int>,greater<int>>
#define pq_max priority_queue<int>
#define two_vec vector<vector<int>>
#define two_vecc vector<vector<char>>
#define st unordered_set<int>
#define mp unordered_map<int>
#define vec vector<int>
#define mod 1000000007
#define pp pair<int,int>
using namespace std;
int dp[1005][1005];
int f(two_vecc& path, int i, int j,int n){
     if(i>=n || j>=n || path[i][j]=='*') return 0;
    if(i==n-1 && j==n-1) return 1;
      if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=(f(path,i+1,j,n)%mod+f(path,i,j+1,n)%mod)%mod;
}
int main(){
    int n;
     cin>>n;
    
    two_vecc path(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          cin>>path[i][j];
        }
    }
    memset(dp,-1,sizeof dp);
    cout<<f(path,0,0,n);
}