#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
	vector<string> inventory;
	vector<string>::const_iterator iter_ro;
	vector<string>::iterator iter_rw;

	inventory.push_back("Dagger");
	inventory.insert(inventory.begin(), "Pistol");
	inventory.insert(inventory.begin(), "Automatic Rifle");
	inventory.insert(inventory.end(), "Grenade");

	cout << "No. of items in inventory: " << inventory.size() << endl << endl;
	cout << "Items in Inventory, in order: " << endl;
	for (iter_ro = inventory.begin(); iter_ro != inventory.end(); ++iter_ro )
	{
		cout << *iter_ro << endl;
	}

	string oldWeapon = "Dagger";

	for (iter_rw = inventory.begin(); iter_rw != inventory.end(); ++iter_rw )
	{
		if ( oldWeapon==(*iter_rw) )
		{
			*iter_rw = "Knife";
			cout << "\nDagger has been replaced by the standard military issue knife. " << endl << endl;
		}
	}

	cout << "No. of items in inventory: " << inventory.size() << endl << endl;
	cout << "Items in Inventory, in order: " << endl;
	for (iter_ro = inventory.begin(); iter_ro != inventory.end(); ++iter_ro )
	{
		cout << *iter_ro << endl;
	}

	inventory.clear();
	cout << "\nA thief has stolen all your items. " << endl;
	cout << "No. of items in inventory: " << inventory.size() << endl << endl;
	cout << "Items in Inventory, in order: " << endl;
	for (iter_ro = inventory.begin(); iter_ro != inventory.end(); ++iter_ro )
	{
		cout << *iter_ro << endl;
	}	

	return 0;
}
