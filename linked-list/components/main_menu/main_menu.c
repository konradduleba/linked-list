#include <stdbool.h>

#include "main_menu.h"
#include "string.h"
#include "main_menu_constants.h"
#include "cs50.h"
#include "are_strings_the_same.h"
#include "empty_line.h"

void displayMenuOptions(void)
{
    emptyLine();
    printf(MENU_LIST_MESSAGE);
    emptyLine();

    for (int i = 0; i < MENU_OPTIONS_COUNT; i++)
    {
        printf("%s\n", MENU[i]);
    }

    emptyLine();
}

string getMenuOption(void)
{
    bool isMenuOptionCorrect = false;
    string menuOption = MENU_ACTION_CLOSE;

    while(!isMenuOptionCorrect)
    {
        menuOption = getStringFromUser(MENU_SELECT_OPTION_MESSAGE);

        for (int i = 0; i < MENU_OPTIONS_COUNT; i++)
        {
            string menuAction = MENU_ACTIONS[i];

            if (areStringsTheSame(menuOption, menuAction))
            {
                isMenuOptionCorrect = true;
            }
        }
    }

    return menuOption;
}
