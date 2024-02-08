
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main()
{
  ll q;
  cin>>q;
  
  while(q--)
  {
    ll k;
    cin>>k;
    
    ll val = 9;
    ll digits = 1;
    
    while(k>val*digits)
    {
        k = k-val*digits;
        
        val = val*10;
        digits++;
    }
    
    ll res = k/digits;
    
    ll rem = k%digits;
    
    ll ans = 1;
    
    ll w = digits-1;
    
    while(w--)
    {
        ans = ans*10;
    }
    
    ans = ans-1;
    
    ans = ans+res;
    
    if(rem==0)
    {
        cout<<ans%10<<endl;
    }
    
    else{
        ans = ans+1;
        
        vector<int>num;
        while(ans!=0)
        {
            num.push_back(ans%10);
            ans = ans/10;
        }
        
        ll n = num.size();
        cout<<num[n-rem]<<endl;
    }
    
  }
}
