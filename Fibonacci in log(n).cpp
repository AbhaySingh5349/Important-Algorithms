#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int fib(int n){
	long long int ans[2][2]={{1,0},{0,1}};
	long long int base[2][2]={{1,1},{1,0}};
	n-=1;
	while(n){
		if(n%2==0){
			long long int temp[2][2];
			temp[0][0]=((base[0][0]%mod*base[0][0]%mod)%mod + (base[0][1]%mod*base[1][0]%mod)%mod)%mod;
			temp[0][1]=((base[0][0]%mod*base[0][1]%mod)%mod + (base[0][1]%mod*base[1][1]%mod)%mod)%mod;
			temp[1][0]=((base[1][0]%mod*base[0][0]%mod)%mod + (base[1][1]%mod*base[1][0]%mod)%mod)%mod;
			temp[1][1]=((base[1][0]*base[0][1])%mod + (base[1][1]*base[1][1])%mod)%mod;
			for(int i=0;i<2;i++){
				for(int j=0;j<2;j++){
					base[i][j]=temp[i][j]%mod;
				}
			}
			n/=2;
		}else{
			long long int temp[2][2];
			temp[0][0]=((ans[0][0]%mod*base[0][0]%mod)%mod + (ans[0][1]%mod*base[1][0]%mod)%mod)%mod;
			temp[0][1]=((ans[0][0]%mod*base[0][1]%mod)%mod + (ans[0][1]%mod*base[1][1]%mod)%mod)%mod;
			temp[1][0]=((ans[1][0]%mod*base[0][0]%mod)%mod + (ans[1][1]%mod*base[1][0]%mod)%mod)%mod;
			temp[1][1]=((ans[1][0]%mod*base[0][1]%mod)%mod + (ans[1][1]%mod*base[1][1]%mod)%mod)%mod;
			for(int i=0;i<2;i++){
				for(int j=0;j<2;j++){
					ans[i][j]=temp[i][j]%mod;
				}
			}
			n--;
		}
	}
	return (ans[0][0])%mod;
}
    
int main()
{
	int n;
	cin>>n;
	cout<<fib(n);
	
	return 0;
}
