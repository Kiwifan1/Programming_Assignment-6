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
 **/

#include "header.h"

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
    if(inventoryData == nullptr)
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