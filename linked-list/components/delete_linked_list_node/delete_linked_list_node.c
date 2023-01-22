#include <stdlib.h>

#include "delete_linked_list_node.h"
#include "node.h"
#include "get_int_from_user.h"
#include "get_linked_list_length.h"
#include "string.h"

const string SELECT_INDEX_TO_DELETE_MESSAGE = "Select index to delete: ";

void deleteSelectedLinkedListNode(node *linkedList, int selectedIndex){
    node *previousNode = malloc(sizeof(linkedList));

    int i = 0;
    int linkedListLength = getLinkedListLength(linkedList);

    for (node *tmp = linkedList; tmp != NULL; tmp = tmp->next)
    {
        if (selectedIndex == 0 && linkedListLength == 1)
        {
            linkedList->next = NULL;
            linkedList->initialized = true;
        }

        if (selectedIndex == 0 && i == 1)
        {
            linkedList->number = tmp->number;
            linkedList->next = tmp->next;

            free(previousNode);

            break;
        }

        if (i + 1 == selectedIndex)
        {
            previousNode = tmp;
        }

        if (i == selectedIndex && i != 0)
        {
            previousNode->next = tmp->next;

            free(tmp);

            break;
        }

        i++;
    }
}

void deleteLinkedListNode(node *linkedList)
{
    int indexToDelete = getIntFromUser(SELECT_INDEX_TO_DELETE_MESSAGE);

    deleteSelectedLinkedListNode(linkedList, indexToDelete);
}
