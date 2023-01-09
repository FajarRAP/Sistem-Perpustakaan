#ifndef __BinaryTree
#define __BinaryTree
#include "BinaryTreeNode.hpp"

//tipe data abstrak pohon biner
template <typename T> 
class BinaryTree 
  {
public:
  // constructor
  BinaryTree()
  {
    this->root = 0;
  }

  //destructor
  ~BinaryTree()
  {
    
  }

  //cek apakah pohon kosong
  bool isEmpty()
  {
    return this->root == 0;
  }

  //ambil data akar
  T getRoot()
  {
    if(this->root != 0)
    {
      return this->root->data;
    }
    return;
  }

  //bangun pohon
  void makeTree(const T &data, 
                BinaryTree<T> &left, 
                BinaryTree<T> &right)
  {
    this->root = new BinaryTreeNode<T>(data, 
                                       left.root,
                                       right.root);
  }


  //cetak secara preorder
  void preOrder() 
  {
    preOrder(cetak, this->root);
    std::cout << std::endl;
  }

  //cetak secara inorder
  void inOrder()
  {
    inOrder(cetak, this->root);
    std::cout << std::endl;
  }

  //cetak secara postorder
  void postOrder()
  {
    postOrder(cetak, this->root);
    std::cout << std::endl;
  }

private:
  //akar
  BinaryTreeNode<T> *root;
  //fungsi untuk cetak sekaligus ketika pemanggilan
  //parameter
  static void cetak(BinaryTreeNode<T> *node) 
  { 
    std::cout << node->data << " "; 
  }
  //proses cetak preorder
  void preOrder(void (*)(BinaryTreeNode<T> *node), BinaryTreeNode<T> *root) 
  {
    if (root) 
      {
      cetak(root);
      preOrder(cetak, root->left);
      preOrder(cetak, root->right);
    }
  }
  //proses cetak inorder
  void inOrder(void (*)(BinaryTreeNode<T> *node), BinaryTreeNode<T> *root)
  {
    if(root)
      {
      inOrder(cetak, root->left);
      cetak(root);
      inOrder(cetak, root->right);
    }
  }
  //proses cetak postorder
  void postOrder(void (*)(BinaryTreeNode<T> *node), BinaryTreeNode<T> *root)
  {
    if(root)
      {
      postOrder(cetak, root->left);
      postOrder(cetak, root->right);
      cetak(root);
    }
  }
};

#endif