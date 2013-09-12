/**
*       @file rbt.cpp
*       @brief Contains Definitions for methods of class rbt.
*
*       @author Anil Kumar Chilli, Praveen Srinivas
*
*/

#include "dict.h"

/*rbt::rbt()
{
	head->parent = NULL;
	tail = NULL;
	head = tail;
}*/

/**
*	Constructor: Initializes root to tail(or nil node)
*/
rbt::rbt()
{
	tail = new node;
	tail->color = 0;
//	tail->element = 1000000000000000000;
	tail->left = NULL;
	tail->right = NULL;
	head = tail;
	head->parent = tail;
}

/**
*	search_tree searches the tree for value
*	@param value to be searched
	@return pointer to node with value or tail if value does not exist
*/
node* rbt::search_tree(int value)
{
	node *pres;

	pres = head;
	while((pres!=tail/*NULL*/)&&(!(pres->element==(value))))
	{
		if(pres->element>(value))
			pres = pres->left;
		else
			pres = pres->right;
	}
	return pres;
}

/**
*	Finds the least element of the sub-tree
*       rooted at node.
*       @param Pointer to the root of sub-tree
*       @return pointer to the node with least value
*/
node* rbt::find_minimum(node *mynode)
{
	node *pres;
	pres = mynode;

	while((pres->left!=tail))//NULL))
		pres = pres->left;
	return pres;
}

/**
*       Finds the largest element of the sub-tree
*       rooted at node.
*       @param Pointer to the root of sub-tree.
*       @return pointer to the node with largest value.
*/
node* rbt::find_maximum(node *mynode)
{
	node *pres;
	pres = mynode;

	while((pres->right!=tail))//NULL))
		pres = pres->right;
	return pres;
}

/**
*       Finds the successor of a node in the tree
*       @param Pointer to the node to which successor
*       has to be computed.
*       @return Pointer to the successor node.
*/
node* rbt::find_successor(node *mynode)
{
	node *pres,*parent;
	pres = mynode;

	if(pres->right !=tail)//NULL)
		return find_minimum(pres->right);

	parent = pres;
	while((pres!=tail/*NULL*/)&&(pres == parent->right))
	{
		pres = parent;
		parent = parent->parent;
	}
	return parent;
}

/**
*	Left rotates the tree around mynode
*	@param mynode node around which rotation happens
*	
*/
void rbt::left_rotation(node *mynode)
{
	node *pres,*rightchild;

	pres = mynode;
	rightchild = pres->right;
	pres->right = rightchild->left;
	if(rightchild->left != tail)//null
		rightchild->left->parent = pres;
	rightchild->parent = pres->parent;
	if(pres->parent == tail)//NULL)
		head = rightchild;
	else if(pres == pres->parent->left)
		pres->parent->left = rightchild;
	else
		pres->parent->right = rightchild;
	rightchild->left = pres;
	pres->parent = rightchild;
}

/**
*       Right rotates the tree around mynode
*       @param mynode node around which rotation happens
*       
*/
void rbt::right_rotation(node *mynode)
{
	node *pres,*leftchild;

	pres = mynode;
	leftchild = pres->left;
	pres->left = leftchild->right;
	if(leftchild->right != tail)//NULL)
		leftchild->right->parent = pres;
	leftchild->parent = pres->parent;
	if(pres->parent == tail)//NULL)
		head = leftchild;
	else if(pres == pres->parent->left)
		pres->parent->left = leftchild;
	else
		pres->parent->right = leftchild;
	leftchild->right = pres;
	pres->parent = leftchild;
}

/**
*	Adjust the tree so that RBT properties are satisfied
*	@param mynode: the node which breaks the rules
*/
void rbt::insert_adjust(node *mynode)
{
	node *pres,*uncle;

	pres = mynode;
	while(pres->parent->color == 1)
	{
		if(pres->parent == pres->parent->parent->left)
		{
			uncle = pres->parent->parent->right;
			if(uncle->color == 1)
			{
				pres->parent->color = 0;
				uncle->color = 0;
				pres->parent->parent->color = 1;
				pres = pres->parent->parent;
			}
			else{
				if(pres == pres->parent->right)
				{
					pres = pres->parent;
					left_rotation(pres->parent->parent);
				}
				pres->parent->color = 0;
				pres->parent->parent->color = 1;
				right_rotation(pres->parent->parent);
			}
		}
		else
		{
			uncle = pres->parent->parent->left;
			if(uncle->color == 1)
			{
				pres->parent->color = 0;
				uncle->color = 0;
				pres->parent->parent->color = 1;
				pres = pres->parent->parent;
			}
			else
			{
				 if(pres == pres->parent->left)
				{
					pres = pres->parent;
					right_rotation(pres->parent->parent);
				}
				pres->parent->color = 0;
				pres->parent->parent->color = 1;
				left_rotation(pres->parent->parent);
			}
		}
	}
	head->color = 0;
}

