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
 * 11/19/21 - all methods for Player doubly linked list created
 * 11/21/21 - creating constructors, destructors, and virtual methods for inherited classes
 * 11/21/21 - all of player methods finished
 * 11/29/21 - added helping methods, overloaded some insert ones, and added things for filling lists and removing them
 * 12/2/21 - added declaration of static variables, added methods for helping creation of node
 * 12/3/21 - changed how some methos for battlescorecard worked
 * 12/4/21 - changed how destructors worked so it wouldn't pull error
 **/

#include "header.h"

int Player::numPlayers = 0;

vector<int> Player::playerIds;
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
    int pos = 0;
    if(headPtr == nullptr)
    {
        headPtr = newInventoryData;
        headPtr->nextSlot = nullptr;
        headPtr->prevSlot = nullptr;
        length++;
        return true;
    }
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
 * Date created: 11/29/21
 * Date last modified: 11/29/21
 * Description: Creates a PlayerInventoryData node and adds it to the end
 * @param weaponName the name of the weapon as a string
 * @param damage the damage the weapon does
 * @param index the index to add the item to
 * @return whether it could add to inventory
 * @pre unmade node
 * @post created node that has been added to inventory at specified index
 **/
bool PlayerInventory::insertAtPosition(string weaponName, int damage, int index)
{
    PlayerInventoryData newNode;
    newNode.damage = damage;
    newNode.weaponName = weaponName;
    newNode.prevSlot = nullptr;
    newNode.nextSlot = nullptr;
    return insertAtPosition(&newNode, index);
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
    return insertAtPosition(newInventoryData, length);
}


/**
 * Name: Joshua Venable
 * Date created: 12/2/21
 * Date last modified: 12/2/21
 * Description: Creates a node of weapon data
 * @param weaponName the name of the weapon as a string
 * @param damage the amount of damage as an integer
 * @return A pointer to a new node
 * @pre unmade node 
 * @post made node pointer ready to be added
 **/
PlayerInventory::PlayerInventoryData* PlayerInventory::createNode(string weaponName, int damage)
{
    PlayerInventoryData *nodePtr = new PlayerInventoryData;
    nodePtr->damage = damage;
    nodePtr->weaponName = weaponName;
    nodePtr->prevSlot = nullptr;
    nodePtr->nextSlot = nullptr;
    return nodePtr;
}

/**
 * Name: Joshua Venable
 * Date created: 12/2/21
 * Date last modified: 12/2/21
 * Description: Returns the node at a given index
 * @param index the index to find the node at 
 * @return the pointer node at the spot in the doubly linked list
 * @pre unfound node in linked list
 * @post found and returned node in linked list
 **/
PlayerInventory::PlayerInventoryData* PlayerInventory::getNode(int index) const
{
    PlayerInventoryData *nodePtr = headPtr;
    int count = 0;

    //if the linked list is empty
    if(headPtr == nullptr || index < 0)
    {
        return nullptr;
    }
    //else look through linked list
    else
    {
        //while there is stuff in the linked list or the index hasn't been reached
        while(nodePtr != nullptr && count != index)
        {
            count++;
            nodePtr = nodePtr->nextSlot;
        }
        //if item found
        if(count == index)
        {
            return nodePtr;
        }
        //if end of linked list found
        else if(nodePtr == nullptr)
        {
            return nullptr;
        }
    }
    return nullptr;
}

/**
 * Name: Joshua Venable
 * Date created: 11/29/21
 * Date last modified: 11/29/21
 * Description: Creates a PlayerInventoryData node and adds it to the end
 * @param weaponName the name of the weapon as a string
 * @param damage the damage the weapon does
 * @return whether it could add to inventory
 * @pre unmade node
 * @post created node that has been added to inventory
 **/
bool PlayerInventory::insertAtEnd(string weaponName, int damage)
{
    PlayerInventoryData *newNodePtr = createNode(weaponName, damage);
    return insertAtEnd(newNodePtr);
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
        cout << "Size: " << length << endl;
        return;
    }
    //recursive else statement
    else
    {
        cout << "Weapon: " << inventoryData->weaponName << " - damage: " << inventoryData->damage << endl;
        displayAllItems(inventoryData->nextSlot);
    }
}

/**
 * Name: Joshua Venable
 * Date created: 11/29/21
 * Date last modified: 11/29/21
 * Description: Displays all items in the linkedList starting at the given position
 * @param index the index to start at
 * @return nothing
 * @pre unprinted out items in list
 * @post printed out items in list
 **/
