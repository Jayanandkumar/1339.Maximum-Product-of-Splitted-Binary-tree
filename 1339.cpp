class Solution {
public:
    long long totalSumValue = 0;
    long long bestProduct = 0;
    vector<long long> allSums;

    int maxProduct(TreeNode* root) {
        allSums.clear();
        bestProduct = 0;
        totalSumValue = calculateSubtreeSums(root);
        
        for (long long s : allSums) {
            long long currentProduct = s * (totalSumValue - s);
            if (currentProduct > bestProduct) {
                bestProduct = currentProduct;
            }
        }
        
        return bestProduct % 1000000007;
    }

    long long calculateSubtreeSums(TreeNode* node) {
        if (!node) return 0;
        long long currentSum = node->val + calculateSubtreeSums(node->left) + calculateSubtreeSums(node->right);
        allSums.push_back(currentSum);
        return currentSum;
    }
};