#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

struct Node
{
  int value;
  Node *left;
  Node *right;
};

using ITE = std::vector<int>::iterator;

Node *buildTree (ITE postBeg, ITE postEnd, ITE inBeg, ITE inEnd)
{
  int size = (int)(postEnd - postBeg);
  if (size == 0)
    return nullptr;
  else if (size == 1)
    return new Node{ *postBeg, nullptr, nullptr };
  else
  {
    auto parentIte = find (inBeg, inEnd, postBeg[size - 1]);
    int leftLen = (int)(parentIte - inBeg), rightLen = size - 1 - leftLen;

    Node *left = buildTree (postBeg, postBeg + leftLen, inBeg, inBeg + leftLen);
    Node *right = buildTree (postEnd - 1 - rightLen, postEnd - 1, inEnd - rightLen, inEnd);

    return new Node{ *parentIte, left, right };
  }
}

void freeTree (Node *tree)
{
  if (tree)
  {
    freeTree (tree->left);
    freeTree (tree->right);
    delete tree;
  }
}

int main ()
{
  int nodeNum;
  scanf ("%d", &nodeNum);

  std::vector<int> postorder (nodeNum);
  for (int i = 0; i < nodeNum; ++i)
  {
    int value;
    scanf ("%d", &value);
    postorder[i] = value;
  }

  std::vector<int> inorder (nodeNum);
  for (int i = 0; i < nodeNum; ++i)
  {
    int value;
    scanf ("%d", &value);
    inorder[i] = value;
  }

  Node *tree = buildTree (postorder.begin (), postorder.end (), inorder.begin (), inorder.end ());
  std::queue<Node*> nodeQueue;

  nodeQueue.push (tree);
  while (1)
  {
    Node *front = nodeQueue.front ();
    nodeQueue.pop ();
    printf ("%d", front->value);

    if (front->left)
      nodeQueue.push (front->left);

    if (front->right)
      nodeQueue.push (front->right);

    if (!nodeQueue.empty ())
      printf (" ");
    else
      break;
  }
  printf ("\n");


  freeTree (tree);

  return 0;
}