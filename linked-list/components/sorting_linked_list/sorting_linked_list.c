#include "sorting_linked_list.h"
#include "cs50.h"
#include "node.h"
#include "string.h"
#include "get_linked_list_length.h"
#include "create_new_linked_list_node.h"

const string GET_SORTING_TYPE_MESSAGE = "How do you wanna sort linked list? ASC/DESC (A/D)?: ";

void sortAnArray(int number[], int first, int last){

    int i, j, pivot, temp;

    if (first < last){

        pivot = first;

        i = first;

        j = last;

        while(i < j){

            while(number[i] <= number[pivot] && i < last){
                i++;
            }
            

            while(number[j] > number[pivot]){
                j--;
            }

            if (i < j) {

                temp = number[i];

                number[i] = number[j];

                number[j] = temp;
            }

        }

        temp = number[pivot];

        number[pivot] = number[j];

        number[j] = temp;

        sortAnArray(number, first, j - 1);

        sortAnArray(number, j + 1, last);
    }
}

void sortLinkedList(node *linkedList){
    char sortingType = getCharFromUser(GET_SORTING_TYPE_MESSAGE);
    
    while (sortingType != 'A' && sortingType != 'D') {
        sortingType = getCharFromUser(GET_SORTING_TYPE_MESSAGE);
    }
    
    int linkedListLength = getLinkedListLength(linkedList);
    int lastIndex = linkedListLength - 1;
    
    int linkedListValues[linkedListLength];
    
    int i = 0;
    
    for (node *tmp = linkedList; tmp != NULL; tmp = tmp->next)
    {
        linkedListValues[i] = tmp->number;
        i++;
    }

    sortAnArray(linkedListValues, 0, lastIndex);
    
    linkedList->next = NULL;
    linkedList->initialized = true;
    
    for(int i = 0; i < linkedListLength; i++){
        int index = sortingType == 'A' ? i : lastIndex - i;
        addNewValueAtTheEndOfTheLinkedList(linkedList, linkedListValues[index]);
    }
}
