#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

string JumbleWord(string givenWord)
{
	srand(time(0));

	string jumble = givenWord;
	int length = jumble.size();

	for(int i = 0; i < length; i++)
	{
		int index1 = rand() % length;
		int index2 = rand() % length;

		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;

	}

	return jumble;
}

int main(int argc, char const *argv[])
{
	string str;

	cout << "Enter a string: " << endl;
	cin >> str;
	string jumble = JumbleWord(str);
	cout << "\nJumbled string: \n" << jumble << endl << endl;

	return 0;
}
