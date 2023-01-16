#include "validate_operation_on_linked_list.h"
#include "can_operate_on_linked_list.h"
#include "display_linked_list.h"
#include "can_not_operate_on_empty_list_message.h"
#include "node.h"

void validateOperationOnLinkedList(node *linkedList, void (*operation)(node *linkedList))
{
    if (canOperateOnLinkedList(linkedList)){
        displayLinkedList(linkedList);
        operation(linkedList);
        displayLinkedList(linkedList);
    } else {
        canNotOperateOnEmptyListMessage();
    }
}
