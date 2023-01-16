#include "main_menu_constants.h"
#include "string.h"

const int MENU_OPTIONS_COUNT = 5;

const string MENU_ACTION_CREATE = "CREATE";
const string MENU_ACTION_READ = "READ";
const string MENU_ACTION_UPDATE = "UPDATE";
const string MENU_ACTION_DELETE = "DELETE";
const string MENU_ACTION_CLOSE = "CLOSE";

const string MENU_SELECT_OPTION_MESSAGE = "Select option from the menu above: ";
const string MENU_LIST_MESSAGE = "IN TODAY'S MENU";

const string MENU_ACTIONS[MENU_OPTIONS_COUNT] = {
    MENU_ACTION_CREATE,
    MENU_ACTION_READ,
    MENU_ACTION_UPDATE,
    MENU_ACTION_DELETE,
    MENU_ACTION_CLOSE,
};

const string MENU[MENU_OPTIONS_COUNT] = {
    "[CREATE] Add new linked list element",
    "[READ] Display linked list",
    "[UPDATE] Update selected element in linked list",
    "[DELETE] Remove selected element from linked list",
    "[CLOSE] Close the application"
};
