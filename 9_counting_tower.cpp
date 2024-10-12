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
ll dp[1000005][5];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
         // base cases
        dp[n][0] = 1;
        dp[n][1] = 1;
        for(int i=n-1;i>=0;i--){
            dp[i][0] = (2ll * dp[i+1][0] + dp[i+1][1])%mod;
            dp[i][1] = (4ll * dp[i+1][1] + dp[i+1][0])%mod;
        }
        
        // final subproblem
        cout<<(dp[1][0] + dp[1][1])%mod<<"\n";
    }

}