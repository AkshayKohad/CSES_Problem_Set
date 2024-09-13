#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

ll power(ll a,ll n){
    if(n==0)return 1;
    if(n==1)return a%mod;
    
    if(n%2==0){
        ll res = power(a,n/2);
        return (res*res)%mod;
    }else{
        ll res = power(a,(n-1)/2);
        
        return (res*res*a)%mod;
    }   
}


int main(){
    ll n;
    cin>>n;
    
    ll sum = 0;
    
    sum = n*(n+1);
    sum = sum/2;
    
    if(sum%2!=0){
        cout<<"0";
        return 0;
    }
    
    sum = sum/2;
    
   
 
   
  vector<ll>prev(sum+1,0);
  vector<ll>cur(sum+1,0);
   
  prev[0]=1;
   
  for(ll i=n;i>=1;i--) {
      for(ll j=0;j<=sum;j++)  {
          if(j==0) {
              cur[j]=1;
              continue;
          }
           
          ll res = 0;
           
          if(j-i>=0){
              res = prev[j-i];
          }
           
          cur[j] = (prev[j] + res)%mod;
      }
       
      prev = cur;
  }
   //fermat's little theorem to divide number in modulo
    cout<<(prev[sum]*power(2,mod-2))%mod<<"\n";
 }
