class Solution {
public:
    bool isCbt(struct Node* root, int index, int cnt) {
        if (root == NULL) {
            return true;
        }
        if (index >= cnt) {
            return false;
        }
        bool left = isCbt(root->left, 2 * index + 1, cnt);
        bool right = isCbt(root->right, 2 * index + 2, cnt);
        return (left && right);
    }

    int totalCount(struct Node* root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + totalCount(root->left) + totalCount(root->right);
    }

    bool maxOrder(struct Node* root) {
        if (root->left == NULL && root->right == NULL) {
            return true;
        }
        if (root->right == NULL) {
            return (root->data > root->left->data);
        } else {
            bool left = maxOrder(root->left);
            bool right = maxOrder(root->right);
            return (left && right && root->data > root->left->data && root->data > root->right->data);
        }
    }

    bool isHeap(struct Node* tree) {
        int index = 0;
        int cnt = totalCount(tree);
        return isCbt(tree, index, cnt) && maxOrder(tree);
    }
};
