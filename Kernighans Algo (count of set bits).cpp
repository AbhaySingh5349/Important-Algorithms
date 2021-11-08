class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c=0;
        while(n>0){
            int rmsb=n&(-n);
            n-=rmsb;
            c++;
        }
        return c;
    }
};
