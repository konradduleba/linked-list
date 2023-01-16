#include <stdbool.h>
#include <string.h>

#include "are_strings_the_same.h"
#include "string.h"

bool areStringsTheSame(string firstWord, string secondWord)
{
    return !strcmp(firstWord, secondWord);
}
