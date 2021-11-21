/**
 * Name: Joshua Venable
 * Class: CPSC 122, Fall 2021
 * Date: 11/19/2021
 * Programming Assigment: PA6
 * Description: Player battle that focuses on recursion, Linked Lists, ADTs, and Inheritance
 * Notes: 
 * 
 * 11/19/21 - file creation
 * 11/19/21 - all methods for Player doubly linked list created
 * 11/21/21 - creating constructors, destructors, and virtual methods for inherited classes
 * 11/21/21 - all of player methods finished
 **/

#include "header.h"

//-----------------------------PLAYERINVENTORY FUNCTIONS-----------------------------

/**
 * Name: Joshua Venable
 * Date created: 11/19/21
 * Date last modified: 11/19/21
 * Description: constructor for PlayerInventory instance
 * @pre uninitialized inventory
 * @post initlialized inventory setting head to null
 **/
PlayerInventory::PlayerInventory()
{
    headPtr = nullptr;
    headPtr->prevSlot = nullptr;
    headPtr->nextSlot = nullptr;
    length = 0;
}

/**
 * Name: Joshua Venable
 * Date created: 11/19/21
 * Date last modified: 11/19/21
 * Description: adds a node for new inventory item to the doubly linked list at position
 * @param newInventoryData the new data to be added as a node
 * @param index the index the data will be added to
 * @return whether or not the data is able to be added
 * @pre nothing changed to the doubly linked list 
 * @post doubly linked list with added node or let know that node could not be added
 **/
bool PlayerInventory::insertAtPosition(PlayerInventoryData *newInventoryData, int index)
{
    PlayerInventoryData *nodePtr = headPtr;
    PlayerInventoryData *prevNodePtr = nullptr;
    int pos = 1;
    //while nodePtr isn't at the end and hasn't hit the index to put data in, increment
    while (nodePtr != nullptr && pos != index)
    {
        prevNodePtr = nodePtr;
        nodePtr = nodePtr->nextSlot;
        pos++;
    }
    //if the pointer has reached the index then add the node
    if (pos == index)
    {
        prevNodePtr->nextSlot = newInventoryData;
        newInventoryData->prevSlot = prevNodePtr;
        newInventoryData->nextSlot = nodePtr;
        length++;
        return true;
    }
    //else if the node has reached the end but hasn't found the index just add to end
    else if (prevNodePtr != nullptr)
    {
        newInventoryData->nextSlot = nodePtr;
        prevNodePtr->nextSlot = newInventoryData;
        newInventoryData->prevSlot = prevNodePtr;
        length++;
        return true;
    }
    return false;
}

/**
 * Name: Joshua Venable
 * Date created: 11/19/21
 * Date last modified: 11/19/21
 * Description: adds an item to the end of the doubly linked list
 * @param newInventoryData pointer object pointing to new node PlayerInventoryData
 * @return whether or not the item could be added
 * @pre unedited piece of doubly linked list
 * @post added or unadded node to doubly linked list
 **/
bool PlayerInventory::insertAtEnd(PlayerInventoryData *newInventoryData)
{
    return insertAtPosition(newInventoryData, length - 1);
}

/**
 * Name: Joshua Venable
 * Date created: 11/19/21
 * Date last modified: 11/19/21
 * Description: removes the item in the inventory whose name matches
 * @param nameOfInventoryItem name of item to be removed as a string
 * @return whether an item was removed or not
 * @pre a doubly linked list as is
 * @post doubly linked list that either removed an item or didn't find it
 **/
bool PlayerInventory::removeItem(string nameOfInventoryItem)
{
    PlayerInventoryData *nodePtr = headPtr;
    PlayerInventoryData *prevNodePtr = headPtr;

    //if the head is the item to be removed edit the head
    if (headPtr->weaponName == nameOfInventoryItem)
    {
        nodePtr = headPtr->nextSlot;
        delete headPtr;
        headPtr = nodePtr;
        length--;
        return true;
    }
    else
    {
        //while the nodePtr isn't at the end and the name isn't the same as the item to be removed
        while (nodePtr != nullptr && nodePtr->weaponName != nameOfInventoryItem)
        {
            prevNodePtr = nodePtr;
            nodePtr = nodePtr->nextSlot;
        }
        //if the previous node isn't hitting null and the nodePtr isn't hitting null (to prevent outofBounds error)
        //  then we delete the node that matches the name
        if (prevNodePtr != nullptr && nodePtr != nullptr)
        {
            prevNodePtr->nextSlot = nodePtr->nextSlot;
            nodePtr->nextSlot->prevSlot = prevNodePtr;
            delete nodePtr;
            length--;
            return true;
        }
        prevNodePtr = nodePtr;
    }
    return false;
}

/**
 * Name: Joshua Venable
 * Date created: 11/19/21
 * Date last modified: 11/19/21
 * Description: displays all of the inventory items to console
 * @return nothing
 * @pre unprinted out all items
 * @post printed out all items to console
 **/
void PlayerInventory::displayAllItems(PlayerInventoryData *inventoryData) const
{
    //ending condition for recursion
    if (inventoryData == nullptr)
    {
        return;
    }
    //recursive else statement
    else
    {
        cout << "Weapon: " << inventoryData->weaponName << " - damage: " << inventoryData->damage << endl;
        displayAllItems(inventoryData->nextSlot);
    }
    cout << "Size: " << length << endl;
}

/**
 * Name: Joshua Venable
 * Date created: 11/19/21
 * Date last modified: 11/19/21
 * Description: erases all of the inventory data
 * @return whether all data could be erased
 * @pre unedited doubly linked list
 * @post completlely destroyed doubly linked list
 **/
