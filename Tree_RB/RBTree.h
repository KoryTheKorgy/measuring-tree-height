#ifndef RED_BLACK_TREE_RBTREE_H
#define RED_BLACK_TREE_RBTREE_H

using namespace std;

enum Color {RED, BLACK, DOUBLE_BLACK};


template <typename T>
class Node
{
    public:
        T data;
        int color;
        Node<T> *left, *right, *parent;
        explicit Node(T);
};

template <typename T>
class RBTree
{
    private:
        Node<T> *root;
    protected:
        void rotateLeft(Node<T> *&);
        void rotateRight(Node<T> *&);
        void fixInsertRBTree(Node<T> *&);
        int getColor(Node<T> *&);
        void setColor(Node<T> *&, int);
        Node<T> *insertBST(Node<T> *&, Node<T> *&);
        int getBlackHeight(Node<T> *);
        int maxDepthUtil(Node<T> *);
    public:
        RBTree();
        void insertValue(T);
        int maxDepth();
};

template <typename T>
Node<T>::Node(T data) {
    this->data = data;
    color = RED;
    left = right = parent = nullptr;
}

template <typename T>
RBTree<T>::RBTree() {
    root = nullptr;
}

template <typename T>
int RBTree<T>::getColor(Node<T> *&node) {
    if (node == nullptr)
        return BLACK;

    return node->color;
}

template <typename T>
void RBTree<T>::setColor(Node<T> *& node, int color) {
    if (node == nullptr)
        return;

    node->color = color;
}

template <typename T>
Node<T>* RBTree<T>::insertBST(Node<T> *& root, Node<T> *&ptr) {
    if (root == nullptr)
        return ptr;
    if (ptr->data < root->data) {
        root->left = insertBST(root->left, ptr);
        root->left->parent = root;
    } else if (ptr->data > root->data) {
        root->right = insertBST(root->right, ptr);
        root->right->parent = root;
    }
    return root;
}

template <typename T>
void RBTree<T>::insertValue(T n) {
    Node<T> *node = new Node<T>(n);
    root = insertBST(root, node);
    fixInsertRBTree(node);
}

template <typename T>
void RBTree<T>::rotateLeft(Node<T> *&ptr) {
    Node<T> *right_child = ptr->right;
    ptr->right = right_child->left;

    if (ptr->right != nullptr)
        ptr->right->parent = ptr;

    right_child->parent = ptr->parent;

    if (ptr->parent == nullptr)
        root = right_child;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = right_child;
    else
        ptr->parent->right = right_child;

    right_child->left = ptr;
    ptr->parent = right_child;
}

template <typename T>
void RBTree<T>::rotateRight(Node<T> *&ptr) {
    Node<T> *left_child = ptr->left;
    ptr->left = left_child->right;

    if (ptr->left != nullptr)
        ptr->left->parent = ptr;

    left_child->parent = ptr->parent;

    if (ptr->parent == nullptr)
        root = left_child;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = left_child;
    else
        ptr->parent->right = left_child;

    left_child->right = ptr;
    ptr->parent = left_child;
}

template <typename T>
void RBTree<T>::fixInsertRBTree(Node<T> *&ptr) {
    Node<T> *parent = nullptr;
    Node<T> *grandparent = nullptr;
    while (ptr != root && getColor(ptr) == RED && getColor(ptr->parent) == RED) {
        parent = ptr->parent;
        grandparent = parent->parent;
        if (parent == grandparent->left) {
            Node<T> *uncle = grandparent->right;
            if (getColor(uncle) == RED) {
                setColor(uncle, BLACK);
                setColor(parent, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            } else {
                if (ptr == parent->right) {
                    rotateLeft(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateRight(grandparent);
                swap(parent->color, grandparent->color);
                ptr = parent;
            }
        } else {
            Node<T> *uncle = grandparent->left;
            if (getColor(uncle) == RED) {
                setColor(uncle, BLACK);
                setColor(parent, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            } else {
                if (ptr == parent->left) {
                    rotateRight(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateLeft(grandparent);
                swap(parent->color, grandparent->color);
                ptr = parent;
            }
        }
    }
    setColor(root, BLACK);
}

template <typename T>
int RBTree<T>::getBlackHeight(Node<T> *node) {
    int blackheight = 0;
    while (node != nullptr) {
        if (getColor(node) == BLACK)
            blackheight++;
        node = node->left;
    }
    return blackheight;
}

template <typename T>
int RBTree<T>::maxDepthUtil(Node<T> *node){
    if (node == NULL)
        return 0;
    else {
        int lDepth = maxDepthUtil(node->left);
        int rDepth = maxDepthUtil(node->right);
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

template <typename T>
int RBTree<T>::maxDepth(){
    return maxDepthUtil(root);
}

#endif //RED_BLACK_TREE_RBTREE_H