#include <stdio.h>
#include "find_value_in_linked_list.h"
#include "cs50.h"
#include "string.h"
#include "node.h"
#include "empty_line.h"

const string WHAT_VALUE_ARE_YOU_LOOKING_FOR_MESSAGE = "What value are you looking for?: ";
const string FOUNDED_HEADER_MESSAGE = "Index. Value - Address in memory";
const string NO_VALUE_IN_LINKED_LIST_MESSAGE = "There is no value that you're looking for.";
const string FOUNDED_MESSAGE_IN_LINKED_LIST = "Founded %i records";

void findValueInLinkedList(node *linkedList){
    const value = getIntFromUser(WHAT_VALUE_ARE_YOU_LOOKING_FOR_MESSAGE);
    
    int findedRecords = 0;
    int i = 0;

    for (node *tmp = linkedList; tmp != NULL; tmp = tmp->next)
    {
        int number = tmp->number;

        if(tmp->number == value) {
            if (findedRecords == 0){
                emptyLine();
                printf(FOUNDED_HEADER_MESSAGE);
                emptyLine();
            }
            
            printf("%i. %i - %p\n", i, number, tmp);
            findedRecords++;
        }

        i++;
    }
    emptyLine();

    if(findedRecords == 0){
        printf(NO_VALUE_IN_LINKED_LIST_MESSAGE);
    } else {
        printf(FOUNDED_MESSAGE_IN_LINKED_LIST, findedRecords);
    }
    
    emptyLine();
}
