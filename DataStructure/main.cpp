// this is the routine for graph component

#include <bits/stdc++.h>

using namespace std;

// interview question 1

// 1) Given a singly linked list, swap every 2 nodes, for odd number of input;
//    retain the last node as it is.
//    Eg: Input:  5 13 15 18 20 11 6 7
//        Output: 13 5 18 15 11 20 7 6
//
//        Verified boundary cases

class SingleListNode
{
  int value;
  SingleListNode* pNext;

public:
  SingleListNode(int val)
  {
    value = val;
    pNext = NULL;
  }

  SingleListNode* processList()
  {
    // process the list
    SingleListNode* pHead = nullptr;
    SingleListNode* p1 = this;
    SingleListNode* p1Parent = nullptr;
    
    while(p1 && p1->pNext)
    {
      // save the third item
      SingleListNode*  p3 = nullptr;
      if( p1->pNext && p1->pNext->pNext)
	{
	  p3 = p1->pNext->pNext;
	}

      //swap the current two items
      SingleListNode*  p2 = p1->pNext;
      if(p1Parent)
	{
	  p1Parent->pNext = p2;
	}

      // save the first p2 as pHead
      if(pHead == nullptr)
	{
	  pHead = p2;
	}
    
      //swap p1 and p2
       p2->pNext = p1;

       //link to the p3
      if(p2->pNext)
	{
	  p2->pNext->pNext = p3;
	}

      // move parent to next item
      if(p1Parent == nullptr)
	{
	  p1Parent = p2->pNext;	  
	}
      else
	{
	  p1Parent = p1Parent->pNext->pNext;
	}

      // move to the p3 to be processed
      p1 = p3;
    }  
    //end of process

    return pHead;
  }

  void populateTestData()
  {
    SingleListNode* node13 = new SingleListNode(13);
    this->pNext = node13;
    SingleListNode* node15 = new SingleListNode(15);
    node13->pNext = node15;
    SingleListNode* node18 = new SingleListNode(18);
    node15->pNext = node18;
    SingleListNode* node20 = new SingleListNode(20);
    node18->pNext = node20;
    SingleListNode* node11 = new SingleListNode(11);
    node20->pNext = node11;
    SingleListNode* node6 = new SingleListNode(6);
    node11->pNext = node6;
    SingleListNode* node7 = new SingleListNode(7);
    node6->pNext = node7;
    SingleListNode*  node76 = new SingleListNode(76);
    node7->pNext = node76;
  }

  void printSingleList(SingleListNode* pNode)
  {
    //print out the list
    SingleListNode* p = pNode;
    while(p)
    {
      cout << p->value;
      if(p->pNext)
	{
	  cout  << " -> ";
	}
      p = p->pNext;
    }
    // end of list
  }
};


// 2) Given a binary tree, find the number of pairs where sum of 2 nodes’ values equal to k
//Eg:
//
// 1
//2 3
//4 5 7 
//Say k=7, output =2 ( 2+5, 3+4)
//Suggested an approach where I’d use in order traversal of this,
//Then interviewer asked me to solve the simplified problem,
// find k in sorted array instead of tree.
// Got solution for this one, to have 2 pointers at each end, and traverse accordingly.
//I was asked the approach for extending same to BST.
//Then, I implemented the same for BST using stack.
    
class BTree
{
public:
  int m_value;
  BTree* m_pLeft;
  BTree* m_pRight;

  BTree(int value)
  {
    m_value = value;
    m_pLeft = nullptr;
    m_pRight = nullptr;
  }

  void populateBTree()
  {
    BTree* pLeft2 = new BTree(2);
    BTree* pRight3 = new BTree(3);
    this->m_pLeft = pLeft2;
    this->m_pRight = pRight3;

    BTree* pLeft4 = new BTree(4);
    BTree* pRight5 = new BTree(5);
    pLeft2->m_pLeft = pLeft4;
    pLeft2->m_pRight = pRight5;

    BTree* pLeft7 = new BTree(7);
    pRight3->m_pLeft = pLeft7;
  }

