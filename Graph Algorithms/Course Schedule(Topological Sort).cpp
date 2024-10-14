#include <bits/stdc++.h>
using namespace std;

#define boost ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    int n,m;
    cin>>n>>m;
    
    vector<int>adj[n+1];
    vector<int>indegree(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        
        adj[a].push_back(b);
        indegree[b]++;
    }
    
    queue<int>q;
    vector<int>result;
    for (int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    
    while (!q.empty()){
        int cur_nd = q.front();
        q.pop();
        result.push_back(cur_nd);
        
        for (auto u:adj[cur_nd]){
            indegree[u]--;
            if(indegree[u]==0){
                q.push(u);
            }  
        }
    }
    
    if (result.size()!=n){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    
    for (int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<"\n";
    
    
    
}
