#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main()
{
    int n;
    cin>>n;
    
    
    vector<int>dp(n+1);
    
     dp[0] = 0;
     
    for(ll i=1;i<=n;i++)
    {
        int temp = i;
        dp[i] = INT_MAX;
        
        while(temp)
        {
            ll rem = temp%10;
            temp = temp/10;
            
            if(rem==0)
            {
                continue;
            }
            
            dp[i] = min(dp[i],1+dp[i-rem]);
        }
    }
    
    cout<<dp[n]<<"\n";
}
