#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int data;
	struct node* next;
} node;

node* CreateNode(int value){
	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}

void push_back(node** head, int value){
	node *temp = *head;
	node *newNode = CreateNode(value);
	if(*head == NULL){
		*head = newNode;
		return;
	}
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
}

void push_front(node** head, int value){
	node* newNode = CreateNode(value);
	newNode->next = *head;
	*head = newNode;
}

int size(node *head){
	int cnt = 0;
	while(head !=NULL){
		++cnt;
		head = head->next;
	
	}
	return cnt;
}

void insert(node** head, int value, int position) {
    int n = size(*head);
    if (position < 1 || position > n + 1) 
        return;

    if (position == 1) {
        push_front(head, value); 
        return;
    }

    node* temp = *head;
    int cnt = 1;
    while (cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }
    

    node* newNode = CreateNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}
void pop_front(node** head){
	if(*head == NULL) return;
	node *temp = *head;
	*head = (*head)->next;
	free(temp);
}

void pop_back(node** head){
	if(*head == NULL) return;
	node* temp = *head;
	if(temp->next == NULL){
		*head = NULL; free(temp);
		return;
	}
	while(temp->next->next !=NULL){
		temp = temp->next;
	}
	node *last = temp->next;
	temp->next = NULL;
	free(last);
}

int front(node* head){
	return (head)->data;
}

int back(node* head){
	node* temp = head;
	if(temp->next == NULL){
		return;
	}
	while(temp->next !=NULL){
		temp = temp->next;
	}
	return temp->data;
} 

void erase(node** head, int position){
	int n = size(*head);
	if(position < 1 || position > n) return;
	if(position == 1) pop_front(head);
	else{
		node *temp = *head;
		int cnt = 1;
		while(cnt< position -1){
			temp = temp -> next;
			cnt++;
		}
		node *kth = temp->next;
		temp->next = kth->next;
		free(kth);
	}
}

bool empty(node ** head) {
   return (*head == NULL);
}
int get(node* head, int position) {
    int i = 0;
 
    while (head->next != NULL && position != i) {
        head = head->next;
        i++;
    }

    if (position != i) {
        printf("Error: List has less element\n");
        return 0;
    }
    return head->data;
}

void display (node * head){
	while(head != NULL){
		printf("%d",head->data);
		head = head->next;
	}
}

int main(){
	node* array = NULL; 
	while(1){
		printf("1. Them vao dau\n");
		printf("2. Them vao cuoi\n");
		printf("3. Xoa node dau\n");
		printf("4. Xoa node cuoi\n");
		printf("5. Lay gia tri cua note dau\n");
		printf("6. Lay gia tri cua note cuoi\n");
	    printf("7. Them node vao vi tri bat ky\n");
	    printf("8. Xoa node tai vi tri bat ky\n");
	    printf("9. Size \n");
	    printf("10. Lay gia tri cua note bat ky\n");
	    printf("11. Kiem tra note trong\n");
	    printf("12. Hien thi linked list\n");
	    printf("Nhap lua chon: ");
	    int choice;
	    scanf("%d",&choice);
	    printf("\n");
	int val,pos;
	switch (choice) {
        case 1:
        	printf("Value: ");
        	scanf("%d",&val);
        	push_front(&array,val);  
            break;
        case 2:
        	printf("Value: ");
            scanf("%d",&val);
        	push_back(&array,val);  
            break;
        case 3:
           	pop_front(&array);
            break;
        case 4:
            pop_back(&array);
            break;
        case 5:
            front(array);
            printf("Front value: %d\n", front(array)); 
            break;
        case 6:
            back(array);
            printf("Back value: %d\n", back(array));
            break;
        case 7:
       		printf("Value: ");
        	scanf("%d",&val);
        	printf("Position: ");
        	scanf("%d",&pos);
            insert(&array,val,pos);
            break;
        case 8:
        	printf("Position: ");
        	scanf("%d",&pos);
           	erase(&array,pos);
            break;
        case 9:
        	printf("Size: %d\n", size(array));
            size(array);
            break;
        case 10:
  			printf("Position: ");
        	scanf("%d",&pos);
            get(array,pos);
            break;
        case 11:
            empty(&array);
            printf("Phat Is empty: %s\n", empty(&array) ? "true" : "false");
            break;
        default:
            display(array);
            printf("\n");
            break;
    }
	}
	}
	
