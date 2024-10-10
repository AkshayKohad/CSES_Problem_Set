#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>>directions = {{0,1},{0,-1},{1,0},{-1,0}};
vector<char>dir_sym = {'R','L','D','U'};

int main(){
    int n,m;
    cin>>n>>m;
    
    vector<vector<char>>mat(n,vector<char>(m));
    
    vector<pair<int,int>>monsters;
    pair<int,int>source;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
            
            if(mat[i][j]=='M'){
                monsters.push_back({i,j});
            }
            else if(mat[i][j]=='A'){
                source = {i,j};
            }
        }
    }
    
    vector<vector<int>>visited(n,vector<int>(m,INT_MAX));
    vector<vector<char>>cell_dir(n,vector<char>(m,'X'));
    
    queue<vector<int>>q;
    
    
    
    for(auto k:monsters){
        q.push({k.first,k.second,1,1});
    }
    q.push({source.first,source.second,0,0});
    pair<int,int>dest;
    bool possible=false;
    while(q.empty()==false){
        
        vector<int>cur = q.front();
        q.pop();
        
        int x = cur[0];
        int y = cur[1];
        int status = cur[2];
        int val = cur[3];
        
        if((status==0)&&(x==n-1 || y==m-1 || x==0 || y==0)){
            dest = {x,y};
            visited[x][y] = val;
            possible=true;
            break;
        }
        
        for(int i=0;i<4;i++){
            int xf = x+directions[i].first;
            int yf = y+directions[i].second;
            
            if(xf<0 || yf<0 || xf>=n || yf>=m || mat[xf][yf]=='#')continue;
            
            if(status==1){
                if(visited[xf][yf]==1)continue;
                visited[xf][yf]=1;
                mat[xf][yf]='M';
                q.push({xf,yf,1,1});
            }else{
                if(mat[xf][yf]=='M' || visited[xf][yf]<=val+1)continue;
                
                q.push({xf,yf,0,val+1});
                visited[xf][yf] = val+1;
                cell_dir[xf][yf] = dir_sym[i];
            }
            
        }
    }
    
    if(!possible){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
        cout<<visited[dest.first][dest.second]<<"\n";
        
        int i = dest.first;
        int j = dest.second;
        
        pair<int,int>cur = {i,j};
        string res_dir;
        while(cur!=source){
          
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
