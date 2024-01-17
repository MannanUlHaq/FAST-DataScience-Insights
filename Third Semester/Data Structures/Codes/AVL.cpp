#include <iostream>
#include<queue>
using namespace std;

class TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
        height = 1;
    }

    friend class AVLTree;
};

class AVLTree
{
    TreeNode* root;

    int getHeight(TreeNode* node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int getBalanceFactor(TreeNode* node)
    {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    TreeNode* leftRotate(TreeNode* x)
    {
        TreeNode* temp1 = x->right;
        TreeNode* temp2 = temp1->left;

        temp1->left = x;
        x->right = temp2;

        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        temp1->height = 1 + max(getHeight(temp1->left), getHeight(temp1->right));

        return temp1;
    }

    TreeNode* rightRotate(TreeNode* y)
    {
        TreeNode* temp1 = y->left;
        TreeNode* temp2 = temp1->right;

        temp1->right = y;
        y->left = temp2;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        temp1->height = 1 + max(getHeight(temp1->left), getHeight(temp1->right));

        return temp1;
    }

    TreeNode* Insert(TreeNode* node, int data)
    {
        if (node == nullptr)
            return new TreeNode(data);
         
        if (data < node->data)
            node->left = Insert(node->left, data);
        else if (data > node->data)
            node->right = Insert(node->right, data);
        else
            return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalanceFactor(node);

        // Left heavy
        if (balance > 1)
        {
            if (data < node->left->data)
                return rightRotate(node);
            else
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }

        // Right heavy
        if (balance < -1)
        {
            if (data > node->right->data)
                return leftRotate(node);
            else
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }

        return node;
    }

    void levelorderPrintHelper(TreeNode* currNode)
    {
        if (currNode == nullptr)
            return;

        queue<TreeNode*> q;
        q.push(currNode);

        while (!q.empty())
        {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i)
            {
                TreeNode* node = q.front();
                q.pop();
                cout << node->data << " ";

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            cout << endl;
        }
    }

public:
    AVLTree()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        root = Insert(root, value);
    }

    void levelorderPrint()
    {
        levelorderPrintHelper(root);
    }
};

int main()
{
    AVLTree avl;

    avl.insert(50);
    avl.insert(17);
    avl.insert(76);
    avl.insert(9);
    avl.insert(23);
    avl.insert(54);
    avl.insert(14);
    avl.insert(19);
    avl.insert(72);
    avl.insert(12);
    avl.insert(67);

    cout << "Level-order traversal of AVL Tree after converting from BST: " << endl;
    avl.levelorderPrint();

    return 0;
}