void PlayerInventory::displayItemsFromPosition(int index) const
{
    int count = 0;
    PlayerInventoryData *nodePtr = headPtr;

    //if the index is out of bounds then don't run
    if(index >= length || index < 0)
    {
        cout << "this is out of bounds!\n";
        return;
    }
    //else reach the position in the list to start at
    else
    {
        while(count < index)
        {
            nodePtr = nodePtr->nextSlot;
            count++;
        }
        displayAllItems(nodePtr);
    }
}

/**
 * Name: Joshua Venable
 * Date created: 11/29/21
 * Date last modified: 11/29/21
 * Description: gets the item in the inventory at specified index
 * @param index the index the item to be grabbed
 * @return the string name of the item
 * @pre an unknown item at an index
 * @post a known item at an index
 **/
string PlayerInventory::getItemName(int index)
{
    int count = 0;
    PlayerInventoryData *nodePtr = headPtr;
    if(index < 0 || index > this->length)
    {
        cout << "index out of bounds!\n";
        return "";
    }
    else
    {
        while(count < index)
        {
            nodePtr = nodePtr->nextSlot;
        }
        return nodePtr->weaponName;
    }
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

PlayerInventory::~PlayerInventory()
{
    //no need to delete since other destructors call the erase() function
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
    while (playerIdIsInList(randNum) || flag)
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
 * Date created: 11/29/21
 * Date last modified: 11/29/21
 * Description: Fills up the inventory with random items from the global vector
 * @param numItems the number of items to be put into the list
 * @return whether it was able to fill up the list
 * @pre empty linked list
 * @post filled linked list
 **/
bool Player::fillList(int numItems)
{
    int randIndex = 0;
    string weaponName;
    int damage;

    for (int i = 0; i < numItems; i++)
    {
        randIndex = generateRandomStat(0, possibleItems.size() - 1);
        weaponName = possibleItems.at(randIndex).weaponName;
        damage = possibleItems.at(randIndex).damage;
        this->playerInventory.insertAtEnd(weaponName, damage);
    }
    if(this->playerInventory.getNode(0) != nullptr)
    {
        return true;
    }
    return false;
}

/**
 * Name: Joshua Venable
 * Date created: 12/4/21
 * Date last modified: 12/4/21
 * Description: removes the item in the inventory whose name matches
 * @return whether an item was removed or not
 * @pre a doubly linked list as is
 * @post doubly linked list that either removed an item or didn't find it
 **/
bool Player::removeItem()
{
    return this->removeItem(this->playerInventory.getNode(0)->weaponName);
}

/**
 * Name: Joshua Venable
 * Date created: 11/29/21
 * Date last modified: 12/2/21
 * Description: displays all of the player's inventory data
 * @return nothing
 * @pre unprinted inventory data
 * @post printed to console inventory data
 **/
void Player::showAllItems(void) const
{
    
    this->playerInventory.displayAllItems(this->playerInventory.getNode(0)); //displays starting at beginning
}

/**
 * Name: Joshua Venable
 * Date created: 11/21/21
 * Date last modified: 11/29/21
 * Description: checks whether an id is in the list of pre-existing ids
 * @param id the integer to check for
 * @return true or false regarding if id is in the vector
 * @pre unknown whether id is in the vector
 * @post known whether id is in the vector
 **/
bool Player::playerIdIsInList(int id)
{
    for (int i = 0; i < playerIds.size(); i ++)
    {
        if (playerIds.at(i) == id)
        {
            return true;
        }
    }

    return false;
}

Player::~Player()
{
    this->playerInventory.erase();
}

//-----------------------------ROGUE FUNCTIONS----------------------------------------

Rogue::Rogue() : Player()
{
    subclass = "Rogue";
    critChance = -1;
}

Rogue::~Rogue()
{
    this->playerInventory.erase();
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

/**
 * Name: Joshua Venable
 * Date created: 11/29/21
 * Date last modified: 11/29/21
 * Description: Prints out all of the players class info
 * @return nothing
 * @pre unprinted player info
 * @post player info printed to console
 **/
void Rogue::printPlayerClassInfo(void) const
{
    cout << "Critical hit chance: " << this->critChance << "%\n";
}

//-----------------------------NINJA FUNCTIONS----------------------------------------

Ninja::Ninja() : Rogue()
{
    specialty = "Ninja";
    sneakyDamage = -1;
}

Ninja::~Ninja()
{
    this->playerInventory.erase();
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

/**
 * Name: Joshua Venable
 * Date created: 11/29/21
 * Date last modified: 11/29/21
 * Description: Prints out all of the players class info
 * @return nothing
 * @pre unprinted player info
 * @post player info printed to console
 **/
void Ninja::printPlayerClassInfo(void) const
{
    Rogue::printPlayerClassInfo();
    cout << "Specialization: "
         << "Ninja\n";
    cout << "Sneak Extra Damage: " << this->sneakyDamage << endl;
}

//-----------------------------MAIN FUNCTIONS-----------------------------------------