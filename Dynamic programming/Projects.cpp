#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define boost ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll solve(ll i,ll n,vector<vector<ll>>&projects,vector<ll>&memo){
    if(i==n)return 0;
    
    if(memo[i]!=-1)return memo[i];
    
    ll res = solve(i+1,n,projects,memo);
    
    ll l = i+1;
    ll r = n-1;
    ll index=-1;
    
    ll end_time = projects[i][1];
    
    while(l<=r)
    {
        ll mid = (r-l)/2+l;
        
        if(end_time>=projects[mid][0])
        l=mid+1;
        
        else
        {
          index = mid;    
          r = mid-1;
          
        }
    }
    
    if(index==-1)
    return memo[i] = max(res,projects[i][2]);
    
    ll res2 = solve(index,n,projects,memo);
    
    return memo[i] = max(res,projects[i][2]+res2);
}
int main(){
    ll n;
    cin>>n;
    
    vector<vector<ll>>project(n);
    
    for(ll i=0;i<n;i++){
        ll start,end,cost;
        cin>>start>>end>>cost;
        
        project[i] = {start,end,cost};
    }
    
    sort(project.begin(),project.end());
    
    vector<ll>memo(n,-1);
    cout<<solve(0,n,project,memo);
    
}
