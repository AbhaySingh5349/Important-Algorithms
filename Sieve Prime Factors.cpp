class Solution {
public:
    
    // spf[x] is the smallest prime factor of number x, where x >= 2
    vector<int> sieve(int n){
        vector<int> spf(n);
        for(int i=0;i<n;i++) spf[i]=i; // O(N)
        
        for(int i=2;i*i<n;i++){
            if(spf[i]==i){
                for(int j=i*i;j<n;j+=i){
                    if(spf[j]>i) spf[j]=i; // update to the smallest prime factor of j
                }
            }
        }
        return spf;
    }
    
     // O(logN)
    vector<int> primeFactors(vector<int> &spf, int n){
        vector<int> factors;
        while(n>1){
            factors.push_back(spf[n]);
            n/=spf[n];
        }
        return factors;
    }
    
    void getPrimeFactors(vector<int>& a) {
        
        vector<int> spf=sieve(num+1);
        vector<int> factors=primeFactors(spf,num);
    }
};
