
//MOVIES ON FLIGHT
//You are on a flight and wanna watch two movies during this flight.
//You are given int[] movie_duration which includes all the movie durations.
//You are also given the duration of the flight which is d in minutes.
//Now, you need to pick two movies and the total duration of the two movies is less than or equal to (d - 30min).
//Find the pair of movies with the longest total duration. If multiple found, return the pair with the longest movie.

//e.g.
//Input
//movie_duration: [90, 85, 75, 60, 120, 150, 125]
//d: 250

//Output from aonecode.com
//[90, 125]
//90min + 125min = 215 is the maximum number within 220 (250min - 30min)
//.

#include <bits/stdc++.h>

using namespace std;

bool Compare(pair<int, int> lhs, pair<int, int> rhs)
{
  return (lhs.first+lhs.second) > (rhs.first + rhs.second);
}

class Solution
{
public:

  void findNumOfPairsLessThanD(int d, vector<int> movie_d, vector<pair<int, int>>& pairs)
  {
    //nlog2(n)
    for( auto it = movie_d.begin(); it != movie_d.end(); it++)
      {
	int remaining = d - *it;
	cout << " remaing: " << remaining << endl;
	// log2(n)
	auto it_lower = lower_bound(movie_d.begin(), movie_d.end(), remaining);
	cout << "it_lower: " << *it_lower << endl;
	
	for(auto iTemp = movie_d.begin(); iTemp < it_lower && iTemp != movie_d.end(); iTemp++)
	  {
	    pairs.push_back({*it, *iTemp});
	  }
      }    
  }

  void testCase()
  {
    int d = 250;
    vector<int> movie_d  = {90, 85, 75, 60, 120, 150, 125};
    sort(movie_d.begin(), movie_d.end());
    //printArr(movie_d);

    //O(n^2)
    vector<pair<int, int>> vPairs;
    int timeAvailable = d-30;
    findNumOfPairsLessThanD(timeAvailable, movie_d, vPairs);

    //O(nlog(n))
    sort(vPairs.begin(), vPairs.end(), Compare);
    printVPair(vPairs);
    //sort(movie_d.begin(), movie_d.end(), less<int>());
    //printArr(movie_d);
    //auto it = less_bound(movie_d.begin(), movie_d.end(),);
    
  }

  void printArr(vector<int> movie_d)
  {
    for(auto it = movie_d.begin(); it != movie_d.end(); it++)
      {
	cout << *it << " ";
      }
    cout << endl;    
  }

  void printVPair(vector<pair<int,int>> movies)
  {
    for(auto it = movies.begin(); it != movies.end(); it++)
      {
	cout << it->first << " " << it->second;
	cout << endl;
      }
    cout << endl;    
  }
 
};
  

int main(int argc, char* argv[] )
{
  Solution s;
  s.testCase();
  return 0;
}
