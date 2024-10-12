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
int dp[1005][100005];
int f(vec& book, vec& page, int x,int n){
   

   for(int i=1;i<=n;i++){
    for(int j=1;j<=x;j++){
        if(book[i-1]>j)  dp[i][j]=dp[i-1][j];
        else dp[i][j]= max(page[i-1]+dp[i-1][j-book[i-1]],dp[i-1][j]);
    }
   }
     
    return dp[n][x];
     
}
int main(){
    int n ,x;
    cin>>n>>x;

    vec book;
    vec page;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        book.push_back(x);
    }
    for(int i=0;i<n;i++){
        int y;
        cin>>y;
        page.push_back(y);
    }
    memset(dp,0,sizeof dp);
     cout<<f(book,page,x,n)<<"\n";

}