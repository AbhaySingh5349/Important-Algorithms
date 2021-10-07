#include <vector>
using namespace std;

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
