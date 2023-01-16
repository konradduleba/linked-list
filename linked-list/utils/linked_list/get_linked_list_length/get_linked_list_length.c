#include "get_linked_list_length.h"
#include "node.h"

int getLinkedListLength(node *linkedList)
{
    int linkedListLength = 0;

    for (node *tmp = linkedList; tmp != NULL; tmp = tmp->next)
    {
        linkedListLength++;
    }

    return linkedListLength;
}
