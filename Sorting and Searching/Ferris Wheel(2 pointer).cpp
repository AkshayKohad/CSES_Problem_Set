#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



ll solve()
{
	long long n, x;
	cin >> n >> x;
	vector<long long> v(n);
	for (long long i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end(),greater<long long>());
	long long no_of_gondolas = 0;
	long long second = n - 1;
	for (long long i = 0; i <= second; i++)
	{
		if ((v[i] + v[second]) <= x)
		{
			second--;
			no_of_gondolas++;
		}
		else
		{
			no_of_gondolas++;
		}
	}
	cout << no_of_gondolas << endl;
	return 0;
}

int main()
{
	long long testCase=1;
	while(testCase--){
		solve();
	}
	return 0;
}
