#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main()
{
    ll t;
    cin>>t;
    
    while(t--)
    {
        ll a,b;
        
        cin>>a>>b;
        
        ll mini = min(a,b);
        ll maxi = max(a,b);
        
        if(mini*2<maxi)
        {
            cout<<"NO"<<endl;
        }
        else{
            
            ll total = mini+maxi;
             
            if(total%3==0)
            {
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        
        
    }
}
