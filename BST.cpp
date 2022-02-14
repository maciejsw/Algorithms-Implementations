#include <iostream>
using namespace std;

struct BST {
        int value;
        BST* left, * right;
};

BST* Insert(BST* root, int value) {
        if (root == nullptr) {
                root = new BST;
                root->value = value;
                root->left = nullptr;
                root->right = nullptr;
                return root;
        }
        else if (value > root->value) root->right = Insert(root->right, value);
        else root->left = Insert(root->left, value);
        return root;
}

BST* Delete(BST* root, int value) {
        if (root == nullptr) return root;
        if (root->value < value) root->right = Delete(root->right, value);
        else if (root->value > value) root->left = Delete(root->left, value);
        else {
                if ((root->left == nullptr) && (root->right == nullptr)) return nullptr;
                else if (root->left == nullptr) {
                        BST* newRoot = root->right;
                        delete root;
                        return newRoot;
                }
                else if ((root->right == nullptr)) {
                        BST* newRoot = root->left;
                        delete root;
                        return newRoot;
                }
                else {
                        BST* newRoot = root->right;
                        while ((newRoot->left) != nullptr) newRoot = newRoot->left;
                        root->value = newRoot->value;
                        root->right = Delete(root->right, newRoot->value);
                }
        }
        return root;
}

BST* Search(BST* root, int value) {
        if ((root == nullptr) || (root->value == value)) return root;
        else if (root->value < value) return Search(root->right, value);
        else return Search(root->left, value);
}

int FindMax(BST* root) {
        if (root == nullptr) return INT_MIN;

        int maxi = root->value;
        //int left = FindMax(root->left);
        int right = FindMax(root->right);
        //if (maxi < left) maxi = left;
        if (maxi < right) maxi = right;
        return maxi;
}

int FindMin(BST* root) {
        if (root == nullptr) return INT_MAX;

        int mini = root->value;
        int left = FindMin(root->left);
        //int right = FindMin(root->right);
        if (mini > left) mini = left;
        //if (mini > right) mini = right;
        return mini;
}

void FreeMemory(BST* root) {
        if (root != nullptr) {
                FreeMemory(root->left);
                FreeMemory(root->right);
                delete(root);
        }
}

int main() {
        BST* root = nullptr, * found = nullptr;
        char command=' ';
        int value;
        
        while (command != 'q') {
                cin >> command;
                switch (command) {
                case '+':
                        cin >> value;
                        root = Insert(root, value);
                        break;
                case '-':
                        cin >> value;
                        root = Delete(root, value);
                        break;
                case '?':
                        cin >> value;
                                found = Search(root, value);
                                if (found == nullptr) cout << "0" << endl;
                                else cout << "1" << endl;
                        break;
                case 'm':
                        if (root == nullptr) cout << "NULL" << endl;
                        else cout << FindMin(root) << endl;
                        break;
                case 'M':
                        if (root == nullptr) cout << "NULL" << endl;
                        else cout << FindMax(root) << endl;
                        break;
                case 'q':
                        break;
                default:
                        cout << "wtf" << endl;
                        break;
                }
        }
        FreeMemory(root);
        //delete found;
        
        return 0;
}
