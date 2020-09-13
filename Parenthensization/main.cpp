// Algorithm questions:
//
// 1. Boolean Parenthensization
// 2. Counting Boolean Parenthensization using stack

#include <bits/stdc++.h>

using namespace std;

// interview question
//
//given a boolean expression with following symbols.
//Symbols
//    'T' ---> true 
//    'F' ---> false 
//And following operators filled between symbols

//Operators
//    &   ---> boolean AND
//    |   ---> boolean OR
//    ^   ---> boolean XOR 
//Count the number of ways we can parenthesize the expression
//so that the value of expression evaluates to true.

//Examples:
//
//Input: symbol[]    = {T, F, T}
//       operator[]  = {^, &}
//Output: 2
//The given expression is "T ^ F & T", it evaluates true
//in two ways "((T ^ F) & T)" and "(T ^ (F & T))"
//

//Input: symbol[]    = {T, F, F}
//       operator[]  = {^, |}
//Output: 2
//The given expression is "T ^ F | F", it evaluates true
//in two ways "( (T ^ F) | F )" and "( T ^ (F | F) )". 
//

//Input: symbol[]    = {T, T, F, T}
//       operator[]  = {|, &, ^}
//Output: 4
//The given expression is "T | T & F ^ T", it evaluates true
//in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) 
//and (T|((T&F)^T)).
//

class Solution
{
  
public:

  char Evalue(char symbols[], char operators[], int nOps, int opIndex, char c1, char c2, string& exp)
  {
    char result = 'F';
    switch(operators[opIndex])
      {
      case '&':
	if( c1 == 'T' && c2 == 'T')
	  {
	    result = 'T';
	  }
	else
	  {
	    result = 'F';
	  }
	break;
      case '|':
	if(c1 == 'T' || c2 == 'T')
	  {
	    result = 'T';
	  }
	else
	  {
	    result = 'F';
	  }
	break;
      case '^':
	if((c1 == 'T' && c2 == 'T') ||
	   (c1 == 'F' && c2 == 'F') )
	  {
	    result = 'F';
	  }
	else
	  {
	    result = 'T';
	  }
	break;
      }

    //    if(result == 'T' && opIndex < nOps)
    //      {
    //	if(opIndex == 0)
    //	  {
    //	    exp.push_back('(');
    //	    exp.push_back(c1);
    //	  }
    //	exp.push_back(operators[opIndex]);
    //	exp.push_back(c2);
    //	if(opIndex < nOps - 1)
    //	  {
    //	    exp.push_back(')');
    //	  }
    //	int nextOp = ++opIndex;
    //	char cNext = symbols[nextOp+1];

    //	if(nextOp < nOps)
    //	  {
    //	    return Evalue(symbols, operators, nOps, nextOp, result, cNext, exp);	    
    //	  }
    // }

    return result;
  }
  
  bool EvalueElems(char symbols[], char operators[], int iSymbol, int nOps, string& exp)
  {
    for( int i = 0; i < nOps; i++)
      {
	char c1 = symbols[i];
	char c2 = symbols[i+1];
	char result = Evalue(symbols, operators, nOps, i, c1, c2, exp);	
      }
    
    return false;
  }
  
  void waysOfParenthesize(char symbols[], char operators[], int nSymbols, int nOps)
  {
    // edge case
    string expression;
    for( int iOp = 0; iOp < nOps; iOp++)
      {
	if(iOp == 0 )
	  {
	    expression.push_back(symbols[iOp]);
	  }
	expression.push_back(operators[iOp]);
	expression.push_back(symbols[iOp+1]);	
      }
    
    cout << "expression: " << expression << "\n";
    
  string exp;
  for( int iOp = 0; iOp < nOps; iOp++)
    {
      for( int k = 0; k < iOp; k++)
	{
	  exp.push_back(symbols[k]);
	  exp.push_back(operators[k]);
	}
      
      char result = Evalue(symbols, operators, nOps, iOp, symbols[iOp], symbols[iOp+1], exp);
      if(result == 'T')
	{
	  cout <<"result: "<< result << " exp: "  <<  exp << "\n";
	}
    }
  }

  void printArr(int N, int T[3][3], int F[3][3])
  {
    cout << " T[][]:\n";
    for( int i = 0; i < N; i++)
      {
	for( int j = 0; j < N; j++)
	  {
	    cout << T[i][j] << " ";
	  }
	cout << "\n";
      }

    cout << "\nF[][]\n";

        for( int i = 0; i < N; i++)
          {
	    for( int j = 0; j < N; j++)
	      {
		cout << F[i][j] << " ";
	      }
	    cout << "\n";
	  }
       cout << "\n";

    
  }
  
  int countingBooleanParenthesize(char symbols[], char operators[], int N)
  {

    static int count = 0;
    int T[3][3], F[3][3];

    for(int i =0; i < N; i++)
      {
	for( int j =0; j < N; j++)
	  {
	    T[i][j] = -1;
	    F[i][j] = -1;
	  }
      }

    for(int i = 0; i < N; i++)
      {
	if(symbols[i] == 'T')
	  {
	    T[i][i] = 1;
	    F[i][i] = 0;
	  }
	else
	  {
	    T[i][i] = 0;
	    F[i][i] = 1;
	  }
      }

    for( int gap = 1; gap < N; ++gap)
      {
	for(int i = 0, j = gap; j < N; ++i, ++j)
	  {
	    T[i][j] = F[i][j] = 0;
	    for( int g = 0; g < gap; g++)
	      {
		int k = i + g;
		
              // Store Total[i][k] and Total[k+1][j] 
                int tik = T[i][k] + F[i][k]; 
                int tkj = T[k+1][j] + F[k+1][j]; 
  
                // Follow the recursive formulas according to the current 
                // operator 
                if (operators[k] == '&') 
                { 
                    T[i][j] += T[i][k]*T[k+1][j]; 
                    F[i][j] += (tik*tkj - T[i][k]*T[k+1][j]); 
                } 
                if (operators[k] == '|') 
                { 
                    F[i][j] += F[i][k]*F[k+1][j]; 
                    T[i][j] += (tik*tkj - F[i][k]*F[k+1][j]); 
                } 
                if (operators[k] == '^') 
                { 
                    T[i][j] += F[i][k]*T[k+1][j] + T[i][k]*F[k+1][j]; 
                    F[i][j] += T[i][k]*T[k+1][j] + F[i][k]*F[k+1][j]; 
                }

		//if(count == 0)
		//  {
		//    printArr(3, T, F);
		//    return 0;
		//  }
	      }	    
	  }
      }

    return T[0][N-1];
  }

  void testCases()
  {
    char symbol[]     = {'T', 'F','T'};
    char operators[]  = {'^', '&'};

    int nSymbol = 3;
    int nOps = 2;

    cout << "output: " <<  countingBooleanParenthesize(symbol, operators, 3) << "\n";
    //waysOfParenthesize(symbol, operators, nSymbol, nOps);
  }
};


int main(int argc, char* argv[] )
{
   Solution s;
   s.testCases();
   
  return 0;
}
