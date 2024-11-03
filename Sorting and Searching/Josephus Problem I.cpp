#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n, k = 2; // You can change k to any step you want
    cin >> n;
 
    // Initialize a list with people numbered from 1 to n
    list<int> circle;
    for(int i = 1; i <= n; i++) {
        circle.push_back(i);
    }
 
    // Iterator to track the current position
    auto it = circle.begin();
 
    // Continue until all people are eliminated
    while(!circle.empty()){
        // Move (k-1) steps ahead in the circle
        for(int i = 1; i < k; i++){
            if(it == circle.end()) it = circle.begin();
            it++;
            if(it == circle.end()) it = circle.begin();
        }
 
        // Eliminate the current person and print their number
        cout << *it << " ";
        it = circle.erase(it); // Remove the person from the circle
 
        // If the iterator reaches the end, wrap it around to the beginning
        if(it == circle.end() && !circle.empty()) {
            it = circle.begin();
        }
    }
    cout << endl;
}
