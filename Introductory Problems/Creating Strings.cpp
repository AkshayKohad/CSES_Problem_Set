#include <bits/stdc++.h>
using namespace std;

void solve(int i,string &s,int &n,set<string>&st)
{
    if(i==n)
    {
        if(st.find(s)==st.end())
        {
        st.insert(s);
        }
        
        return;
    }
    
    for(int j=i;j<n;j++)
    {
        swap(s[i],s[j]);
        
        solve(i+1,s,n,st);
        
        swap(s[i],s[j]);
    }
}
int main()
{
    string s;
    cin>>s;
    
    int n = s.length();
    
    sort(s.begin(),s.end());
    set<string>st;
  
    
    solve(0,s,n,st);
    
    cout<<st.size()<<endl;
    
    for(auto k:st)
    {
        cout<<k<<endl;
    }
    
    
}
