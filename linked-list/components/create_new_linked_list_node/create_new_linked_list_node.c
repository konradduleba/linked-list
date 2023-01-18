#include <stdio.h>
#include <stdlib.h>

#include "create_new_linked_list_node.h"
#include "node.h"
#include "get_int_from_user.h"
#include "string.h"

const string MEMORY_ISSUE_MESSAGE = "Memory issue. Please try again";
const string INSERT_NUMERIC_VALUE_MESSAGE ="Insert numeric value: ";

void addNewValueToTheLinkedList(node *linkedList, int value){
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

void createNewLinkedListNode(node *linkedList)
{
    int userValue = getIntFromUser(INSERT_NUMERIC_VALUE_MESSAGE);

    addNewValueToTheLinkedList(linkedList, userValue);
}
