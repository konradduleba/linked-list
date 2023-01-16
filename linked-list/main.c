#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "clear_terminal_window.h"
#include "main_menu.h"
#include "are_strings_the_same.h"
#include "handle_selected_menu_option.h"
#include "string.h"
#include "empty_line.h"

const string THX_FOR_USING_APP = "Thanks for using this app, see you next time";

int main(void)
{
    node *linkedList = NULL;

    node *n = malloc(sizeof(linkedList));

    n->number = 0;
    n->next = NULL;
    n->initialized = true;

    linkedList = n;

    bool isOver = false;

    while(!isOver)
    {
        displayMenuOptions();

        string menuOption = getMenuOption();

        if (areStringsTheSame(menuOption, "CLOSE"))
        {
            cleanTerminalWindow();
            printf(THX_FOR_USING_APP);
            emptyLine();

            return 1;
        }

        handleSelectedMenuOption(menuOption, linkedList);
    }

    return 1;
}

