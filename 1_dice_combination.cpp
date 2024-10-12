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
ll dp[1000005];
ll f(int n){
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];
    int sum=0;
    for(int i=1;i<=6;i++){
           if(n-i<0) break;
           sum = (sum%mod + f(n-i)%mod)%mod;
    }
     return dp[n]=sum%mod;
}
int main(){
  int n;
  cin>>n;
   memset(dp,-1, sizeof dp);
   cout<<f(n)<<"\n";
}