#include<stdio.h>
#include<string.h>
#include<ctype.h>
void stringDecode(char* input,int n, char* result){

    if (n==0) {
        printf("Empty String\n");
        return;
    }
    int i = 0;
    int index = 0;
    char prevch;
    while(i < n) {
        if(isdigit(input[i])){
            // extract the integer and check the count
            int count = 0;
            while(i < n && isdigit(input[i])) {
                count = count * 10 + input[i++] - '0';

            }
            while (count --> 1) {
                result[index++] = prevch;
            }

        } else {
            // if it is alphabet
            result[index++] = input[i];
            prevch = input[i];
            i++;
        }
    }

    for (int i = 0; i < index; i++) {
        printf("%c", result[i]);
    }
    printf("\n");

}
int main()
{
    char input[]="a3b14cd3";
    char result[50];
    int n=strlen(input);//n is the size of input array
    stringDecode(input,n,result);
    return 0;
}
