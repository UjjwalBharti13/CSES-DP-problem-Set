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

int dp[100005][105]; // Memoization table
int n, m;
vec a;
bool valid(int k, int m) {
    return k>=1 && k<=m;  // Check if 'k' is within valid range
}

// Recursive function
int f(int i, int k) {
    if (!valid(k,m)) return 0;  
    if (i==1) return (a[i-1]==0 || a[i-1]==k)? 1 : 0;  // Base case
    
    if (dp[i][k]!=-1) return dp[i][k]; 
    
    // Recursive case: calculate the sum of transitions
    dp[i][k] = 0;
    if (a[i-1]==0 || a[i-1]==k) {
        for (int prev=k-1; prev<=k+1;prev++) {
            if (valid(prev,m)) {
                dp[i][k] = (dp[i][k] + f(i-1,prev))%mod ;
            }
        }
    }
    return dp[i][k];
}

int main() {
    cin >> n >> m;
    a.resize(n);
    
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
     memset(dp, -1, sizeof dp);  // Initialize memoization table with -1
    
    int ans = 0;
    for (int k=1;k<= m;k++) {
        ans = (ans+f(n, k))%mod;  // Sum over all valid 'k' at the last index
    }
      cout<<ans<<endl;
}
