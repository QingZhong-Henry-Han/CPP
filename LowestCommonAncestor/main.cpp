
// this is the routine for graph Maximum Independent Set
// 1. Simple algorithm for lowest common ancestor
//       Assign all vertices to a candidate set of C
//       Veriex v from C is moved into I and all verices adjacent to v are removed from C


#include <bits/stdc++.h>

using namespace std;

// binary tree
struct Node
{
  int key;
  Node *pLeft, *pRight;
};


Node* newNode(int keyValue)
{
  Node* pTemp = new Node();
  pTemp->key = keyValue;
  pTemp->pLeft = pTemp->pRight = NULL;
  return pTemp;
}

// finds the path from root node to a given root of the binary tree
// stores the path in a vector path[], returns true if path exists otherwise false
bool findPath(Node* root, vector<int> &path, int key)
{
  //base case
  if(root == NULL )
    {
      return false;
    }

  // store the path
  path.push_back(root->key);
  
  // see if the key is the same as root's key
  if(root->key == key)
    return true;

  // check if key is found in left or roght sub-tree
  if((root->pLeft && findPath(root->pLeft, path, key)) ||
     (root->pRight && findPath(root->pRight, path, key)) )
    {
      return true;
    }

  //if not present in subtree rooted with root, remove root from
  // path[] and return false
  path.pop_back();
  return false;
}


// return LCA if node1, node2 are present in the given binary tree
// otherwise return -1;
int findLCA(Node* root, int node1, int node2)
{
  // to store paths to node1 and node2 from root
  vector<int> path1, path2;

  // find paths from root to node1 and root to node2. if either node1 and node2
  // is not present, return -1
  if(!findPath(root, path1, node1) || !findPath(root, path2, node2))
    {
      return -1;
    }

  // compare the paths to get the first different value
  int i = 0;
  for( i = 0; i < path1.size() && i < path2.size(); i++)
    {
      if( path1[i] != path2[i])
	{
	  break;
	}
    }

  return path1[i-1];
}

//this function returns pointer to LCA of two given values node1 and node2
struct Node* find_LCAUtil(struct Node* root, int node1, int node2, bool &v1, bool &v2)
{
  //base case
  if(root == NULL )
    return NULL;

  // if either node1 or node2 matches with root's key, report the presence
  // by setting v1 or v2 as true and return root ( Note that if a key
  // is ancestor of the other, then the ancestor key become LCA)
  if(root->key == node1)
    {
      v1 = true;
      return root;
    }

  if(root->key == node2)
    {
      v2= true;
      return root;
    }

  //look for keys in left and right subtree
  Node* left_lca = find_LCAUtil(root->pLeft, node1, node2, v1, v2);
  Node* right_lca = find_LCAUtil(root->pRight, node1, node2, v1, v2);

  // if both of the above calls return Non-NULL, then one key
  // is present one subtree and other is present in other
  // So this node is LCA

  if(left_lca && right_lca)
    return root;

  //otherwise check if the left subtree or right subtree is LCA
  return ( left_lca != NULL )? left_lca : right_lca;
}

//Returns true if key is present in tree rooted with root
bool find(Node *root, int key)
{
  // base case
  if(root == NULL)
    return false;

  // if key is present at root, or in left subtree or right subtree
  // return true
  if(root->key == key || find(root->pLeft, key) || find(root->pRight, key))
    return true;

  //else return false;
  return false;
}

// this function return LCA of node1 and node2 only if both node1 and node2 are present
// in tree, otherwise return NULL;
Node* find_LCA(Node* root, int node1, int node2)
{
  //Init node1, node2 as not visited
  bool v1 = false, v2 = false;

  Node* lca = find_LCAUtil(root, node1, node2, v1, v2);
  
  // Return LCA only if both node1 and node2 are present in tree
  if(v1 && v2 || v1 && find(lca, node2) || v2 && find(lca, node1))
    return lca;

  //else return NULL

  return NULL;
}


int main(int argc, char* argv[] )
{

  
  Node* root = newNode(1);
  root->pLeft = newNode(2);
  root->pRight = newNode(3);
  root->pLeft->pLeft = newNode(4);
  root->pLeft->pRight = newNode(5);
  root->pRight->pLeft = newNode(6);
  root->pRight->pRight = newNode(7);

  #ifdef TEST
  // cout
  cout << "\nLCA(4, 5) : " << findLCA(root, 4, 5);
  cout << "\nLCA(4, 6) : " << findLCA(root, 4, 6);
  cout << "\nLCA(3, 4) : " << findLCA(root, 3, 4);
  cout << "\nLCA(2, 4) : " << findLCA(root, 2, 4);
  #else
  Node * lca = find_LCA(root, 4, 5);
  if( lca != NULL)
    cout << "\n LCA(4, 5) = " << lca->key;
  else
    cout << "\nkey are not present";
  #endif

 
  return 0;
}
