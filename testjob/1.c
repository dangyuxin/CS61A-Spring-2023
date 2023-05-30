#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

// 实现一个二分查找树
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

// 创建一个节点
Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 插入一个节点
void insertNode(Node *root, int data)
{
    if (root->data > data)
    {
        if (root->left == NULL)
        {
            root->left = createNode(data);
        }
        else
        {
            insertNode(root->left, data);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = createNode(data);
        }
        else
        {
            insertNode(root->right, data);
        }
    }
}

// 中序遍历
void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// 前序遍历
void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// 后序遍历
void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

// 查找一个节点
Node *searchNode(Node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == data)
    {
        return root;
    }
    if (root->data > data)
    {
        return searchNode(root->left, data);
    }
    else
    {
        return searchNode(root->right, data);
    }
}

// 删除一个节点
Node *deleteNode(Node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == data)
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            Node *temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
            return root;
        }
    }
    else if (root->data > data)
    {
        root->left = deleteNode(root->left, data);
        return root;
    }
    else
    {
        root->right = deleteNode(root->right, data);
        return root;
    }
}

// 释放一个二叉树
void freeTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// 编写测试程序
int main()
{
    Node *root = createNode(5);
    insertNode(root, 3);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 4);
    insertNode(root, 6);
    insertNode(root, 8);
    printf("中序遍历：");
    inOrder(root);
    printf("\n");
    printf("前序遍历：");
    preOrder(root);
    printf("\n");
    printf("后序遍历：");
    postOrder(root);
    printf("\n");
    printf("查找节点：");
    Node *node = searchNode(root, 7);
    printf("%d\n", node->data);
    printf("删除节点：");
    root = deleteNode(root, 7);
    inOrder(root);
    printf("\n");
    freeTree(root);
    return 0;
}

// c语言标准库都有哪些
// stdio.h
// stdlib.h
// string.h
// math.h
// time.h
// ctype.h
// assert.h
// stdarg.h
// errno.h
// float.h
// limits.h
// locale.h
// setjmp.h
// signal.h
// stddef.h

// 如何理解c语言的指针
// 指针是一个变量，其值为另一个变量的地址，即，内存位置的直接地址。就像其他变量或常量一样，必须在使用指针存储其他变量地址之前，对其进行声明。指针变量声明的一般形式为：type *var-name;在这里，type 是指针的基类型，它必须是一个有效的 C 数据类型，var-name 是指针变量的名称。用来声明指针的星号 * 与乘法中使用的星号是相同的。但是，在这个语句中，星号是用来指定一个变量是指针。以下是有效的指针声明：int *ip;    /* 一个整型的指针 */double *dp; /* 一个 double 型的指针 */float *fp;  /* 一个浮点型的指针 */char *ch     /* 一个字符型的指针 */