  void BFSUtil(int total, int& count, BTree* pNode, vector<pair<int,int>>& resultsPair)
  {
    if(pNode == nullptr)
      return;
    
    if(pNode->m_pLeft)
      {
	if((pNode->m_pLeft->m_value + m_value) == total)
	  {	    
	    count++;
	    resultsPair.push_back({m_value, pNode->m_pLeft->m_value});
	  }
	BFSUtil(total, count, pNode->m_pLeft, resultsPair);
      }
    
    if(pNode->m_pRight)
      {
	if((pNode->m_pRight->m_value + m_value) == total)
	  {
	    count++;
	    resultsPair.push_back({m_value, pNode->m_pRight->m_value});
	  }
	BFSUtil(total, count, pNode->m_pRight, resultsPair);
      }
  }
  
  void BFSPrint()
  {
    //BFSUtil(this);
  }

  int countOfTwoNodesEqualTo(int total)
  {
    int count = 0;
    vector<pair<int, int>> resultPairs;
    
    BFSUtil(total, count, this, resultPairs);
    for(int i = 0; i < count; i++)
      {
	cout << "(" <<  resultPairs[i].first << "," << resultPairs[i].second << ")"; 
      }

    cout << "\n";     
    return count;
  }
};

//K-diff Pairs in an Array
//Given an array of integers and
//an integer k, you need to find the number of unique k-diff pairs in the array.
//Here a k-diff pair is defined as an integer pair (i, j),
//where i and j are both numbers in the array and their absolute difference is k.

//Example 1:
//Input: [3, 1, 4, 1, 5], k = 2
//Output: 2
//Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
//Although we have two 1s in the input, we should only return the number of unique pairs.
//Example 2:
//Input:[1, 2, 3, 4, 5], k = 1
//Output: 4
//Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
//Example 3:
//Input: [1, 3, 1, 5, 4], k = 0
//Output: 1
//Explanation: There is one 0-diff pair in the array, (1, 1).
//Note:
//The pairs (i, j) and (j, i) count as the same pair.
//The length of the array won't exceed 10,000.
//All the integers in the given input belong to the range: [-1e7, 1e7].
  
class Solution {
public:
  bool fncomp( pair<int, int> lhs, pair<int, int> rhs)
  {
    return lhs < rhs;
  }

  struct classcomp{
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
    {
      return lhs < rhs;
    }
  };
  
    int findPairs(vector<int>& nums, int k) {

      map<int, pair<int,int>> rMap;
      for( int i = 0; i < nums.size(); i++)
	{
	  for( int j = i+1; j < nums.size(); j++)	    {
	      if(abs(nums[i] - nums[j]) == k)
		{
		  rMap[nums[i]+nums[j]] = make_pair(i,j);
		}
	    }
	}

      return rMap.size();
    }

  void testCases()
  {
    vector<int> testArr1{3, 1, 4, 1, 5};
    int k = 2;
    cout << findPairs(testArr1, k) << "\n";

    vector<int> testArr2{1, 2, 3, 4, 5};
    k = 1;
    cout << findPairs(testArr2, k) << "\n";

    vector<int> testArr3{1, 3, 1, 5, 4};
    k = 0;
    cout << findPairs(testArr3, k) << "\n";
    
  }
};


int main(int argc, char* argv[] )
{

  //#define LIST_NODES_SWAP   
  #define BST_TWO_ITEMS_NUM   
  //#define K_DIFF_TEST   

#ifdef LIST_NODES_SWAP
  // first node
   SingleListNode* pFirstNode = new SingleListNode(5);
   
   pFirstNode->populateTestData();
   cout << "\n Original list:\n";
   pFirstNode->printSingleList(pFirstNode);
   cout << "\n end of the original list \n";
   SingleListNode* pResult = pFirstNode->processList();
   cout << "\n processed list \n";
   pFirstNode->printSingleList(pResult);
   cout << "\n end of processed list \n";
#endif

#ifdef BST_TWO_ITEMS_NUM
   BTree* pFirstNode = new BTree(1);
   pFirstNode->populateBTree();
   pFirstNode->BFSPrint();
   cout << " total = 5\n";
   pFirstNode->countOfTwoNodesEqualTo(5);
   cout << " \n  total= 7\n";
   pFirstNode->countOfTwoNodesEqualTo(7);
   cout << "\n";
#endif

#ifdef K_DIFF_TEST   
   Solution s;
   s.testCases();
#endif
   
  return 0;
}
