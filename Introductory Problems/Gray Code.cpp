#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int si = n;
    vector<int>a;
    
    a.push_back(0);
    a.push_back(1);
    
    n = n-1;
    int val = 2;
    
    
    while(n--)
    {
      for(int i=a.size()-1;i>=0;i--)
      {
          a.push_back(a[i]+val);
      }
      
      val = val*2;
    }
    
    for(int i=0;i<a.size();i++)
    {
        int val = a[i];
        vector<int>temp;
        while(val>0)
        {
            temp.push_back(val%2);
            val=val/2;
        }
        int sz = temp.size();
        
        int res_sz = si-sz;
        
        while(res_sz--)
        cout<<"0";
        
        for(int j=temp.size()-1;j>=0;j--)
        {
            cout<<temp[j];
        }
        cout<<endl;
    }
    //cout<<endl;
}
