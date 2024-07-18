#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<unordered_map>
#include<queue>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)return NULL;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
//class Solution {
//public:
//    vector<vector<int>> levelOrder(TreeNode* root) {
//        queue<TreeNode* >q;
//        vector<vector<int>>res;
//        TreeNode* cur = root;
//        q.push(root);
//        while (cur && !q.empty()) {
//            int size = q.size();
//            vector<int>temp;
//            while (size--) {
//                TreeNode* node = q.front();
//                q.pop();
//                if (node)
//                {
//                    temp.push_back(node->val);
//                    if (node->left) q.push(node->left);
//                    if (node->right) q.push(node->right);
//                }
//            }
//            res.push_back(temp);
//        }
//        return res;
//    }
//};
//102.二叉树的层序遍历
//107.二叉树的层次遍历II
//199.二叉树的右视图
//637.二叉树的层平均值
//429.N叉树的前序遍历
//515.在每个树行中找最大值
//116.填充每个节点的下一个右侧节点指针
//117.填充每个节点的下一个右侧节点指针II
//104.二叉树的最大深度
//111.二叉树的最小深度
//
//作者：代码随想录
//链接：https ://leetcode.cn/problems/binary-tree-level-order-traversal/solutions/859716/dai-ma-sui-xiang-lu-er-cha-shu-ceng-xu-b-zhun/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
//class Solution {
//public:
//    vector<int> inorderTraversal(TreeNode* root) {
//        vector<int>res;
//        stack<TreeNode*>st;
//        TreeNode* current = root;
//        while (current != NULL || !st.empty()) {
//            if (current != NULL) {
//                st.push(current);
//                current = current->left;
//            }
//            else {
//                current = st.top();
//                st.pop();
//                res.push_back(current->val);
//                current = current->right;
//            }
//        }
//        return res;
//    }
//};
//class Solution {
//public:
//    vector<int> topKFrequent(vector<int>& nums, int k) {
//        unordered_map<int, int>hash;
//        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> res2;
//        vector<pair<int, int>>res;
//        vector<int>result;
//        for (auto i : nums) {
//            hash[i]++;
//        }
//        for (auto i : hash) {
//            res2.push({ i.second, i.first });
//            if (res2.size() > k)
//                res2.pop();
//        }
//        while (k--) {
//            result.push_back(res2.top().second);
//            res2.pop();
//        }
//        return result;
//    }
//};
 
//class Solution {
//public:
//    vector<int>res;
//    void traversal(TreeNode* head) {
//        if (head != NULL) {
//            res.push_back(head->val);
//            traversal(head->left);
//            traversal(head->right);
//        }
//    }
//    vector<int> preorderTraversal(TreeNode* root) {
//        traversal(root);
//        return res;
//    }
//};