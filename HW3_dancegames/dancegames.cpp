/* 
 * File:   dancegames.cpp
 * Author: Roy Van Liew and Saqib Zahid
 * 
 * Last Modified February 17th, 2014
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Counting function works and critters work so far.

class Player
{
public:
    
    Player();       // default constructor prototype
	Player(int thres, int stam, string name); // constructor with parameters
        Player(int thres, string name = "Expert"); // constructor with default parameters
	Player(const Player& c); //copy constructor
	~Player(); //destructor
    void getStats();
    	/***** Accessor Functions for our Dance Game Players. *****/
	int getStamina()
	{
		return stamina;
	}
	int getWater()
	{
		return water;
	}
	string getName()
	{
		return dname;
	}
	int getThreshold()
	{
		return threshold;
	}
	int getPlayerCount()
	{
		return playercount;
	}

	/***** Mutator Functions for our Dance Game Players. *****/
	void gainStamina(){
		if (water > 0 && stamina <= 45)
		{
			stamina += 5; // Gain some stamina
			water -= 1; // Lose some water from bottle
		}
		else if (water == 0)
			cout << "Water bottle empty.\n";
		else
			cout << "At maximum stamina.\n";
	}
	void refillWater(){
		if (water >= 0 && water < 5)
			water = 5; // Refill water bottle.
		else
			cout << "Water bottle is full.\n";
	}
	void fixThreshold(){
		if (stamina >= 5 && stamina < 15)
			threshold -= 2;
		else if (stamina >= 15 && stamina <= 50)
			threshold += 2;
		else if (stamina > 50)
			cout << "You're taking steroids.\n";
	}


private:
	string dname; // Name of the dance game player.
	int water; // How much water the player has left in his or her bottle.
	int stamina; // How much energy the player has left.
	int threshold; // Highest difficulty dance game player can pass.
	static int playercount; // Keep track of how many dance game players we have.
};

Player::Player() // Default constructor
{
        dname = "ITG Player";
        stamina = 25;
        water = 5;
        threshold = 12;
        playercount++;
        cout << dname << " has entered the dance scene." << endl;
}
Player::Player(int thres, int stam, string name) // Constructor with parameters
{
        dname = name;
        stamina = stam;
        water = 5;
        threshold = thres;
        playercount++;
        cout << dname << " has entered the dance scene." << endl;
}
Player::Player(int thres, string name) // Constructor with default parameters
{
        dname = name;
        stamina = 25;
        water = 5;
        threshold = thres;
        playercount++;
        cout << dname << " has entered the dance scene." << endl;
}
Player::Player(const Player& p) // Copy constructor
{
	dname = "Clone of " + p.dname;
	water = p.water;
	stamina = p.stamina;
	threshold = p.threshold;
	playercount++;
	cout << dname << " has entered the dance scene." << endl;
}

	//destructor
Player::~Player()
{
        cout << dname << " left the dance scene." << endl;
		
}

int Player::playercount = 0; // Initialize player count to zero.
int metalpad = 20; // Initialize our dance pad's condition
string songname[12];
int songdifficulty[12];

void makeSongList()
{

	int i;
	// Fill in our song difficulties.
	for (i = 0; i < 12; i++)
		songdifficulty[i] = 10 + i; // We start at difficulty 10
	songname[0] = "Anubis (10)"; // Difficulty 10
	songname[1] = "Uptown Saturday Night (11)";
	songname[2] = "Euphoria (12)";
	songname[3] = "Welcome To Rainbow (13)";
	songname[4] = "Calamity Fortune (14)";
	songname[5] = "One More Lovely (15)";
	songname[6] = "Still Grey (16)";
	songname[7] = "Moonearth (17)";
	songname[8] = "Whazamup (18)";
	songname[9] = "Bokura no 16bit warz (19)";
	songname[10] = "The Skies are Not Enough (20)";
	songname[11] = "Sigatrev (21)";

}

void fixPads()
{
	if (metalpad >= 15)
		cout << "The pads are fine." << endl;
	else
	{
		metalpad = 20;
		cout << "Fixed the sensors, it should be good now." << endl;
	}

 }

void Player::getStats()
{
    cout << "Player: " << dname << endl;
    cout << "Stamina: " << stamina << endl;
    cout << "Passing capability: " << (threshold+2) << endl;
    cout << "Water left: " << water << endl;
    cout << "\n";
}

int main()
{    
    makeSongList();
    cout << "--- Welcome to In The Groove ---" << endl;
    
    {
        // Create our players
        Player player1;
        Player player2(19, "Matt");
        Player player3(15);
        Player player4(player2);
        cout << "We have " << player1.getPlayerCount() << " players!" << endl;
        cout << "\n";
    }
    
	
    return 0;
}

