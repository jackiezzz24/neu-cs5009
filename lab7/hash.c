/* Implementation using SHA function*/
/* compile gcc -lcrypto */
#include<stdio.h>
#include<string.h>
#include<openssl/sha.h>
int main() {
    char data[] = "Hello World!";
    int length = strlen(data);
    int i;
    unsigned char hash[SHA_DIGEST_LENGTH]; 
    SHA1((unsigned char*) data, length, hash);
    for (i = 0; i < SHA_DIGEST_LEGTH; i++) {
        printf("%x", hash[i]);
    }
    printf("\n");
    return 0;
}