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
int dp[1000005];
int f(vector<int>& coin,int x){
    if(x==0) return 0;
    if(dp[x]!=-1) return dp[x];
    int mn = INT_MAX;
    for(int i=0;i<coin.size();i++){
        if(x-coin[i]<0) continue;
        mn = min(mn,f(coin,x-coin[i]));
    }
    //cout<<mn;
     return dp[x]= (mn==INT_MAX?mn:1+mn);
}
int main(){
    int n,x;
    cin>>n>>x;

    vector<int> coin;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        coin.push_back(x);
    }
    memset(dp,-1,sizeof dp);
    int ans =f(coin,x);
       cout<<(ans==INT_MAX?-1:ans);
}