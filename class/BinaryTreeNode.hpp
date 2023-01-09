#ifndef __btnode
#define __btnode

// Node untuk tree
template <typename T> 
class BinaryTreeNode 
{
public:
  // constructor untuk nullkan *
  BinaryTreeNode() 
  {
    this->left = 0;
    this->right = 0;
  }
  // bikin root
  BinaryTreeNode(const T &data) 
  {
    this->data = data;
    this->left = 0;
    this->right = 0;
  }
  // bikin subtree
  BinaryTreeNode(const T &data, BinaryTreeNode<T> *left,
                 BinaryTreeNode<T> *right) 
  {
    this->data = data;
    this->left = left;
    this->right = right;
  }
  T data;
  BinaryTreeNode *left;
  BinaryTreeNode *right;
};

#endif