#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data=data;
            left= right=NULL;
        }
};
class BinarySearchTree{
    public:
    Node*root;
    int leafVariable;
    BinarySearchTree(){
        root=NULL;
    }
    Node* Insert(Node* root,int val);
    void remove(Node* root, int val);
    void inOrderTraversal(Node* root);
    void preOrderTraversal(Node* root);
    void postOrderTraversal(Node* root);
    void makeDeletion(Node*&nodePtr);
    void Merging(BinarySearchTree tree);
    void calculateLeaf(Node*root,int count);
    int getLeafCount(Node* node);
};
int main (){
    BinarySearchTree tree;
    BinarySearchTree Stree;
    BinarySearchTree Mtree;
    tree.Insert(tree.root, 10);
    tree.Insert(tree.root, 8);
    tree.Insert(tree.root, 6);
    tree.Insert(tree.root, 9);
    tree.Insert(tree.root, 15);
    tree.Insert(tree.root, 14);
    tree.Insert(tree.root, 20);
    cout<<"The leaf nodes are: ";
    cout<<tree.getLeafCount(tree.root);
    cout<<"\n        In-Order"<<endl;
    cout<<"Left ---- Root ---- Right"<<endl;
    tree.inOrderTraversal(tree.root);
    cout<<"\n        Pre-Order"<<endl;
    cout<<"Root ---- Left ---- Right"<<endl;
    tree.preOrderTraversal(tree.root);
    cout<<"\n        Post-Order"<<endl;
    cout<<"Left ---- Right ---- Root"<<endl;
    tree.postOrderTraversal(tree.root);
    //Stree.Merging(tree);
    return 0;
}
Node* BinarySearchTree::Insert(Node * r, int val){
    if (r==NULL){
        Node* t= new Node(val);
        if (r==root)
        {
            root=r=t;
            }
        else
        {
            r=t;
        }
        return r;
    }
    else if (val==r->data){
        cout<<" Duplicate Data: "<< val<<endl;
    }
    else if (val < r->data){
        r->left= Insert(r->left, val);
    }
    else if (val > r->data){
        r->right= Insert(r->right, val);
    }
    return r;
}
void BinarySearchTree::inOrderTraversal(Node* r){
    if (r==NULL)
      return ;
    inOrderTraversal(r->left);
    cout<<" "<< r->data <<" -> ";
    inOrderTraversal(r->right);
}
void BinarySearchTree::preOrderTraversal(Node* r){
    if (r==NULL)
      return ;
    cout<<" "<< r->data <<" -> ";
    inOrderTraversal(r->left);
    inOrderTraversal(r->right);
}
void BinarySearchTree::postOrderTraversal(Node* r){
    if (r==NULL)
      return ;  
    inOrderTraversal(r->left);
    inOrderTraversal(r->right);
    cout<<" "<< r->data <<" -> ";
}
void BinarySearchTree::makeDeletion(Node*&nodePtr)
{
	Node*tempNodePtr;	
	if (nodePtr == NULL)
		cout << "Cannot delete empty node.\n";
	else if (nodePtr->right == NULL)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left; 
		delete tempNodePtr;
	}
    else if (nodePtr->left == NULL)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right; 
		delete tempNodePtr;
	}
	else
	{
		tempNodePtr = nodePtr->right;
		while (tempNodePtr->left)
		tempNodePtr = tempNodePtr->left;
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}
void BinarySearchTree::Merging(BinarySearchTree tree){
    tree.inOrderTraversal(tree.root->left);
    Insert(root,root->data);
    tree.inOrderTraversal(tree.root->right);
}
/*
void BinarySearchTree::calculateLeaf(Node*root,int count){
    if(root==NULL){
        cout<<"Your Tree Is Empty: ";
        return;
    }
    inOrderTraversal(root->left);
    if(root->left==NULL && root->right==NULL){
        count++;
        cout<<count;
    }
    inOrderTraversal(root->right);
}
*/
int BinarySearchTree::getLeafCount(Node* node)
{
	if(node == NULL)	
		return 0;
	if(node->left == NULL && node->right == NULL)
		return 1;		
	else
		return getLeafCount(node->left)+
			getLeafCount(node->right);
}