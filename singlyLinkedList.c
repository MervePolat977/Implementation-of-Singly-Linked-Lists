#include <stdio.h>
#include <stdlib.h>

typedef struct SinglyLinkedList{
    int data;
    struct SinglyLinkedList* next;
}SLLI;

//Function's Prototype
SLLI* AddItemToEnd(SLLI* headOfTheList, int adding);
SLLI* AddItemInOrder(SLLI* headOfTheList, int adding);
SLLI* DeleteItem(SLLI* headOfTheList, int deletingItem);
void PrintList(SLLI* headOfTheList);


SLLI* AddItemToEnd(SLLI* headOfTheList, int adding)
{
    SLLI* iter = headOfTheList;
    //if the list is EMPTY
    if(headOfTheList == NULL)
    {
        headOfTheList = (SLLI*)malloc(sizeof(SLLI));
        headOfTheList->data = adding;
        headOfTheList->next = NULL;
        return headOfTheList;
    }
    while(iter->next != NULL)
    {
        iter = iter->next;
    }
    iter->next = (SLLI*)malloc(sizeof(SLLI));
    iter->next->data = adding;
    iter->next->next = NULL;
    
    return headOfTheList;
}


SLLI* AddItemInOrder(SLLI* headOfTheList, int adding)
{
    //the list is EMPTY
    if(headOfTheList == NULL){
        headOfTheList = (SLLI*)malloc(sizeof(SLLI));
        headOfTheList->data = adding;
        headOfTheList->next = NULL;
        return headOfTheList;
    }
    else if(headOfTheList->data > adding){
        SLLI* temp = (SLLI*)malloc(sizeof(SLLI));
        temp->data = adding;
        temp->next = headOfTheList;
        headOfTheList = temp;
        return headOfTheList;
    }
    SLLI* iter = headOfTheList;
    while(iter->next != NULL && iter->next->data < adding){
        iter = iter->next;
    }
    
    SLLI* temp = (SLLI*)malloc(sizeof(SLLI));
    temp->data = adding;
    temp->next = iter->next;
    iter->next = temp;
    return headOfTheList;
    
}


SLLI* DeleteItem(SLLI* headOfTheList, int deletingItem){
    SLLI* iter = headOfTheList;
    SLLI* temp;
    
    //if deletingItem is the ROOT of the list
    if(headOfTheList->data == deletingItem){
        temp = headOfTheList;
        headOfTheList = headOfTheList->next;
        free(temp);
        return headOfTheList;
    }
    
    while(iter->next != NULL && iter->next->data != deletingItem){
        iter = iter->next;
    }
    if(iter->next == NULL){
        printf("'%d' NOT FOUND!\n", deletingItem);
        return headOfTheList;
    }
    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
    return headOfTheList;
    
}


void PrintList(SLLI* headOfTheList){
    SLLI* iter = headOfTheList;
    while(iter != NULL){
        printf("%d ", iter->data);
        iter = iter->next;
    }
    printf("\n");
}



int main(){
    SLLI* headOfTheList;
    headOfTheList = NULL;   // The list is EMPTY
    
    printf("\t\t\t\tIMPLEMENTATION OF SINGLY LINKED LISTS\n\n");
    
    headOfTheList = AddItemToEnd(headOfTheList,33);
    headOfTheList = AddItemToEnd(headOfTheList,12);
    headOfTheList = AddItemToEnd(headOfTheList,56);
    headOfTheList = AddItemToEnd(headOfTheList,11);
    headOfTheList = AddItemToEnd(headOfTheList,87);
    headOfTheList = AddItemToEnd(headOfTheList,59);
    headOfTheList = AddItemToEnd(headOfTheList,103);
    PrintList(headOfTheList);
    
    headOfTheList = DeleteItem(headOfTheList, 56);
    PrintList(headOfTheList);
    
    headOfTheList = DeleteItem(headOfTheList, 12);
    PrintList(headOfTheList);
    
    //deletes an element that is NOT IN THE LIST
    headOfTheList = DeleteItem(headOfTheList, 450);
    PrintList(headOfTheList);
    
    //deletes the root item
    headOfTheList = DeleteItem(headOfTheList, 33);
    PrintList(headOfTheList);
    
    return 0;
}