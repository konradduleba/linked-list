#include <stdbool.h>

#include "can_operate_on_linked_list.h"
#include "node.h"

bool canOperateOnLinkedList(node *linkedList)
{
    return !(linkedList->initialized);
}
