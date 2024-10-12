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
vec get_digit(int n){
    vec ans;
    while(n>0){
        if(n%10) ans.push_back(n%10);
        n/=10;
    }
     
    return ans;
}

int f(int n){
    if(n==0) return 0;
    if(n<=9) return 1;

    vec d = get_digit(n);
    int mn = INT_MAX;
     if(dp[n]!=-1) return dp[n];
    for(int i=0;i<d.size();i++){
        mn = min(mn,f(n-d[i]));
    }
    return dp[n]= 1+mn;

    
}

int main(){
    int n;
    cin>>n;
    
    memset(dp,-1,sizeof dp);
    cout<<f(n)<<"\n";

}