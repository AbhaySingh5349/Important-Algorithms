Question Link: https://leetcode.com/problems/number-of-1-bits/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c=0;
        while(n>0){
            int rmsb=n&(-n); // rightmost set bit
            n-=rmsb;
            c++;
        }
        return c;
    }
};
