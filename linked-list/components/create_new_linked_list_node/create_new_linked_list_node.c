#include <stdio.h>
#include <stdlib.h>

#include "create_new_linked_list_node.h"
#include "node.h"
#include "string.h"
#include "cs50.h"
#include "are_strings_the_same.h"

const string MEMORY_ISSUE_MESSAGE = "Memory issue. Please try again";
const string INSERT_NUMERIC_VALUE_MESSAGE = "Insert numeric value: ";
const string INSERT_OPTION_MESSAGE = "Do you wanna insert at the beggining of the list - Ω(1) or in the end Ω(n)? B/E: ";

void addNewValueAtTheEndOfTheLinkedList(node *linkedList, int value){
    node *n = malloc(sizeof(linkedList));

    if(n == NULL)
    {
        printf(MEMORY_ISSUE_MESSAGE);
        return;
    }
    
    if (linkedList->initialized){
        linkedList->number = value;
        linkedList->initialized = false;
    } else {
        for (node *tmp = linkedList; tmp != NULL; tmp = tmp->next)
        {
            if (tmp->next == NULL)
            {
                n->number = value;
                n->initialized = false;
                n->next = NULL;
                tmp->next = n;
                break;
            }
        }
    }
}

void addNewValueAtTheBeginningOfTheLinkedList(node *linkedList, int value){
    node *n = malloc(sizeof(linkedList));
    
    if(n == NULL)
    {
        printf(MEMORY_ISSUE_MESSAGE);
        return;
    }
    
    if (linkedList->initialized){
        linkedList->number = value;
        linkedList->initialized = false;
    } else {
        n->number = linkedList->number;
        n->next = linkedList->next;
        
        linkedList->number = value;
        linkedList->next = n;
    }
}

void createNewLinkedListNode(node *linkedList)
{
    int userValue = getIntFromUser(INSERT_NUMERIC_VALUE_MESSAGE);
    
    if (linkedList->initialized){
        addNewValueAtTheBeginningOfTheLinkedList(linkedList, userValue);
        return;
    }
    
    char insertOption = getCharFromUser(INSERT_OPTION_MESSAGE);
    
    while(insertOption != 'B' && insertOption != 'E'){
        insertOption = getCharFromUser(INSERT_OPTION_MESSAGE);
    }
    
    if (insertOption == 'E'){
        addNewValueAtTheEndOfTheLinkedList(linkedList, userValue);
    } else {
        addNewValueAtTheBeginningOfTheLinkedList(linkedList, userValue);
    }
}
