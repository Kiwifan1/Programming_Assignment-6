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
 * 12/4/21 - added code for filling list and for continuing the battle
 **/

#include "header.h"

int main(void)
{

	srand((unsigned) time(0));
	Rogue player1 = Rogue();
	Ninja player2 = Ninja();
	int turn = 1;
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

