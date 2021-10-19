#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> a) {
  int n=a.size();
	for(int i=0;i<n;i++){
		bool flag=false;
		for(int j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
				flag=true;
			}
		}
		if(flag==false) break;
	}
  return a;
}
