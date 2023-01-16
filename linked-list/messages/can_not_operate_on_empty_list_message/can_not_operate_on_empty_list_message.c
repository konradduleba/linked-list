#include "can_not_operate_on_empty_list_message.h"
#include "string.h"
#include "empty_line.h"

const string CAN_NOT_OPERATE_ON_EMPTY_LINKED_LIST_MESSAGE = "You can not operate on empty linked list!";

void canNotOperateOnEmptyListMessage(void)
{
    printf(CAN_NOT_OPERATE_ON_EMPTY_LINKED_LIST_MESSAGE);
    emptyLine();
}
