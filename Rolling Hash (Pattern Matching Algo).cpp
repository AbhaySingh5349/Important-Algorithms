#include <bits/stdc++.h>
using namespace std;

// Rollong Hash 

#define lg long long
lg int power(lg int a, lg int b, lg int mod){
	lg int ans=1;
	while(b>0){
		if(b%2==0){
			a=(a*a)%mod;
			b/=2;
		}else{
			ans=(ans*a)%mod;
			b--;
		}
	}
	return ans;
}

bool RollingHashAlgorithm(string s, string p) {
  int base=26;
//	int mod1=(1<<29)-1, mod2=(1<<29)+1;
	int mod1=1e9+5, mod2=1e9+7;
	int n=s.length(), m=p.length();
	
	lg int patHash1=0, patHash2=0, strHash1=0, strHash2=0;
	for(int i=0;i<m;i++){
		patHash1=(patHash1*base+(p[i]-'a'))%mod1;
		patHash2=(patHash2*base+(p[i]-'a'))%mod2;
		
		strHash1=(strHash1*base+(s[i]-'a'))%mod1;
		strHash2=(strHash2*base+(s[i]-'a'))%mod2;
	}
	
	lg int pow1=power(base,m,mod1), pow2=power(base,m,mod2);
	for(int i=m;i<n;i++){
		if(patHash1==strHash1 && patHash2==strHash2) return true;
		
		strHash1=((strHash1*base+(s[i]-'a'))%mod1 - ((s[i-m]-'a')*pow1)%mod1 + mod1)%mod1;
		strHash2=((strHash2*base+(s[i]-'a'))%mod2 - ((s[i-m]-'a')*pow2)%mod2 + mod2)%mod2;
	}
	if(patHash1==strHash1 && patHash2==strHash2) return true;
  return false;
}