bool PlayerInventory::erase(void)
{
    PlayerInventoryData *nodePtr;
    PlayerInventoryData *nextPtr;
    //if head of list is empty
    if (headPtr == nullptr)
    {
        delete headPtr;
        return true;
    }
    else
    {
        nodePtr = headPtr;
        //while nodePtr isn't at the end delete the node
        while (nodePtr != nullptr)
        {
            nextPtr = nodePtr->nextSlot;
            delete nodePtr;
            nodePtr = nextPtr;
        }
    }
    //if everything was deleted
    if (headPtr == nullptr)
    {
        return true;
    }
    return false;
}
int PlayerInventory::size(void)
{
    PlayerInventoryData *nodePtr = headPtr;
    length = 0;
    //while nodePtr isn't at the end increment length of list
    while (nodePtr != nullptr)
    {
        length++;
        nodePtr = nodePtr->nextSlot;
    }
    return length;
}
//-----------------------------PLAYER FUNCTIONS---------------------------------------

/**
 * Name: Joshua Venable
 * Date created: 11/19/21
 * Date last modified: 11/19/21
 * Description: Gets a random number from 1 to MAX_ID_VALUE
 * @return the random number as an integer
 * @pre an unchosen random number
 * @post a randomly chosen number generated from srand(1)
 **/
int Player::generatePlayerId() const
{
    int randNum = 0;
    bool flag = true;
    while(playerIdIsInList(randNum) || flag)
    {
        randNum = (rand() % MAX_ID_VALUE) + 1; //random number between 1 and MAX_ID_VALUE inclusive
        flag = false;
    }
    playerIds.push_back(randNum);
    return (randNum);
}

/**
 * Name: Joshua Venable
 * Date created: 11/21/21
 * Date last modified: 11/21/21
 * Description: Generates random stats for a player given a min and max number
 * @param min the minimum a value can be
 * @param max the maximum a value can be
 * @return the number that was generated
 * @pre an unknown stat value
 * @post a known and returned stat value
 **/
int Player::generateRandomStat(int min, int max) const
{
    int randStat;
    randStat = (rand() % max) + min;
    return randStat;
}

/**
 * Name: Joshua Venable
 * Date created: 11/21/21
 * Date last modified: 11/21/21
 * Description: checks whether an id is in the list of pre-existing ids
 * @param id the integer to check for
 * @return true or false regarding if id is in the vector
 * @pre unknown whether id is in the vector
 * @post known whether id is in the vector
 **/
bool Player::playerIdIsInList(int id)
{
    for (int i = 0; i < playerIds.size(); i++)
    {
        if (playerIds.at(i) == id)
        {
            return true;
        }
    }
    return false;
}

/**
 * Name: Joshua Venable
 * Date created: 11/21/21
 * Date last modified: 11/21/21
 * Description: prints out the battle card for the players per turn
 * @param p1 the first player
 * @param p2 the second player
 * @param turn the turn it is as an int
 * @return nothing
 * @pre nothing printed out
 * @post both players data printed out to console
 **/
template <class T1, class T2>
void Player::printBattleCard(T1 p1, T2 p2, int turn)
{
}

/**
 * Name: Joshua Venable
 * Date created: 11/21/21
 * Date last modified: 11/21/21
 * Description: determines whether a hit is successful 
 * @param p1 the first player given as reference
 * @param p2 the second player given as a const reference
 * @return true or false whether or not there was a successful hit
 * @pre two players ready to hit each other
 * @post one player may have hitten another
 **/
/*
*  //TODO: your comment block
*  This function accepts two template objects
*  p1 is the attacking player, p2 is the player receiving the attack
*  p1 is by reference and modifyable, p2 is a constant reference
*  This function determines whether a hit (p1 > p2) was successful
*  and returns true on a successful hit
*  if p1 is successful, they gain experience
*  hit% is dependent on the type of subclass for each class
*  e.g., InheritedClass1 might hit 60% of the time while
*  InheritedClass2 might hit 10% of the time
*/
template <class T1, class T2>
bool Player::attackPlayerSuccess(T1 &p1, const T2 &p2)
{
}

//-----------------------------ROGUE FUNCTIONS----------------------------------------

Rogue::Rogue() : Player()
{
    subclass = "Rogue";
    critChance = -1;
}

Rogue::~Rogue()
{
    playerInventory.erase();
}

/**
 * Name: Joshua Venable
 * Date created: 11/21/21
 * Date last modified: 11/21/21
 * Description: initializes data of rogue player
 * @param newName the string going to be set to the Rogues name
 * @return nothing
 * @pre an uninitialized rogue player
 * @post an initialized rogue player
 **/
void Rogue::initializePlayer(string newName)
{
    this->name = newName;
    this->critChance = generateRandomStat(1, 30);
    this->playerId = generatePlayerId();
    this->health = generateRandomStat(50, 100);
    this->experience = 0;
}

//-----------------------------NINJA FUNCTIONS----------------------------------------

Ninja::Ninja() : Rogue()
{
    specialty = "Ninja";
    sneakyDamage = -1;
}

Ninja::~Ninja()
{
    playerInventory.erase();
}

/**
 * Name: Joshua Venable
 * Date created: 11/21/21
 * Date last modified: 11/21/21
 * Description: initializes data of ninja, rogue player
 * @param newName string going to be set to Ninjas name
 * @return nothing
 * @pre uninitialized ninja player
 * @post initialized ninja player
 **/
void Ninja::initializePlayer(string newName)
{
    this->name = newName;
    this->playerId = generatePlayerId();
    this->health = generateRandomStat(40, 90);
    this->critChance = generateRandomStat(10, 45);
    this->sneakyDamage = generateRandomStat(1, 8);
    this->experience = 0;
}

//-----------------------------MAIN FUNCTIONS-----------------------------------------