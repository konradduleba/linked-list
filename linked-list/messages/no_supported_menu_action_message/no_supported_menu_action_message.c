#include "no_supported_menu_action_message.h"
#include "string.h"
#include "empty_line.h"

const string NO_SUPPORTED_MENU_ACTION_MESSAGE = "NO SUPPORTED MENU ACTION! ";

void noSupportedMenuActionMessage(void)
{
    printf(NO_SUPPORTED_MENU_ACTION_MESSAGE);
    emptyLine();
}
