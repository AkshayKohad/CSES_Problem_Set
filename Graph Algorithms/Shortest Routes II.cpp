#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main(){
    ll n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>>FloydWarshall(n+1,vector<ll>(n+1,LLONG_MAX));
    
    for(ll i=1;i<=n;i++){
            FloydWarshall[i][i]=0;
    }
    for(ll i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        
        FloydWarshall[a][b] = min(FloydWarshall[a][b],c);
        FloydWarshall[b][a] = min(FloydWarshall[b][a],c);
        
    }
    
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                
                if(FloydWarshall[i][k]==LLONG_MAX || FloydWarshall[k][j]==LLONG_MAX)continue;
                
                FloydWarshall[i][j] = min(FloydWarshall[i][j],FloydWarshall[i][k]+FloydWarshall[k][j]);
            }
        }
    }
    while(q--){
        ll a,b;
        cin>>a>>b;
        
        if(FloydWarshall[a][b]==LLONG_MAX)
        FloydWarshall[a][b]=-1;
        
        cout<<FloydWarshall[a][b]<<"\n";
    }
    return 0;
    
}
