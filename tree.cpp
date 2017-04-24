//-----------------------------------------------------------
//  Purpose:    Implementation of BinaryTree class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include "tree.h"

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
BinaryTree::BinaryTree()
{
   Root = NULL;
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
BinaryTree::~BinaryTree()
{
}

//-----------------------------------------------------------
// Search helper function.
//-----------------------------------------------------------
bool BinaryTree::SearchHelper(int Value, Node * Tree)
{
   // Data value not found
   if (Tree == NULL)
      return false;

   // Data value found
   else if (Tree->Value == Value)
      return true;

   // Recursively search for data value
   else if (Tree->Value > Value)
      return (SearchHelper(Value, Tree->Left));
   else if (Tree->Value < Value)
      return (SearchHelper(Value, Tree->Right));
}

//-----------------------------------------------------------
// Search for data in the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Search(int Value)
{
   // Call tree searching function
   return (SearchHelper(Value, Root));
}

//-----------------------------------------------------------
// Insert helper function.
//-----------------------------------------------------------
bool BinaryTree::InsertHelper(int Value, Node * &Tree)
{
   // Insert data into the tree
   if (Tree == NULL)
   {
      Tree = new Node;
      Tree->Value = Value;
      Tree->Left = NULL;
      Tree->Right = NULL;
      return true;
   }

   // Data value already inserted
   else if (Tree->Value == Value)
      return false;

   // Recursively search for insertion position
   else if (Tree->Value > Value)
      return (InsertHelper(Value, Tree->Left));
   else if (Tree->Value < Value)
      return (InsertHelper(Value, Tree->Right));
}

//-----------------------------------------------------------
// Insert data into the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Insert(int Value)
{
   // Call tree insertion function
   return (InsertHelper(Value, Root));
}

//-----------------------------------------------------------
// Print helper function.
//-----------------------------------------------------------
void BinaryTree::PrintHelper(Node * Tree)
{
   // Check terminating condition
   if (Tree != NULL)
   {
      cout << "(";
      // Print left subtree
      PrintHelper(Tree->Left);

      // Print node value
      cout << " " << Tree->Value << " ";

      cout << ")";
      // Print right subtree
      PrintHelper(Tree->Right);
   }
}

//-----------------------------------------------------------
// Print all records in the binary tree.
//-----------------------------------------------------------
void BinaryTree::Print()
{
   // Call tree printing function
   PrintHelper(Root);
   cout << endl;
}

int BinaryTree::Count()
{
 int count = 0;
 CountHelper(Root, count);
 return count;
}

void BinaryTree::CountHelper(Node * Tree, int &count)
{
 if(Tree != NULL)
 {
  count++;
  CountHelper(Tree->Left, count);
  CountHelper(Tree->Right, count);
 }
}

int BinaryTree::Height()
{
 int height = 0;
 HeightHelper(Root, height);
 return height;
}

void BinaryTree::HeightHelper(Node * Tree, int &height)
{
 if(Tree != NULL)
 {
  if(Tree->Left != NULL || Tree->Right != NULL)
  {
    height++;
  }

  HeightHelper(Tree->Left, height);
  HeightHelper(Tree->Right, height);
 }
}

//-----------------------------------------------------------
// Main program.
//-----------------------------------------------------------
int main()
{
  BinaryTree tree;

  for(int z = 0;z < 1024;z++)
  {
    tree.Insert(rand() % 1024);
  }

  //tree.Print();
  cout << tree.Height() << endl;

  BinaryTree tree2;

  for(int z = 0;z < 1024;z++)
  {
    tree2.Insert(z);
  }

  cout << tree2.Height() << endl;

}

