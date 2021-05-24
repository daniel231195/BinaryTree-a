#include "doctest.h"
#include "BinaryTree.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace ariel;
using namespace std;

TEST_CASE("Testing methods"){ 
    BinaryTree<int> tree;
    /* this is the tree1
          1
        /   \
       3     2
      / \    / \
     7   6  5   4
*/ 
    // add to root child
    CHECK_NOTHROW(tree.add_root(1));
    CHECK_NOTHROW(tree.add_right(1,2));
    CHECK_NOTHROW(tree.add_left(1,3));
    // add to right child
    CHECK_NOTHROW(tree.add_right(2,4));
    CHECK_NOTHROW(tree.add_left(2,5));
    // add to left child 
    CHECK_NOTHROW(tree.add_right(3,6));
    CHECK_NOTHROW(tree.add_left(3,7));
    string post_out;
    for (auto it=tree.begin_postorder(); it!=tree.end_postorder(); ++it) {
        post_out+=to_string(*it)+',';
    }
    CHECK(post_out=="7,6,3,5,4,2,1,");
    post_out.clear();
    // add same node no more leaf or node
        tree.add_right(3,6);

        for (auto it=tree.begin_postorder(); it!=tree.end_postorder(); ++it) {
            post_out+=to_string(*it)+',';
        }
        CHECK(post_out=="7,6,3,5,4,2,1,");
        post_out.clear();

    // add to currect node  
/* this is the tree1
          1
        /   \
       3     2
      / \    / \
     7   9  3   4
*/  
        tree.add_left(2,3);
        tree.add_right(3,9);
        for (auto it=tree.begin_postorder(); it!=tree.end_postorder(); ++it) {
            post_out+=to_string(*it)+',';
        }
        CHECK(post_out=="7,9,3,3,4,2,1,");
        post_out.clear();
//------------check opertor---------------------------------------------------------------------------------------------------------        
        tree.add_right(1,11);
        auto befor=tree.begin();
        auto after=tree.begin();
        after++;
        for (auto it=tree.begin_postorder(); it!=tree.end_postorder(); ++it) {
            post_out+=to_string(*it)+',';
        }
        CHECK(post_out=="7,9,3,3,4,11,2,");
        CHECK_FALSE(befor==after);
        CHECK(befor!=after);
        
        // check print  
        CHECK_NOTHROW(cout<<tree<<endl); 
        for (auto it=tree.begin_postorder(); it!=tree.end_postorder(); ++it) {
            CHECK_NOTHROW(cout<<(*it)<<endl); 
        }
        post_out.clear();

    //check in,pre,post
/* this is the tree
          8
        /   \
       2     14
      / \    / \
     1   3  9   15
*/    
    BinaryTree<int> tree2;
    tree2.add_root(8);
    tree2.add_left(8,2);
    tree2.add_left(2,1);
    tree2.add_right(2,3);
    tree2.add_right(8,14);
    tree2.add_right(14,9);
    tree2.add_left(14,15);
    string outcome;
    for (auto it=tree2.begin_postorder(); it!=tree2.end_postorder(); ++it) {
        outcome+=to_string(*it)+',';
    }
    CHECK(outcome=="1,3,2,9,15,14,8");
    outcome.clear();
    for (auto it=tree2.begin_inorder(); it!=tree2.end_inorder(); ++it) {
        outcome+=to_string(*it)+',';
    }
    CHECK(outcome=="1,2,3,8,9,14,15");
    outcome.clear();
    for (auto it=tree2.begin_preorder(); it!=tree2.end_preorder(); ++it) {
        outcome+=to_string(*it)+',';
    }
    CHECK(outcome=="8,2,1,3,14,9,15");
    outcome.clear();
    // check print  
    CHECK_NOTHROW(cout<<tree2<<endl); 
    for (auto it=tree2.begin_postorder(); it!=tree2.end_postorder(); ++it) {
        CHECK_NOTHROW(cout<<(*it)<<endl); 
    }
}

