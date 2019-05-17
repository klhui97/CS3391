// http://alan790712.pixnet.net/blog/post/65146468-%5Buva%5D-10739---string-to-palindrome

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MIN(x,y)((x)<(y)?(x):(y))

char str[1001];
int dp[1001][1001];
int findDp(int i,int j){
    if(dp[i][j]==-1){
        if(i>=j)dp[i][j]=0;
        else{
            if(str[i]==str[j]){
                dp[i][j] = findDp(i+1,j-1);
            }else {
                dp[i][j] = MIN(findDp(i+1,j-1),MIN(findDp(i+1,j),findDp(i,j-1)))+1;
            }
        }
    }
    return dp[i][j];
}
int main(){
    int t,Case=0;
    scanf("%d",&t);
    gets(str);
    while(t--){
        gets(str);
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",++Case,findDp(0,strlen(str)-1));
    }

    return 0;
}