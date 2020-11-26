
#include <sys/time.h>
#include <bits/stdc++.h>

// in quote example from cpp programming
template <typename Container>
bool in_quote(const Container& cont, const std::string& s)
{
    return std::search(cont.begin(), cont.end(), s.begin(), s.end()) != cont.end();
}

// search_n example from cpp programming
template <class Container, class Size, class T>
bool consecutive_values(const Container& c, Size count, const T& v)
{
  return std::search_n(std::begin(c),std::end(c),count,v) != std::end(c);
}

// the following is count
//  // counting elements in array:
//  int myints[] = {10,20,30,30,20,10,10,20};   // 8 elements
//  int mycount = std::count (myints, myints+8, 10);
//  std::cout << "10 appears " << mycount << " times.\n";
//
//  // counting elements in container:
//  std::vector<int> myvector (myints, myints+8);
//  mycount = std::count (myvector.begin(), myvector.end(), 20);
//  std::cout << "20 appears " << mycount  << " times.\n";


//  std::count_if
//
//bool IsOdd (int i) { return ((i%2)==1); }
//
//int main () {
//  std::vector<int> myvector;
//  for (int i=1; i<10; i++) myvector.push_back(i); // myvector: 1 2 3 4 5 6 7 8 9
//
//  int mycount = count_if (myvector.begin(), myvector.end(), IsOdd);
//  std::cout << "myvector contains " << mycount  << " odd values.\n";
//
//  return 0;
//}


// std::find_if and std::find_if_not
//bool IsOdd (int i) {
//  return ((i%2)==1);
//}

//int main () {
//  std::vector<int> myvector;

//  myvector.push_back(10);
//  myvector.push_back(25);
//  myvector.push_back(40);
//  myvector.push_back(55);

//  std::vector<int>::iterator it = std::find_if (myvector.begin(), myvector.end(), IsOdd);
//  std::cout << "The first odd value is " << *it << '\n';

//  return 0;
//}

void printOutStr(std::string str)
{
  std::cout << ' ' << str;
}

template<typename charT>
struct caseInsensitiveComp{
  caseInsensitiveComp(const std::locale& loc):loc_(loc){}
  bool operator()(charT ch1, charT ch2){
    return std::toupper(ch1, loc_) == std::toupper(ch2, loc_);
  }
private:
  const std::locale& loc_;
};

template<typename T>
typename T::iterator ci_find_substr(const typename T::iterator it1b, const typename T::iterator it1e,  const T& v, const std::locale& loc = std::locale())
{
  typename T::iterator itTemp = std::search(it1b, it1e, v.begin(), v.end(), caseInsensitiveComp<typename T::value_type>(loc));
  if( itTemp != it1e)
    {
      return itTemp;
    }
  else
    {
      return it1e;
    }
}

bool compareElement(std::pair<std::string, int> e1, std::pair<std::string, int> e2 )
{
  if(e1.second > e2.second )
    {
      return true;
    }
  else if ( e1.second == e2.second )
    {
      return (e1.first < e2.first);
    }

  return false;     
}


std::vector<std::string> topNBuzzwords(int numToys, int topToys, std::vector<std::string> toys, int numQuotes, std::vector<std::string> quotes);

int main(void)
{
  struct timeval startTime, endTime;
  long mTime, seconds, uSeconds;
    
  
  int numToys = 6;
  int topToys = 2;
  int numQuotes = 6;
  std::vector<std::string> vToys = {"elmo", "elsa","legos","drone","tablet","warcraft"};
  std::vector<std::string> vQuotes = {"Elmo is the hottest of the season! Elmo will be on evry kid's wishlist!",
				    "The new Elmo dolls are super high quality",
				    "Expect the Elsa dolls to be very popular this year, Elsa!",
				    "Elsa and Elmo are the toys I'll be buying for my kids, Elsa is good",
				    "For parents of older kids, look into buying them a drone",
				    "Warcraft is slowly rising in popularity ahead of the holiday season"};

  std::for_each(vToys.begin(), vToys.end(),printOutStr);
  std::cout << '\n';

  gettimeofday(&startTime,NULL);
  std::vector<std::string> vResults = topNBuzzwords(numToys, topToys,  vToys, numQuotes, vQuotes);

  std::for_each(vResults.begin(),vResults.end(), printOutStr);
  std::cout << '\n';
  
  gettimeofday(&endTime, NULL);

  seconds = endTime.tv_sec - startTime.tv_sec;
  uSeconds = endTime.tv_usec - startTime.tv_usec;
  mTime = seconds*1000+uSeconds/1000;
  printf("Elapsed time %ld ms\n",mTime);
  
  return 0;
}

std::vector<std::string> topNBuzzwords(int numToys, int topToys, std::vector<std::string> toys, int numQuotes, std::vector<std::string> quotes)
{
  std::vector<std::string> retStrs = std::vector<std::string>();
  std::unordered_map<std::string, int> freq;

  for(auto v:toys)
    {
      int count = 0;
      for(auto s:quotes)
	{
          std::string::iterator found = s.begin();
          found = ci_find_substr<std::string>(found, s.end(), v);
	  while(found != s.end())
	    {
	      count++;
	      found++;
	      found = ci_find_substr<std::string>(found,s.end(),v);
	    }
	}
      freq[v] = count;   
    }

  //print out unordered_map to see what e get
  // for(const auto& n: freq){
  //    std::cout << "Key:[" << n.first << "] value:[" << n.second << "]\n";
  //}

  //top k algorithm
  std::vector<std::pair<std::string, int>> results(freq.begin(), freq.end());

  std::sort(results.begin(), results.end(), compareElement );

  for(int i = 0; i < topToys; i++)
    {
      retStrs.push_back(results[i].first);
    }
  
  
  return retStrs;
}
