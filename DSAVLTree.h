//
// Created by mikec_g1kgiu8 on 11/9/2021.
//

#ifndef INC_21F_FINAL_PROJ_TEMPLATE_DSAVLTREE_H
#define INC_21F_FINAL_PROJ_TEMPLATE_DSAVLTREE_H

#include <stdexcept>
#include <iostream>
#include <ostream>
#include <queue>
#include <fstream>

using namespace std;
/// A templated AVL tree with an AVLNode class within.
///
/// A templated AVL tree with functions to insert, search for, and delete elements.
/// @tparam K The type of the key
/// @tparam V The type of the value
template <typename K, typename V>
class DSAVLTree {
    private:

    ///A templated AVL node within the AVLTree.
    ///
    ///A templated AVL node that contains a key-value pair.
    class DSAVLNode {
    public:

        ///The main data of each AVL node.
        ///
        ///The main data of each AVL node that contains a key-value pair.
        struct nodeElement { //the key value pair of the data
            K key;
            V value;
        };

        nodeElement data;
        DSAVLNode* left;
        DSAVLNode* right;
        int height;

        ///Default Constructor.
        ///
        ///Initializes data, left, and right to nullptr, and set height = 0.
        DSAVLNode() {
            data = nullptr;
            left = nullptr;
            right = nullptr;
            height = 0;
        }

        /// Overloaded Constructor.
        ///
        /// Initializes the data's key, left, right, and height to the values passed to it
        /// @param theKey The key value that is to be copied.
        /// @param lt The left node pointer that is to be copied.
        /// @param rt The right node pointer that is to be copied.
        /// @param h The height of the node that is to be copied.
        DSAVLNode(const K& theKey, DSAVLNode* lt, DSAVLNode *rt, int h = 0 ) {
            data.key = theKey;
            left = lt;
            right = rt;
            height = h;
        }

    };

        DSAVLTree::DSAVLNode* root;

        //Private Functions
        /// Returns the height of the node.
        ///
        /// Returns the height of the node (or -1 if the node is a leaf node)
        /// @param node The node whose height is to be returned
        /// @return The height of the tree
        int height(DSAVLTree::DSAVLNode* node);

        /// Inner, recursive insert function.
        ///
        /// Inner, recursive insert function that inserts a new element into the tree.
        /// @param x The key that is to be inserted into the tree.
        /// @param t The current AVL Node that is being looked at.
        /// @return The associated value of the key that was passed to the function (the value is passed by reference so it can be changed).
        V& insert(const K&x, DSAVLTree::DSAVLNode *&t);

        /// Balances the AVL tree.
        ///
        /// Balances the AVL tree by calling the different rotation functions depending on the difference in heights between nodes.
        ///@param t The current nod that is being checked.
        void balance(DSAVLTree::DSAVLNode *&t);

        /// Inner, recursive find function.
        ///
        /// Finds the key passed to it and returns its associated value. If the key is not found in the AVL tree, then a runtime error is thrown.
        /// @param arg The key that is being searched for.
        /// @param t The current AVL Node being checked.
        /// @return The value associated with the passed along key.
        V& find(const K& arg, DSAVLTree::DSAVLNode*& t);

        /// Balances the tree when an imbalance occurs at the left subtree of the left child.
        ///
        /// Rotates the imbalanced node with its left child to achieve balance.
        /// @param k2 The imbalanced node.
        void rotateWithLeftChild(DSAVLTree::DSAVLNode*& k2);

        /// Balances the tree when an imbalance occurs at the right subtree of the left child.
        ///
        /// Rotates the imbalanced node's left child with the left child's right child. Then rotates the imbalanced node with its new left child.
        /// @param k3 The imbalanced node.
        void doubleWithLeftChild(DSAVLTree::DSAVLNode*& k3);

        /// Balances the tree when an imbalance occurs at the right subtree of the right child.
        ///
        /// Rotates the imbalanced node with its right child to achieve balance.
        /// @param k2 The imbalanced node.
        void rotateWithRightChild(DSAVLTree::DSAVLNode*& k2);

        /// Balances the tree when an imbalance occurs at the left subtree of the right child.
        ///
        /// Rotates the imbalanced node's right child with the right child's left child. Then rotates the imbalanced node with its new right child.
        /// @param k3 The imbalanced node.
        void doubleWithRightChild(DSAVLTree::DSAVLNode*& k3);

        /// Deletes the AVL tree.
        ///
        /// Iterates through the entire AVL tree and deletes every node.
        /// @param n The current node being viewed.
        void deleteTree(DSAVLNode*& n);