TEST_CASE("check change "){ 
    BinaryTree<int> tree;
    //root
    tree.add_root(8);
    tree.add_root(1);
    //left and right
    tree.add_left(1,2);
    tree.add_left(1,3);
    tree.add_right(1,6);
    tree.add_right(1,9);
    string outcome;
    for (auto it=tree.begin_preorder(); it!=tree.end_preorder(); ++it) {
        outcome+=to_string(*it)+',';
    }
    CHECK(outcome=="1,3,9");
    outcome.clear();

    //change leaf
    BinaryTree<int> tree2;
    tree2.add_root(8);
    tree2.add_left(8,2);
    tree2.add_left(2,1);
    tree2.add_right(2,3);
    tree2.add_right(8,14);
    tree2.add_right(14,9);
    tree2.add_left(14,15);
    //change leaf
    tree2.add_left(2,12);
    tree2.add_right(2,5);
    tree2.add_right(14,15);
    tree2.add_left(14,11);
    // check
    for (auto it=tree2.begin_preorder(); it!=tree2.end_preorder(); ++it) {
        outcome+=to_string(*it)+',';
    }
    CHECK(outcome=="8,2,12,5,14,15,11");
    outcome.clear();
    // check mid 
    cout<<"check new 6"<<endl;
    tree2.add_right(8,123);
    tree2.add_left(8,22);
    for (auto it=tree2.begin_preorder(); it!=tree2.end_preorder(); ++it) {
        outcome+=to_string(*it)+',';
    }
    CHECK(outcome=="8,123,12,5,22,15,11");
    outcome.clear();
    tree2.add_root(1);
    // check change root and full tree
    for (auto it=tree2.begin_preorder(); it!=tree2.end_preorder(); ++it) {
        outcome+=to_string(*it)+',';
    }
    CHECK(outcome=="1,123,12,5,22,15,11");
    outcome.clear();
}

TEST_CASE("check type"){
    SUBCASE("check char "){    
        string outcome;
    /* this is the tree
              w
            /   \
           a      b
          / \    / \
          d   e  f   g
    */    
    BinaryTree<char> tree2;
    tree2.add_root('w');
    tree2.add_left('w','a');
    tree2.add_left('a','d');
    tree2.add_right('a','e');
    tree2.add_right('w','b');
    tree2.add_right('b','f');
    tree2.add_left('b','g');
    for (auto it=tree2.begin_postorder(); it!=tree2.end_postorder(); ++it) {
        outcome+=to_string(*it)+',';
    }
    CHECK(outcome=="d,e,a,f,g,b,w");
    outcome.clear();
    for (auto it=tree2.begin_inorder(); it!=tree2.end_inorder(); ++it) {
        outcome+=to_string(*it)+',';
    }
    CHECK(outcome=="d,a,e,w,f,b,g");
    outcome.clear();
    for (auto it=tree2.begin_preorder(); it!=tree2.end_preorder(); ++it) {
        outcome+=to_string(*it)+',';
    }
    CHECK(outcome=="w,a,d,e,b,f,g");
    outcome.clear();

    SUBCASE("change "){
        // change root
        tree2.add_root('k');
        for (auto it=tree2.begin_postorder(); it!=tree2.end_postorder(); ++it) {
            outcome+=to_string(*it)+',';
        }
        CHECK(outcome=="d,e,a,f,g,b,k");
        outcome.clear();
        //change leaf
        tree2.add_left('a','z');
        tree2.add_right('a','c');
        for (auto it=tree2.begin_preorder(); it!=tree2.end_preorder(); ++it) {
            outcome+=to_string(*it)+',';
        }
        CHECK(outcome=="k,a,z,c,b,f,g");
        outcome.clear();
        tree2.add_right('w','p');
        for (auto it=tree2.begin_preorder(); it!=tree2.end_preorder(); ++it) {
            outcome+=to_string(*it)+',';
        }
        CHECK(outcome=="k,a,z,c,p,f,g");
        outcome.clear();
        }
    }
    SUBCASE("check double "){    
        string outcome;
    //check in,pre,post
    /* this is the tree
              2.0
            /   \
           4.0   7.6
    */    
    BinaryTree<double> tree2;
    tree2.add_root(2.0);
    tree2.add_left(2.0,4.0);
    tree2.add_right(2.0,7.6);

    for (auto it=tree2.begin_postorder(); it!=tree2.end_postorder(); ++it) {
        outcome+=to_string(*it)+',';
    }
    CHECK(outcome=="2.0,4.0,7.6");
    outcome.clear();
    for (auto it=tree2.begin_inorder(); it!=tree2.end_inorder(); ++it) {
        outcome+=to_string(*it)+',';
    }
    CHECK(outcome=="4.0,2.0,7.6");
    outcome.clear();
    for (auto it=tree2.begin_preorder(); it!=tree2.end_preorder(); ++it) {
        outcome+=to_string(*it)+',';
    }
    CHECK(outcome=="4.0,7.6,2.0");
    outcome.clear();

    SUBCASE("change "){
        // change root
        tree2.add_root(7.0);
        for (auto it=tree2.begin_postorder(); it!=tree2.end_postorder(); ++it) {
            outcome+=to_string(*it)+',';
        }
        CHECK(outcome=="4.0,7.6,7.0");
        outcome.clear();
        //change leaf
        tree2.add_left(7.0,7.2);
        for (auto it=tree2.begin_preorder(); it!=tree2.end_preorder(); ++it) {
            outcome+=to_string(*it)+',';
        }
        CHECK(outcome=="7.2,7.0,7.6");
        outcome.clear();
        }
    }
        SUBCASE("check string "){    
        string outcome;
    /* this is the tree
              abc
            /   \
           fr1   asr@
    */    
    BinaryTree<string> tree2;
    tree2.add_root("abc");
    tree2.add_left("abc","fr1");
    tree2.add_right("abc","asr@");

    for (auto it=tree2.begin_postorder(); it!=tree2.end_postorder(); ++it) {
        outcome+=*it+',';
    }
    CHECK(outcome=="abc,fr1,asr@");
    outcome.clear();
    for (auto it=tree2.begin_inorder(); it!=tree2.end_inorder(); ++it) {
        outcome+=*it+',';
    }
    CHECK(outcome=="fr1,abc,asr@");
    outcome.clear();
    for (auto it=tree2.begin_preorder(); it!=tree2.end_preorder(); ++it) {
        outcome+=*it+',';
    }
    CHECK(outcome=="fr1,asr@,abc");
    outcome.clear();

    SUBCASE("change "){
        // change root
        tree2.add_root("skj");
        for (auto it=tree2.begin_postorder(); it!=tree2.end_postorder(); ++it) {
            outcome+=*it+',';
        }
        CHECK(outcome=="fr1,asr@,skj");
        outcome.clear();
        //change leaf
        tree2.add_left("skj","asd");
        for (auto it=tree2.begin_preorder(); it!=tree2.end_preorder(); ++it) {
            outcome+=*it+',';
        }
        CHECK(outcome=="asd,asr@,skj");
        outcome.clear();
        }
    }
}

