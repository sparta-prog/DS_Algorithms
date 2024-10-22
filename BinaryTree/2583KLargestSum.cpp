#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root == nullptr)
            return 0;

        int levelCount = 0;
        long long levelSum = 0;
        queue<TreeNode*> q;
        q.push(root);

        priority_queue<long long> maxLvlSum;

        while(!q.empty())
        {
            int lvlSize = q.size();
            levelSum = 0;
            while(lvlSize--) 
            {
                TreeNode* frontNode = q.front();
                q.pop();

                levelSum += (long long)frontNode->val;

                if(frontNode->left) {
                    q.push(frontNode->left);
                }
                if(frontNode->right) {
                    q.push(frontNode->right);
                }
            }
            maxLvlSum.push(levelSum);
            levelCount++;
        }

        if(levelCount < k)
        {
            return -1;
        }

        long long reqdSum = 0;
        
        while(k--) {
            reqdSum = maxLvlSum.top();
            maxLvlSum.pop();
        }

        return reqdSum;
    }
};

int main() 
{
    TreeNode * head = new TreeNode(5);
    head->left = new TreeNode(8);
    head->right = new TreeNode(9);

    head->left->left = new TreeNode(2);
    head->left->right = new TreeNode(1);

    head->left->left->left = new TreeNode(4);
    head->left->left->right = new TreeNode(6);

    head->right->left = new TreeNode(3);
    head->right->right = new TreeNode(7);

    Solution obj;
    int k = 2;

    cout<<obj.kthLargestLevelSum(head,k);

}