#include <bits/stdc++.h>
using namespace std;

void buildTable(string p, vector<int> &table){
	int m=p.length();
	int j=0, i=1; // pointing at pattern
	while(i<m){
		if(p[i]==p[j]){
			table[i]=j; // we got a prefix in string from [0,i] ending in j that is also a suffix ending in i
			i++, j++;
		}else{
			if(j>0){
				// we might have a substring to look into
				j=table[j-1]; // since we had faliure at idx j, we go to prefix for which (j-1) was suffix 
				j++; // char right after to see if we got a match
			}else{
				i++; // we keep moving forward to get match for 0th idx
			}
		}
	}
}

bool findpattern(string s, string p, vector<int> table){
	int n=s.length(), m=p.length();
	int i=0, j=0;
	while(i+m-j<=n){
		if(s[i]==p[j]){
			if(j==m-1) return true;
			i++, j++;
		}else{
			if(j>0){
				j=table[j-1];
				j++;
			}else{
				i++;
			}
		}
	}
	return false;
}

bool knuthMorrisPrattAlgorithm(string s, string p) {
  int n=s.length(), m=p.length();
	vector<int> table(m,-1); // previous idx where we found the matching substring till (j-i) as end of prefix
	buildTable(p,table);
  return findpattern(s,p,table);
}

