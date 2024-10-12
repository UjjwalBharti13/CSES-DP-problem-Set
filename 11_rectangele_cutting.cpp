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
    int n,m;
    cin>>n>>m;
 
   vector<vector<int>>dp(n+1,vector<int>(m+1, 1e9));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==j){
                    dp[i][j]=0;
                    continue;
                }
                // handle for vertical case
             for(int v=1;v<=i-1;v++){
                dp[i][j] = min(dp[i][j],dp[v][j]+dp[i-v][j]+1);
             }
             // handle for horizontal case 
               for(int h=1;h<=j-1;h++){
                dp[i][j] = min(dp[i][j],dp[i][h]+dp[i][j-h]+1);
             }

            }
        }
        cout<<dp[n][m]<<"\n";
}