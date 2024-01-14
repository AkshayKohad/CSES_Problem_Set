#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

   ll n;
   cin>>n;
   
   ll result_2 = 0;
   ll result_5 = 0;
   
   ll res_2 = 2;
   
   while(n>=res_2)
   {
       result_2 += n/res_2;
       
       res_2 = res_2*2;
   }
   
   ll res_5 = 5;
   
   while(n>=res_5)
   {
       result_5 += n/res_5;
       
       res_5 = res_5*5;
   }
   
   cout<<min(result_2,result_5);

	return 0;
}
