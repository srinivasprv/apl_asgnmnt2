/**
*       @file dict.h
*       @brief Header file containing prototypes for classes bst, rbt.
*
*       @author Anil Kumar Chilli, Praveen Srinivas
*
*/

#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

/**
*	Base class dictionary
*/
class dict
{
	public:
		///search and return whether elment exists or no
		virtual bool search(int value)=0;
		///inserct element into dictionary
		virtual void insert(int value)=0;
		///delete element from dictianary
		virtual void delete_element(int value)=0;
		///clears the dictionary
		virtual void clear()=0;
		///Displays the dictinary in ascending order
		virtual void display()=0;
};

/**
*	Node of BST(Binary Search Tree)
*/
class bst_node
{
	public:
		int element;///< value of a node
		bst_node *parent;/**< pointer to parent of the node*/
		bst_node *left;///< pointer to left child
		bst_node *right;///< pointer to right child
};

/**
*	Class Binary Search Tree
*/
class bst :public dict
{
	public:
		bst();
		bst_node *head;///< pointer to root of the tree
		bst_node* search_tree(int value);
		void pio(bst_node *ptr);
		bst_node* find_minimum(bst_node *value);
		bst_node* find_maximum(bst_node *value);
		bst_node* find_successor(bst_node *value);
		void replace(bst_node *a,bst_node *b);
		bool search(int value);
		void insert(int value);
		void delete_element(int value);
		void clear();
		void display();
};

/**
*	class Red-Black Tree node
*/
class node
{
	public:
		int element;///< Value of the node
		bool color;///< colour of node
		bool orig_color;///< orig colour: used while delete_fix
		node *parent;///< pointer to parent
		node *left;///< pointer to left child
		node *right;///< pointer to right child
};

/**
*	Red Black Tree class
*/
class rbt :public dict
{
	public:
		rbt();
		node *head;///< pointer to root of the tree
		node *tail;///< pointer to nil node
		node* search_tree(int value);
		node* find_minimum(node *value);
		void pio(node *ptr);
		node* find_maximum(node *value);
		node* find_successor(node *value);
		node* left_rotation(node *mynode);
		node* right_rotation(node *mynode);
		void insert_adjust(node *node);
		void delete_adjust(node *node);
		void replace(node *a,node *b);
		bool search(int value);
		void insert(int value);
		void delete_element(int value);
		void clear();
		void display();
};
#endif
