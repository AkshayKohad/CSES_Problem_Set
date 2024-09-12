#include <bits/stdc++.h>
using namespace std;
 
 
#define boost ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod 1000000007
#define ll long long
 
ll solve(ll i, ll prev_val,vector<ll>&a,ll &n,ll &m)
{
      
    if(i==n)return 1;
    
    
    if(prev_val==-1)
    {
        if(a[i]==0)
        {
            ll res=0;
            for(ll j=1;j<=m;j++)
               res = (res+solve(i+1,j,a,n,m))%mod;
               
            
            return res;
        }
        else{
            return solve(i+1,a[i],a,n,m)%mod;
        }
    }
    else{
        if(a[i]==0)
        {
            ll res,res1=0,res2=0;
            res = solve(i+1,prev_val,a,n,m);
            
            if(prev_val-1>=1)
            res1 = solve(i+1,prev_val-1,a,n,m);
            
            if(prev_val+1<=m)
            res2 = solve(i+1,prev_val+1,a,n,m);
            
            return (res + (res1 + res2)%mod)%mod;
            
        }
        else{
            if(abs(prev_val-a[i])>1)return 0;
            
            else{
                return solve(i+1,a[i],a,n,m)%mod;
            }
        }
    }
}
int main()
{
    ll n,m;
    cin>>n>>m;
    
    vector<ll>a(n);
    
    for(ll i=0;i<n;i++)
    cin>>a[i];
    
    if(n==1)
    {
        if(a[0]==0)
        cout<<m;
        
        else
        cout<<"1\n";
        
        return 0;
    }
    
    
    //cout<<solve(0,-1,a,n,m);
    
    vector<vector<ll>>dp(n+1,vector<ll>(m+2,0));
    
   
    for(ll i=1;i<=m;i++)
      dp[n][i]=1;
    
    for(ll i=n-1;i>=1;i--)
    {
        
        for(ll j=1;j<=m;j++)
        {
             if(a[i]==0)
             {
                ll res,res1=0,res2=0;
                res = dp[i+1][j];
            
                
                res1 = dp[i+1][j-1];
            
               
                res2 = dp[i+1][j+1];
            
            dp[i][j] = (res + res1 + res2)%mod;
            
        }
        else{
            if(abs(j-a[i])>1)
            dp[i][j] = 0;
            
            else{
                dp[i][j] = dp[i+1][a[i]];
            }
          }
        }
        
    }
    
    ll ans = 0;
    if(a[0]==0)
    {
        for(ll i=1;i<=m;i++)
        {
            ans += dp[1][i];
            
            ans %= mod;
        }
        
    }
    else{
        ans = dp[1][a[0]];
    }
    
    cout<<ans<<"\n";
}



// SPACE OPTIMIZATION IN Linear Complexity

#include <bits/stdc++.h>
using namespace std;
 
 
#define boost ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod 1000000007
#define ll long long
 
ll solve(ll i, ll prev_val,vector<ll>&a,ll &n,ll &m)
{
    
    // if(prev_val<1 || prev_val>100)
    // return 0;
    
    if(i==n)return 1;
    
    
    if(prev_val==-1)
    {
        if(a[i]==0)
        {
            ll res=0;
            for(ll j=1;j<=m;j++)
               res = (res+solve(i+1,j,a,n,m))%mod;
               
            
            return res;
        }
        else{
            return solve(i+1,a[i],a,n,m)%mod;
        }
    }
    else{
        if(a[i]==0)
        {
            ll res,res1=0,res2=0;
            res = solve(i+1,prev_val,a,n,m);
            
            if(prev_val-1>=1)
            res1 = solve(i+1,prev_val-1,a,n,m);
            
            if(prev_val+1<=m)
            res2 = solve(i+1,prev_val+1,a,n,m);
            
            return (res + (res1 + res2)%mod)%mod;
            
        }
        else{
            if(abs(prev_val-a[i])>1)return 0;
            
            else{
                return solve(i+1,a[i],a,n,m)%mod;
            }
        }
    }
}
int main()
{
    ll n,m;
    cin>>n>>m;
    
    vector<ll>a(n);
    
    for(ll i=0;i<n;i++)
    cin>>a[i];
    
    if(n==1)
    {
        if(a[0]==0)
        cout<<m;
        
        else
        cout<<"1\n";
        
        return 0;
    }
    
    
    //cout<<solve(0,-1,a,n,m);
    
  
    vector<ll>prev(m+2,0);
    vector<ll>cur(m+2,0);
    
   
    for(ll i=1;i<=m;i++)
      prev[i]=1;
    
    for(ll i=n-1;i>=1;i--)
    {
        
        for(ll j=1;j<=m;j++)
        {
             if(a[i]==0)
             {
                ll res,res1=0,res2=0;
                res = prev[j];
            
                
                res1 = prev[j-1];
            
               
                res2 = prev[j+1];
            
            cur[j] = (res + res1 + res2)%mod;
            
        }
        else{
            if(abs(j-a[i])>1)
            cur[j] = 0;
            
            else{
                cur[j] = prev[a[i]];
            }
          }
        }
        
        prev = cur;
        
    }
    
    ll ans = 0;
    if(a[0]==0)
    {
        for(ll i=1;i<=m;i++)
        {
            ans += prev[i];
            
            ans %= mod;
        }
        
    }
    else{
        ans = prev[a[0]];
    }
    
    cout<<ans<<"\n";
}

