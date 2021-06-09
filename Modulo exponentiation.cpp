#include <bits/stdc++.h>
using namespace std;

long long int power(long long int a, long long int b, int mod){
    long long int ans=1;
    while(b){
        if(b%2==0){
            a = (((a+mod)%mod)*((a+mod)%mod))%mod;
            b/=2;
        }else{
            ans = (((ans+mod)%mod)*((a+mod)%mod))%mod;
            b--;
        }
    }
    return ans;
}
    
int main()
{
	int x,n,mod;
	if(x==0) return 0;
    cout<<power(x,n,d);
    
	return 0;
}

