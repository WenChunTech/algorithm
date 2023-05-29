# Definition for singly-linked list.
from typing import Optional


class ListNode:

    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:

    def partition(self, head: Optional[ListNode],
                  x: int) -> Optional[ListNode]:
        lt_head = ListNode()
        lt = lt_head
        bt_head = ListNode()
        bt = bt_head
        while head:
            if head.val < x:
                lt_head.next = head
                lt_head = lt_head.next
            else:
                bt_head.next = head
                bt_head = bt_head.next
            head = head.next

        lt_head.next = bt.next
        bt_head.next = None

        return lt.next


if __name__ == '__main__':
    list1 = ListNode(
        1, ListNode(4, ListNode(3, ListNode(2, ListNode(5, ListNode(2))))))
    result = Solution().partition(list1, 3)
    while result:
        print(result.val)
        result = result.next