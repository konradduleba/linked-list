#include "handle_selected_menu_option.h"

#include "string.h"
#include "node.h"
#include "clear_terminal_window.h"
#include "are_strings_the_same.h"
#include "create_new_linked_list_node.h"
#include "update_linked_list_value.h"
#include "delete_linked_list_node.h"
#include "display_linked_list.h"
#include "validate_operation_on_linked_list.h"
#include "no_supported_menu_action_message.h"
#include "main_menu_constants.h"
#include "export_linked_list.h"
#include "import_linked_list.h"
#include "cs50.h"
#include "delete_range_of_linked_list.h"
#include "find_value_in_linked_list.h"
#include "sorting_linked_list.h"

const string SELECT_DELETION_OPTION_MESSAGE = "Choose type of deletion (S) - Single row, (M) - Multiple rows: ";

void handleDeletionOption(node *linkedList)
{
    char deletionOption = getCharFromUser(SELECT_DELETION_OPTION_MESSAGE);
    
    while(deletionOption != 'S' && deletionOption != 'M'){
        deletionOption = getCharFromUser(SELECT_DELETION_OPTION_MESSAGE);
    }
    
    if (deletionOption == 'S'){
        deleteLinkedListNode(linkedList);
    } else {
        deleteRangeOfLinkedListNodes(linkedList);
    }
}

void handleSelectedMenuOption(string menuOption, node *linkedList)
{
    cleanTerminalWindow();

    if (areStringsTheSame(menuOption, MENU_ACTION_CREATE)){
        createNewLinkedListNode(linkedList);
        displayLinkedList(linkedList);
    } else if(areStringsTheSame(menuOption, MENU_ACTION_READ)){
        displayLinkedList(linkedList);
    } else if(areStringsTheSame(menuOption, MENU_ACTION_UPDATE)){
        displayLinkedList(linkedList);
        validateOperationOnLinkedList(linkedList, updateLinkedListValue);
        displayLinkedList(linkedList);
    } else if(areStringsTheSame(menuOption, MENU_ACTION_DELETE)){
        displayLinkedList(linkedList);
        validateOperationOnLinkedList(linkedList, handleDeletionOption);
        displayLinkedList(linkedList);
    } else if(areStringsTheSame(menuOption, MENU_ACTION_FIND)){
        displayLinkedList(linkedList);
        validateOperationOnLinkedList(linkedList, findValueInLinkedList);
    } else if(areStringsTheSame(menuOption, MENU_ACTION_SORT)){
        displayLinkedList(linkedList);
        validateOperationOnLinkedList(linkedList, sortLinkedList);
        displayLinkedList(linkedList);
    } else if(areStringsTheSame(menuOption, MENU_ACTION_IMPORT)){
        importLinkedListFromCSVFile(linkedList);
        displayLinkedList(linkedList);
    } else if(areStringsTheSame(menuOption, MENU_ACTION_EXPORT)){
        displayLinkedList(linkedList);
        validateOperationOnLinkedList(linkedList, exportLinkedListIntoCSVFile);
    } else {
        noSupportedMenuActionMessage();
    }
}
