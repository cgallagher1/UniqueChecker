/* Problem 1.01
1.01 Is Unique: Implement an efficient function to determine if a string has all unique characters. 
(By “efficient”, we mean one pass through the string.) 
Then implement another function that solves the same problem without additional data structures. 

Assume that the string uses the ASCII character set 0-127.*/
#include <iostream>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//Return true whenever a given string has all unique characters
bool is_unique1(string s)
{
	if(s.length() > 128)
		return false;		//Because there are only 128 different characters!

    //Declare an array with indices 0-127.
    int array[128] = {};
    //Pass through the string using the array to keep track of characters
    //and return false if something is previously marked off.
    for(int i = 0; i < s.length(); i++)
    {
        int value = s[i];
        array[value] = array[value] + 1;
        if(array[value] > 1)
        {
            return false;
        }
    }
	//One pass through the string suffices, so we say the function has
	//order n where n is the string's length.

	return true;	//Replace this and test the function.
}

//Return true whenever a given string has all unique characters
bool is_unique2(string s)
{
	if(s.length() > 128)
		return false;		//Because there are only 128 different characters!

    //Compare each character to every other character with nested for loops.
    for(int i = 0; i < s.length(); i++)
    {
		for(int j = i+1; j < s.length();j++)
		{
			if(i == j)
			{
				return false;
			}
		}
    }
	//We pass through the string roughly once for each character, so we say the function has
	//order n^2 where n is the string's length

	return true;	//Replace this and test the function.
}

//Return true whenever a given string has all unique characters
bool is_unique3(string s)
{
	//sort the string
	sort(s.begin(), s.end());
	
	//Now we can step through the string to see if any adjacent characters are the same.
	for(int i = 0; i < s.length()-1; i++)
	{
		if(i == i+1)
		{
			return false;
		}
	}
	
	return true;	//Replace this and test the function.

}

/*Analysis
is_unique1 is order n, but it requires more memory to hold the "check-off" array."
is_unique2 works in place, meaning it needs no extra memory. But it is slow -- order n^2.
is_unique3 requires no extra memory but requires sort (order nlog(n)) and single pass through the string (order n).
*/


int main()
{
	cout << "Problem 1.01." << endl;

	cout << "string \"abadef\" -- is_unique1 returns " << is_unique1("abadef") << endl;
	cout << "string \"abcdef\" -- is_unique1 returns " << is_unique1("abcdef") << endl << endl;


	cout << "string \"abadef\" -- is_unique2 returns " << is_unique2("abadef") << endl;
	cout << "string \"abcdef\" -- is_unique2 returns " << is_unique2("abcdef") << endl << endl;

	cout << "string \"abadef\" -- is_unique3 returns " << is_unique3("abadef") << endl;
	cout << "string \"abcdef\" -- is_unique3 returns " << is_unique3("abcdef") << endl << endl;

	system("pause");
	return 0;
}