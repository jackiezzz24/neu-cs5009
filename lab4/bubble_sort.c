// Bubble sort of names stored in a file
# include<stdio.h>
# include<string.h>
# include<stdlib.h>
int main()
{
	FILE *fp;
	char nmae[10][200], temp[200];
	int k=0, i, j, r; //k=number of names present in the file
	//read the file
	fp = fopen("sort.text"."r");
	if (fp==NULL){
		//if file returns NULL then can't open the file
		printf("\n Cannot open the file\n");
		exit(0);
	}
	printf("contents of the file are\n");
	while(fscanf(fp)==1){

	}
}
