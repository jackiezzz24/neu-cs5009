#include<stdio.h>
void swap(int* a, int* b){
	int temp; //temp variable
	temp=*a;
	*a=*b;
	*b=temp;
	printf("The variable in the function after swap: %d, %d\n", *a, *b);
}

int main(){
	int m = 10, n = 5;
	swap(&m, &n); /*call by reference*/
	printf("Value m and n after swap: %d, %d\n", m, n);
	return 0;
}
 
