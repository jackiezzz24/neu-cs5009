
/*-----CPU scheduling based on the priority(Linked lists)--------*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int process;
    int burst_time;
    int priority;
    struct node* next;
}node_t;

typedef struct queue{
    node_t* head;
}queue_t;

/*Initializing queue with head as NULL*/
queue_t* init_queue(){
    queue_t* pq = (queue_t*)malloc(sizeof(queue_t));
    pq->head = NULL;
    return pq;
}
/*---creating the node with fields process number,burst time,priority and next---*/
node_t* create_node(int process, int burst_time, int pri){
    node_t *node=(node_t*)malloc(sizeof(node_t));
    node->process=process;
    node->burst_time=burst_time;
    node->priority=pri;
    node->next=NULL;
    return node;
    
}

void insert_node(queue_t* pq,node_t* node){
// list is empty 
if (pq->head == NULL) {
    pq->head = node;
    return;
}
// if the list not empty, highest priority process arrives
 node_t* current = pq->head;
 node_t* previous = pq->head;
 if (current != NULL && current->priority > node->priority) {
    node->next = current; // establish link
    pq->head = node; //update head pointer
    return;
 } 
 // if the list not empty and lower priority process arrives
 while (current != NULL && current->priority <= node->priority) {
    previous=current; // keep track of prev node
    current=current->next; //traverse through the list to find appropriate position
 }
 {
    //establish two links
    previous->next = node;
    node->next = current;
 }
}


/*----Function to display the output-----*/
void display(queue_t* pq, int n){
    node_t* current = pq->head;
if(current == NULL)
        return;
printf("\nProcessnumber\tPriority\t\tBurst Time\n");
    while(current != NULL){
        printf("%d\t\t%d\t\t\t%d\t\t\n",current->process,current->priority,current->burst_time);
        current = current->next;
    }
    printf("\n");
}
/*----Deallocate the queue---------*/
void destroy_queue(queue_t* pq){
    if(pq->head== NULL)
        return;
    node_t* current = pq->head;
    node_t* temp;
    while(current != NULL){
        temp = current;
        current = current->next;
        free(temp);

    }
}
/*----------Main Program-------------*/
int main(){
    printf("---CPU process scheduling based on the priority---- \n");
    queue_t* pq = init_queue();
    int n,burst_time,priority;
    
    printf("Number of Processes: \n");
    scanf("%d",&n);
    
    for(int i = 1; i <= n; i++)
    {
        printf("\nEnter Burst Time of process %d \n",i);
        scanf("%d",&burst_time);
        printf("Enter Priority of process %d \n",i);
        scanf("%d",&priority);
        node_t *newnode= create_node(i, burst_time,priority);
        insert_node(pq,newnode);
    }
    display(pq,n);
    destroy_queue(pq);
    free(pq);
    
    return 0;
}
