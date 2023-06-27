Question : sort array of 0,1

// Approach : 
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
