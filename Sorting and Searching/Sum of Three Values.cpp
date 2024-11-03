#include <bits/stdc++.h>
using namespace std;

vector<int>find_3sum(vector<pair<int,int>>&nums,int &n,int &limit){
    
    for(int i=0;i<n;i++){
        int j=i+1;
        int k=n-1;
        int rem_limit = limit - nums[i].first;
        
        while(j<k){
            int temp = nums[j].first + nums[k].first;
            
            if(temp == rem_limit) return {nums[i].second,nums[j].second,nums[k].second};
            
            if(temp > rem_limit){
                k--;
            }else{
                j++;
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
    
    
    if(n<3){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    sort(nums.begin(),nums.end());
    vector<int>res = find_3sum(nums,n,x);
    
    if(res.size()==0){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    
    sort(res.begin(),res.end());
    cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<"\n";
    
    return 0;
}
