#include <iostream>

using namespace std;

/*
Idea is to use ASCII value from a-z(97-122) in order to save the number of occurance of a specific character

Also converting a-z char of a string and saving it as an int

This only works because problem constraint states that string only contains a-z characters.

For more you can also use 256 array to incorporate all ASCII characters.
*/


int charToIntIndex (char character)
{
  int ascii = (int) character;
  //cout << (int) character << endl;
  int index = (123 - ascii) - 26;	//index from 0 to 25
  if (index < 0)
	{
	  index = -index;
	}
  return index;					//
}

void printArray (int *a, int size)
{
  cout << endl;
  for (int i = 0; i < size; i++)
	{
	  cout << a[i] << ",";
	}
}

//Without map but with constraints that contains only 26 letters
#define TOTAL_CHAR 26
bool withConstraints (string s, string t)
{

  if (s.size () != t.size ())
	{
	  return false;
	}

  int sArray[TOTAL_CHAR] = { 0 };	// lowercase a-z = 97 to 122 , init with 0s
  int tArray[TOTAL_CHAR] = { 0 };

  for (int i = 0; i < s.size (); i++)
	{
	  // cout << charToIntIndex(s[i]) << endl;
	  sArray[charToIntIndex (s[i])]++;
	  tArray[charToIntIndex (t[i])]++;
	}

  //printArray(sArray, 26);
  //printArray(tArray, 26);

  for (int i = 0; i < 26; i++)
	{
	  if (sArray[i] != tArray[i])
		{
		  return false;
		}
	}

  return true;
}


int main ()
{

  // cout << charToIntIndex('d') << endl;

  //index must match for both to compare the right one.
  string s1[] = { "ae", "anagram", "danger", "salesman", "rat", "ajay" };
  string s2[] = { "fe", "anagram", "garden", "nameless", "car", "ajay" };

  //cout << endl << withConstraints("ae", "fe") << endl; 
  // 0 false 1 true

  int size = sizeof (s1) / sizeof (string);

  for (int i = 0; i < size; i++)
	{
	  if (withConstraints (s1[i], s2[i]))
		{
		  cout << "Anagrams";
		}
	  else
		{
		  cout << "Not anagrams";
		}
		cout << endl;
	}


  //cout << ajay << endl;
}