TEST_CASE("not work and trhow exp,No place exists"){
    SUBCASE("No place exists"){   
        /* this is the tree1
                1
              /   \
             3     2
            / \    / \
           7   6  5   4
        */ 
        BinaryTree<int> tree;
        tree.add_root(1);
        tree.add_right(1,2);
        tree.add_left(1,3);
        tree.add_right(2,4);
        tree.add_left(2,5);
        tree.add_right(3,6);
        tree.add_left(3,7);
        CHECK_THROWS(tree.add_right(11,2));
        CHECK_THROWS(tree.add_left(11,2));
        CHECK_THROWS(tree.add_left(2.0,8));
        CHECK_THROWS(tree.add_right(2.0,2));
        CHECK_THROWS(tree.add_left(2,'c'));
        CHECK_THROWS(tree.add_right(3,'w'));
        CHECK_THROWS(tree.add_left('c',2));
        CHECK_THROWS(tree.add_right('w',3));
        // const char* a="asd";
        // CHECK_THROWS(tree.add_left(2,a));
        // const char* q="qwe";
        // CHECK_THROWS(tree.add_right(3,q));
        // CHECK_THROWS(tree.add_left(q,2));
        // CHECK_THROWS(tree.add_right(a,3));
        string post_out;
        for (auto it=tree.begin_postorder(); it!=tree.end_postorder(); ++it) {
            post_out+=to_string(*it)+',';
        }
        CHECK(post_out=="7,6,3,5,4,2,1,");
        /* this is the tree1
               'a'
              /   \
            'c'     'b'
            / \    / \
           'g'   'f'  'e'   'd'
        */ 
        BinaryTree<char> tree2;
        tree2.add_root('a');
        tree2.add_right('a','b');
        tree2.add_left('a','c');
        tree2.add_right('b','d');
        tree2.add_left('b','e');
        tree2.add_right('c','f');
        tree2.add_left('c','g');
        CHECK_THROWS(tree2.add_left('z','r'));
        CHECK_THROWS(tree2.add_right('z','r'));
        CHECK_THROWS(tree2.add_right(11,2));
        CHECK_THROWS(tree2.add_left(11,2));
        CHECK_THROWS(tree2.add_left(2.0,8));
        CHECK_THROWS(tree2.add_right(2.0,2));
        CHECK_THROWS(tree2.add_left(2,'c'));
        CHECK_THROWS(tree2.add_right(3,'w'));
        CHECK_THROWS(tree2.add_left('c',2));
        CHECK_THROWS(tree2.add_right('c',3));
    }
}
