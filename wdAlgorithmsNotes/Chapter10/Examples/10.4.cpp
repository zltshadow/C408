/*
* 题目名称：二叉排序树
* 题目来源：华中科技大学复试上机题
* 题目链接：http://t.cn/AiKD0L5V
* 代码作者：zlt_shadow
*/

#include <iostream>
#include <cstdio>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode *leftChild;
    TreeNode *rightChild;
    TreeNode(int x) : data(x), leftChild(NULL), rightChild(NULL) {}
};

TreeNode *Insert(TreeNode *root, int x)
{
    if (root == NULL)
    { //创建新节点
        root = new TreeNode(x);
    }
    else if (x < root->data)
    { //插入左子树
        root->leftChild = Insert(root->leftChild, x);
    }
    else if (root->data < x)
    { //插入右子树
        root->rightChild = Insert(root->rightChild, x);
    }
    return root;
}

void PreOrder(TreeNode *root)
{ //前序遍历
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PreOrder(root->leftChild);
    PreOrder(root->rightChild);
    return;
}

void InOrder(TreeNode *root)
{ //中序遍历
    if (root == NULL)
    {
        return;
    }
    InOrder(root->leftChild);
    cout << root->data << " ";
    InOrder(root->rightChild);
    return;
}

void PostOrder(TreeNode *root)
{ //后序遍历
    if (root == NULL)
    {
        return;
    }
    PostOrder(root->leftChild);
    PostOrder(root->rightChild);
    cout << root->data << " ";
    return;
}

int main()
{
    int n;
    while (cin >> n)
    {
        TreeNode *root = NULL; //建立空树
        for (int i = 0; i < n; ++i)
        { //逐个插入
            int x;
            cin >> x;
            root = Insert(root, x);
        }
        PreOrder(root);
        cout << endl;
        InOrder(root);
        cout << endl;
        PostOrder(root);
        cout << endl;
    }
    return 0;
}