/**
*	Inserts a new node into existing RBT
	@param value: to be inserted
*/
void rbt::insert(int value)
{
	node *pres,*prev,*new_leaf;
	
	new_leaf = new node();
	new_leaf->element=(value);
	//new_leaf->left = head->right = tail;
	new_leaf->left = new_leaf->right = tail;
	new_leaf->color = 1;

	pres = head;
	prev = tail;
	while(pres != tail)
	{
		prev = pres;
		if(pres->element>(value))
			pres = pres->left;
		else if(pres->element < value)
			pres = pres->right;
		else
			return;
	}
	new_leaf->parent = prev;
	if(prev == tail)
		head = new_leaf;
	else if(prev->element>(value))
		prev->left = new_leaf;
	else
		prev->right = new_leaf;//printf("%d\n",value);
	insert_adjust(new_leaf);
}

/**
*	Replaces node a by b
*	@param pointers to nodes a nd b
*/
void rbt::replace(node *a,node *b)
{
	if(a->parent==tail)
		head = b;
	else if(a == a->parent->left)
		a->parent->left = b;
	else
		a->parent->right = b;
	b->parent = a->parent;
}

/**
*	Adjust the tree so that RBT properties are satisfied after Deletion
*       @param mynode: the node which breaks the rules
*/
void rbt::delete_adjust(node *mynode)
{
	node *pres,*brother;

	pres = mynode;
	while((pres!=head) && (pres->color == 0))
	{
		if(pres == pres->parent->left)
		{
			brother = pres->parent->right;
			if(brother->color == 1)
			{
				brother->color = 0;
				pres->parent->color = 1;
				left_rotation(pres->parent);
				brother = pres->parent->right;
			}
			if((brother->left->color == 0)&&(brother->right->color == 0))
			{
				brother->color = 1;
				pres = pres->parent;
			}
			else
			{
				if(brother->right->color == 0)
				{
					brother->left->color = 0;
					brother->color = 1;
					right_rotation(brother);
					brother = pres->parent->right;
				}
				brother->color = pres->parent->color;
				pres->parent->color = 0;
				brother->right->color = 0;
				left_rotation(pres->parent);
				pres = head;
			}
		}
		else
		{
			brother = pres->parent->left;
			if(brother->color == 1)
			{
				brother->color = 0;
				pres->parent->color = 1;
				right_rotation(pres->parent);
				brother = pres->parent->left;
			}
			if((brother->right->color == 0)&&(brother->left->color == 0))
			{
				brother->color = 1;
				pres = pres->parent;
			}
			else
			{
				if(brother->left->color == 0)
				{
					brother->right->color = 0;
					brother->color = 1;
					left_rotation(brother);
					brother = pres->parent->right;
				}
				brother->color = pres->parent->color;
				pres->parent->color = 0;
				brother->right->color = 0;
				right_rotation(pres->parent);
				pres = head;
			}
		}
	}
	pres->color = 0;
}

/**
*	Deletes the node with value 'value'
*	@param value to be deleted
*/
void rbt::delete_element(int value)
{
	node *pres,*prev,*child_node,*delete_node;
	bool flag;

	delete_node = search_tree(value);
	if(delete_node == tail)
	{
		printf("element does not exist in tree\n");
		return;
	}

	pres = delete_node;
	pres->orig_color = pres->color;
	if(delete_node->left==tail)
	{
		child_node = delete_node->right;
		replace(delete_node,delete_node->right);
	}
	else if(delete_node->right==tail)//NULL)
	{
		child_node = delete_node->left;
		replace(delete_node,delete_node->left);
	}
	else
	{
		pres = find_minimum(delete_node->right);
		pres->orig_color = pres->color;
		child_node = pres->right;
		if(pres->parent == delete_node)
		{
			child_node-> parent = pres;
		}
		else
		{
			replace(pres,pres->right);
			pres->right = delete_node->right;
			pres->right->parent = pres;
		}
		replace(delete_node,pres);
		pres->left = delete_node->left;
		pres->left->parent = pres;
		pres->color = delete_node->color;
	}
	if(pres->orig_color == 0)
		delete_adjust(child_node);
		
	delete delete_node;
}

/**
*	Search if a value exists in the tree
*	@param value: what to search for
*	@return exists or no
*/
bool rbt::search(int value)
{
	return (search_tree(value) != tail);//NULL);
}

/**
*	Prints the tree in-order
*/
void rbt::display()
{
        pio(head);
        printf("\n");
}

/**
*	Reursive method to implement io-order traversal
*	@param Pointer to the node from which in-order traversal happens
*/
void rbt::pio( node *ptr )//print inorder from a node
{
        if( ptr->left != tail )
        pio( ptr->left );
        printf("%d %d,",ptr->element,ptr->color);
        if( ptr->right != tail )
        pio( ptr->right );
}

/**
*	Clears the tree
*/
void rbt::clear()
{
	clear_pot(head);
	head = tail;
}

/**
*	clear the nodes recursively in post-order
*	@param pointer to node from where post-order traversal happens
*/
void rbt::clear_pot(node *ptr)
{
	if(ptr->left!=NULL)
		clear_pot(ptr->left);
	if(ptr->right!=NULL)
		clear_pot(ptr->right);
	delete ptr;
}
