/*******************************************************************************
 * Name        : rbtree.h
 * Author      : David Ott
 * Version     : 1.0
 * Date        : 11/6/12
 * Description : Implementation of red-black tree.
 * Pledge      : I pledge my honor that I have abided by the stevens honor system
 ******************************************************************************/
#ifndef RBTREE_HS
#define RBTREE_H_

#include "node.h"
#include "tree.h"
#include "treeprinter.h"
#include <iostream>
#include <cstdlib>
#include <exception>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>

using namespace std;

// Forward declaration
template<typename K, typename V>
class RedBlackTree;

/**
 * tree_exception class
 * Demonstrates how you can write your own custom exceptions in C++.
 */
class tree_exception: public std::exception {
public:
    tree_exception(const std::string &message) :
            message_(message) {
    }

    ~tree_exception() throw () {
    }

    virtual const char* what() const throw () {
        return message_.c_str();
    }

private:
    std::string message_;
};

template<typename K, typename V>
class RedBlackTreeIterator {
public:
    /**
     * Constructor
     */
    RedBlackTreeIterator() :
            node_ptr(NULL), tree(NULL) {
    }

    /**
     * Equality operator. Compares node pointers.
     */
    bool operator==(const RedBlackTreeIterator &rhs) const {
        return node_ptr == rhs.node_ptr;
    }

    /**
     * Inequality operator. Compares node pointers.
     */
    bool operator!=(const RedBlackTreeIterator &rhs) const {
        return node_ptr != rhs.node_ptr;
    }

    /**
     * Dereference operator. Returns a reference to key-value pair pointed to
     * by node_ptr.
     */
    std::pair<K, V>& operator*() const {
        return node_ptr->kv_pair_;
    }

    std::pair<K, V>* operator->() const {
        return &node_ptr->kv_pair_;
    }

    /**
     * Preincrement operator. Moves forward to next larger value.
     */
    RedBlackTreeIterator& operator++() {
        Node<K, V> *p;

        if (node_ptr == NULL) {
            // ++ from end(). Get the root of the tree.
            node_ptr = tree->root_;

            // Error, ++ requested for an empty tree.
            if (node_ptr == NULL)
                throw tree_exception(
                        "RedBlackTreeIterator operator++(): tree empty");

            // Move to the smallest value in the tree, which is the first node
            // in an inorder traversal.
            while (node_ptr->left_ != NULL) {
                node_ptr = node_ptr->left_;
            }
        } else {
            if (node_ptr->right_ != NULL) {
                // Successor is the leftmost node of right subtree.
                node_ptr = node_ptr->right_;

                while (node_ptr->left_ != NULL) {
                    node_ptr = node_ptr->left_;
                }
            } else {
                // Have already processed the left subtree, and
                // there is no right subtree. Move up the tree,
                // looking for a parent for which node_ptr is a left child,
                // stopping if the parent becomes NULL (or in this case,
                // root_parent_. A non-NULL parent is the successor. If parent
                // is NULL, the original node was the last node inorder, and
                // its successor is the end of the list.
                p = node_ptr->parent_;
                while (p != tree->root_parent_ && node_ptr == p->right_) {
                    node_ptr = p;
                    p = p->parent_;
                }

                // If we were previously at the rightmost node in
                // the tree, node_ptr = NULL, and the iterator specifies
                // the end of the list.
                node_ptr = (p == tree->root_parent_) ? NULL : p;
            }
        }

        return *this;
    }

    /**
     * Postincrement operator. Moves forward to next larger value.
     */
    RedBlackTreeIterator operator++(int) {
        RedBlackTreeIterator tmp(*this);
        operator++(); // prefix-increment this instance
        return tmp;   // return value before increment
    }

private:
    // node_ptr is the current location in the tree. We can move
    // freely about the tree using left, right, and parent.
    // tree is the address of the RedBlackTree object associated
    // with this iterator. It is used only to access the
    // root pointer, which is needed for ++ and --
    // when the iterator value is end().
    Node<K, V> *node_ptr;
    RedBlackTree<K, V> *tree;
    friend class RedBlackTree<K, V> ;

    /**
     * Constructor used to construct an iterator return value from a tree
     * pointer.
     */
    RedBlackTreeIterator(RedBlackNode<K, V> *p, RedBlackTree<K, V> *t) :
            node_ptr(p), tree(t) {
    }
};

template<typename K, typename V>
class RedBlackTree: public Tree {
public:
    typedef RedBlackTreeIterator<K, V> iterator;

