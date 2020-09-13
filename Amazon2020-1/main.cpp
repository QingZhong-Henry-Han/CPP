//
// Find Substrings
// Given a string S of lowercase letters, you need to find as many as substrings possible
// from the S that meets these conditions:
//
//1. no overlap among substrings
//2. one letter can only exist in one substring
//3. you want to find as many as substrings possible.
//4. if there are two solutions with the same number of substrings. return
//    the one with smaller total length.
//
//   return substrings as a list.
//
//  Exaple 1:
//   input:
//   S = "bbeadcxede"
//   output:
//   ["bb", 'a", "c", "x"]
//
//  Exaple 2:
//   input:
//   S = "baddacxb"
//   output:
//   ["dd", 'c", "x"]


#include <bits/stdc++.h>

using namespace std;


class Solution
{
  
public:

  
  list<string> findSubStrings(string s)
  {
    list<string> result;

    if(s.length() == 0 || s.length() == 1)
      {
	result.push_back(s);
	return result;
      }

    for( int i = 0; i < s.length(); i++)
      {
	string sTemp;
	do{
	  sTemp.push_back(s[i]);
	  i++;
	}while(s[i] == s[i-1]);
	i--;
	result.push_back(sTemp);
      }

    // remove the duplicated ones
    map<string, int> map;
    for( auto it = result.begin(); it != result.end(); it++)
      {
	map[*it] = ++map[*it];
      }

    result.clear();
    
    for(auto it = map.begin(); it != map.end(); it++)
      {
	if(it->second == 1)
	  {
	    result.push_back(it->first);
	  }
      }
    
    return result;
 
  }

  void TestCase1()
  {
    string S("bbeadcxede");
    list<string> result =  findSubStrings(S);
    for( auto s1 : result )
      {
	cout << s1 << " : ";
      }
    cout << "\n";
  }

  void TestCase2()
  {
    string S("baddacxb");
    list<string> result =  findSubStrings(S);
    for( auto s1 : result )
      {
	cout << s1 << " : ";
      }
    cout << "\n";
  }
};


int main(int argc, char* argv[] )
{
   Solution s;
   s.TestCase1();
   s.TestCase2();
    
  return 0;
}
