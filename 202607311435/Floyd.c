#include <stdlib.h>
#include <stdio.h>

typedef int elemType;
typedef struct nodeList
{
    elemType data;
    struct nodeList *next;
} nodeList, *NodeList;
nodeList *initCycle();
void freeNodeList(nodeList *a);
void Floyd()
{
    nodeList *c = initCycle();
    // 确定环存在
    nodeList *slow = c->next;
    nodeList *fast = c->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            printf("has cycle");
            break;
        }
    }
    if (!fast || !fast->next)
    {
        printf("no cycle");
        return;
    }
    // 确定环起点
    slow = c->next;
    while (slow != fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    printf("\ncycle start at %d", slow->data);
    freeNodeList(c);
}

int main()
{
    Floyd();
    return 0;
}

void freeNodeList(nodeList *a)
{
    // 确定环起点，断开环，再释放内存
}
nodeList *initCycle()
{
    nodeList *c = (nodeList *)malloc(sizeof(nodeList));
    c->next = NULL;
    nodeList *enter;
    nodeList *trail;

    for (int i = 8; i >= 0; i--)
    {
        nodeList *p = (nodeList *)malloc(sizeof(nodeList));
        p->data = i;
        p->next = c->next;
        c->next = p;
        if (i == 8)
            trail = p; // 尾部为null
        if (i == 3)
            enter = p;
    }
    trail->next = enter; // 闭合

    return c;
}