    /**
     * Constructor to create an empty red-black tree.
     */
    RedBlackTree() :
            root_(NULL), root_parent_(new RedBlackNode<K, V>()), size_(0) {
        root_parent_->color_ = RedBlackNode<K, V>::BLACK;
    }

    /**
     * Constructor to create a red-black tree with the elements from the
     * vector.
     */
    RedBlackTree(std::vector<std::pair<K, V> > &elements) :
            root_(NULL), root_parent_(new RedBlackNode<K, V>()), size_(0) {
        root_parent_->color_ = RedBlackNode<K, V>::BLACK;
        insert_elements(elements);
    }

    /**
     * Destructor.
     */
    ~RedBlackTree() {
        delete_tree(root_);
        delete root_parent_;
    }

    /**
     * Inserts elements from the vector into the red-black tree.
     * Duplicate elements are not inserted.
     */
    void insert_elements(std::vector<std::pair<K, V> > &elements) {
        for (size_t i = 0, len = elements.size(); i < len; ++i) {
            try {
                insert(elements[i].first, elements[i].second);
            } catch (const tree_exception &te) {
                std::cerr << "Warning: " << te.what() << std::endl;
            }
        }
    }

    /**
     * Inserts a key-value pair into the red black tree.
     * const iterator &it indicates where to start the search for the place to
     * insert the node. If it == end(), the search starts at the root.
     */
    void insert(const iterator &it, const std::pair<K, V> &key_value) {

        Node<K, V> *x, *y;
        RedBlackNode<K, V>* newNode = new RedBlackNode<K, V>(key_value.first,
                key_value.second);
        if (it != end()) {
            x = it.node_ptr;
            y = x->parent_;
        } else {
            x = root_;
            y = root_parent_;

        }
        // TODO

        while (x != NULL) {
            y = x;
            if (key_value.first < x->kv_pair_.first) {
                x = static_cast<RedBlackNode<K, V>*>(x->left_);
            } else {
                x = static_cast<RedBlackNode<K, V>*>(x->right_);
            }
        }
        newNode->parent_ = y;
        if (y == root_parent_) {
            root_ = newNode;
        } else if (key_value.first < y->kv_pair_.first) {
            y->left_ = newNode;
        } else {
            y->right_ = newNode;
        }
        newNode->color_ = RedBlackNode<K, V>::RED;

        insert_fixup(newNode);
        size_++;
    }

    /**
     * Inserts a key-value pair into the red-black tree.
     */
    void insert(const K &key, const V &value) {
        iterator e = end();
        insert(e, std::pair<K, V>(key, value));
    }

    /**
     * Returns an ASCII representation of the red-black tree.
     */
    std::string to_ascii_drawing() {
        BinaryTreePrinter<K, V> printer(root_);
        return printer.to_string();
    }

    /**
     * Returns the height of the red-black tree.
     */
    size_t height() const {
        size_t h = height(root_);
        return h == 0 ? 0 : h - 1;
    }

    /**
     * Returns the number of nodes in the red-black tree.
     */
    size_t size() const {
        return size_;
    }

    /**
     * Returns the leaf count of the red-black tree.
     */
    size_t leaf_count() const {
        return leaf_count(root_);
    }

    /**
     * Returns the internal node count of the red-black tree.
     */
    size_t internal_node_count() const {
        return internal_node_count(root_);
    }

    /**
     * Returns the diameter of the red-black tree.
     */
    size_t diameter() const {
        size_t D = diameter(root_);
        if (D != 0) {
            return D - 1;
        } else {
            return 0;
        }

    }

    /**
     * Returns the max width of the red-black tree, i.e. the largest number of
     * nodes on any level.
     */
    size_t max_width() const {
        size_t max_width = 0;
        for (int i = 0, h = height(root_); i <= h; ++i) {

            size_t w = width(root_, i);
            if (w > max_width) {
                max_width = w;
            }
        }
        return max_width;
    }

    /**
     * Returns the successful search cost, i.e. the average number of nodes
     * visited to find a key that is present.
     */
    double successful_search_cost() const {
        return size_ == 0 ? 0 : 1 + (double) sum_levels() / size_;
    }

    /**
     * Returns the unsuccessful search cost, i.e. the average number of nodes
     * visited to find a key that is not present.
     */
    double unsuccessful_search_cost() const {
        return (double) sum_null_levels() / null_count();
    }

    /**
     * Searches for item. If found, returns an iterator pointing
     * at it in the tree; otherwise, returns end().
     */
    iterator find(const K &key) {
        Node<K, V> *x = root_;
        while (x != NULL) {
            if (key == x->kv_pair_.first) {
                break; // Found!
            } else if (key < x->kv_pair_.first) {
                x = x->left_;
            } else {
                x = x->right_;
            }
        }
        return iterator(static_cast<RedBlackNode<K, V>*>(x), this);
    }

