/*
	CPSC 122
	PA6 - Players Starter Code
	You should NOT be submitting a file named "pa6Starter.cpp"
	Please use this as a starting point.
	Cite all sources used.
*/



using namespace std;



int main(void)
{
	//Recall, since Player is an Abstract Base Class, you cannot declare a Player variable.
	//You must declare instances of your derived classes.

	//Main Tasks:
	//declare and initialize an instance of InheritedClass1 and InheritedClass2
	// Note: be creative! You do not have to follow my "Wizard" example as long as you
	// meet the requirements
	// 
	// Task: demonstrate use of your list class object -> insertion
	// "fill up" each of your players' inventory with at least 10 items from your possibleItems
	// list. These should be chosen randomly. Duplicates are fine.
	// What are you filling up? Each player will have a protected member "playerInventory" that
	// is your "list" (doubly linked list, stack linked list, or queue linked list) where you 
	// can add and remove "items" from.
	// 
	// Task: demonstrate use of your class object -> printing contents
	// Reminder: printing your list contents should be done in forward order via a recursive function
	// before starting the 'game' print out the contents of one player's list.
	// 
	// Task: demonstrate use of your list class object -> deletion/removal
	// remove an item from the list.
	
	// Task: demonstrate use of your class object -> printing contents
	// Reminder: printing your list contents should be done in forward order via a recursive function
	// print the contents of the list again.
	// 
	//print out their starting info
	//force the two class objects to fight each other!
	//at the start of each turn, display their health
	//for each turn, display
	//	1. who is attacking who
	//	2. which weapon they are using
	//	3. hit and damage (or miss)
	// damage should be deducted from target player health
	// hits should grant experience to the attacking player
	//when one player health drops to 0 or lower, the 'game' ends.
	//display a message indicating the winner and display the ending player info

	return 0;
}

/*
*  //TODO: your comment block
*  This function accepts two template objects
*  p1 is the attacking player, p2 is the playe receiving the attack
*  p1 is by reference and modifyable, p2 is a constant reference
*  This function determines whether a hit (p1 > p2) was successful
*  and returns true on a successful hit
*  if p1 is successful, they gain experience
*  hit% is dependent on the type of subclass for each class
*  e.g., InheritedClass1 might hit 60% of the time while
*  InheritedClass2 might hit 10% of the time
*/
template<class T1, class T2>
bool Player::attackPlayerSuccess(T1& p1, const T2& p2)
{
	return false;
}
