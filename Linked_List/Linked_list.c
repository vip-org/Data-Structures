/*
MIT License

Copyright (c) 2021 velai_illa_programmer

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum main_menu{
    INSERT_MAIN_MENU=1,
    DISPLAY_MAIN_MENU,
    EXIT_MAIN_MENU
};

enum insert_menu{
    INSERT_AT_START=1,
    INSERT_AT_POS,
    INSERT_AT_END,
    EXIT_INSERT_MENU
};

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void displayList()
{
    struct node* temp = head;
    if(temp){
        printf("The elements in the Linked List are:\n");
    }else{
        printf("\nThe list is empty!\n");
    }
    while (temp != NULL) {
        printf("   ( %p )\n",temp);
        printf("| %3d | %p |", temp->data,temp->next);
        temp = temp->next;
        if(temp){
            printf(" \n %*c | \n %*c V \n",8,' ',8,' ');
        }
    }
}

bool insertAtStart()
{
    int data = 0;
    struct node* new_node = NULL;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(!new_node){
        printf("Linked list new_node allocation Failed\n");
        return false;
    }
    printf(" Enter the data to be inserted: ");
    scanf("%d",&data);
    new_node->data = data;
    new_node->next = head;
    head = new_node; 
    return true;
}

bool insertAtEnd()
{
    if(!head){
        if(insertAtStart(head)){
            return true;
        }else{
            return false;
        }
    }
    int data = 0;
    struct node* cur_node = head;
    struct node* new_node = NULL;
    printf(" Enter the data to be inserted: ");
    scanf("%d",&data);
    while (cur_node->next!=NULL)
    {
        cur_node = cur_node->next;
    }
    new_node = (struct node*)malloc(sizeof(struct node));
    if(!new_node){
        printf("Linked list new_node allocation Failed\n");
        return false;
    }
    new_node->data = data;
    new_node->next = NULL;
    cur_node->next = new_node;
    return true;
}

bool insertAtPos()
{
    int data=0,pos=0;
    int cnt=0;
    struct node*  cur_node = head;
    struct node*  new_node = NULL;
    printf("NOTE: The list is zero-indexed list.\n");
    printf(" Enter the postion: ");
    scanf("%d",&pos);
    if(pos<0){
        printf("Error: Invalid Position Entered!!\n");
        return false;
    }
    if(pos==0){
        if(insertAtStart(head)){
            return true;
        }else{
            return false;
        }
    }

    while(cnt<pos-1 && cur_node && cur_node->next ){
        cur_node = cur_node->next;
        cnt++;
    }
    if(cnt==pos-1 && cur_node->next==NULL){
        if(insertAtEnd()){
            return true;
        }else{
            return false;
        }
    }else if(cnt==pos-1){
        printf(" Enter the data to be inserted: ");
        scanf("%d",&data);  
        new_node = (struct node*)malloc(sizeof(struct node));
        if(!new_node){
            printf("Linked list new_node allocation Failed\n");
            return false;
        }
        new_node->data = data;
        new_node->next = cur_node->next;
        cur_node->next = new_node;
    }else{
        printf("Error: Position not found!!\n");
        return false;
    }
    return true;
}

void insertNewNode()
{
    int option=-1;
    while(true){
        printf("\nInsert New Node Menu:\
                \n 1.Insert at start \
                \n 2.Insert at position \
                \n 3.Insert at end \
                \n 4.Back to main menu \
                \n Enter your option:");
        scanf("%d",&option);
        
        switch (option)
        {
        case INSERT_MAIN_MENU:
            if(insertAtStart()){
                printf("The data has been inserted successfully.\n");
                displayList();
            }else{
                printf("The data has not been inserted.\n");
            }
            break;
        case INSERT_AT_POS:
            if(insertAtPos()){
                printf("The data has been inserted successfully.\n");
                displayList();
            }else{
                printf("The data has not been inserted.\n");
            }
            break;
        case INSERT_AT_END:
            if(insertAtEnd()){
                printf("The data has been inserted successfully.\n");
                displayList();
            }else{
                printf("The data has not been inserted.\n");
            }
            break;
        case EXIT_INSERT_MENU:
            break;
        default:
            printf("Invalid option selected!!");
            break;
        }
        if(option==EXIT_INSERT_MENU){
            break;
        }
    }
}

void clearList(){
    struct node*  cur_node = head;
    struct node* next_node = cur_node;
    while(next_node!=NULL){
        cur_node=next_node;
        next_node=next_node->next;
        free(cur_node);
    }
    head = NULL;
}

int main(int argc, char const *argv[])
{
    int option= -1;
    while(true){
        printf("\nLinked List Main Menu:\
                \n 1.Insert New Node \
                \n 2.Display the List \
                \n 3.Exit \
                \n Enter your option:");
        scanf("%d",&option);
        switch (option)
        {
            case INSERT_MAIN_MENU:
                insertNewNode();
                break;
            case DISPLAY_MAIN_MENU:
                displayList();
                break;
            case EXIT_MAIN_MENU:
                break;         
            default:
                printf("Invalid option selected!!");
                break;
        }
        if(option==EXIT_MAIN_MENU){
            break;
        }
    }
    clearList(&head);
    return 0;
}
