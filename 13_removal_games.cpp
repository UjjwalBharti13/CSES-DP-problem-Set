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
int main(){
    int n;
    cin>>n;
    vec game(n);
    for(int i=0;i<n;i++){
        cin>>game[i];
    }
    ll dp[5005][5005];
    memset(dp,0, sizeof dp);

      for(int len=1;len<=n;len++){
         for(int i=0;i+len<=n;i++){
            int j = i+len-1;
            ll x,y,z;
            x = (i+2<=j)?dp[i+2][j]:0;
            y = (i+1<=j-1)?dp[i+1][j-1]:0;
            z = (i<=j-2)?dp[i][j-2]:0;

            dp[i][j] = max(game[i]+min(x,y),game[j]+min(y,z));
         }
      }
      cout<<dp[0][n-1]<<"\n";

}