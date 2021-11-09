#include <vector>
using namespace std;

// Approach 1:

int kadanesAlgorithm(vector<int> a) {
  int n=a.size();
	int dp[n];
        int maxsum=a[0];
        dp[0]=a[0];
        
        for(int i=1;i<n;i++){
            dp[i]=a[i] + (dp[i-1]>0 ? dp[i-1]:0);
            maxsum=max(maxsum,dp[i]);
        }
  return maxsum;
}

// Approach 2:

int kadanesAlgorithm(vector<int> a) {
  int n=a.size();
	int maxsum=INT_MIN, s=0;
	
	for(int i=0;i<n;i++){
		s+=a[i];
		if(s>maxsum) maxsum=s;
		if(s<0) s=0;
	}
  return maxsum;
}
