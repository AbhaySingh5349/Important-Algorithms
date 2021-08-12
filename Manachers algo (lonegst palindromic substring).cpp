#include <bits/stdc++.h>
using namespace std;
    
int main()
{
	string temp="@#";
        for(int i=0;i<s.length();i++){
            temp+=s[i];
            temp+="#";
        }
        temp+="&";
        int n=temp.length();
        vector<int> lps(n,0);
        int maxlen=0;
    /*    for(int i=1;i<n-1;i++){
            while(temp[i+lps[i]+1]==temp[i-lps[i]-1]) lps[i]++;
            maxlen=max(maxlen,lps[i]);
        }
        int si=-1, ej=-1;
        for(int i=1;i<n-1;i++){
            if(maxlen==lps[i]){
                si=i-lps[i], ej=i+lps[i];
                break;
            }
        }
        string ans="";
        for(int i=si;i<=ej;i++){
            if((isalpha(temp[i]) || isdigit(temp[i]))) ans+=temp[i];
        }
        return ans; */
        
        // centre is idx whose lps has been known , right is farthest idx included in its lps
        int centre=0, right=0; 
        for(int i=1;i<n-1;i++){
            int mirror=centre-(i-centre); // mirror Of ith idx element
            if(i<right){
                lps[i]=min(lps[mirror],lps[centre]-(i-centre));
            }
            while(temp[i+lps[i]+1]==temp[i-lps[i]-1]) lps[i]++;
            maxlen=max(maxlen,lps[i]);
            if(i+lps[i]>right){
                centre=i;
                right=i+lps[i];
            }
        }
        int si=-1, ej=-1;
        for(int i=1;i<n-1;i++){
            if(maxlen==lps[i]){
                si=i-lps[i], ej=i+lps[i];
                break;
            }
        }
        string ans="";
        for(int i=si;i<=ej;i++){
            if((isalpha(temp[i]) || isdigit(temp[i]))) ans+=temp[i];
        }
        return ans;
	return 0;
}
