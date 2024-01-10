#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base :: sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;
    cin>>n;
    
    if(n==1)
    {
        cout<<n<<endl;
        return 0;
    }
    
    else if(n==2 || n==3)
    {
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
    
    
   if(n%2==0)
   {
       for(int i=2;i<=n;i=i+2)
       {
          cout<<i<<" ";    
       }
       
       for(int i=1;i<=n-1;i=i+2)
       {
           cout<<i<<" ";
       }
       
       cout<<endl;
       
   }
   else{
       for(int i=2;i<=n-1;i=i+2)
       {
          cout<<i<<" ";    
       }
       
       for(int i=1;i<=n;i=i+2)
       {
           cout<<i<<" ";
       }
       
       cout<<endl;
       
   }
   
}
