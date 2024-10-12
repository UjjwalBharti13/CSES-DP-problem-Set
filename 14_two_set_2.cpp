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
const long long mod_inverse_2 = 500000004;
using namespace std;
int main(){
       int n;
    cin>>n;
    if((n*(n+1))%4!=0){
        cout<<0<<"\n";
        return 0;
    }
    int maxSum = (n * (n + 1)) / 4;
    
    vector<vector<ll>> dp(n + 1, vector<ll>(maxSum + 1, false));
    // dp[i][j] = number of ways to generate a sum of j with subsets
    // from first i numbers
    
    // base case, if there are no elements, only 0 can be generated
    // such that we don't pick any element    
    dp[0][0] = 1;
    
    for(int i = 1; i <= n; i++){
        int val = i;
        for(int j = 0; j <= maxSum; j++){
            // find dp[i][j] here
            dp[i][j] = dp[i - 1][j];
            if(j - val >= 0){
                dp[i][j] = (dp[i][j] + dp[i - 1][j - val])%mod;
            }
        }
    }
    cout<<((dp[n][maxSum]*mod_inverse_2)%mod)<<"\n";
}
