Question : sort array of 0,1

// Approach : [0,i] => 0's , [i+1,j-1] => 1's and [j,n-1] => undefined
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

Question : sort array of 0,1,2

 // Approach : [0,i] => 0's , [i+1,j-1] => 1's, [j,k] => undefined, [k+1,n-1]: 2's
class Solution {
public:
    void sortColors(vector<int>& a) {
        int n=a.size();
        
        int i=-1, j=0, k=n-1;
        while(j<=k){
            if(a[j] == 0){
                i++;
                swap(a[i],a[j]);
                j++;
            }else if(a[j] == 2){
                swap(a[j],a[k]);
                k--;
            }else{
                j++;
            }
        }
    }
};
