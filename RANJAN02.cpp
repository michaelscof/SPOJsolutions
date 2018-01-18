#include <bits/stdc++.h>
using namespace std;
int main() {
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		unsigned long long int ans;
		unsigned long long int dp[36];
		dp[0]=0;
		dp[1]=2;
		dp[2]=8;
		for(int i=3;i<=35;i++)
		{
			dp[i]=3*dp[i-1]+2;
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}
