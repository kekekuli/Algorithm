
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return creator(nums, 0, nums.size() - 1);
    }
    TreeNode* creator(vector<int>& nums, int l, int r){
        if(l > r)
            return NULL;
        int max_i = find_max_i(nums, l, r);
        TreeNode *root = new TreeNode(nums[max_i]);
        TreeNode *leftNode = creator(nums, l, max_i - 1);
        TreeNode *rightNode = creator(nums, max_i + 1, r);
        root -> left = leftNode;
        root -> right = rightNode;
        return root;
    }
    int find_max_i(vector<int>&nums, int l, int r){
        int max_i = l;
        for(int i = l; i <= r; i++)
            if(nums[i] > nums[max_i])
                max_i = i;
        return max_i;
    }
};