// this is the routine for graph component

#include <bits/stdc++.h>

using namespace std;

//Given an N-ary tree, find the subtree with the maximum average. Return the root of the subtree.
//A subtree of a tree is the node which have at least 1 child plus all its descendants.
// The average value of a subtree is the sum of its values, divided by the number of nodes.

//Example 1:

//Input:
//	    20
//	   /  \
//	 12    18
//      / | \  /  \
//    11  2  3 15  8

//Output: 18
//Explanation:
//There are 3 nodes which have children in this tree:
//12 => (11 + 2 + 3 + 12) / 4 = 7
//18 => (18 + 15 + 8) / 3 = 13.67
//20 => (12 + 11 + 2 + 3 + 18 + 15 + 8 + 20) / 8 = 11.125

//18 has the maximum average so output 18.
//

// Time Complexity: O(n), where n is number of nodes.

class Solution{

public:
  struct TreeNode
  {
    TreeNode(int val)
    {
      value = val;
    }
    
    void addNode(TreeNode* pChild)
    {
      children.push_back(pChild);      
    }
    
    int value;
    vector<TreeNode*> children;
  };

  void printTreeDFS(TreeNode* pNode)
  {
    if( pNode == nullptr)
      {
	return;
      }

    cout << pNode->value << " ";

    for(auto it = pNode->children.begin(); it != pNode->children.end(); it++)
      {
	printTreeDFS(*it);
      }

    cout << "\n";
  }

  double max = INT_MIN;
  TreeNode *maxNode = nullptr;

  double GetAverageSubTree(TreeNode* pNode)
  {
    if(pNode == nullptr)
      {
	return 0;
      }

    if(pNode->children.size() == 0)
      {
	return pNode->value;
      }
    
    double temp = pNode->value;
    int count = pNode->children.size() + 1;
    for( auto it = pNode->children.begin(); it != pNode->children.end(); ++it)
      {
	temp += GetAverageSubTree(*it);
      }

    temp = temp/count;
    if(temp > max)
      {
	max = temp;
	maxNode = pNode;
      }
    
    return temp;
  }

  void testCase()
  {
    TreeNode *pRoot = new TreeNode(20);
    //
    TreeNode* pNode12 = new TreeNode(12);
    pRoot->addNode(pNode12);
    TreeNode* pNode18 = new TreeNode(18);
    pRoot->addNode(pNode18);

    //
    TreeNode* pNode11 = new TreeNode(11);
    pNode12->addNode(pNode11);
    TreeNode* pNode2 = new TreeNode(2);
    pNode12->addNode(pNode2);
    TreeNode* pNode3 = new TreeNode(3);
    pNode12->addNode(pNode3);

    //
    TreeNode* pNode15 = new TreeNode(15);
    pNode18->addNode(pNode15);
    TreeNode* pNode8 = new TreeNode(8);
    pNode18->addNode(pNode8);
    
    //
    //printTreeDFS(pRoot);
    GetAverageSubTree(pRoot);
    cout << " max node: " << maxNode->value << "\n";
  }
};


int main(int argc, char* argv[] )
{
  Solution s;
  s.testCase();

  return 0;
}
