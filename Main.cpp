/**
 * Name: Joshua Venable
 * Class: CPSC 122, Fall 2021
 * Date: 11/19/2021
 * Programming Assigment: PA6
 * Description: Player battle that focuses on recursion, Linked Lists, ADTs, and Inheritance
 * Notes: 
 * Questions:  Can I include things like 'stagger' where there's a chance the other player cannot attack, and so the turn ends?
 * 
 * 11/19/21 - file creation
 **/

#include "header.h"
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
int main(void)
{
	srand(1);
	
	return 0;
}