    /**
     * Return an iterators pointing to the first item in order.
     */
    iterator begin() {
        RedBlackNode<K, V> *curr = root_;

        // if the tree is not empty, the first node
        // in order is the farthest node left from root
        if (curr != NULL) {
            while (curr->left_ != NULL) {
                curr = static_cast<RedBlackNode<K, V>*>(curr->left_);
            }
        }

        // build return value using private constructor
        return iterator(curr, this);
    }

    /**
     * Returns an iterator pointing just past the end of the tree data.
     */
    iterator end() {
        return iterator(NULL, this);
    }

private:
    RedBlackNode<K, V> *root_, *root_parent_;
    size_t size_;
    friend class RedBlackTreeIterator<K, V> ;

    /**
     * Deletes all nodes from the red-black tree.
     */
    void delete_tree(Node<K, V> *n) {
        // TODO
        if (n == NULL) {
            return;
        }
        delete_tree(n->left_);
        delete_tree(n->right_);
        delete n;

    }

    /**
     * Fixup method described on p. 316 of CLRS.
     */
    void insert_fixup(RedBlackNode<K, V> *node) {
        // TODO static_cast<RedBlackNode<K, V>*>(node->parent_->parent_->right)

        while (static_cast<RedBlackNode<K, V>*>(node->parent_)->color_
                == RedBlackNode<K, V>::RED) {

            if (node->parent_ == node->parent_->parent_->left_) {

                RedBlackNode<K, V>* y =
                        static_cast<RedBlackNode<K, V>*>(node->parent_->parent_->right_);

                if (y != NULL && y->color_ == RedBlackNode<K, V>::RED) {

                    static_cast<RedBlackNode<K, V>*>(node->parent_)->color_ =
                            RedBlackNode<K, V>::BLACK;
                    y->color_ = RedBlackNode<K, V>::BLACK;
                    static_cast<RedBlackNode<K, V>*>(node->parent_->parent_)->color_ =
                            RedBlackNode<K, V>::RED;
                    node =
                            static_cast<RedBlackNode<K, V>*>(node->parent_->parent_);

                } else {
                    if (node == node->parent_->right_) {

                        node = static_cast<RedBlackNode<K, V>*>(node->parent_);

                        left_rotate(node);

                    }
                    static_cast<RedBlackNode<K, V>*>(node->parent_)->color_ =
                            RedBlackNode<K, V>::BLACK;
                    static_cast<RedBlackNode<K, V>*>(node->parent_->parent_)->color_ =
                            RedBlackNode<K, V>::RED;

                    right_rotate(node->parent_->parent_);
                }
            } else {
                RedBlackNode<K, V>* y =
                        static_cast<RedBlackNode<K, V>*>(node->parent_->parent_->left_);
                if (y != NULL && y->color_ == RedBlackNode<K, V>::RED) {
                    static_cast<RedBlackNode<K, V>*>(node->parent_)->color_ =
                            RedBlackNode<K, V>::BLACK;
                    y->color_ = RedBlackNode<K, V>::BLACK;
                    static_cast<RedBlackNode<K, V>*>(node->parent_->parent_)->color_ =
                            RedBlackNode<K, V>::RED;
                    node =
                            static_cast<RedBlackNode<K, V>*>(node->parent_->parent_);

                } else {
                    if (node == node->parent_->left_) {

                        node = static_cast<RedBlackNode<K, V>*>(node->parent_);

                        right_rotate(node);

                    }
                    static_cast<RedBlackNode<K, V>*>(node->parent_)->color_ =
                            RedBlackNode<K, V>::BLACK;
                    static_cast<RedBlackNode<K, V>*>(node->parent_->parent_)->color_ =
                            RedBlackNode<K, V>::RED;

                    left_rotate(node->parent_->parent_);
                }

            }
        }

        // Last line below
        root_->color_ = RedBlackNode<K, V>::BLACK;
    }

    /**
     * Left-rotate method described on p. 313 of CLRS.
     */
    void left_rotate(Node<K, V> *x) {
        // TODO

        RedBlackNode<K, V>* y = static_cast<RedBlackNode<K, V>*>(x->right_);
        x->right_ = y->left_;
        if (y->left_ != NULL) {
            y->left_->parent_ = x;
        }
        y->parent_ = x->parent_;
        if (x->parent_ == root_parent_) {
            root_ = y;

        } else if (x == x->parent_->left_) {
            x->parent_->left_ = y;

        } else {
            x->parent_->right_ = y;
        }
        y->left_ = x;
        x->parent_ = y;

    }

