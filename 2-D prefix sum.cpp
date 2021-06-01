#include <bits/stdc++.h>
using namespace std;
    
int main()
{
	int mat[n][m];
	
	int pre[n][m];
	memset(pre,0,sizeof(pre));
        
    	int i,j;
        
    	for(i=0;i<n;i++){
	   for(j=0;j<m;j++){
		pre[i][j]=mat[i][j];
                if(i>0) pre[i][j]+=pre[i-1][j];
		if(j>0) pre[i][j]+=pre[i][j-1];
		if(i>0 && j>0) pre[i][j]-=pre[i-1][j-1];

		cout<<pre[i][j]<<" ";
	    }
	    cout<<"\n";
        }
	cout<<(pre[x2][y2]-pre[x2][y1-1]-pre[x1-1][y2]+pre[x1-1][y1-1]);
	return 0;
}
