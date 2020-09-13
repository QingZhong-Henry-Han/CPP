
#include <sys/time.h>
#include <bits/stdc++.h>

using namespace std;

//Given an array of strings products and a string searchWord.
//We want to design a system that suggests at most three product names from products
//after each character of searchWord is typed.
//Suggested products should have common prefix with the searchWord.
//If there are more than three products with a common prefix
//return the three lexicographically minimums products.

//Return list of lists of the suggested products after each character of searchWord is typed. 

 

//Example 1:

//Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
//Output: [
//["mobile","moneypot","monitor"],
//["mobile","moneypot","monitor"],
//["mouse","mousepad"],
//["mouse","mousepad"],
//["mouse","mousepad"]
//]
//Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
//After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
//After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
//Example 2:

//Input: products = ["havana"], searchWord = "havana"
//Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
//Example 3:

//Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
//Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
//Example 4:

//Input: products = ["havana"], searchWord = "tatiana"
//Output: [[],[],[],[],[],[],[]]

const int ALPHABET_SIZE = 26;

// trie node 
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
  
    // isEndOfWord is true if the node represents 
    // end of a word 
    bool isEndOfWord; 
}; 
  
// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
    pNode->isEndOfWord = false; 
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = nullptr; 
  
    return pNode; 
}

// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index])
	  {
            pCrawl->children[index] = getNode();
	  }
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
} 
  
// Returns true if key presents in trie, else false 
bool search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
}


class Solution
{
public:
  vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)
  {
    vector<vector<string>> results;

    TrieNode* pRoot = getNode();
    for( auto it = products.begin(); it != products.end(); it++)
      {
	insert(pRoot, *it);
      }

    int k = 3;

    for( int i = 0; i < searchWord.length(); i++)
      {
	char str[256];
	vector<string> items;
	string tempSearchWord = searchWord;
	tempSearchWord = searchWord.substr(0,i+1);
	findItems(pRoot, str, 0, items, tempSearchWord, k);
	results.push_back(items);
      }

    return results;
  }
 
  //Traverse trie tree from root
  void findItems(struct TrieNode* root, char str[], int level, vector<string>& items, string searchWord, int itemNum)
  {
    struct TrieNode *pCrawl = root;
    //check searchword
    for( int i = 0; i < searchWord.length(); i++)
      {
	if( level < searchWord.length())
	  {
	    int index = searchWord[level] - 'a';
	    if(pCrawl && pCrawl->children[index])
	      {
		str[level] = searchWord[level];
		pCrawl = pCrawl->children[index];
		level++;
	      }
	    else
	      {
		return;
	      }
	  }
      }
    
    if(pCrawl->isEndOfWord)
    {
      str[level] = '\0';
      string oneItem(str);
      items.push_back(oneItem);
    }
      if( items.size() == 3)
	{
	  return;
	}

    int i = 0;
    for (i = 0; i < ALPHABET_SIZE; i++)  
    { 
        // if NON NULL child is found 
        // add parent key to str and 
        // call the display function recursively 
        // for child node 
        if (pCrawl->children[i])  
        { 
            str[level] = i + 'a'; 
            findItems(pCrawl->children[i], str, level + 1, items, searchWord, itemNum); 
        } 
    } 
  }

  void print(vector<vector<string>> results)
  {
    cout << "[\n";
      for( auto it = results.begin(); it != results.end(); it++)
      {
	cout << "[";

	auto itNext = it->begin();
	for(auto it1 = it->begin(); it1 != it->end(); it1++)
	  {
	    cout << *it1;
	    itNext++;
	    if(itNext != it->end())
	      {
		cout << ",";
	      }
	  }
	cout << "]\n";
      }
      cout << "]\n";
  }

  void Test()
  {
    vector<string> products{"mobile","mouse","moneypot","monitor","mousepad"};
    string searchWord = "mouse";
    vector<vector<string>> results = suggestedProducts(products, searchWord);
    print(results);

    vector<string> products1{"havana"};
    searchWord = "havana";
    results = suggestedProducts(products1, searchWord);
    print(results);
    
    vector<string> products2{"bags","baggage","banner","box","cloths"};
    searchWord = "bags";
    results = suggestedProducts(products2, searchWord);
    print(results);
//Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
//Example 4:

    vector<string> products3 = {"havana"};
    searchWord = "tatiana";
    results = suggestedProducts(products3, searchWord);
    print(results);
//Output: [[],[],[],[],[],[],[]]

  }
};

int main(void)
{
  Solution s;
  s.Test();
  
  return 0;
}

