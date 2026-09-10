---
time: 2026-07-31 14:35
photos:
draft: false
---

`Floyd 判圈算法`是用于判断链表中有无环以及检测环入点的经典算法。

它利用了快慢指针的思想，以及环无终点，快慢指针互相追逐，相遇即环存在，再移动一个指针到头部，两指针再每次移动1结点，第二次相遇即得环起点。

<div style="width: 100%; aspect-ratio: 16 / 9; overflow: hidden;">
<video width="100%" controls src="assets/2026-07-31_14-34-16.mp4" title="Title"></video>
</div>

在线玩：[cycle.html](/moments/202607311435/cycle.html)

<details>
<summary>code</summary>

```c
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
```

</details>
<details>
<summary>output</summary>

```bash
❮cmd❯  …\pblog  main [  ✓] via  v22.22.2 via  v3.14.5
の a
has cycle
cycle start at 3
```

</details>
