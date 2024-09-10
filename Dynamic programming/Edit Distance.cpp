#include <bits/stdc++.h>
using namespace std;

int solve(int n,int m,string a, string b)
{
    if(n==0)
    return m;
    
    if(m==0)
    return n;
    
    if(a[n-1]==b[m-1])
    {
        return solve(n-1,m-1,a,b);
    }
    
    else{
        return 1+min({solve(n-1,m-1,a,b),solve(n-1,m,a,b),solve(n,m-1,a,b),solve(n,m-1,a,b),solve(n-1,m,a,b)});
    }
}
int main()
{
    
    
    string a,b;
    cin>>a>>b;
    
    int n = a.length();
    int m = b.length();
    
    //cout<<solve(n,m,a,b)<<"\n";
    
    int dp[n+1][m+1];
    
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=i;
    }
    for(int i=0;i<=m;i++)
    {
        dp[0][i]=i;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
            }
        }
    }
    
    cout<<dp[n][m]<<"\n";
}
