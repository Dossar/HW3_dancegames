//Constructor Player
//Demonstrates constructors

#include <iostream>
#include <string>

using namespace std;

class Player
{
public:
    
    Player();       // default constructor prototype
	Player(int thres, string name); // constructor with parameters
	Player(const Player& c); //copy constructor
	~Player(); //destructor
    void Greet();
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
//	int getPlayerCount()
//	{
//		return playercount;
//	}

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
	// static int playercount; // Keep track of how many dance game players we have.
};

Player::Player()       // constructor definition
{
        dname = "ITG Player";
        stamina = 15;
        water = 5;
        threshold = 12;
        //playercount++;
        cout << dname << " has entered the dance scene!" << endl;
}
Player::Player(int thres, string name)       // constructor definition
{
        dname = name;
        stamina = 15;
        water = 5;
        threshold = thres;
        //playercount++;
        cout << dname << " has entered the dance scene!" << endl;
}
Player::Player(const Player& p)//copy constructor
{
	dname = "Clone of " + p.dname;
	water = p.water;
	stamina = p.stamina;
	threshold = p.threshold;
	//playercount++;
	cout << dname << " has entered the dance scene!" << endl;
}

	//destructor
Player::~Player()
{
        cout << dname << " left the dance scene!" << endl;
		
}

// int Player::playercount = 0; // Initialize player count to zero.
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

void Player::Greet()             
{
    cout << "Hello, my name is " << dname << endl;
}

void Player::getStats()
{
    cout << "Player: " << dname << endl;
    cout << "Stamina: " << stamina << endl;
    cout << "Passing capability: " << threshold << endl;
    cout << "Water left: " << water << endl;
}

int main()
{    
    Player crit1;
    crit1.Greet();
    crit1.getStats();

	Player crit2(19, "Matt");
	crit2.Greet();
        crit2.getStats();

	Player crit3(crit2);
	crit3.Greet();
        crit3.getStats();
	
    return 0;
}

