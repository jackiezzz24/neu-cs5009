/*Implementation of stack using single linked list*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} node_t;

typedef struct s {
	struct node* head;
} stack1_t;

/*create a new node*/
node_t* newNode(int val) {
	node_t* t= (node_t*)malloc(sizeof(node_t));
	if (t==NULL){
		exit(1);
	}
	t->data=val;
	t->next=NULL;
	return t;
}

/*create a stack with head node null*/
stack1_t* initStack(){
	stack1_t* s;
	s = (stack1_t*)malloc(sizeof(stack1_t));
	if (s !=NULL){
		s->head=NULL;
	}
	return s;
}
/*check if the stack is empty*/
int isEmpty(stack1_t* s){
	if (s->head==NULL){
		return 1;
	}
	else {
	return 0;
	}
}

/*Push the element into the stack*/
void push(stack1_t* s1, int data){
	node_t* temp = newNode(data);
	if (isEmpty(s1)){
		s1->head = temp;
		printf("The data pushed is: %d\n",temp->data);
		return;
	}	
	printf("The data pushed is: %d\n", temp->data);
	temp->next = s1->head; //linking the nodes
	s1->head = temp; //updating head pointer
	return;	
}

/*pop operation*/
int pop(stack1_t* s1){
	int val;
	if (isEmpty(s1)){
		printf("stack is empty.\n");
		return -1;
	}
	node_t* temp=s1->head;
	val=temp->data;
	s1->head=temp->next;
	free(temp);
	return val;
}

/*display stack*/
void display(stack1_t* s1) {
	node_t* temp = s1->head;
	if (temp==NULL){
		printf("empty stack\n");
	}
	printf("stack is \n");
	while (temp !=NULL){
		printf("%d\t", temp->data);
		temp=temp->next;
	}
	return;	
}

/*Main program*/
int main(){
	stack1_t* s1 = initStack();
	push(s1, 11);
	push(s1, 22);
	push(s1, 33);
	display(s1);
	printf("\nPoped data is \n");
	while(!isEmpty(s1)){
		printf("%d\n",pop(s1));
	}
	free(s1);
	return 0;
}
