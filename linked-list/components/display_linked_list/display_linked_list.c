#include <stdio.h>

#include "display_linked_list.h"
#include "node.h"
#include "empty_line.h"
#include "string.h"

const string EMPTY_LINKED_LIST_MESSAGE = "Empty Linked List!";
const string LINKED_LIST_HEADER_MESSAGE = "Index. Value - Address in memory";

void displayLinkedList(node *linkedList)
{
    if (linkedList->initialized)
    {
        printf(EMPTY_LINKED_LIST_MESSAGE);
        emptyLine();
        return;
    }

    printf(LINKED_LIST_HEADER_MESSAGE);
    emptyLine();

    int i = 0;

    for (node *tmp = linkedList; tmp != NULL; tmp = tmp->next)
    {
        int number = tmp->number;

        printf("%i. %i - %p\n", i, number, tmp);

        i++;
    }
}
