#include <bits/stdc++.h>
using namespace std;


vector<pair<int,int>>directions = {{0,1},{0,-1},{1,0},{-1,0}};
vector<char>dir_sym = {'R','L','D','U'};
int main(){
   
    int n,m;
    cin>>n>>m;
    
    vector<vector<char>>mat(n,vector<char>(m));
    
    pair<int,int>source;
    pair<int,int>dest;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
            
            if(mat[i][j]=='A'){
                source = {i,j};
            }
            if(mat[i][j]=='B'){
                dest = {i,j};
            }
        }
    }
    
    vector<vector<int>>visited(n,vector<int>(m,INT_MAX));
    vector<vector<char>>cell_dir(n,vector<char>(m,'X'));
    queue<pair<int,int>>q;
    q.push(source);
    
    visited[source.first][source.second]=0;
    while(q.empty()==false){
        
        pair<int,int>cur = q.front();
        q.pop();
        
        int x = cur.first;
        int y = cur.second;
        
        if(x==dest.first && y==dest.second)continue;
        
        for(int i=0;i<4;i++){
            int xf = x+directions[i].first;
            int yf = y+directions[i].second;
            
            if(xf<0 || yf<0 || xf>=n || yf>=m || mat[xf][yf]=='#' || visited[xf][yf] <= visited[x][y]+1){
                continue;
            }
            
            q.push({xf,yf});
            
            cell_dir[xf][yf] = dir_sym[i];
            visited[xf][yf] = visited[x][y]+1;
        }
    }
    
    if(cell_dir[dest.first][dest.second]=='X'){
        cout<<"NO\n";
    }
    
    else{
        cout<<"YES\n";
        cout<<visited[dest.first][dest.second]<<"\n";
        
        string res_dir;
        
        int i = dest.first;
        int j = dest.second;
        
        pair<int,int>cur = {i,j};
        
        while(cur!=source){
           // cout<<i<<" "<<j<<endl;
            if(cell_dir[i][j]=='U'){
                res_dir.push_back('U');
                i++;
            }
            else if(cell_dir[i][j]=='D'){
                res_dir.push_back('D');
                i--;
            }
            else if(cell_dir[i][j]=='L'){
                res_dir.push_back('L');
                j++;
            }
            else if(cell_dir[i][j]=='R'){
                res_dir.push_back('R');
                j--;
            }
            cur = {i,j};
        }
        
        reverse(res_dir.begin(),res_dir.end());
        cout<<res_dir<<"\n";
    }
    
    
    
}
