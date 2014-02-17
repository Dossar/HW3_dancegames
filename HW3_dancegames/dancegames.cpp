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
    void playGame();
    void selectMusic();
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
		if (water > 0)
		{
			stamina += 5; // Gain some stamina
			water -= 1; // Lose some water from bottle
		}
	}
	void refillWater(){
		if (water >= 0 && water < 5)
			water = 5; // Refill water bottle.
		else
			cout << "Water bottle is full.\n";
	}
	void fixThreshold(){
		if ( stamina > 25 )
                    threshold += 1;
                else if ( stamina == 5 )
                    threshold -= 1;
                if ( threshold > 15 )
                    threshold = 15;
	}


private:
	string dname; // Name of the dance game player.
	int water; // How much water the player has left in his or her bottle.
	int stamina; // How much energy the player has left.
	int threshold; // Highest difficulty dance game player can pass.
	static int playercount; // Keep track of how many dance game players we have.
};

int Player::playercount = 0; // Initialize player count to zero.

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
	playercount--;	
}

void Player::playGame()
{
    int menu = 1;
    do
    {
        cout << "\n";
        getStats(); // Print out the player's attributes.
        cout << "1.) Play a song" << endl;
        cout << "2.) Drink from water bottle" << endl;
        cout << "3.) Stop playing In The Groove with " << dname << endl;
        
            cout << "What would you like " << dname << " to do: ";
            cin >> menu;
            cout << "\n";

            switch (menu) {
                case 1:
                    selectMusic();
                    break;
                case 2:
                    if( water < 1 )
                    {
                        cout << "Looks like my water bottle is empty, refilling it.\n" << endl;
                        refillWater();
                    }
                    else
                        gainStamina();
                        if( stamina > 25 && threshold < 15 )
                            fixThreshold();
                    break;
                case 3:
                    break;
                default:
                    cout << "\nInvalid input.\n";
            }
            
    }while( menu != 3 );
}

int metalpad = 20; // Initialize our dance pad's condition
string songname[6];
int songdifficulty[6];

void Player::selectMusic()
{

    int i;
    int select;
    // Fill in our song difficulties.
    for (i = 0; i < 6; i++)
        songdifficulty[i] = 10 + i; // We start at difficulty 10
    songname[0] = "Anubis (10)"; // Difficulty 10
    songname[1] = "Uptown Saturday Night (11)";
    songname[2] = "Euphoria (12)";
    songname[3] = "Welcome To Rainbow (13)";
    songname[4] = "Calamity Fortune (14)";
    songname[5] = "One More Lovely (15)";
    for( i = 0 ; i < 6 ; i++ )
        cout << (i+1) << ".) " << songname[i] << endl;
    cout << "\n";
    cout << "Select Music: " << endl;
    int song = 0;
    while( song < 1 || song > 6 )
    {
        cin >> song;
        if( song < 1 || song > 6 )
            cout << "Song list is numbered 1-6, try again." << endl;
        // If song selection was correct
        if( song >= 1 && song <= 6 )
        {
            if( metalpad < 10 ){
                metalpad = 20;
                cout << "Fixed the sensors, the pads should be good now." << endl;
            }
            if( stamina > 50 )
                fixThreshold();
            if( songdifficulty[song-1]>threshold )
                cout << "This song is too hard for me.\n" << endl;
            if( threshold==songdifficulty[song-1] && stamina < 25 )
                cout << "I need to drink some water first.\n";
            if( threshold==songdifficulty[song-1] && stamina >= 25 ){
                stamina -= 20;
                cout << dname << " screams 'AAAAHHHHHHHHHH!!!'" << endl;
                cout << dname << " passed with a bad score.\n" << endl;
                if( stamina == 5 )
                    fixThreshold();
                metalpad -= 4;
            }
            if( threshold-songdifficulty[song-1] == 1 && stamina < 20 )
                cout << "I need to drink some water first.\n";    
            if( threshold-songdifficulty[song-1] == 1 && stamina >= 20 ){
                stamina -= 15;
                cout << dname << " says 'OW, that was hard.'" << endl;
                cout << dname << " passed with a decent score.\n" << endl;
                if( stamina == 5 )
                    fixThreshold();                
                metalpad -= 3;
            }
            if( threshold-songdifficulty[song-1] == 2 && stamina < 15 )
                cout << "I need to drink some water first.\n";    
            if( threshold-songdifficulty[song-1] == 2 && stamina >= 15 ){
                stamina -= 10;
                cout << dname << " passed with a good score.\n" << endl;
                if( stamina == 5 )
                    fixThreshold();                
                metalpad -= 2;
            }
            if( threshold-songdifficulty[song-1] >= 3 && stamina < 10 )
                cout << "I need to drink some water first.\n";    
            if( threshold-songdifficulty[song-1] >= 3 && stamina >= 10 ){
                stamina -= 5;
                cout << dname << " passed with an excellent score.\n" << endl;
                if( stamina == 5 )
                    fixThreshold();                
                metalpad -= 1;
            }
            break;
        }
        // End of if song selection was correct
    }

}

