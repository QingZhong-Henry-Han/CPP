//
// 1. How do you reverse a given string in place? (solution)
// 2. How do you print duplicate characters from a string? (solution)
// 3. How do you check if two strings are anagrams of each other? (solution)
// 4. How do you find all the permutations of a string? (solution)
// 5. How can a given string be reversed using recursion? (solution)
// 6. How do you check if a string contains only digits? (solution)
// 7. How do you find duplicate characters in a given string? (solution)
// 8. How do you count a number of vowels and consonants in a given string? (solution)
// 9. How do you count the occurrence of a given character in a string? (solution)
// 10. How do you print the first non-repeated character from a string? (solution)
// 11. How do you convert a given String into int like the atoi()? (solution)
// 12. How do you reverse words in a given sentence without using any library method? (solution)
// 13. How do you check if two strings are a rotation of each other? (solution)
// 14. How do you check if a given string is a palindrome? (solution)
// 15. How do you find the length of the longest substring without repeating characters? (solution)
//      Given string str, How do you find the longest palindromic substring in str? (solution)
// 16. How to convert a byte array to String? (solution)
// 17. how to remove the duplicate character from String? (solution)
// 18. How to find the maximum occurring character in given String? (solution)
// 19. How do you remove a given character from String? (solution)
// 20. How to check if the string is Palindrome


#include <bits/stdc++.h>

using namespace std;


class Solution
{
  
public:

  //Q1.
  void reverseStringInPlace(char s[], int left, int right)
  {
    if(left >= right )
      {
	return;
      }
    
    char tmp = s[left];
    s[left++] = s[right];
    s[right--] = tmp;
    reverseStringInPlace(s, left, right);
  }

  //Q2.
  void printDuplicateChar(string &s)
  {
    map<char, int> mapCount;
    for(int i = 0; i < s.length(); i++)
      {
	if(mapCount.find(s[i]) == mapCount.end())
	  {
	    mapCount.insert({s[i], 1});
	  }
	else
	  {
	    mapCount[s[i]] =  ++mapCount[s[i]];
	  }
      }

    for(auto it = mapCount.begin(); it != mapCount.end(); it++)
      {
	if( it->second > 1)
	  {
	    cout << it->first << " : " << it->second << " ";
	  }
      }
    cout << "\n";
  }

  //Q3.
  // two string has the same characters
  bool anagramCheck(string s1, string s2)
  {
    if(s1.length() != s2.length())
      {
	return false;
      }
    
    bool bResult = true;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    for(int i = 0; i > s1.length(); i++)
      {
	if(s1[i] != s2[i])
	  {
	    return false;
	  }
      }

    return bResult;
  }

  //Q4.
  void printPermutations(string &s, int l, int r)    
  {
    //base case
    if(l == r)
      {
	cout << s << "\n";
      }
    else
      {
	for(int i = l; i <= r; i++)
	  {
	    //Swapping done
	    swap(s[l], s[i]);

	    //Recursion done
	    printPermutations(s, l+1, r);

	    //backtrack
	    swap(s[l], s[i]);
	  }
      }
  }

  //5.
  void findMultDuplicatesInArr(int nums[], int N)
  {

  }

  //6
  void removeDuplicates(int nums[], int N)
  {
    
  }

  //7.
  void sortedinPlaceUsingQuickSort()
  {
  }

  //8.
  void removeDuplicateInPlace()
  {
  }

  //9.
  void reverseArrayInPlace()
  {
  }

  //10.
  void removeDuplicateWithoutUsingLib()
  {
    
  }

  // 18. How to find the maximum occurring character in given String? (solution)
  char findTheMaxOccurrCharIn(char* str)
  {
    if (str == nullptr)
      {
	return NULL;
      }

    int freq[26] ={0};

    while( *str != '\0' )
      {
	char c = tolower(*str);
	if( c >= 'a' and c <= 'z')
	  {
	    freq[c-'a']++;	      
	  }
	str++;
      }

    int max = -1;
    char result;
    for(int i = 0; i < 26; i++)
      {
	if(max < freq[i])
	  {
	    max = freq[i];
	    result = (char)(i+'a');
	  }
      }
    
    return result;
  }

  void TestQ18()
  {
    char str[] = "Zzz ZZZ AAA z a ccc ";
    cout << "Maximum char is:" << findTheMaxOccurrCharIn(str) << endl;
  }

  // 20. How to check if the string is Palindrome
  bool isStringPalindrome(string s)
  {
    // if string is empty
    if(s.size() == 0)
      {
	return false;
      }
    
    bool bResult = true;

    int i = 0;
    int j = s.size()-1;
    do{
      if(s[i] != s[j])
	{
	  bResult = false;
	  break;
	}
      i++;
      j--;
    }while(i<j);

    return bResult;
  }

  void TestQ1()
  {
    char s[] = {'h','e','l', 'l', 'o'};
    reverseStringInPlace(s, 0, 4);
    cout << s << "\n";
  }
  
  void TestQ2()
  {
    string s("hello");
    printDuplicateChar(s);
  }
  
  void TestQ3()
  {
    string s1("LISTEN");
    string s2("SILENT");
    if(anagramCheck(s1,s2) == true)
      {
	cout << s1 << " is the anagram of " << s2 << "\n";
      }
    
    string s3("TRIANGLE");
    string s4("INTEGRAL");
    if(anagramCheck(s3,s4) == true)
      {
	cout << s3 << " is the anagram of " << s4 << "\n";
      }

  }

  void TestQ4()
  {
    string s("ABC");
    printPermutations(s,0,2);
  }  

  void TestQ5()
  {

  }

  void TestQ20()
  {
    string answer = isStringPalindrome("radar")? "a palindrome " : " not a palindrome ";
    cout << "radar is " << answer << endl ; 

    answer = isStringPalindrome("raddar")? "a palindrome " : " not a palindrome ";
    cout << "raddar is " << answer << endl ; 
  }
 
};


int main(int argc, char* argv[] )
{
   Solution s;
   //s.TestQ0();
   //s.TestQ1();
   //s.TestQ2();
   //s.TestQ3();
   s.TestQ4();
   //s.TestQ18();
   //s.TestQ20();
   
  return 0;
}
