# Definition for singly-linked list.
class ListNode:

    def __init__(self, x):
        self.val = x
        self.next = None


# 反转链表
# A -> B -> C -> D
def reverse_list(head: ListNode) -> ListNode:
    pre_node = None
    cur_node = head
    next_node = head.next
    while next_node:
        # 指针反转
        cur_node.next = pre_node
        # 指针偏移一位
        pre_node = cur_node
        cur_node = next_node
        next_node = next_node.next

    cur_node.next = pre_node
    return cur_node


def reverse_list_recursive(head: ListNode) -> ListNode:
    if head is None or head.next is None:
        return head

    temp_head = reverse_list_recursive(head.next)
    # head.next == temp_head
    head.next.next = head
    head.next = None

    return temp_head


def print_node(head: ListNode):
    while head:
        print(head.val, end=' ')
        head = head.next
    print()


if __name__ == '__main__':
    first = ListNode(1)
    second = ListNode(2)
    third = ListNode(3)
    forth = ListNode(4)
    fifth = ListNode(5)

    first.next = second
    second.next = third
    third.next = forth
    forth.next = fifth

    # res = reverse_list(first)
    res = reverse_list_recursive(first)
    print_node(res)
