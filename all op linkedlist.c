#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert_begin()
{
    int a;
    printf("Enter node data: ");
    scanf("%d", &a);
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if(temp != NULL)
    {
        temp->data = a;
        temp->next = head;
        head = temp;
    }
}

void insert_end()
{
    int a;
    printf("Enter node data: ");
    scanf("%d", &a);
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if(temp != NULL)
    {
        temp->data = a;
        temp->next = NULL;
        if(head == NULL)
            head = temp;
        else
        {
            struct node* temp1 = head;
            while(temp1->next != NULL)
            {
                temp1 = temp1->next;
            }
            temp1->next = temp;
        }
    }
}

void insert_specific()
{
    int a;
    printf("Enter node data: ");
    scanf("%d", &a);
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if(temp != NULL)
    {
        temp->data = a;
        temp->next = NULL;
        struct node* temp1 = head;
        while(temp1 && temp1->data != a)
        {
            temp1 = temp1->next;
        }
        if(temp1 == NULL)
        {
            printf("Note found...\n");
            free(temp);
        }
        else
        {
            temp->next = temp1->next;
            temp1->next = temp;
        }
    }
}

void deletion_head()
{
    if(head == NULL)
        printf("Linked list is empty");
    else
    {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
}

void deletion_end()
{
    if(head == NULL)
        printf("Linked list is empty");
    else
    {
        struct node* temp = head, *pre = NULL;
        while(temp->next != NULL)
        {
            pre = temp;
            temp = temp->next;
        }
        if(temp == head)
            head = NULL;
        else
        {
            pre->next = NULL;
            free(temp);
        }
    }
}

void deletion_pos()
{
    int a;
    if(head == NULL)
        printf("Empty....\n");
    else
    {
        struct node* temp = head, *pre = NULL;
        printf("Enter the data you want to delete: ");
        scanf("%d", &a);
        while(temp && temp->data != a)
        {
            pre = temp;
            temp = temp->next;
        }
        if(temp == NULL)
            printf("element not found....\n");
        else
        {
            if(temp == head)
                head = head->next;
            else
            {
                pre->next = temp->next;
                free(temp);
            }
        }
    }
}

void display()
{
    if(head == NULL)
        printf("Empty");
    else
    {
        struct node* ptr = head;
        while(ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}

void search()
{
    int a;
    printf("Enter the data you want to search: ");
    scanf("%d", &a);
    if(head == NULL)
        printf("Empty");
    else
    {
        struct node* ptr = head;
        while(ptr != NULL && ptr->data != a)
            ptr = ptr->next;
        if(ptr == NULL)
            printf("Element not found");
        else
            printf("Element found");
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("\nEnter your choice\n");
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert at specific value\n4. Delete at head\n5. Delete at end\n6. Delete at specific place\n7. Display\n8. Search\n9. Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                insert_begin();
                display();
                break;
            case 2:
                insert_end();
                display();
                break;
            case 3:
                insert_specific();
                display();
                break;
            case 4:
                deletion_head();
                display();
                break;
            case 5:
                deletion_end();
                display();
                break;
            case 6:
                deletion_pos();
                display();
                break;
            case 7:
                display();
                break;
            case 8:
                search();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

