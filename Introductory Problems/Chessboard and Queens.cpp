#include <bits/stdc++.h>
using namespace std;

bool check(int i,int j,vector<vector<int>>grid,vector<pair<int,int>>reserved)
{
    for(int k=0;k<reserved.size();k++)
    {
        if(reserved[k].first == i && reserved[k].second == j)
        return false;
    }
    
    for(int row = 0; row<i; row++)
    {
        if(grid[row][j]==1)
        return false;
    }
    
    for(int row=i-1,col=j-1; row>=0 && col>=0;row--,col--)
    {
        if(grid[row][col]==1)
        return false;
    }
    
    
    for(int row=i-1,col=j+1; row>=0 && col<8;row--,col++)
    {
        if(grid[row][col]==1)
        return false;
    }
    return true;
}

void solve(int i,vector<pair<int,int>>&reserved,vector<vector<int>>&grid,int &res)
{
   if(i==8)
   {
       res++;
       return;
   }
   
   for(int j=0;j<8;j++)
   {
       if(check(i,j,grid,reserved))
       {
           grid[i][j]=1;
           solve(i+1,reserved,grid,res);
           grid[i][j]=0;
       }
   }
}

int main()
{
    vector<pair<int,int>>reserved;
    
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            char ch;
            cin>>ch;
            
            if(ch=='*')
            {
              reserved.push_back({i,j});    
            }
        }
    }
    
    
    
    int res = 0;
    
    vector<vector<int>>grid(8,vector<int>(8,0));
    
    solve(0,reserved,grid,res);
    
    cout<<res<<endl;
}
