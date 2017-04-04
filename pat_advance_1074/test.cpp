#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

int _main()
{
	list<int> coll;

	for (int i = 1; i <= 9; ++i)
	{
		coll.push_back(i);
	}

	list<int>::iterator pos = coll.begin();
	cout << *pos << endl;

	advance(pos, 3);
	cout << *pos << endl;

	advance(pos, -1);
	cout << *pos << endl;

	return 0;
}