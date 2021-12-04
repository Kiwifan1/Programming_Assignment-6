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
 * 12/2/21 - added methods to main for running program, fixed how list is filled.
 * 12/3/21 - all functions and methods added, everything works except the inventory
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
	Rogue player1 = Rogue();
	Ninja player2 = Ninja();
	int turn = 0;
	bool hit = false;

	player1.initializePlayer("Jameson");
	player2.initializePlayer("Colby");

	player1.fillList(5);
	player2.fillList(5);

	cout << "Filled the linked list...\n";

	player1.showAllItems();

	cout << "Demonstrating Removing an item from the list...\n";

	player1.removeItem();
	player1.showAllItems();

	cout << "\nWelcome to the battle arena!\n";
	cout << "Today we will be seeing a battle between two Rogues!\n";
	cout << "Our first participant is: \n";
	player1.printPlayerInfo();
	cout << "And our second participant is: \n";
	player2.printPlayerInfo();
	cout << "\nLet the battle commence! \n";

	//while loop that makes them battle till one dies
	while(player1.getHealth() > 0 && player2.getHealth() > 0)
	{
		//must include battling method here
		player1.printBattleCard(player1, player2, turn);
		hit = player1.attackPlayerSuccess(player1, player2);
		player1.hitPlayer(player1, player2, hit);
		hit = player2.attackPlayerSuccess(player2, player1);
		player2.hitPlayer(player2, player1, hit);
		turn ++;
	}
	//if player 1 wins
	if(player1.getHealth() > 0)
	{
		cout << endl << player1.getName() << " wins!" << endl;
		cout << endl << "Ending Info:" << "\n\n";
		player2.printPlayerInfo();
		player1.printPlayerInfo();
	}
	//else if player 2 wins
	else
	{
		cout << endl << player2.getName() << " wins!" << endl;
		cout << endl << "Ending Info:" << "\n\n";
		player1.printPlayerInfo();
		player2.printPlayerInfo();
	}

	return 0;
}

