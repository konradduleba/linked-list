#include <string.h>
#include <stdlib.h>

#include "import_linked_list.h"
#include "get_string_from_user.h"
#include "get_int_from_user.h"
#include "create_new_linked_list_node.h"
#include "empty_line.h"
#include "are_strings_the_same.h"

const string GET_CSV_FILE_NAME_FROM_USER_MESSAGE = "Name of the file: ";
const string TROUBLE_READING_FILE_MESSAGE = "Trouble reading file";
const string DOES_CSV_CONTAINS_HEADER_MESSAGE = "Does your CSV file contains header? Y/N ";
const string NUMBER_OF_IMPORTED_LINES = "Number of imported lines: %i\n";

const int MAX_CHARACTERS_IN_ONE_LINE = 100;

void importLinkedListFromCSVFile(node *linkedList){
    string fileName = getStringFromUser(GET_CSV_FILE_NAME_FROM_USER_MESSAGE);
    string withHeader = getStringFromUser(DOES_CSV_CONTAINS_HEADER_MESSAGE);
    
    while(!areStringsTheSame(withHeader, "Y") && !areStringsTheSame(withHeader, "N")){
        withHeader = getStringFromUser(DOES_CSV_CONTAINS_HEADER_MESSAGE);
    }

    int linesToRemove = areStringsTheSame(withHeader, "Y");
    
    FILE *fpt;
    
    string fileNameWithExtension = strcat(fileName,".csv");
    
    fpt = fopen(fileNameWithExtension, "r");
    
    if (fpt == NULL) {
        printf(TROUBLE_READING_FILE_MESSAGE);
        exit(0);
    }
    
    char line[MAX_CHARACTERS_IN_ONE_LINE];
    
    int lineNumber = 0;
    int importedLinkedListValue;
    
    char *linePointer;
    
    while(fgets(line, MAX_CHARACTERS_IN_ONE_LINE, fpt) != NULL){
        if(linesToRemove && !lineNumber){
            lineNumber++;
            continue;
        }
        linePointer = strtok(line, ",");
        linePointer = strtok(NULL, ",");
        
        importedLinkedListValue = atoi(linePointer);

        addNewValueToTheLinkedList(linkedList, importedLinkedListValue);

        lineNumber++;
    }

    emptyLine();
    printf(NUMBER_OF_IMPORTED_LINES, lineNumber - linesToRemove);
    emptyLine();
    
    fclose(fpt);
}
