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
	///search the tree iteratively using bst property
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

	///return left most node in the subtree
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

	///return the right most node in the sub tree
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

	///if right sub tree exists return the least elementn in it
	if(pres->right !=NULL)
		return find_minimum(pres->right);

	///o/w
	parent = pres;
	///iterate till pres is left child or we find the root
	while((pres!=NULL)&&(pres == parent->right))
	{
		pres = parent;
		parent = parent->parent;
	}
	///returns null if iterated till root as successor does not exist
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
	///iterate over tree to find the node to which new node is child
	while(pres != NULL)//if->while
	{
		prev = pres;//pres=prev
		if((pres->element)>(value))//paranthesis
			pres = pres->left;
		else if((pres->element)<value)
			pres = pres->right;
		else
		{
			printf("element already exists\n");
			return;
		}
	}
	
	new_leaf->parent = prev;
	///first node-> point it as root
	if(prev == NULL)
		head = new_leaf;
	///create as left or righ tchild accordingly
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
	///if a is root make b as root
	if(a->parent==NULL)
		head = b;
	///if a is left child to its parent, make b as left child to parent of a
	else if(a == a->parent->left)
		a->parent->left = b;
	///same as if case
	else
		a->parent->right = b;
	///update parent of b
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

	///search the tree for value
	delete_node = search_tree(value);
	///print error if element does not exist
	if(delete_node == NULL)
	{
		printf("element does not exist in tree\n");
		return;
	}

	///if left node does not exist replace z with its righ child
	if(delete_node->left==NULL)
		replace(delete_node,delete_node->right);
	///if z does not have right child but has a left child replace left child with z
	else if(delete_node->right==NULL)
		replace(delete_node,delete_node->left);
	///if z have bot children
	else
	{
		///find the least element in right subtree
		pres = find_minimum(delete_node->right);
		///if z is not the parent of the least node
		if(pres->parent != delete_node)//pres->parent == NULL
		{
			///remove pres from its place
			replace(pres,pres->right);
			///update right pointers in place of delete node
			pres->right = delete_node->right;
			pres->right->parent = pres;
		}
		replace(delete_node,pres);
		///update left pointers
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
	///use search_tree
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
	if(ptr == NULL)
	{
		printf("No elements Exist");
		return;
	}
	///call pio recursively on left
	if( ptr->left != NULL )
		pio( ptr->left );
	///after printing left subtree print current root
	printf("%d ,",ptr->element);
	///call pio recursively on right subtree
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
	if(ptr == NULL)
        {
                printf("No elements Exist");
                return;
        }
	///clear left subtree recorsively
	if( ptr->left != NULL )
		clear_pot( ptr->left );
	///clear right subtree recursively
	if( ptr->right != NULL )
		clear_pot( ptr->right );
	///delete current root
	delete ptr;
}
