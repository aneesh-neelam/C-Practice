#include <iostream>

using std::cout;
using std::endl;

enum difficulty{Recruit, Regular, Veteran, Hardened};

int main(int argc, char const *argv[]) 
{
	difficulty myDifficulty = Regular;
	switch(myDifficulty) 
	{
		case 0: 
			cout << "Difficulty chosen: Recruit" << endl;
			break;
		case 1: 
			cout << "Difficulty chosen: Regular" << endl;
			break;
		case 2: 
			cout << "Difficulty chosen: Veteran" << endl;
			break;
		case 3: 
			cout << "Difficulty chosen: Hardened" << endl;
			break;
	}
	
	return 0;
}
