#include"stdio.h"
#include"stdlib.h"
#include"string.h"

// #          A
// #      B       C
// #        D   E
// #       F     G

// # pre: A B D F C E G
// #  in: B F D A E G C


typedef struct BinaryNode
{
    char value;
    struct BinaryNode* lchild, * rchild;
}*BinaryTree, BinaryNode;

BinaryTree rebuild_binarytree(char* pre, int pre_begin, int pre_end, char* in, int in_begin, int in_end) {
    if (pre_begin > pre_end || in_begin > in_end) {
        return NULL;
    }

    char root_value = pre[pre_begin];
    BinaryTree root = (BinaryTree)malloc(sizeof(BinaryNode));
    root->value = root_value;
    root->lchild = NULL;
    root->rchild = NULL;

    // 关键
    if (pre_begin == pre_end || in_begin == in_end) {
        return root;
    }

    int root_index = in_begin;

    // 关键
    while (root_index <= in_end && root_value != in[root_index])
    {
        root_index += 1;
    }

    int node_count = root_index - in_begin;
    root->lchild = rebuild_binarytree(pre, pre_begin + 1, pre_begin + node_count, in, in_begin, root_index - 1);
    root->rchild = rebuild_binarytree(pre, pre_begin + node_count + 1, pre_end, in, root_index + 1, in_end);

    return root;
}

BinaryTree recover_binarytree(char* pre, char* in) {
    if (pre == NULL || in == NULL) {
        return NULL;
    }

    return rebuild_binarytree(pre, 0, strlen(pre) - 1, in, 0, strlen(in) - 1);
}

// 前序遍历
void print_node(BinaryTree root) {
    if (root == NULL)
        return;

    printf("%c", root->value);
    print_node(root->lchild);
    print_node(root->rchild);

}


int main() {
    char pre[] = "ABDFCEG";
    char in[] = "BFDAEGC";
    BinaryTree root = recover_binarytree(pre, in);
    printf("%c, %c\n", root->lchild->value, root->rchild->value);
    print_node(root);
    printf("\n");
}