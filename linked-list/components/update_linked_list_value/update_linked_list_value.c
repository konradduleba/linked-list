#include "update_linked_list_value.h"
#include "get_int_from_user.h"
#include "node.h"
#include "string.h"

const string SELECT_INDEX_TO_UPDATE_MESSAGE = "Select index to update: ";
const string INSERT_NEW_NUMERIC_VALUE_MESSAGE = "Insert new numeric value: ";

void updateLinkedListValue(node *linkedList)
{
    int indexToUpdate = getIntFromUser(SELECT_INDEX_TO_UPDATE_MESSAGE);
    int newUserValue = getIntFromUser(INSERT_NEW_NUMERIC_VALUE_MESSAGE);

    int i = 0;

    for (node *tmp = linkedList; tmp != NULL; tmp = tmp->next)
    {
        if (i == indexToUpdate)
        {
            tmp->number = newUserValue;
            break;
        }

        i++;
    }
}
