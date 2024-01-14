#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    string s;
    cin>>s;
    
    int n = s.length();
    
    vector<int>char_record(26,0);
    
    for(int i=0;i<n;i++)
    {
        char_record[s[i]-'A']++;
    }
    
    bool is_even = false;
    
    if(n%2==0)
    is_even=true;
    
    int odd_cnt = 0;
    
    for(int i=0;i<26;i++)
    {
        if(char_record[i]%2==1)
        {
            odd_cnt++;
        }
    }
    
    vector<char>result(n);
    if(odd_cnt>1)
    {
        cout<<"NO SOLUTION"<<endl;
    }
    else if(odd_cnt==1)
    {
        if(is_even)
        {
            cout<<"NO SOLUTION"<<endl;
        }
        else{
            
            int i=0;
            
            for(int j=0;j<26;j++)
            {
                if(char_record[j]%2==0)
                {
                    while(char_record[j]>0)
                    {
                        result[i]=j+'A';
                        result[n-1-i]=j+'A';
                        
                        i++;
                        char_record[j]=char_record[j]-2;
                    }
                }
                else{
                    result[n/2] = j+'A';
                    char_record[j]=char_record[j]-1;
                    while(char_record[j]>0)
                    {
                        result[i]=j+'A';
                        result[n-1-i]=j+'A';
                        
                        i++;
                        char_record[j]=char_record[j]-2;
                    }
                    
                }
                
            }
            
        }
    }
    
    else{
        int i=0;
            
            for(int j=0;j<26;j++)
            {
                if(char_record[j]%2==0)
                {
                    while(char_record[j]>0)
                    {
                        result[i]=j+'A';
                        result[n-1-i]=j+'A';
                        
                        i++;
                        char_record[j]=char_record[j]-2;
                    }
                }
                else{
                    result[n/2] = j+'A';
                    char_record[j]=char_record[j]-1;
                    while(char_record[j]>0)
                    {
                        result[i]=j+'A';
                        result[n-1-i]=j+'A';
                        
                        i++;
                        char_record[j]=char_record[j]-2;
                    }
                    
                }
                
            }
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<result[i];
    }
    cout<<endl;
}
