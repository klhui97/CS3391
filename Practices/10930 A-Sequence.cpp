#include <cstring>
#include <cstdio>
 
int number[33];
int dp[900009];
 
int main()
{
	int D, cases = 1;
	while (~scanf("%d",&D)) {
		int sum = 0;
		for (int i = 0; i < D; ++ i) {
			scanf("%d",&number[i]);
			sum += number[i];
		}
		
		int flag = 1;
		for (int i = 1; i < D; ++ i)
			if (number[i] <= number[i-1]) {
				flag = 0;
				break;
			}
		if (flag) {
			memset(dp, 0, sizeof(dp));
			dp[0] = 1;
			for (int i = 0; i < D; ++ i) {
				if (dp[number[i]]) {
					flag = 0;
					break;
				}
				if (flag)
					for (int j = sum; j >= number[i]; -- j)
						if (dp[j-number[i]])
							dp[j] = 1;
			}
		}
		
		printf("Case #%d:",cases ++);
		for (int i = 0; i < D; ++ i)
			printf(" %d",number[i]);
		printf("\nThis is ");
		if (!flag) printf("not ");
		printf("an A-sequence.\n");
	}
    return 0;
}