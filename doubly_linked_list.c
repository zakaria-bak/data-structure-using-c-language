#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    struct Node* prev;                   
    int data;                            
    struct Node* next;                  
}; 

/*    functions prototypes      */

void printdata(struct Node *head);
int count_Node(struct Node *head);

struct Node* createlist(struct Node *head);

struct Node* addToempty(struct Node *head, int data);
struct Node* add_at_beg(struct Node *head, int data);
void add_at_end(struct Node *head, int data);
struct Node* add_at_pos(struct Node *head, int data, int pos);

struct Node* delete_first(struct Node *head);
void delete_last(struct Node *head);
struct Node* delete_pos(struct Node *head, int pos);

struct Node* reverse(struct Node *head);

int main(int arc, char *argv[])
{printf("\n");
  
    struct Node *head;
    head = addToempty(head, 45); 
    head = add_at_beg(head, 2);
    add_at_end(head, 10);
    add_at_end(head, 14);

    printf("the doubly linked list : \n");
    printdata(head);

    head = reverse(head);
    printf("\nAfter reversing the list : \n");
    printdata(head);
   
}

  /*    adding elemnts   */

// creating a doubly linked list by inserting data from the user as inputs
struct Node* createlist(struct Node *head)
{
    int n, data, i;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);
    
    if(n == 0)
       return head;
    
    printf("\nEnter the data for Node 1 : ");
    scanf("%d", &data);
    head = addToempty(head, data);

    for(i = 1; i< n; i++){
        printf("Enter data for Node %d : ", i+1);
        scanf("%d", &data);
        add_at_end(head, data);
    }
    return head;
}

// adding an element at any position in the doubly linked list
struct Node* add_at_pos(struct Node *head, int data, int pos)
{
    int count = count_Node(head);
    if(pos == 1){
        head = add_at_beg(head, data);
        return head;
    }
    else if(pos > count){
        add_at_end(head, data);
        return head;
    } 
    struct Node *temp, *ptr = head;
    temp = malloc(sizeof(struct Node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    
    while(pos != 2){
        ptr = ptr->next;
        pos--;
    }
    temp->next = ptr->next;
    ptr->next->prev = temp;
    temp->prev = ptr;
    ptr->next = temp;

    return head;
}

// add an element at teh end of the the doubly linked list
void  add_at_end(struct Node *head, int data)
{
    struct Node *temp, *ptr = head;
    temp = malloc(sizeof(struct Node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;

}

// add an element at the beginning of the list
struct Node* add_at_beg(struct Node *head, int data)
{
    struct Node *temp = malloc(sizeof(struct Node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    temp->next = head;
    head->prev = temp;
    head = temp;

    return head;
}

// adding an element to an empty list
struct Node* addToempty(struct Node *head, int data)
{
    struct Node *temp = malloc(sizeof(struct Node));
    temp->prev = NULL;
    temp->data = 45;
    temp->next = NULL;
    head = temp;
    return head;
}

/*        deleting elements   */

// delete an element of the list at any position 
struct Node* delete_pos(struct Node *head, int pos)
{
    if(head == NULL){
        printf("doubly linked list is empty");
    }
    else if(pos == 1){
        head = delete_first(head);
    }
    else if(pos >= count_Node(head)){
        delete_last(head);
    }
    else{
        struct Node *temp = head;
        struct Node *current = head;
        while(pos > 1){
            temp = current;
            current = current->next;
            pos--;
        }
        temp->next = current->next;
        current->next->prev = temp;
        free(current);
        current = NULL;
        temp = NULL;
    }
    return head;

}

// delete the last element of the list
void delete_last(struct Node *head)
{
    struct Node *temp = head;
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    temp = NULL;
}

// delete the first element of the list
struct Node* delete_first(struct Node *head)
{   
    if(head == NULL){
        printf("doubly linked list is empty");
    }
    else{
        head = head->next;
        free(head->prev);
        head->prev = NULL;
    }
    return head;
} 

// reversing the list
struct Node* reverse(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *ptr2 = ptr->next;

    ptr->next = NULL;
    ptr->prev = ptr2;

    while(ptr2 != NULL){
        ptr2->prev = ptr2->next;
        ptr2->next = ptr;
        ptr = ptr2;
        ptr2 = ptr2->prev;
    }
    head = ptr;
    return head;

}

// printing elements of the list
void printdata(struct Node *head)
{
    if(head == NULL){
        printf("doubly linked list is empty");
    }

    while(head != NULL){
        printf("%d\t", head->data);
        head = head->next;
    }
}

// count Node's of the list
int count_Node(struct Node *head)
{
    int count = 0;
    if(head == NULL){
        printf("doubly linked list is empty");
    }
    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
}


