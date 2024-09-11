#include <iostream>
#include <vector>

using namespace std;
/*Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//1brute force
class Solution
{
public:
    void preOrder(TreeNode* root,vector<TreeNode*> &nodes) {
        if(root == NULL)
            return;

        nodes.push_back(root);

        preOrder(root->left,nodes);
        preOrder(root->right,nodes);

        return;
    }
    void flatten(TreeNode *root)
    {
        //
        vector<TreeNode*> nodes;

        preOrder(root,nodes);

        int n = nodes.size();

        for(int i=0;i<n-1;i++) {
            nodes[i]->left = NULL;
            nodes[i]->right = nodes[i+1];
        }

        nodes[n-1]->left = NULL;
        nodes[n-1]->right = NULL;
    }
};

//class optimized
class Optimized
{
    TreeNode* prev = nullptr;
public:
    void flatten(TreeNode *root)
    {
        if(root == nullptr) {
            return;
        }

        //go to the right
        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};
int main()
{
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    // Solution sol;
    // sol.flatten(root);

    Optimized obj;
    obj.flatten(root);

    // Traverse the flattened tree
    TreeNode* curr = root;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->right;
    }

    return 0;
}