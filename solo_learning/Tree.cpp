#include <iostream>

struct Node {
    char data;
    Node *left = nullptr;
    Node *right = nullptr;
};

class Tree {
public:
    Node *root = nullptr;

    bool isEmpty() {
        return (root == nullptr);
    }

    void init(Node *&tree, char value) {
        if (tree == nullptr) {
            tree = new Node;
            tree->data = value;
        }
    }

    void preOrder(Node *tree) {
        if (tree != nullptr) {
            std::cout << tree->data << " ";
            preOrder(tree->left);
            preOrder(tree->right);
        }
    }

    void inOrder(Node *tree) {
        if (tree != nullptr) {
            inOrder(tree->left);
            std::cout << tree->data << " ";
            inOrder(tree->right);
        }
    }

    void postOrder(Node *tree) {
        if (tree != nullptr) {
            postOrder(tree->left);
            postOrder(tree->right);
            std::cout << tree->data << " ";
        }
    }

    void destroyTree(Node *&tree) {
        if (tree != nullptr) {
            destroyTree(tree->left);
            destroyTree(tree->right);
            delete tree;
            tree = nullptr;
        }
    }
};

int main() {
    Tree baru;
    Node *n = nullptr;
    baru.init(n, 'h');
    baru.init(n->left, 'e');
    baru.init(n->left->left, 'l');
    baru.init(n->right, 'l');
    baru.init(n->right->right, 'o');

    std::cout << "postOrder : ";
    baru.postOrder(n);
    std::cout << "\n";
    std::cout << "inOrder : ";
    baru.inOrder(n);
    std::cout << "\n";
    std::cout << "preOrder : ";
    baru.preOrder(n);

    baru.destroyTree(n);

    return 0;
}
