#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    
    cin>>a;
    
    int n = a.length();
    
    int i=0;
    
    int result = 0;
    
    while(i<n)
    {
        int cnt = 0;
        
        int val = a[i];
        
        while(a[i]==val)
        {
            i++;
            cnt++;
        }
        
       result = max(result,cnt);    
    }
    
    
    cout<<result<<endl;
    
}
