#include <bits/stdc++.h>
using namespace std;

vector<int>find_4sum(vector<pair<int,int>>&nums,int &n,int &limit){
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int k=j+1;
            int l=n-1;
            int rem_limit = limit - nums[i].first-nums[j].first;
            
            while(k<l){
                int temp = nums[k].first + nums[l].first;
                
                if(temp == rem_limit) return {nums[i].second,nums[j].second,nums[k].second,nums[l].second};
                
                if(temp > rem_limit){
                    l--;
                }else{
                    k++;
                }
            }
        }
    }
    
    return {};
}
int main(){
    int n,x;
    cin>>n>>x;
    

    vector<pair<int,int>>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i].first;
        nums[i].second = i+1;
    }
    
    
    if(n<4){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    sort(nums.begin(),nums.end());
    vector<int>res = find_4sum(nums,n,x);
    
    if(res.size()==0){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    
    sort(res.begin(),res.end());
    cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<" "<<res[3]<<"\n";
    
    return 0;
}
