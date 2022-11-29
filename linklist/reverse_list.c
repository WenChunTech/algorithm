#include"stdio.h"
#include"stdlib.h"

typedef struct Node
{
    int val;
    struct Node* next;
}Node, * ListNode;

ListNode reverse_list(ListNode head) {

    ListNode pre_node = (ListNode)malloc(sizeof(Node));
    ListNode cur_node = (ListNode)malloc(sizeof(Node));
    ListNode next_node = (ListNode)malloc(sizeof(Node));

    pre_node = NULL;
    cur_node = head;
    next_node = head->next;

    while (next_node != NULL)
    {
        cur_node->next = pre_node;
        pre_node = cur_node;
        cur_node = next_node;
        next_node = next_node->next;
    }

    cur_node->next = pre_node;
    return cur_node;
}

ListNode reverse_list_recursive(ListNode head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode temp_node = reverse_list_recursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return temp_node;
}


void print_node(ListNode head) {
    while (head)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    ListNode first, second, third, forth, fifth;
    first = (ListNode)malloc(sizeof(Node));
    second = (ListNode)malloc(sizeof(Node));
    third = (ListNode)malloc(sizeof(Node));
    forth = (ListNode)malloc(sizeof(Node));
    fifth = (ListNode)malloc(sizeof(Node));

    first->val = 1;
    first->next = second;

    second->val = 2;
    second->next = third;

    third->val = 3;
    third->next = forth;

    forth->val = 4;
    forth->next = fifth;

    fifth->val = 5;
    fifth->next = NULL;

    // ListNode res = reverse_list(first);
    ListNode res = reverse_list_recursive(first);
    print_node(res);
}