        /// Copies the AVL tree to another AVL tree.
        ///
        /// Iterates through the entire AVL tree and inserts its values into another AVL tree.
        /// @param argNode The current node being viewed.
        void copyNodes(DSAVLNode* argNode);

        /// Iterates over the entire AVLTree and counts the number of nodes.
        ///
        /// Iterates over the entire AVLTree, incrementing nodeCount by 1 for every node it finds.
        /// @param n The current AVLNode being looked at.
        void inOrder(DSAVLNode* n);

        /// Writes the contents of the AVLTree to a persistence file.
        ///
        /// Writes the contents of the AVLTree to a persistence file, which is then stored in memory (in the form of a .txt file).
        /// @param n The current AVLNode being looked at.
        /// @param file The output stream writing to the persistence index.
        void writePreOrderToPersistence(DSAVLNode *&n, ofstream &file);


        int nodeCount = 0;

    public:
        /// Default constructor.
        ///
        /// Initializes the root to nullptr.
        DSAVLTree();

        /// Destructor.
        ///
        /// Calls deleteTree() to delete every node in the AVL tree.
        ~DSAVLTree();

        /// Copy Constructor
        ///
        /// Copies the passed AVLTree's values into the new AVL tree.
        /// @param arg The AVLTree that is to be copied.
        DSAVLTree(const DSAVLTree<K,V>& arg);

        /// Overloaded Assignment Operator
        ///
        /// Deletes everything in the current AVLTree, then copies all data from the passed AVLTree to the current AVLTree
        /// @param arg The AVLTree that is to be copied.
        /// @return The current AVLTree that contains the newly copied values.
        DSAVLTree& operator=(const DSAVLTree& arg);

        //Public Functions
        /// Inserts the passed value into the AVLTree.
        ///
        /// Inserts the passed value into the AVLTree by calling the inner, recursive insert function.
        /// @param arg1 The key that is to be inserted into the AVLTree.
        /// @return The value associated with the recently inserted key.
        V& insert(const K& arg1);

        /// Searches the AVLTree for the passed in key.
        ///
        /// Calls the inner, recursive find function that finds the key passed to it and returns its associated value. If the key is not found in the AVL tree, then a runtime error is thrown.
        /// @param arg The key value that is being looked for.
        /// @return The value associated with the key being looked for.
        V& find(const K& arg);

        /// Calls the inner inOrder function.
        ///
        /// Calls the inner inOrder function, which starts from the root and counts all of the nodes in the AVLTree.
        void inOrder();

        /// Returns the number of nodes in the tree.
        ///
        /// Returns the number of nodes in the tree (which is stored in nodeCount).
        /// @return The number of nodes in the tree (which equates to the number of words in the index).
        int getUniqueWordCount();

        /// Calls writePreOrderToPersistence.
        ///
        /// Calls the private writePreOrderToPersistence function so that the persistence file can be written.
        /// @param file The output stream writing to the persistence index.
        void callPersistenceWithRoot(ofstream &file);

        /// Deletes the AVLTree.
        ///
        /// Iterates through every node in the AVLTree and deletes it.
        void deleteTree();
};

template<typename K, typename V>
DSAVLTree<K,V>::DSAVLTree() {
    root = nullptr;
}

template<typename K, typename V>
DSAVLTree<K,V>::~DSAVLTree() {
    deleteTree();
}

template<typename K, typename V>
DSAVLTree<K,V>::DSAVLTree(const DSAVLTree<K,V> &arg){
    root = nullptr;
    *this = arg;
}

template<typename K, typename V>
DSAVLTree<K,V>& DSAVLTree<K,V>::operator=(const DSAVLTree& arg) {
    if (root != nullptr) {
        deleteTree();
    }
    copyNodes(arg.root);
    return *this;
}

template<typename K, typename V>
int DSAVLTree<K,V>::height(DSAVLTree::DSAVLNode *node) {
    // If No Next Node Return A Height Of -1
    if (node == nullptr)
        return -1;

    // Else Return The Height Of The Node
    return node->height;
}

template<typename K, typename V>
V& DSAVLTree<K,V>::insert(const K &x, DSAVLTree::DSAVLNode *&t) {
    if (t == nullptr) {
        t = new DSAVLTree::DSAVLNode(x, nullptr, nullptr);
        return t->data.value;
    } else if (x < t->data.key) {
        V& temporary = insert(x, t->left);
        balance(t);
        return temporary;
    } else if (t->data.key < x) {
        V& temporary = insert(x, t->right);
        balance(t);
        return temporary;
    } else if (t->data.key == x) {
        return t->data.value;
    }
}

