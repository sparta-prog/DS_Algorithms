#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include<unordered_set>

using namespace std;

/*Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution
{
public:
    void populateParent(TreeNode* node,unordered_map<TreeNode*,TreeNode*>& parent)
    {
        if(node == nullptr)
        {
            return;
        }

        if(node->left)
        {
            parent[node->left] = node;
        }

        if(node->right)
        {
            parent[node->right] = node;
        }

        //call to left and right
        populateParent(node->left,parent);
        populateParent(node->right,parent);
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        if (root == nullptr || target == nullptr)
        {
            return {};
        }

        vector<int> ans;
        unordered_map<TreeNode*,TreeNode*> parent;
        //populate the parent map
        //allows us to go backward
        populateParent(root,parent);

        //go to the target node
        //have to print nodes at a dist k
        //use bfs here
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> visited;
        visited.insert(target);

        while(!q.empty())
        {
            int size = q.size();

            if(k == 0)
            {
                break;
            }

            while(size--)
            {
                TreeNode* top = q.front();
                q.pop();
            //left
                if(top->left != nullptr && visited.count(top->left) == 0)
                {
                    q.push(top->left);
                    visited.insert(top->left);
                }
            //right
                if(top->right != nullptr && visited.count(top->right) == 0)
                {
                    q.push(top->right);
                    visited.insert(top->right);
                }
            //parent
            //some nodes might not have a parent
                if(parent.count(top) != 0 && visited.count(parent[top]) == 0)
                {
                    q.push(parent[top]);
                    visited.insert(parent[top]);
                }
            }
            k--;
        }

        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};

int main() 
{
    Solution sol;

    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node9 = new TreeNode(9);

    // Constructing the binary tree
    node1->left = node2;
    node1->right = node3;

    node2->left = node4;
    node2->right = node5;

    node3->left = node6;
    node3->right = node7;

    node4->left = node8;
    node4->right = node9;

    vector<int> ans = sol.distanceK(node1,node6,2);

    for(auto x: ans) {
        cout<<x<<" ";
    }
}