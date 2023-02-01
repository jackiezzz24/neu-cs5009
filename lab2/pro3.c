#include<stdio.h>
int main() {
	int arr[5]={10, 29, 30, 38, 40};
	int i, sum=0;
	for (i = 0; i< 5; i++){
		printf("%d\n",arr[i]);
		sum +=arr[i];
	}
	printf("sum is: %d\n", sum);
	return 0;
}
