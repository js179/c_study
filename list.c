#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

typedef struct List
{
    char data[20];
    int length;
    struct List *next;
} List;

// 当前长度
int len(List *head)
{
    return head == NULL ? 0 : head->length;
}

// 是否为空, 长度为0
bool isEmpty(List *head)
{
    return len(head) > 0;
}

// 初始化
List *newList(char *data)
{
    List *l = malloc(sizeof(List));
    strcpy(l->data, data);
    l->next = NULL;
    l->length = 1;
    return l;
}

// 左插
void ladd(List **head, char *data)
{
    List *l = malloc(sizeof(List));
    strcpy(l->data, data);
    l->next = *head;
    l->length = (*head)->length;
    *head = l;
    ++((*head)->length);
}

// 右插
void radd(List **head, char *data)
{
    List *r = (*head);
    while (r->next)
    {
        r = r->next;
    }
    List *val = malloc(sizeof(List));
    strcpy(val->data, data);
    val->next = NULL;
    r->next = val;
    ++((*head)->length);
}

// 删除指定元素
void delete(List **head, char *data)
{
    List *p = (*head);
    if (strcmp(p->data, data) == 0)
    {
        (*head)->next->length = --((*head)->length);
        (*head) = (*head)->next;
    }
    else
    {
        while (p->next)
        {
            if (strcmp((p->next)->data, data) == 0)
            {
                p->next = p->next->next;
                --((*head)->length);
                break;
            }
            p = p->next;
        }
    }
}

// 遍历
void print(List *head)
{
    int num = 0, length = len(head);
    while (head)
    {
        printf("List[%d] = %s\n", num++, head->data);
        head = head->next;
    }
}

int main()
{
    List *head = newList("first");
    printf("head is null? ");
    isEmpty(head) == 0 ? printf("true\n") : printf("false\n");
    ladd(&head, "1");
    ladd(&head, "2");
    ladd(&head, "3");
    ladd(&head, "4");
    ladd(&head, "5");
    radd(&head, "11");
    radd(&head, "12");
    radd(&head, "13");
    radd(&head, "14");

    printf("len = %d\n", len(head));

    delete (&head, "5");
    printf("***after delete***\n");
    printf("len = %d\n", len(head));

    delete (&head, "14");
    printf("***after delete***\n");
    printf("len = %d\n", len(head));

    radd(&head, "15");
    printf("***after add***\n");
    printf("len = %d\n", len(head));

    print(head);

    return 0;
}