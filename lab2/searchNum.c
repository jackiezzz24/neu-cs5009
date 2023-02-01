#include<stdio.h>
int main(){
	int arr[6] = {8,9,6,5,4,3};
	int p = -1;
	int num = 3;
	for (int i = 0; i<6;i++){
		if (arr[i]==num){
			p = i;
		}
	}
	if (p == -1){
		printf("The element is not found.\n");
	}
	else {
		printf("The element %d is found at posistion %d\n", num, p);
	}

	return 0;
}
