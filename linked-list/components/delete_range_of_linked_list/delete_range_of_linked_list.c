#include <stdlib.h>

#include "delete_range_of_linked_list.h"
#include "delete_linked_list_node.h"
#include "node.h"
#include "cs50.h"
#include "get_linked_list_length.h"
#include "string.h"
#include "empty_line.h"

const string SELECT_STARTING_INDEX_TO_DELETE_MESSAGE = "Select starting index to delete: ";
const string SELECT_ENDING_INDEX_TO_DELETE_MESSAGE = "Select ending index to delete: ";
const string STARTING_INDEX_INCORRECT_VALUE = "Starting index can not be lower then 0";
const string ENDING_INDEX_OUT_OF_SCOPE = "Ending index can not be higher then linked list length!";

void deleteRangeOfLinkedListNodes(node *linkedList){
    int startingIndexToDelete = getIntFromUser(SELECT_STARTING_INDEX_TO_DELETE_MESSAGE);
    int endingIndexToDelete = getIntFromUser(SELECT_ENDING_INDEX_TO_DELETE_MESSAGE);
    
    while (startingIndexToDelete < 0) {
        printf(STARTING_INDEX_INCORRECT_VALUE);
        emptyLine();
        startingIndexToDelete = getIntFromUser(SELECT_STARTING_INDEX_TO_DELETE_MESSAGE);
    }
    
    while (startingIndexToDelete > endingIndexToDelete){
        startingIndexToDelete = getIntFromUser(SELECT_STARTING_INDEX_TO_DELETE_MESSAGE);
        endingIndexToDelete = getIntFromUser(SELECT_ENDING_INDEX_TO_DELETE_MESSAGE);
    }
    
    int i = 0;
    int linkedListLength = getLinkedListLength(linkedList);
    
    while (endingIndexToDelete > linkedListLength - 1) {
        printf(ENDING_INDEX_OUT_OF_SCOPE);
        emptyLine();
        endingIndexToDelete = getIntFromUser(SELECT_ENDING_INDEX_TO_DELETE_MESSAGE);
    }
    
    if (startingIndexToDelete == endingIndexToDelete){
        deleteSelectedLinkedListNode(linkedList, startingIndexToDelete);
        
        return;
    }
    
    node *previousNode = malloc(sizeof(linkedList));
    
    for (node *tmp = linkedList; tmp != NULL; tmp = tmp->next)
    {
        if ((startingIndexToDelete == 0 && linkedListLength == 1) || (startingIndexToDelete == 0 && linkedListLength - 1 == endingIndexToDelete))
        {
            linkedList->next = NULL;
            linkedList->initialized = true;
        }
        
        if (startingIndexToDelete == 0 && endingIndexToDelete == i - 1)
        {
            linkedList->number = tmp->number;
            linkedList->next = tmp->next;

            break;
        }
        
        if (i + 1 == startingIndexToDelete) {
            previousNode = tmp;
        }
        
        if (endingIndexToDelete == i && startingIndexToDelete != 0) {
            previousNode->next = tmp->next;
            
            break;
        }

        i++;
    }
}
