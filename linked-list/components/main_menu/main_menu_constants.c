#include "main_menu_constants.h"
#include "string.h"

const int MENU_OPTIONS_COUNT = 8;

const string MENU_ACTION_CREATE = "CREATE";
const string MENU_ACTION_READ = "READ";
const string MENU_ACTION_UPDATE = "UPDATE";
const string MENU_ACTION_DELETE = "DELETE";
const string MENU_ACTION_FIND = "FIND";
const string MENU_ACTION_IMPORT = "IMPORT";
const string MENU_ACTION_EXPORT = "EXPORT";
const string MENU_ACTION_CLOSE = "CLOSE";

const string MENU_SELECT_OPTION_MESSAGE = "Select option from the menu above: ";
const string MENU_LIST_MESSAGE = "IN TODAY'S MENU";

const string MENU_ACTIONS[MENU_OPTIONS_COUNT] = {
    MENU_ACTION_CREATE,
    MENU_ACTION_READ,
    MENU_ACTION_UPDATE,
    MENU_ACTION_DELETE,
    MENU_ACTION_FIND,
    MENU_ACTION_IMPORT,
    MENU_ACTION_EXPORT,
    MENU_ACTION_CLOSE,
};

const string MENU[MENU_OPTIONS_COUNT] = {
    "[CREATE] Add new linked list element",
    "[READ] Display linked list",
    "[UPDATE] Update selected element in linked list",
    "[DELETE] Remove selected element from linked list",
    "[FIND] Find value in linked list",
    "[IMPORT] Import linked list from CSV file",
    "[EXPORT] Export linked list into CSV file",
    "[CLOSE] Close the application"
};
