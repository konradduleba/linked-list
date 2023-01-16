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

void handleSelectedMenuOption(string menuOption, node *linkedList)
{
    cleanTerminalWindow();

    if (areStringsTheSame(menuOption, MENU_ACTION_CREATE)){
        createNewLinkedListNode(linkedList);
        displayLinkedList(linkedList);
    } else if(areStringsTheSame(menuOption, MENU_ACTION_READ)){
        displayLinkedList(linkedList);
    } else if(areStringsTheSame(menuOption, MENU_ACTION_UPDATE)){
        validateOperationOnLinkedList(linkedList, updateLinkedListValue);
    } else if(areStringsTheSame(menuOption, MENU_ACTION_DELETE)){
        validateOperationOnLinkedList(linkedList, deleteLinkedListNode);
    } else {
        noSupportedMenuActionMessage();
    }
}
