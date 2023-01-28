#include "filter_linked_list.h"
#include "string.h"
#include "node.h"
#include "cs50.h"
#include "empty_line.h"

const string INSERT_FIRST_VALUE_MESSAGE = "First value: ";
const string INSERT_SECOND_VALUE_MESSAGE = "Second value: ";
const string FILTERED_HEADER_MESSAGE = "Index. Value - Address in memory";
const string FOUNDED_FILTERED_VALUES_MESSAGE = "Founded %i values";
const string NO_FOUNDED_FILTERED_VALUES_MESSAGE = "Not founded any value";

void filterLinkedList(node *linkedList){
    int firstValue = getIntFromUser(INSERT_FIRST_VALUE_MESSAGE);
    int secondValue = getIntFromUser(INSERT_SECOND_VALUE_MESSAGE);
    
    int lowerValue = firstValue < secondValue ? firstValue : secondValue;
    int higherValue = firstValue > secondValue ? firstValue : secondValue;
    
    int i = 0;
    int foundedValuesCount = 0;
    
    printf(FILTERED_HEADER_MESSAGE);
    emptyLine();

    for (node *tmp = linkedList; tmp != NULL; tmp = tmp->next)
    {
        int number = tmp->number;
        
        if (number >= lowerValue && number <= higherValue){
            printf("%i. %i - %p\n", i, number, tmp);
            foundedValuesCount++;
        }

        i++;
    }
    
    emptyLine();
    
    if (foundedValuesCount){
        printf(FOUNDED_FILTERED_VALUES_MESSAGE, foundedValuesCount);
    } else {
        printf(NO_FOUNDED_FILTERED_VALUES_MESSAGE);
    }
    
    emptyLine();
}
