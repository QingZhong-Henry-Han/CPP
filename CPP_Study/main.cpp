//
// for array data strcture
//1.How do you find the missing number in a given integer array of 1 to 100? (solution)
//2.How do you find the duplicate number on a given integer array? (solution)
//3.How do you find the largest and smallest number in an unsorted integer array? (solution)
//4.How do you find all pairs of an integer array whose sum is equal to a given number? (solution)
//5.How do you find duplicate numbers in an array if it contains multiple duplicates? (solution)
//6.How are duplicates removed from a given array in Java? (solution)
//7.How is an integer array sorted in place using the quicksort algorithm? (solution)
//8.How do you remove duplicates from an array in place? (solution)
//9.How do you reverse an array in place in Java? (solution)
//10.How are duplicates removed from an array without using any library? (solution)
//


#include <bits/stdc++.h>

using namespace std;


class Solution
{
  
public:

  constexpr long int fib(int n)
  {
    return (n <= 1) ? n : fib(n-1) + fib(n-2);
  }
  
  void TestQ0()
  {
    const long int result = fib(30);
    cout << result << std::endl;
  }
  
  // structured bindinf declaration

  /*
  struct yay
  {
    int a;
    float b;
    std::string c;
  };

  yay foo();
  auto [a,b,c] = foo();
  */

  std::tuple<char, int, bool>
  myTuple(char c, int v, bool bV)
  {
    char a = c;
    int i = v;
    bool b = bV;

    return std::make_tuple(a, i, b);
  }
  
  void TestQ1()
  {
    char a;
    int i;
    int bv;

    std::tie(a, i, bv) = myTuple('a', 100, true);

    cout << a << " : " << i << " : ";
    std::string re =  bv? "true" : "false";
    cout << re << std::endl;
  }
  
  void TestQ2()
  {
  }
  
  void TestQ3()
  {
  }

  void TestQ4()
  {
  }  

  void TestQ5()
  {
  }  
};


int main(int argc, char* argv[] )
{
   Solution s;
   //s.TestQ0();
   s.TestQ1();
   //s.TestQ2();
   //s.TestQ3();
   //s.TestQ4();
   //s.TestQ5();
   
  return 0;
}
