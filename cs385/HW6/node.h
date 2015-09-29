/*******************************************************************************
 * Name        : node.h
 * Author      : Brian S. Borowski
 * Version     : 1.0
 * Date        : October 8, 2014
 * Description : Implementation of node for binary search tree and
 *               red-black tree.
 ******************************************************************************/
#ifndef NODE_H_
#define NODE_H_

#include <cstdlib>
#include <utility>

template<typename K, typename V>
class Node {
public:
    Node() : left_(NULL), right_(NULL), parent_(NULL) { }
    Node(const K &key, const V &value) :
        left_(NULL), right_(NULL), parent_(NULL),
        kv_pair_(std::make_pair(key, value)) { }

    Node<K, V> *left_, *right_, *parent_;
    std::pair<K, V> kv_pair_;
};

template<typename K, typename V>
class RedBlackNode : public Node<K, V> {
public:
    typedef unsigned char color_t;
    enum { RED, BLACK };
    RedBlackNode() : color_(RED) { }
    RedBlackNode(const K &key, const V &value) :
        Node<K, V>(key, value), color_(RED) { }

    color_t color_;
};

#endif /* NODE_H_ */
