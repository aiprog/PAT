#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node
{
  int key;
  Node *left;
  Node *right;
  int height;
};

int getHeight (Node *node)
{
  if (!node)
    return 0;
  else
    return node->height;
}

void leftRotate (Node *&root, Node *node, Node *parent)
{
  if (!parent)
    root = node->left;

  Node *lChild = node->left, *lrChild = lChild->right;
  node->left = lrChild;
  lChild->right = node;

  if (parent)
  {
    if (node == parent->left)
      parent->left = lChild;
    else
      parent->right = lChild;
  }
}

void rightRotate (Node *&root, Node *node, Node *parent)
{
  if (!parent)
    root = node->right;

  Node *rChild = node->right, *rlChild = rChild->left;
  node->right = rlChild;
  rChild->left = node;

  if (parent)
  {
    if (node == parent->left)
      parent->left = rChild;
    else
      parent->right = rChild;
  }
}

void insertAVL (Node *&root, Node *node, Node *add, Node *parent)
{
  if (!root)
    root = add;
  else
  {
    Node *newNode = NULL;
    int key = add->key;

    if (key < node->key)
    {
      Node *lChild = node->left;
      if (!lChild)
        node->left = add;
      else
      {
        insertAVL (root, lChild, add, node);

        int lHeight = getHeight (node->left), rHeight = getHeight (node->right);
        if (lHeight - rHeight == 2)
        {
          Node *llChild = lChild->left, *lrChild = lChild->right;
          if (llChild && llChild->height + 1 == lHeight)
          {
            leftRotate (root, node, parent);
            newNode = lChild;
          }
          else if (lrChild && lrChild->height + 1 == lHeight)
          {
            rightRotate (root, lChild, node);
            leftRotate (root, node, parent);
            newNode = lrChild;
          }
        }
      }
    }
    else
    {
      Node *rChild = node->right;
      if (!rChild)
        node->right = add;
      else
      {
        insertAVL (root, rChild, add, node);

        int rHeight = getHeight (node->right), lHeight = getHeight (node->left);
        if (rHeight - lHeight == 2)
        {
          Node *rrChild = rChild->right, *rlChild = rChild->left;
          if (rrChild && rrChild->height + 1 == rHeight)
          {
            rightRotate (root, node, parent);
            newNode = rChild;
          }
          else if (rlChild && rlChild->height + 1 == rHeight)
          {
            leftRotate (root, rChild, node);
            rightRotate (root, node, parent);
            newNode = rlChild;
          }
        }
      }
    }

    if (!newNode)
      node->height = max (getHeight (node->left), getHeight (node->right)) + 1;
    else
    {
      newNode->height = node->height;
      newNode->left->height = newNode->right->height = newNode->height - 1;
    }
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
    insertAVL (root, root, new Node { key, NULL, NULL, 1 }, NULL);
  }

  queue<Node *> que;
  que.push (root);

  bool first = true, noChild = false, CBT = true;
  while (!que.empty ())
  {
    auto top = que.front ();
    que.pop ();

    if (!first)
      printf (" ");
    else
      first = false;
    printf ("%d", top->key);

    if (top->left)
    {
      if (noChild)
        CBT = false;
      que.push (top->left);
    }
    else
      noChild = true;

    if (top->right)
    {
      if (noChild)
        CBT = false;
      que.push (top->right);
    }
    else
      noChild = true;
  }
  printf ("\n");

  if (CBT)
    printf ("YES\n");
  else
    printf ("NO\n");

  return 0;
}