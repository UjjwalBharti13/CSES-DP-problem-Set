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
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
using namespace std;
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
 
void generate_next_masks(int current_mask, int i, int next_mask, int n, 
                            vector<int>& next_masks){
      if(i == n + 1){
        next_masks.push_back(next_mask);
        return;
      }
      
      if((current_mask & (1 << i)) != 0)
          generate_next_masks(current_mask, i + 1, next_mask, n, next_masks);
      
      if(i != n)
        if((current_mask & (1 << i)) == 0 && (current_mask & (1 << (i+1))) == 0)
          generate_next_masks(current_mask, i + 2, next_mask, n, next_masks);      
      
      if((current_mask & (1 << i)) == 0)
          generate_next_masks
                (current_mask, i + 1, next_mask + (1 << i), n, next_masks);    
}
 
int dp[1001][1<<11];
int solve(int col, int mask, const int m, const int n){
    // BASE CASE
    if(col == m + 1){
        if(mask == 0)
          return 1;
        return 0;
    }
 
    if(dp[col][mask] != -1)
      return dp[col][mask];
 
    int answer = 0;
    vector<int> next_masks;
    generate_next_masks(mask, 1, 0, n, next_masks);
 
    for(int next_mask: next_masks){
        answer = (answer + solve(col + 1, next_mask, m, n)) % mod;
    }
 
    return dp[col][mask] = answer;
}
 
int main() {
   init_code();
   int t = 1; //cin >> t;
   while(t--){
        read(n); read(m);
        memset(dp, -1, sizeof dp);
        cout << solve(1, 0, m, n); 
   }
}
