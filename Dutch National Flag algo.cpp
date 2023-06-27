Question : sort array of 0,1

// Approach : [0,i] belongs to 0's , [i+1,j-1] belongs to 1's and [j,n-1] is undefined region
class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n=a.size();
         
        int i=-1, j=0;
        while(j<n){
            if(a[j] == 0){
                i++;
                swap(a[i],a[j]);
            }
            j++;
        }
    }
};
