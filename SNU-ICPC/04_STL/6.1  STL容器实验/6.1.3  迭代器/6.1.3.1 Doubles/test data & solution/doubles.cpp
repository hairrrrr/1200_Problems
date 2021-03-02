// 2003 ACM Mid-Central Regional Programming Contest
// Problem F: Doubles
// by Greg Eastman, Drury University

#include <iostream>
#include <fstream>
#include <set>
using namespace std;
 
////////////////////////////////////////////////////////
//The set is fairly well optimized for insertion and
//lookup, averaging on the order of logn where n is the
//number of items in the set.  Not really needed as
//a simple brute force search will suffice with such small
//lists.
typedef set<int> INT_SET;
const int MAX_LIST = 15;

int main()
{
	INT_SET int_set;
	//Used to traverse the set
	INT_SET::const_iterator int_set_iter;
	//Used when testing that some element is double another.
	INT_SET::const_iterator int_set_find;
	//File I/O
	ifstream in;
	ofstream out;
	//Used for console output
	int listcount = 0;
	int elcount;
	//Used for contest output
	int number;
	int double_count;

	in.open("doubles.in");
	if(in.fail())
	{
		cout << "Unable to open input." << endl;
		exit( 1 );
	}
	out.open("doubles.out");
	if(out.fail())
	{
		cout << "Unable to open output." << endl;
		in.close();
		exit( 1 );
	}
	//Assumptions - No empty file, no empty line, no leading blanks,
	//no trailing blanks
	in >> number;
	while (number > -1)
	{
		listcount++;
		elcount = 0;
		cout << "List " << listcount;
		int_set.clear();
		while(number > 0)
		{
			elcount++;
			int_set.insert(number);
			in >> number;
		}
		cout << " " << elcount << " elements";
		//Find doubles by traversing the list.  
		//Multiply each item by 2 and see if result is in the list. 
		double_count = 0;
		for(int_set_iter = int_set.begin(); int_set_iter != int_set.end(); int_set_iter++)
		{
				if(int_set.find(*int_set_iter * 2)!= int_set.end())
					double_count++;
		}
		/////////////////////////////////////////////////////////
		//Contest output
		out << double_count << endl;
		/////////////////////////////////////////////////////////
		//Console output
		cout << " " << double_count << " doubles" << endl;
		in >> number;
	}

	out.close();
	in.close();
	return 0;
}
