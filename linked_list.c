#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

// funtions prototypes

void count_Nodes(struct Node *head);
void printdata(struct Node *head);

struct Node* add_at_end(struct Node *ptr, int data);
struct Node* add_at_beg(struct Node *ptr, int data);
void add_at_pos(struct Node *head, int data, int pos);

struct Node *del_first(struct Node *head);
void del_last(struct Node *head);
void del_pos(struct Node *head, int pos);
struct Node *del_list(struct Node *head);

int main(int arc, char *argv[])
{printf("\n");

    struct Node *head;
    head = malloc(sizeof(struct Node));
    head->data = 45;
    head->link = NULL;
    
    struct Node *ptr = head;
    ptr = add_at_end(ptr, 3);
    ptr = add_at_end(ptr, 9);

    add_at_pos(head, 7, 2);
    printdata(head);
   
printf("\n");
}

// add a Node at the beginning
struct Node* add_at_beg(struct Node *head, int data)
{
    struct Node *ptr;
    ptr = malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->link = head;

    head = ptr;
    return head;
}

//add a Node at the end
struct Node* add_at_end(struct Node *ptr, int data)
{
    struct Node *temp;
    temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->link = NULL;

    ptr->link = temp;
    return temp;
}

// add a Node at any position
void add_at_pos(struct Node *head, int data, int pos)
{
    struct Node *ptr = head;
    struct Node *ptr2;
    ptr2 = malloc(sizeof(struct Node));
    ptr2->data = data;
    ptr2->link = NULL;

    while(pos != 2){
        ptr = ptr->link;
        pos--;
    }
    ptr2->link = ptr->link;
    ptr->link = ptr2;
}

/*     delete a Node       */

// delete the first Node
struct Node *del_first(struct Node *head)
{
    if(head == NULL){
        printf("linked list is empty");
    }
    else{
        struct Node *temp = head;
        head = head->link;
        free(temp);
    }
    return head;
}

// delete the last Node
void del_last(struct Node *head)
{
    if(head == NULL){
        printf("linked list is empty");
    }
    else if(head->link == NULL){
        free(head);
        head = NULL;
    }
    else{
        struct Node *temp = head;
        while(temp->link->link != NULL){
            temp = temp->link;
        }
        free(temp->link);
        temp->link = NULL;
    }

}

// delete a Node at any position
void del_pos(struct Node *head, int pos)
{  
    struct Node *previous = head;
    struct Node *current = head;

    if(head == NULL){
        printf("linked list is empty");
    }
    else if(pos == 1){
        head = current->link;
        free(current);
        current = NULL;
    }
    else{
        while(pos != 1){
            previous = current;
            current = current->link;
            pos--;
        }
        previous->link = current->link;
        free(current);
        current = NULL;
    }
}


// delete the whole list
struct Node *del_list(struct Node *head)
{
    struct Node *temp = head;
    while(temp != NULL){
        temp = temp->link;
        free(head);
        head = temp;
    }
    return head;
}

// reversing a list
struct Node *reverse(struct Node *head)
{
    struct Node *prv, *next;
    while (head != NULL){
        next = head->link;
        head->link = prv;
        prv = head;
        head = next;
    }
    head = prv;
    return head;
}


// count the number of Nodes
void count_Nodes(struct Node *head)
{
    int count = 0;
    if(head == NULL){
        printf("linked list is empty");
    }
    while(head != NULL){
        count++;
        head = head->link;
    }
    printf("%d Nodes", count);
}

// print the data
void printdata(struct Node *head)
{
    if(head == NULL){
        printf("linked list is empty");
    }
    while(head != NULL){
        printf("%d\t", head->data);
        head = head->link;
    }
}






