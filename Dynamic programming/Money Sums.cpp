#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    int total_sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> coins[i];
        total_sum += coins[i];
    }
    vector<bool> dp(total_sum + 1, false);
    dp[0] = true;
    for(int i = 0; i < n; ++i) {
        int coin = coins[i];
        for(int s = total_sum; s >= coin; --s) {
            if(dp[s - coin]) {
                dp[s] = true;
            }
        }
    }
    vector<int> sums;
    for(int s = 1; s <= total_sum; ++s) {
        if(dp[s]) {
            sums.push_back(s);
        }
    }
    cout << sums.size() << endl;
    for(int s : sums) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
