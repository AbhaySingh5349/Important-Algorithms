#include <bits/stdc++.h>
using namespace std;

ll int power(ll int a, ll int b, ll int mod){
        if(b==0) return 1;
        if(b%2==0) return power((a*a)%mod,b/2,mod);
	return (a*power(a,b-1,mod))%mod;
}

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