void Player::getStats()
{
    cout << "Player: " << dname << endl;
    cout << "Current Stamina: " << stamina << endl;
    cout << "Passing capability: " << threshold << endl;
    cout << "Water left: " << water << endl;
    cout << "\n";
}

int selectPlayer()
{
    int select = -1;
    while( select < 1 || select > 4 )
    {
        cin >> select;
        if( select < 1 || select > 4 )
            cout << "Invalid input.\n" << endl;
    }
    return select;
    
}

int main()
{    

    cout << "--- Welcome to In The Groove ---" << endl;
    int choice = 1;
    // int pselect = -1;
    int person;
    
    
        // Create our players
        Player player1;
        Player player2(14, 35, "Matt");
        Player player3(13);
        Player player4(player2);
        cout << "We have " << player1.getPlayerCount() << " players!" << endl;
        cout << "\n";
        
        do
        {
            cout << "Are you up for some dance games?\n";
            cout << "0.) - Leave The Dance Scene\n";
            cout << "1.) - Play In The Groove\n";
            cout << "2.) - Show our dance game players\n";

            cout << "Please select an item from the menu list: ";
            cin >> choice;
            cout << "\n";

            switch (choice) {
                case 0:
                    cout << "Thanks for coming!\n";
                    break;
                case 1:
                    cout << "Who would you like to choose to play In The Groove?" << endl;
                    cout << "1.) " << player1.getName() << endl;
                    cout << "2.) " << player2.getName() << endl;
                    cout << "3.) " << player3.getName() << endl ;
                    cout << "4.) " << player4.getName() << endl;
                    person = selectPlayer();
                    if( person == 1 )
                        player1.playGame();
                    if( person == 2 )
                        player2.playGame();
                    if( person == 3 )
                        player3.playGame();
                    if( person == 4 )
                        player4.playGame();
                    break;
                case 2:
                        cout << "Player: " << player1.getName() << endl;
                        cout << "Current Stamina: " << player1.getStamina() << endl;
                        cout << "Passing capability: " << player1.getThreshold() << endl;
                        cout << "Water left: " << player1.getWater() << endl;
                        cout << "\n";
                        cout << "Player: " << player2.getName() << endl;
                        cout << "Current Stamina: " << player2.getStamina() << endl;
                        cout << "Passing capability: " << player2.getThreshold() << endl;
                        cout << "Water left: " << player2.getWater() << endl;
                        cout << "\n";  
                        cout << "Player: " << player3.getName() << endl;
                        cout << "Current Stamina: " << player3.getStamina() << endl;
                        cout << "Passing capability: " << player3.getThreshold() << endl;
                        cout << "Water left: " << player3.getWater() << endl;
                        cout << "\n";
                        cout << "Player: " << player4.getName() << endl;
                        cout << "Current Stamina: " << player4.getStamina() << endl;
                        cout << "Passing capability: " << player4.getThreshold() << endl;
                        cout << "Water left: " << player4.getWater() << endl;
                        cout << "\n";
                        break;                        
                default:
                    cout << "\nInvalid input.\n";
            }
            
        }while(choice!=0);
    
    
	
    return 0;
}

