// tail recursion
#include<stdio.h>
int factorial(int n, int result) {
    if (n == 0) {
        return result;
    }
    else {
        return factorial(n - 1, n * result);
    }
}

int main() {
    int i, fact1;
    printf("Enter the number :\n");
    scanf("%d", &i);
    fact1 = factorial(i, 1);
    printf("the factorial is: %d\n", fact1);
}