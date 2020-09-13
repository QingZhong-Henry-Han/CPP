//Given a string S of lowercase letters, partition S into as many as parts so that one letter only appear in one part. Return the partitions as a list.
//Example 1:
//
//Input:
//S = “bbeadcxede”
//
//Output:
//[“bb”, “eadcxede”]
//Example 2:
//Input:
//S = “baddacx”
//Output:
//[“b”, “adda", “c”, “x”]


#include <bits/stdc++.h>

using namespace std;

class Solution
{
  
public:

  vector<int> PartitionS(string s)
  {
    vector<int> partitionLengthes;;
    int lastIndexes[26];
    
    for(int i = 0; i < 26; i++) 
      {
	lastIndexes[i] = -1;
      }
    
    for(int i = 0; i < s.size(); i++) 
      {
	lastIndexes[s[i]-'a'] = i;
      }

    int i = 0;
    while(i < s.size())
      {
	int end = lastIndexes[s[i] -'a'];
	int j = i;

	while( j <  end)
	  {
	    int jEnd = lastIndexes[s[j] -'a'];
	    end = max(end, jEnd);
	    j++;
	  }
	partitionLengthes.push_back(++end-i);
	i = end;
      }

    return partitionLengthes;
  }


  void TestCase()
  {
    //string s("bbeadcxede");
    string s("ababcbacadefegdehijhklij");
    vector<int> result = PartitionS(s);
    for( auto it = result.begin(); it != result.end(); it++)
      {
	cout << *it << " ";
      }
    cout << s << "\n";
  }
};


int main(int argc, char* argv[] )
{
   Solution s;
   s.TestCase();
   
  return 0;
}
