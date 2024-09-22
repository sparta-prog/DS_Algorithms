#include <iostream>
#include <sstream>
#include <queue>
#include <ctype.h>
#include <iomanip>
using namespace std;

/***
 * Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
 *Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
 ***/

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        // preorder traversal
        if (root == nullptr)
        {
            return "#";
        }

        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }
    // helper function
    TreeNode *util(queue<string> &q)
    {
        if (q.empty())
        {
            return nullptr;
        }

        string el = q.front();
        q.pop();

        if (el == "#")
        {
            return nullptr;
        }
        
        TreeNode *root = new TreeNode(stoi(el));
        root->left = util(q);
        root->right = util(q);

        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        stringstream ss(data);
        string token;
        queue<string> q;

        while (ss >> token)
        {
            q.push(token);
        }

        return util(q);
    }

    int getMaxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        return max(getMaxDepth(root->left), getMaxDepth(root->right)) + 1;
    }

    void print(TreeNode *root)
    {
        if (!root)
            return;

        int depth = getMaxDepth(root);
        int maxWidth = pow(2, depth) - 1; // Maximum width of the tree at its bottom level

        queue<TreeNode *> q;
        q.push(root);

        for (int level = 0; level < depth; ++level)
        {
            int nodesInLevel = pow(2, level);           // Number of nodes in the current level
            int spaceBetween = maxWidth / nodesInLevel; // Space between nodes at this level

            // Print leading spaces
            cout << setw(spaceBetween / 2);

            for (int i = 0; i < nodesInLevel; ++i)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node)
                {
                    cout << node->val;
                    q.push(node->left);
                    q.push(node->right);
                }
                else
                {
                    cout << " "; // Placeholder for null nodes
                    q.push(nullptr);
                    q.push(nullptr);
                }

                // Print space between nodes
                cout << setw(spaceBetween);
            }
            cout << endl; // Move to the next level
        }
    }
};

int main()
{
    Codec obj;

    string data = "1 2 # # 3 4 # # 5 # #";

    TreeNode *root = obj.deserialize(data);

    obj.print(root);
}