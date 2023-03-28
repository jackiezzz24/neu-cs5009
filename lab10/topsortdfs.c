
//topological sort using recursive DFS.
#include<stdio.h>
#define N 7
int visited[N];
int j=N;
void DFS(int A[][N], int start,int* result,int n){
    visited[start]=1;//mark i as visited
    int i;
    //perform dfs for its neighboring nodes
    for(i=0;i<n;i++){
        if(A[start][i]==1 && !visited[i]){
            DFS(A,i,result,n);
            
        }
        }
        //store the nodes in result in reverse order
        result[j]=start;
        j--;
    
}

void topoSort(int A[][N], int n){
    int i;
    int result[n];
   //initialize visted array as false
    for(i=0;i<n;i++){
        visited[i]=0;
    }
    //perform DFS for all nodes starting from 0
    for(i=0;i<n;i++){
        if(visited[i]==0)
           DFS(A,i,result,n);
    }
    //display the result
    for(i=1;i<=n;i++){
        printf("%d->",result[i]);
    }
    
}


int main (){
 
    int A[N][N] = {{0, 1, 0, 0, 0, 0,0},
                   {0, 0, 1, 1, 1, 0,0},
                   {0, 0, 0, 0, 1, 0,0},
                   {0, 0, 0, 0, 1, 0,0},
                   {0, 0, 0, 0, 0, 1,0},
                   {0, 0, 0, 0, 0, 0,0},
                   {0, 0, 0, 1, 0, 0, 0}};
                   
    
    topoSort(A,N);
    printf("\n");
    return 0;
}
