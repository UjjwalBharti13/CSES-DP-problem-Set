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
    int n;
    cin>>n;
    vec arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> ans;
    ans.push_back(arr[0]);
       for(int i=1;i<n;i++){
        auto it = lower_bound(ans.begin(),ans.end(),arr[i]);
        if(arr[i]>ans.back()) ans.push_back(arr[i]);
        else {
            *it = arr[i];
        }
       }
      cout<<ans.size()<<"\n";
}