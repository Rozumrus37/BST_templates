//
// Created by Ruslan Rozumnyi on 2/6/20.
//

#pragma once

#include <iostream>
#include "Node.h"

template<class T>
class Tree {
public:
    void insert(Node<T> *root, T val) {
        if (root->value > val) {
            if (!root->left) {
                root->left = new Node<T>(val);
            } else {
                insert(root->left, val);
            }
        } else {
            if (!root->right) {
                root->right = new Node<T>(val);
            } else {
                insert(root->right, val);
            }
        }
    }

    void print(Node<T> *root) {
        if (!root) return;
        print(root->left);
        std::cout << root->value << " ";
        print(root->right);
    }

    bool find(Node<T> *root, T val) {
        if(root == nullptr) return 0;
        if(root->value == val) return 1;
        if(find(root->left, val)) return 1;
        return find(root->right, val);
    }

    T find_min(Node<T> *root) {
        if(root->left == nullptr)
            return root->value;
        return find_min(root->left);

    }

    T find_max(Node<T> *root) {
        if (root->right == nullptr)
            return root->value;
        return find_max(root->right);
    }


};
