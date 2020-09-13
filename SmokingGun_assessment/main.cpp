//C++ Evaluation & Problem Question

#include <bits/stdc++.h>
using namespace std;

// C++ Evluation Part 1 of 2
struct Point2D
{
  Point2D( float xIn, float yIn )
  {
    x = xIn;
    y = yIn;
  }
  
  float x;
  float y;
};

class Rect
{
  
public:
  Rect():m_x(0.0),m_y(0.0),m_width(0.0),m_height(0.0){}
  Rect(float x, float y, float w, float h)
    :m_x(x),m_y(y),
     m_width(w),m_height(h)
  {}

  // Copy constructor 
  Rect(const Rect& obj)
  {
    m_x      = obj.m_x;
    m_y      = obj.m_y;
    m_width  = obj.m_width;
    m_height = obj.m_height;
  }
  
  // Assignment operator
  Rect& operator = (const Rect& obj)
  {
    m_x      = obj.m_x;
    m_y      = obj.m_y;
    m_width  = obj.m_width;
    m_height = obj.m_height;
        
    return *this; 
  }

  bool ContainPoint(const Point2D& obj)
  {
    
    if( (obj.x >= m_x && obj.x <= (m_x + m_width )) &&
	(obj.y >= m_y && obj.y <= (m_y + m_height))    )
      {
	return true;
      }

    return false;    
  }

    bool Intersect( const Rect& obj)
    {
      if( ( ( m_x + m_width  ) < obj.m_x ) || ( m_x > ( obj.m_x + obj.m_width ) ) ||
	  ( ( m_y + m_height ) < obj.m_y ) || ( m_y > ( obj.m_y + obj.m_height) )   )
	{
	  return false;
	}

      return true;
    } 



protected:
  float m_x;
  float m_y;
  float m_width;
  float m_height;  
};

void testContainPoint()
{
  Rect rect(3.0f,3.0f,10.0f,10.0f);

  Point2D ptIn(5,5);
  if( rect.ContainPoint(ptIn) )
  {
      cout << "test ContainPoint case 1 sucessful" << endl;
  }
  else
  {
      cout << "test ContainPoint case 1 failed" << endl;
  }

  Point2D ptOut(0,0);
  if( !rect.ContainPoint( ptOut ) )
  {
      cout << "test ContainPoint case 2 sucessful" << endl;
  }
  else
  {
      cout << "test ContainPoint case 2 failed" << endl;
  }
}

void testIntersect()
{
  Rect rect(3.0f,3.0f,10.0f,10.0f);
  
  Rect rectIn(4.0f,4.0f,10.0f,10.0f);
  if( rect.Intersect(rectIn) )
  {
      cout << "test Intersect case 1 sucessful" << endl;
  }
  else
  {
      cout << "test Intersect case 1 failed" << endl;
  }

  Rect rectOut(14.0f,4.0f,10.0f,10.0f);
  if( !rect.Intersect( rectOut ) )
  {
      cout << "test Intersect case 2 sucessful" << endl;
  }
  else
  {
      cout << "test Intersect case 2 failed" << endl;
  }
}

// Problem Part - 2/2
/* check primes */

int Primes[] = {2, 3, 5};
int startNum = 7;

bool isPrime(long long int Num)
{
  // check if it is the primes in the table
  for( int i = 0; i < 3; i++)
    {
      if( Num == Primes[i] )
	{
	  return true;
	}
    }

  // check divisibility with prime table
  for( int i = 0; i < 3; i++)
    {
      if( Num % Primes[i] == 0)
	{
	  return false;
	}
    }

  // main iteration for Primality check
  
  long long int _upMargin = (long long int) sqrt(Num);
  int                   j = startNum;
  bool                ret = true;

  while( j <= _upMargin )
    {
      if( Num % j == 0 )
	{
	  ret = false;
	  break;
	}
      else
	{
	  j += 2;
	}
    }
  
  return ret;
}

vector<long long int> factorize( long long int Num)
{
  vector<long long int> vFactors;  
  long long int _num = Num;

  for( int k = 0; k < 3; k++)
    {
      int m = Primes[k];

      if( _num < m )
	{
	  break;
	}

      while( _num % m == 0)
	{
	  vFactors.push_back(m);
	  _num = (long long int) _num/m;
	}
    }

  if( _num < startNum )
    {
      sort(vFactors.begin(), vFactors.end());
      return vFactors;
    }

  long long int _upMargin = (long long int) sqrt(_num) + 1;
  long long int i = startNum;

  while( i <= _upMargin )
    {
      if( _num % i == 0)
	{
	  vFactors.push_back(i);
	  _num = _num / i;

	  _upMargin = (long long int ) sqrt(_num) + 1;
	  i = startNum;
	}
      else
	{
	  i += 2;
	}
    }
  vFactors.push_back(_num);
  sort(vFactors.begin(), vFactors.end());

  return vFactors;  
}
  

void printOutMultiples()
{
  long long int n = 2;
        int count = 2;

  do{
    vector<long long int > factors = factorize(n);

    int count2 = std::count(factors.begin(), factors.end(), 2);
    int count3 = std::count(factors.begin(), factors.end(), 3);
    int count5 = std::count(factors.begin(), factors.end(), 5);

    if( ( count2 + count3 + count5) == factors.size())
      {
	cout << count << " : " << n << endl;	
	count++;
      }
    
    n++;
    
    }while( count <= 1500);
 }

int main(int argc, char* argv[] )
{
  //testContainPoint();
  //testIntersect();
  //for( int i  = 0; i < 18; i++)
  //{
  //  unsigned long result = findNumAtPos(i);
  //  printf(" multiples at pos: %6d is:  %ld\n", i, result);
  //}

  printOutMultiples();

  return 0;
}
