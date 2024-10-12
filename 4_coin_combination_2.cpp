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
int dp[105][1000005];
int h(vec& coin, int x,int i){
   
   // base case 
   for(int i=0;i<coin.size();i++){
       dp[i][0]=1;
   }
    
     for(int i = coin.size()-1;i>=0;i--){
        for(int sum = 1; sum<=x;sum++){
            int skipping = dp[i+1][sum];
            int picking =0;
            if(coin[i]<=sum){
                picking = dp[i][sum-coin[i]];  
            }
            dp[i][sum] = (skipping + picking)%mod;
        }
     }
     return dp[0][x];
}
int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);

    int n,x;
    cin>>n>>x;
    vec coin;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        coin.push_back(x);
    }
    cout<<h(coin,x,0)<<"\n";
}