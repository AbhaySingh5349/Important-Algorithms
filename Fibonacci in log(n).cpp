#include <bits/stdc++.h>
using namespace std;

long long int fib(int n){
	long long int ans[2][2]={{1,0},{0,1}};
	long long int base[2][2]={{1,1},{1,0}};
	n-=1;
	while(n){
		if(n%2==0){
			long long int temp[2][2];
			temp[0][0]=base[0][0]*base[0][0] + base[0][1]*base[1][0];
			temp[0][1]=base[0][0]*base[0][1] + base[0][1]*base[1][1];
			temp[1][0]=base[1][0]*base[0][0] + base[1][1]*base[1][0];
			temp[1][1]=base[1][0]*base[0][1] + base[1][1]*base[1][1];
			for(int i=0;i<2;i++){
				for(int j=0;j<2;j++){
					base[i][j]=temp[i][j];
				}
			}
			n/=2;
		}else{
			long long int temp[2][2];
			temp[0][0]=ans[0][0]*base[0][0] + ans[0][1]*base[1][0];
			temp[0][1]=ans[0][0]*base[0][1] + ans[0][1]*base[1][1];
			temp[1][0]=ans[1][0]*base[0][0] + ans[1][1]*base[1][0];
			temp[1][1]=ans[1][0]*base[0][1] + ans[1][1]*base[1][1];
			for(int i=0;i<2;i++){
				for(int j=0;j<2;j++){
					ans[i][j]=temp[i][j];
				}
			}
			n--;
		}
	}
	return ans[0][0];
}
    
signed main()
{
	int n;
	cin>>n;
	cout<<fib(n);
	
	return 0;
}

