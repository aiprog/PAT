#include <cstdio>
#include <algorithm>

using namespace std;

struct Node
{
  int key;
  int height;
  Node *left;
  Node *right;
};

void leftRotate (Node *&root, Node *curNode, Node *parent)
{
  Node *left = curNode->left;
  if (!parent)
    root = left;
  else if (curNode == parent->left)
    parent->left = left;
  else
    parent->right = left;

  curNode->left = left->right;
  left->right = curNode;
}

void rightRotate (Node *&root, Node *curNode, Node *parent)
{
  Node *right = curNode->right;
  if (!parent)
    root = right;
  else if (curNode == parent->left)
    parent->left = right;
  else
    parent->right = right;

  curNode->right = right->left;
  right->left = curNode;
}

void AVLInsert (Node *&root, Node *curNode, Node *parent, int key)
{
  if (!curNode)
    root = new Node { key, 1, NULL, NULL };
  else if (key < curNode->key)
  {
    if (curNode->left)
      AVLInsert (root, curNode->left, curNode, key);
    else
      curNode->left = new Node { key, 1, NULL, NULL };

    int lHeight = curNode->left->height, rHeight = 0;
    if (curNode->right)
      rHeight = curNode->right->height;

    if (lHeight - rHeight == 2)
    {
      int llHeight = 0, lrHeight = 0;
      if (curNode->left->left)
        llHeight = curNode->left->left->height;
      if (curNode->left->right)
        lrHeight = curNode->left->right->height;

      if (llHeight > lrHeight)
      {
        --curNode->height;
        leftRotate (root, curNode, parent);
      }
      else
      {
        --curNode->height;
        --curNode->left->height;
        ++curNode->left->right->height;
        rightRotate (root, curNode->left, curNode);
        leftRotate (root, curNode, parent);
      }
    }
    else
      curNode->height = max (lHeight, rHeight) + 1;
  }
  else
  {
    if (curNode->right)
      AVLInsert (root, curNode->right, curNode, key);
    else
      curNode->right = new Node { key, 1, NULL, NULL };

    int rHeight = curNode->right->height, lHeight = 0;
    if (curNode->left)
      lHeight = curNode->left->height;

    if (rHeight - lHeight == 2)
    {
      int rrHeight = 0, rlHeight = 0;
      if (curNode->right->right)
        rrHeight = curNode->right->right->height;
      if (curNode->right->left)
        rlHeight = curNode->right->left->height;

      if (rrHeight > rlHeight)
      {
        --curNode->height;
        rightRotate (root, curNode, parent);
      }
      else
      {
        --curNode->height;
        --curNode->right->height;
        ++curNode->right->left->height;
        leftRotate (root, curNode->right, curNode);
        rightRotate (root, curNode, parent);
      }
    }
    else
      curNode->height = max (rHeight, rHeight) + 1;
  }
}

int main ()
{
  int nodeNum;
  scanf ("%d", &nodeNum);

  Node *root = NULL;
  for (int i = 0; i < nodeNum; ++i)
  {
    int key;
    scanf ("%d", &key);
    AVLInsert (root, root, NULL, key);
  }
  printf ("%d\n", root->key);
  
  return 0;
}