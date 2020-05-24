#include <stdio.h>
#include <stdlib.h>

/* Definitions */
struct node 
{
    int val;  
    struct node* next; 
};

struct node *head = NULL; 
struct node *current = NULL; 

/* Declarations */
    void push(int val);
    void insert(int val);
    void insert_p(int val, int pos);
    struct node* pop(void);
    int find(struct node *elem);
    int find_val(int val);
    int rmv(struct node *elem);
    int rmv_val(int val);
    int is_empty(void);
    int length(void);
    void print_list(void);

int main(void) 
{   
    push(1);
    print_list();

    push(2);
    print_list();

    push(3);
    print_list();

    insert(4);
    print_list();

    insert_p(5, 1);
    print_list();

    insert_p(6, 0);
    print_list();

    insert_p(7, 7);
    print_list();

    pop(); 
    print_list();

    find(current);
    find_val(4);

    rmv_val(3);
    print_list();

    rmv(current);
    print_list();

    is_empty();

    length();
}

/* Add an node with value 'val' to the list. */
void push(int val) 
{
    struct node *temp = (struct node*) malloc(sizeof(struct node*));
    temp->val = val;
    temp->next = head; 
    head = temp; 
}

struct node* pop(void) 
{
    struct node *temp = head;
    head = head->next; 
    return temp; 
}

void insert(int val) 
{
    push(val);
}

void insert_p(int val, int p) 
{
    if(p == 0)
    {
        push(val);
        return;  
    }

    int i;
    struct node *prev = NULL; 
    struct node *temp = (struct node*) malloc(sizeof(struct node*));
    temp->val = val; 

    current = head; 

    for(i = 0; i < p; i++) 
    {
        if(current == NULL)
        {
            break; 
        }

        prev = current;
        current = current->next; 
    }

    if(i < p && current == NULL) 
    {
        printf("Index does not exist ... (No operation)\n");
        return; 
    } else 
    {
        prev->next = temp; 
        temp->next = current;
        return; 
    }
}

int find(struct node *elem) 
{
    current = head; 

    while(current != NULL) 
    {
        if(current == elem) 
        {   
            printf("Element: %d was found!\n", elem);
            return 1; 
        }
        current = current->next;  
    }
    printf("No element was found!\n");
    return 0;
}

int find_val(int val) 
{
    current = head; 

    while(current != NULL)
    {
        if(current->val == val) 
        {
            printf("Element: %d was found!\n", val);
            return 1;
        }
        current = current->next; 
    }
    printf("No element was found!\n");
    return 0; 
}

int rmv(struct node *elem) 
{
    current = head; 
    struct node *prev = head; 
    
    while(current != NULL)
     {
         if(current == elem)
         {
             prev->next = current->next;
             printf("Element: %d was removed!\n", elem);
             return 1; 
         }
        prev = current;
        current = current->next; 
     }
    printf("No element was removed!\n");
     return 0; 
}

int rmv_val(int val) 
{
    current = head; 
    struct node *prev = head; 
    
    while(current != NULL)
     {
         if(current->val == val)
         {
             prev->next = current->next;
             printf("Element: %d was removed!\n", val);
             return 1; 
         }
        prev = current;
        current = current->next; 
     }
    printf("No element was removed!\n");
     return 0; 
}

int is_empty(void)
{
    if(head == NULL)
    {
        printf("The current list is empty\n");
    } else 
    {
        printf("The current list is populated\n");
    }

    return head == NULL; 
}

int length(void) {
    current = head; 
    int length = 0; 

    while(current != NULL)
    {
        length++; 
        current = current->next; 
    }
    printf("Length of list: %d", length);
    return length; 
}

void print_list(void) 
{
    struct node *current = head; 
    printf("HEAD --> ");
    while(current != NULL) 
    {
        printf("[%d] --> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}