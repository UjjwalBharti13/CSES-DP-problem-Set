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
class Solution {
public:
int dp[5005][5005];

    int minDistance(string word1, string word2) {
        memset(dp,0,sizeof dp);
        
        // base case
         for(int j=0;j<=word2.size();j++){
            int i=word1.size();
            dp[i][j] = word2.size()-j;
         }
           for(int i=0;i<=word1.size();i++){
            int j=word2.size();
            dp[i][j] = word1.size()-i;
         }
        for(int i=word1.size()-1;i>=0;i--){
            for(int j = word2.size()-1;j>=0;j--){
             if(word1[i]==word2[j])  dp[i][j] = dp[i+1][j+1];  
    else  dp[i][j]=min({1+dp[i+1][j+1],1+dp[i+1][j],1+dp[i][j+1]});

            }
        }
         return dp[0][0];
      
    }
};
int main(){
    string word1,word2;
    cin>>word1>>word2;
    Solution sol;
    cout<<sol.minDistance(word1,word2)<<"\n";
}