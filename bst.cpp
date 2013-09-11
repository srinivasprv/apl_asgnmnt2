/**
*       @file bst.cpp
*       @brief Contains Definitions of methods of class bst.
*
*       @author Anil Kumar Chilli, Praveen Srinivas
*
*/

#include "dict.h"

/**
*	Constructor initialises root or head
*	@param 
*/
bst::bst()
{
	head = NULL;
	//head->parent = NULL;
}

/**
*	This method searches the tree
*	@param value to be searched
*	@return A pointer to node if exists
*		NULL o/w.
*/
bst_node* bst::search_tree(int value)
{
	bst_node *pres;

	pres = head;
	while((pres!=NULL)&&(!(pres->element==(value))))
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
*	rooted at node.
*	@param Pointer to the root of sub-tree
*	@return pointer to the node with least value
*/
bst_node* bst::find_minimum(bst_node *node)
{
	bst_node *pres;
	pres = node;

	while((pres->left!=NULL))
		pres = pres->left;
	return pres;
}

/**
*       Finds the largest element of the sub-tree
*       rooted at node.
*       @param Pointer to the root of sub-tree.
*       @return pointer to the node with largest value.
*/
bst_node* bst::find_maximum(bst_node *node)
{
	bst_node *pres;
	pres = node;

	while((pres->right!=NULL))
		pres = pres->right;
	return pres;
}

/**
*	Finds the successor of a node in the tree
*	@param Pointer to the node to which successor
*	has to be computed.
*	@return Pointer to the successor node.
*/
bst_node* bst::find_successor(bst_node *node)
{
	bst_node *pres,*parent;
	pres = node;

	if(pres->right !=NULL)
		return find_minimum(pres->right);

	parent = pres;
	while((pres!=NULL)&&(pres == parent->right))
	{
		pres = parent;
		parent = parent->parent;
	}
	return parent;
}

/**
*	Inserts a new node with value as its elem
*	@param Value(int) to be inserted
*	@return Nothing
*/
void bst::insert(int value)
{//if(head!=NULL)printf("insert %d\n",head->element);
	bst_node *pres,*prev,*new_leaf;
	
	new_leaf = new bst_node();
	new_leaf->element=value;
	new_leaf->left = NULL;
	new_leaf->right = NULL;//head->new_leaf

//	printf("insert2");
	prev = NULL;
	pres = head;
	while(pres != NULL)//if->while
	{
		prev = pres;//pres=prev
		if((pres->element)>(value))//paranthesis
			pres = pres->left;
		else
			pres = pres->right;
	}
	new_leaf->parent = prev;
	if(prev == NULL)
		head = new_leaf;
	else if((prev->element)>(value))//paranthesis)
		prev->left = new_leaf;
	else
		prev->right = new_leaf;
}

/**
*	Replaces node pointed by a with node pointed by b
*	@param a, b as explained
*	@return nothing
*/
void bst::replace(bst_node *a,bst_node *b)
{
	if(a->parent==NULL)
		head = b;
	else if(a == a->parent->left)
		a->parent->left = b;
	else
		a->parent->right = b;
	if(b!=NULL)
		b->parent = a->parent;
}

/**
*	Deletes the node with value if exists
*	@param value to be deleted
*	@return nothing
*/
void bst::delete_element(int value)
{
	bst_node *pres,*prev,*child_node,*delete_node;
	bool flag;

	delete_node = search_tree(value);
	if(delete_node == NULL)
	{
		printf("element does not exist in tree\n");
		return;
	}

	if(delete_node->left==NULL)
		replace(delete_node,delete_node->right);
	else if(delete_node->right==NULL)
		replace(delete_node,delete_node->left);
	else
	{
		pres = find_minimum(delete_node->right);
		if(pres->parent != delete_node)//pres->parent == NULL
		{
			replace(pres,pres->right);
			pres->right = delete_node->right;
			pres->right->parent = pres;
		}
		replace(delete_node,pres);
		pres->left = delete_node->left;
		pres->left->parent = pres;
	}
	delete delete_node;
}

/**
*	Normal search to know elemnt exists or no
*	@param value to be searched
*	@return exists or no
*/
bool bst::search(int value)
{
	return (search_tree(value) != NULL);
}

/**
*	Displays the tree in-order
*/
void bst::display()
{
	pio(head);
	printf("\n");
}

/**
*	Recursively prints tree in-order
*	@param pointer to the root node of the sub-tree
*/
void bst::pio( bst_node *ptr )//print inorder from a node
{
	if( ptr->left != NULL )
		pio( ptr->left );
	printf("%d ,",ptr->element);
	if( ptr->right != NULL )
		pio( ptr->right );
}

void bst::clear()
{
	clear_pot(head);
	head = NULL;
}

void bst::clear_pot( bst_node *ptr )//clearing by postorder traversal
{
	if( ptr->left != NULL )
		clear_pot( ptr->left );
	if( ptr->right != NULL )
		clear_pot( ptr->right );
	delete ptr;
}
