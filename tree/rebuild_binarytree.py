#          A
#      B       C
#        D   E
#       F     G

# pre: A B D F C E G
#  in: B F D A E G C

from typing import List


class BinaryTree:

    def __init__(self, value: int) -> None:
        self.value = value
        self.lchild = None
        self.rchild = None


def recover_binarytree(preorder: List[str], inorder: List[str]) -> BinaryTree:
    if not (preorder and inorder):
        return

    return rebuild_binarytree(preorder, 0,
                              len(preorder) - 1, inorder, 0,
                              len(inorder) - 1)


def rebuild_binarytree(
    preorder: List[str],
    preorder_begin: int,
    preorder_end: int,
    inorder: List[str],
    inorder_begin: int,
    inorder_end: int,
) -> BinaryTree:
    if preorder_begin > preorder_end or inorder_begin > inorder_end:
        return None

    root_value = preorder[preorder_begin]
    root_node = BinaryTree(root_value)
    if preorder_begin == preorder_end or inorder_begin == inorder_end:
        return root_node

    root_inorder = inorder_begin
    while root_inorder <= inorder_end and inorder[root_inorder] != root_value:
        root_inorder += 1

    left_count = root_inorder - inorder_begin
    root_node.lchild = rebuild_binarytree(preorder, preorder_begin + 1,
                                          preorder_begin + left_count, inorder,
                                          inorder_begin, root_inorder - 1)

    root_node.rchild = rebuild_binarytree(preorder,
                                          preorder_begin + left_count + 1,
                                          preorder_end, inorder,
                                          root_inorder + 1, inorder_end)

    return root_node


if __name__ == "__main__":
    preorder = ['A', 'B', 'D', 'F', 'C', 'E', 'G']
    inorder = ['B', 'F', 'D', 'A', 'E', 'G', 'C']
    root = recover_binarytree(preorder, inorder)
    print(root)