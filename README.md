# Implementation-of-Singly-Linked-Lists
In this repository, implementation of Sİngly Linked Lists is shown. 
You can find two types of function that added items into the list. However one of them (AddItemToEnd) adds items to the end of the list while the other one (AddItemInOrder) inserts new nodes sorting the values from small to large.

In the code, i used AddItemToEnd() function, but it is no matter which one you prefer. In case you want to see the difference between them more detailed, check below 

                                                                    
                                                                      


## SLLI* AddItemToEnd(SLLI* headOfTheList, int adding)

~~~ bash

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

~~~


## SLLI* AddItemInOrder(SLLI* headOfTheList, int adding)

~~~ bash

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

~~~



# Running The Code
You can run my code using one these IDEs   
* [Code::Blocks](https://www.codeblocks.org/downloads/) 
* [DevC++](https://www.dev-cpp.com/)  
* or an online one [GDB online Debugger](https://www.onlinegdb.com/)

