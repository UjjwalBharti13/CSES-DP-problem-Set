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
struct Job{
    ll start, finish, profit;
};
bool cmp(Job a, Job b){
     return a.finish<b.finish;
}
 ll BinarySearch(Job arr[], int i){
     ll lo=0;
     ll hi = i-1;
     while(lo<=hi){
        ll mid  = lo+(hi-lo)/2;
        if(arr[mid].finish<arr[i].start){
            if(arr[mid+1].finish<arr[i].start){
                lo = mid+1;
            }
            else return mid;
        }
        else  hi = mid-1;
     }
     return -1;
 }

int main(){
    ll n;
     cin>>n;
    
     struct Job arr[n];
     for(int i=0;i<n;i++){
        cin>>arr[i].start>>arr[i].finish>>arr[i].profit;
     }
     sort(arr,arr+n,cmp);
     vector<ll>dp(n,0);
        dp[0] = arr[0].profit;
       for(int i=1;i<n;i++){
          ll incl = arr[i].profit;
          ll idx = BinarySearch(arr,i);
          if(idx!=-1){
             incl += dp[idx];
          }
          ll excl = dp[i-1];
          dp[i] = max(incl,excl);
       }

       cout<<dp[n-1]<<"\n";
}