template<typename K, typename V>
void DSAVLTree<K,V>::inOrder(DSAVLNode* n) {
    if (n != nullptr) {
        inOrder(n->left);
        nodeCount += 1;
        inOrder(n->right);
    }
}
template<typename K, typename V>
void DSAVLTree<K,V>::inOrder() {
    inOrder(root);
}

template<typename K, typename V>
V& DSAVLTree<K,V>::insert(const K& arg1) {
    return insert(arg1, root);
}

template<typename K, typename V>
void DSAVLTree<K,V>::balance(DSAVLTree::DSAVLNode *& t) {
    if (t == nullptr) {
        return;
    } if (height(t->left) - height(t->right) > 1) {
        if (height(t->left->left) >= height(t->left->right)) {
            rotateWithLeftChild(t);
        } else {
            doubleWithLeftChild(t);
        }
    } else if (height(t->right) - height(t->left) > 1) {
        if (height(t->right->right) >= height(t->right->left)) {
            rotateWithRightChild(t);
        } else {
            doubleWithRightChild(t);
        }
    }
    t->height = max(height(t->left), height(t->right)) + 1;
}

template<typename K, typename V>
V &DSAVLTree<K, V>::find(const K& arg, DSAVLTree::DSAVLNode *& t) {
    if (t == nullptr) {
        throw std::runtime_error("Value is not in the tree"); //throws an error if the key is not in the tree
    } else  if (arg < t->data.key) {
        return find(arg, t->left);
    } else if (t->data.key < arg) {
        return find(arg, t->right);
    } else if (arg == t->data.key) {
        return t->data.value;
    }
}

template<typename K, typename V>
void DSAVLTree<K, V>::writePreOrderToPersistence(DSAVLTree::DSAVLNode*& n, ofstream &file) {
    if (n != nullptr) {
        file << n->data.key << " ";
        for (int i = 0 ; i < n->data.value.size() ; i++ ) {
            file << n->data.value.at(i) << " ";
        }
        file << "\n";
        writePreOrderToPersistence(n->left, file);
        writePreOrderToPersistence(n->right, file);
    }
}

template<typename K, typename V>
void DSAVLTree<K, V>::callPersistenceWithRoot(ofstream &file) {
    writePreOrderToPersistence(root, file);
}


template<typename K, typename V>
V &DSAVLTree<K,V>::find(const K& arg) {
    return find(arg, root);
}

template<typename K, typename V>
void DSAVLTree<K,V>::rotateWithLeftChild(DSAVLTree::DSAVLNode*& k2) {
    DSAVLTree::DSAVLNode* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;
    k2 = k1;
}

template<typename K, typename V>
void DSAVLTree<K,V>::doubleWithLeftChild(DSAVLTree::DSAVLNode*& k3) {
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

template<typename K, typename V>
void DSAVLTree<K,V>::rotateWithRightChild(DSAVLTree::DSAVLNode*& k2) {
    DSAVLTree::DSAVLNode* k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max(height(k2->right), height(k2->left)) + 1;
    k1->height = max(height(k1->right), k2->height) + 1;
    k2 = k1;
}

template<typename K, typename V>
void DSAVLTree<K,V>::doubleWithRightChild(DSAVLTree::DSAVLNode*& k3) {
    rotateWithLeftChild(k3->right);
    rotateWithRightChild(k3);
}

template<typename K, typename V>
void DSAVLTree<K, V>::deleteTree() {
    deleteTree(root);
}

template<typename K, typename V>
void DSAVLTree<K, V>::deleteTree(DSAVLNode*& n) {
    if (n != nullptr) {
        deleteTree(n->left);
        deleteTree(n->right);
        delete n;
    }
    n = nullptr;
}

template<typename K, typename V>
int DSAVLTree<K, V>::getUniqueWordCount() {
    inOrder();
    return nodeCount;
}

template<typename K, typename V>
void DSAVLTree<K, V>::copyNodes(DSAVLTree::DSAVLNode* argNode) {
    if (argNode != nullptr) {
        copyNodes(argNode->left);
        copyNodes(argNode->right);
        insert(argNode->data.key) = argNode->data.value;
    }
}


#endif //INC_21F_FINAL_PROJ_TEMPLATE_DSAVLTREE_H
