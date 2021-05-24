//
// Created by Daniel Sela on 21/05/2021.
//
#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
namespace ariel {

    template<typename T>
    class BinaryTree {

        struct Node {           
            T value;
            Node *left=nullptr;
            Node *right=nullptr;
            Node(T v) 
                    : value(v), left(nullptr), right(nullptr) {}
        };
        Node *root;

        class iterator {
            private:
                    Node* pointer_to_current_node;

            public:
                    iterator(Node* ptr=nullptr):pointer_to_current_node(ptr){

                    }
                    T& operator*() const{
                        return pointer_to_current_node->value;
                    }
                    T* operator->()const {
                        return &(pointer_to_current_node->value);
                    }
                    iterator& operator++(){
                        return *this;
                    }
                    const iterator operator++(int){
                        iterator tmp=*this;
                        return tmp;
                    }
                    bool operator==(const iterator& rhs) const{
                        return pointer_to_current_node==rhs.pointer_to_current_node;
                    }
                    bool operator!=(const iterator& rhs) const{
                        return pointer_to_current_node!=rhs.pointer_to_current_node;
                    }
        };

    public:

        BinaryTree<T>(){
            root = nullptr;
        }
        BinaryTree<T> add_root(const T& value){
            cout<<"add root"<<endl;
            return *this;
        }
        BinaryTree<T> add_left(const T& exist,const T& new_left){
            cout<<"add left child"<<endl;
            return *this;
        }
        BinaryTree<T> add_right(const T& exist,const T& new_right){
            cout<<"add right child"<<endl;
            return *this;
        }
        iterator begin_preorder(){
            return iterator{root};
        }
        iterator end_preorder(){
            return iterator{root};
        }

        iterator begin_inorder(){
            return iterator{root};
        }

        iterator end_inorder(){
            return iterator{root};
        }
        iterator begin_postorder(){
            return iterator{root};
        }

        iterator end_postorder(){
            return iterator{root};
        } 

        iterator begin(){
            return iterator{root};
        }                         
        iterator end(){
            return iterator{root};
        } 
          
        friend std::ostream& operator<<(std::ostream& os, const BinaryTree<T> &tree){
            os<<"print tree";
            return os;
        }    
    };
}