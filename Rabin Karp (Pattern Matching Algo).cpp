#include <bits/stdc++.h>
using namespace std;

// Rabin Karp ALgo

bool matches(map<char,int> sm, map<char,int> pm, string s, string p, int idx){
	int m=p.length();
	map<char,int> :: iterator it;
	for(it=sm.begin();it!=sm.end();it++){
		char ch=it->first;
		if(pm.find(ch)==pm.end()) return false;
		if(pm[ch]!=sm[ch]) return false;
	}
	for(int i=idx-m,j=0;j<m;i++,j++){
		if(s[i]!=p[j]) return false;
	}
	return true;
}

bool RabinKarpAlgorithm(string s, string p) {
	int n=s.length(), m=p.length();
  	map<char,int> sm, pm;
	int i=0;
	while(i<m){
		char ch1=s[i], ch2=p[i];
		sm[ch1]++, pm[ch2]++;
		i++;
	}
	vector<pair<int,int>> idx; // storing start and ending index of pattern
	while(i<n){
		if(matches(sm,pm,s,p,i)){
		//	idx.push_back({i-m,i});
			return true;
		}
		char ch1=s[i-m];
		sm[ch1]--;
		if(sm[ch1]==0) sm.erase(ch1);
		
		char ch2=s[i];
		sm[ch2]++;
		i++;
	}
	if(matches(sm,pm,s,p,i)){
	//	idx.push_back({i-m,i});
		return true;
	}
  return false;
}

