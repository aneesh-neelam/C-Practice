#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::endl;

int main(int argc, char const *argv[]) 
{
	srand(time(0));
	int randomNumber = rand();
	int die = (randomNumber % 6) + 1;

	cout << die << " rolled. " << endl;

	return 0;
}
