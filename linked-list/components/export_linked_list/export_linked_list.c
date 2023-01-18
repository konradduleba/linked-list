#include <stdio.h>
#include <string.h>

#include "export_linked_list.h"
#include "node.h"
#include "string.h"
#include "get_string_from_user.h"
#include "empty_line.h"

const string INPUT_FILE_NAME = "How do you wanna name the CSV file? ";
const string SUCCESSFULL_EXPORTION = "Linked list have been exported successfully";

void exportLinkedListIntoCSVFile(node *linkedList){
    string fileName = getStringFromUser(INPUT_FILE_NAME);
    
    FILE *fpt;
    
    string fileNameWithExtension = strcat(fileName,".csv");
    
    fpt = fopen(fileNameWithExtension, "w+");
    
    fprintf(fpt,"Index, Value, Address in memory\n");
    
    int i = 0;

    for (node *tmp = linkedList; tmp != NULL; tmp = tmp->next)
    {
        int number = tmp->number;

        fprintf(fpt,"%i, %i, %p\n", i, number, tmp);

        i++;
    }
    
    fclose(fpt);
    
    printf(SUCCESSFULL_EXPORTION);
    emptyLine();
}
