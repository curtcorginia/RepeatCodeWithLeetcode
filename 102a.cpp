/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <queue>
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> finalVec; //A+ for variable naming descriptiveness
        if(root == NULL)
        {
            return finalVec; //yes, that is an edge case leetcode will check for. they give you nothing
        }
        std::queue<TreeNode*> q1; //again, A+ for descriptiveness...but there is only one here. queues are for bfs
        q1.push(root); //first add the root to the queue
        while(!q1.empty())
        {
            int qSize = q1.size();
            std::vector<int> thisLevel;
            for(int i = 0; i < qSize; i++) //for each element in queue, add left child and right child
            {
                TreeNode* grabThis = q1.front(); //Yes, grabThis is what I chose to call what we pull off queue
                q1.pop(); //remove as well
                thisLevel.push_back(grabThis->val); //above, val is defined per node. a node is just a holder for a value and up to two children
                if(grabThis->left) //if left exists; implicitly, this also validates that grabThis is not null
                    q1.push(grabThis->left);
                if(grabThis->right)
                    q1.push(grabThis->right);
            }
            finalVec.push_back(thisLevel);
        }
        
        return finalVec;
    }
};