    /**
     * Right-rotate method described on p. 313 of CLRS.
     */
    void right_rotate(Node<K, V> *x) {
        // TODO

        RedBlackNode<K, V>* y = static_cast<RedBlackNode<K, V>*>(x->left_);
        x->left_ = y->right_;
        if (y->right_ != NULL) {
            y->right_->parent_ = x;
        }
        y->parent_ = x->parent_;
        if (x->parent_ == root_parent_) {
            root_ = y;

        } else if (x == x->parent_->right_) {
            x->parent_->right_ = y;

        } else {
            x->parent_->left_ = y;
        }
        y->right_ = x;
        x->parent_ = y;

    }

    /**
     * Returns the height of the red-black tree starting at node.
     * A null node starts at height 0.
     */
    size_t height(Node<K, V> *node) const {
        // TODO
        if (node == NULL) {
            return 0;
        } else if (node->left_ == NULL && node->right_ == NULL) {
            return 1;
        }

        return max(height(node->left_), height(node->right_)) + 1;
    }

    /**
     * Returns the count of leaves in the red-black tree starting at node.
     * For this method, a leaf is a non-null node that has no children.
     */
    size_t leaf_count(Node<K, V> *node) const {
        // TODO
        if (node == NULL) {
            return 0;
        } else if (node->left_ == NULL && node->right_ == NULL) {
            return 1;
        }

        return leaf_count(node->left_) + leaf_count(node->right_);
    }

    /**
     * Returns the count of internal nodes in the red-black tree starting at
     * node.
     * An internal node has at least one child.
     */
    size_t internal_node_count(Node<K, V> *node) const {
        // TODO
        if (node == NULL || (node->left_ == NULL && node->right_ == NULL)) {
            return 0;
        }

        return 1 + internal_node_count(node->left_)

        + internal_node_count(node->right_);
    }

    /**
     * Returns the diameter of the red-black tree rooted at node.
     * Diameter is defined as the number of nodes on the longest path between
     * two (non-null) leaves in the tree. The path does not necessarily have to
     * pass through the root.
     */
    size_t diameter(Node<K, V> *node) const {
        // TODO
        if (node == NULL) {
            return 0;
        }
        size_t leftHeight = height(node->left_);
        size_t rightHeight = height(node->right_);
        size_t leftDiameter = diameter(node->left_);
        size_t rightDiameter = diameter(node->right_);

        return max(leftHeight + rightHeight + 1,
                max(leftDiameter, rightDiameter));
    }

    /**
     * Returns the width of the red-black tree at the designated level.
     * Width is defined as the number of nodes residing at a level.
     */
    size_t width(Node<K, V> *node, size_t level) const {
        // TODO

        if (node == NULL) {
            return 0;
        } else if (level == 0) {

            return 1;
        }

        return width(node->left_, level - 1) + width(node->right_, level - 1);

    }

    size_t null_count() const {
        return null_count(root_);
    }

    /**
     * Returns the count of null nodes in the red-black tree starting at node.
     */
    size_t null_count(Node<K, V> *node) const {
        if (node == NULL) {
            return 1;
        }

        return null_count(node->left_) + null_count(node->right_);
    }

    size_t sum_levels() const {
        return sum_levels(root_, 0);
    }

    /**
     * Returns the sum of the levels of each non-null node in the red-black
     * tree starting at node.
     * For example, the tree
     *   5 <- level 0
     *  / \
     * 2   8 <- level 1
     *      \
     *       10 <- level 2
     * has sum 0 + 2(1) + 2 = 4.
     */
    size_t sum_levels(Node<K, V> *node, size_t level) const {
        // TODO
        if (node == NULL) {
            return 0;
        }

        return level + sum_levels(node->left_, level + 1)
                + sum_levels(node->right_, level + 1);

    }

    size_t sum_null_levels() const {
        return sum_null_levels(root_, 0);
    }

    /**
     * Returns the sum of the levels of each null node in the red-black tree
     * starting at node.
     * For example, the tree
     *    5 <- level 0
     *   / \
     *  2   8 <- level 1
     * / \ / \
     * * * * 10 <- level 2
     *       / \
     *       * * <- level 3
     * has sum 3(2) + 2(3) = 12.
     */
    size_t sum_null_levels(Node<K, V> *node, size_t level) const {
        // TODO
        if (node == NULL) {
            return level;
        }

        return sum_null_levels(node->left_, level + 1)
                + sum_null_levels(node->right_, level + 1);
    }
};

#endif /* RBTREE_H_ */
