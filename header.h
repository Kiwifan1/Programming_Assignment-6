/**
 * Name: Joshua Venable
 * Class: CPSC 122, Fall 2021
 * Date: 11/19/2021
 * Programming Assigment: PA6
 * Description: Player battle that focuses on recursion, Linked Lists, ADTs, and Inheritance
 * Notes: 
 *  Questions:  Can I include things like 'stagger' where there's a chance the other player cannot attack, and so the turn ends?
 * 
 * 11/19/21 - file creation
 * 11/21/21 - creating inherited classes and special variables
 * 11/29/21 - added multiple methods for all parent classes
 * 12/2/21 - added method for node creation
 **/

#ifndef HEADER_H
#define HEADER_H

#include <iostream> //need for IO
#include <string>   //need for string data type and member functions
#include <cstdlib>  //need for random
#include <ctime>    //need for random
#include <vector>   //need for vector data type
#include <iomanip>  //need to format output

using namespace std;

//Global constant to set upper limit on number of playerIds generated
const int MAX_ID_VALUE = 1000;

//This struct is used to populate possibleItems. This is it's
//only purpose. You are not expected to use it as a member
//variable in your classes
struct InventoryItem
{
    string weaponName;
    int damage;
};

//Global CONSTANT variable. You should modify and fill this
//vector with predefined possible weapons for your player
//objects.
const vector<InventoryItem> possibleItems{
    {"Rusty Sword", 8},
    {"Legendary sword", 14},
    {"Beer Jug", 2},
    {"Mysterious Fish", 24},
    {"Long Chair", 25},
    {"Frying Pan", 12}};

//Class for your inventory

//1. A doubly linked list : I Have decided to use a doubly linked List
class PlayerInventory
{
private:
    struct PlayerInventoryData
    {
        string weaponName;
        int damage;
        PlayerInventoryData *nextSlot;
        PlayerInventoryData *prevSlot;
    };

    PlayerInventoryData *headPtr;
    int length; //length of doubly linked list
public:
    PlayerInventoryData* createNode(string weaponName, int damage);
    PlayerInventoryData* getNode(int index) const;
    bool insertAtEnd(PlayerInventoryData *newInventoryData);
    bool insertAtEnd(string weaponName, int damage);
    bool insertAtPosition(PlayerInventoryData *newInventoryData, int index);
    bool insertAtPosition(string weaponName, int damage, int index);
    bool removeItem(string nameOfInventoryItem);
    void displayAllItems(PlayerInventoryData *inventoryData) const;
    void displayItemsFromPosition(int index) const;
    string getItemName(int index);
    bool erase(void);
    int size(void);
    PlayerInventory();
    ~PlayerInventory();
};

//Abstract Base Class
class Player
{
private:
    //static member variable keeping track of the number of players generated
    static int numPlayers;
    //static list of playerIds generated.
    //used to make sure no players have the same id
    static vector<int> playerIds;

protected:
    string subclass;
    string name;
    int playerId;
    int health;
    int experience;

    double multiplier; //damage multiplier. This should vary depending on class

    //Inventory is the name of your doubly linked list, stack linked list, or queue linked list class
    PlayerInventory playerInventory;

    //mutator/setter for player id
    void setPlayerId(int id) { playerId = id; }

    //used to generate a random stat value between min and max, e.g., 50 and 150
    //used when initializing player stats
    int generateRandomStat(int min, int max) const;

    //checks if an id is already in the playerIds vector.
    static bool playerIdIsInList(int id);

    //generates a UNIQUE player id. player id can be between 1 and MAX_ID_VALUE
    //if number generated is in playerIds, generate again otherwise, add to
    //playerIds vector (to keep track of id generated) and return value to be
    //used in initialization
    int generatePlayerId(void) const;


public:
    //Default constructor
    Player()
    {
        subclass = "Player";
        name = "";
        playerId = -1;
        health = -1;
        experience = 0;
        multiplier = 1.0;
        PlayerInventory playerInventory;
        numPlayers++;
    }

    //Destructor
    ~Player();

    //accessors/getters and mutators/setters
    void setName(string newName) { name = newName; }
    string getName(void) const { return name; };
    void setHealth(int h) { health = h; }
    int getHealth(void) const { return health; }
    int getPlayerId(void) const { return playerId; }
    void setExperience(int exp) { experience = exp; }
    int getExperience(void) const { return experience; }
    void showAllItems(void) const;
    bool removeItem(string nameOfItem) { return this->playerInventory.removeItem(nameOfItem); }
    bool fillList(int numItems);

    //Pure Virtual Functions
    //initializes a player of given name with randomly allocated stats
    virtual void initializePlayer(string newName) = 0;
    virtual void printPlayerClassInfo(void) const = 0;

    //Virtual Functions
    virtual double getMultiplier(void) { return multiplier; }
    const virtual void printPlayerInfo(void) final
    {
        string skull = "\n    _____\n   /     \\\n  | () () |\n   \\  ^  /\n    |||||\n";
        string tombstone = "\n       ,-=-.\n      /  +  \\\n      | ~~~ |\n      |R.I.P|\n      |_____| \n";

        string healthValue = this->health > 0 ? to_string(this->health) : tombstone; //"~RIP~"
        cout << ">>>>>>>>>>>>>>>>>>>>>>>>>|PID:" << this->playerId << "|" << endl;
        cout << ">>" << this->name << "'s info" << endl;
        cout << "Health: " << healthValue << endl;
        cout << "Experience: " << this->experience << endl;
        cout << "---------------------------------" << endl;
        cout << "Class: " << this->subclass << endl;
        printPlayerClassInfo();
        cout << "_________________________________" << endl;
        cout << endl;
    }

    //Template Functions
    //prints out the "header" information for each attack turn
    //see example output
    template <class T1, class T2>
    static void printBattleCard(T1 p1, T2 p2, int turn);

    //see example function definition below
    template <class T1, class T2>
    bool attackPlayerSuccess(T1 &p1, const T2 &p2);
};

class Rogue : public Player
{
protected:
    string specialty;
    double critChance; //critical hit chance
    PlayerInventory playerInventory;

public:
    Rogue();
    ~Rogue();

    void initializePlayer(string newName);
    void printPlayerClassInfo(void) const;
};

class Ninja : public Rogue
{
protected:
    double sneakyDamage; //multiplier for multiplier
    PlayerInventory PlayerInventory;
public:
    Ninja();
    ~Ninja();

    void initializePlayer(string newName);
    void printPlayerClassInfo(void) const;
};
//don't forget about static variables.

#endif