// Bubble sort of names stored in a file
# include<stdio.h>
# include<string.h>
# include<stdlib.h>
int main()
{
	FILE *fp, *fp1;
	char name[10][200], temp[200];
	int k=0, i, j, r; //k=number of names present in the file
	//read the file
	fp = fopen("sort.txt","r");
	if (fp==NULL){
		//if file returns NULL then can't open the file
		printf("\n Cannot open the file\n");
		exit(0);
	}
	printf("contents of the file are\n");
	while(fscanf(fp, "%s", name[k])==1){
		printf("%s\n", name[k]);
		k++;
	}
	// bubble sort
	for (i = 0; i< k-1;i++) { //number of passes
		for (j=0; j<k-1-i; j++){ // comparison
			
		r=strcmp(name[j], name[j+1]);//r>0 -- name[j]>name[j+1], r<0 -- name[j]<name[j+1], r=0 -- name[j]=name[j+1]
		if (r>0) { //swapping
			strcpy(temp, name[j]);
			strcpy(name[j], name[j+1]);
			strcpy(name[j+1], temp);	
		}
		}
	}

	//put the contents of name array into the file
	printf("output is :\n");
	fp1=fopen("sorted.txt", "w");
	for (i=0; i<k;i++) {
		fprintf(fp1,"%s\n", name[i]);
		printf("%s\n", name[i]);
	}
	
	fclose(fp);
	fclose(fp1);
	return 0;
}

