#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> a) {
  int n=a.size();
	for(int i=1;i<n;i++){
		int j=i;
		while(j>0 && a[j]<a[j-1]){
			swap(a[j],a[j-1]);
			j--;
		}
	}
  return a;
}
