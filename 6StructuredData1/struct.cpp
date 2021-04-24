/*
    Your Name: Vincent Apanovitch
    Date: 2/20/21
    Program Name: CIS 1202
    Description: A sports team plays games at home and away.  Write a program to keep track of a team's win/loss record at home, away, and their total.  Use nested structures as you develop this program.
    Notes:
        Uses Vectors with struct data type: vector<struct> vect
        Uses Structs ;;; use/pass/declare/referance/return like normal var
        Uses getline(cin,input) and  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //bad \n bad!!
        Uses switch in main() for menu processing
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct WinLoss {
    int wins, losses;
};
struct Team {
    string name;
    WinLoss homeWL, awayWL, totalWL;
};

WinLoss getWinLoss(string location) {
    WinLoss tempWL;
    bool error = false;

    do {
        cout << "Enter " + location + " wins: ";
        cin >> tempWL.wins;
        cout << "Enter " + location + " losses: ";
        cin >> tempWL.losses;

        if (tempWL.wins < 0 || tempWL.losses < 0) {
            error = true;
            cout << "\nERROR: Wins and Losses must be >=0!!!\n";
        }
        else error = false;
    } while (error);

    return tempWL;
}

void displayWinLoss(const WinLoss &wl) {
    cout << wl.wins << "-" << wl.losses;
}

Team getTeam() {
    Team tempTeam;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //bad \n bad!!
    cout << "\nEnter Team name: ";
    getline(cin, tempTeam.name);

    tempTeam.homeWL = getWinLoss("Home");
    tempTeam.awayWL = getWinLoss("Away");
    tempTeam.totalWL.wins = tempTeam.homeWL.wins + tempTeam.awayWL.wins;
    tempTeam.totalWL.losses = tempTeam.homeWL.losses + tempTeam.awayWL.losses;

    return tempTeam;
}

void displayTeam(const Team &team){
    cout << "\nTeam: " + team.name
        << "\nHome Wins-Losses: "; displayWinLoss(team.homeWL);
    cout << "\nAway Wins-Losses: "; displayWinLoss(team.awayWL);
    cout << "\nTotal Wins-Losses: "; displayWinLoss(team.totalWL);
    cout << endl;
}

int menu() {
    int input;
    bool error = false;

    cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-="
        << "\nMain Menu"
        << "\nEnter 1 to Create a new team"
        << "\nEnter 2 to Display all teams"
        << "\nEnter 3 to Find and Display a team"
        << "\nEnter 4 to Quit";
        
    do {
        cout << "\nPlease enter a number: ";
        cin >> input;

        if (input < 1 || 4 < input) {
            error = true;
            cout << "\nERROR: " << input << " is not a valid choice!!!";
        }
        else error = false;
    } while (error);
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    return input;
}

void findTeam(vector<Team> teams) {
    string input; 
    bool found = false;

    cout << "\nEnter a Team Name to Search for: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //bad \n bad!!
    getline(cin, input);
    
    int i = 0;
    for (; i < teams.size(); i++) {
        if (input == teams[i].name) {
            found = true;
            break;
        }
    }
    if (found) {
        cout << "\nFound the Team!";
        displayTeam(teams[i]);
    }
    else {
        cout << "Couldn't find the team: " << input << endl;
    }
}
int main()
{
    vector<Team> teams;
    
    bool quit = false;
    do {
        int numb = menu();
        switch (numb)
        {
        case 1: 
            teams.push_back(getTeam());
            break;
        case 2: 
            for (int i = 0; i < teams.size(); i++)
                displayTeam(teams[i]);
            break;
        case 3:
            findTeam(teams);
            break;
        case 4:
            quit = true;
            break;
        default:
            cout << "\nERROR!!! Unexpected input from menu function!";
            exit(400);
        }
    } while (! quit);

    system("pause");
    return 0;
}

/*
Requirements
1.	Data structures:
    a.	Define a WinLoss structure with wins and losses members (int).
    b.	Define a Team structure with the team name, containing a WinLoss structure variable for total wins/losses, a WinLoss structure variable for home wins/losses, and a WinLoss structure variable for away wins/losses.
    c.	Declare an array of type Team.

2.	Build a menu-driven program with these options:
    a.	Enter a new team
    b.	Display all teams
    c.	Display a particular team
    d.	Exit the program

3.	Define these functions according to these prototypes:
    a.	int menu();
                Shows the menu
                Gets the user selection
                Validates the menu selection
                Returns a valid menu selection
    b.	WinLoss getWinLoss(string);
                    Gets wins and losses from the keyboard for the location indicated by the string parameter ("home" or "away") and returns a WinLoss structure containing the input.
    c.	void displayWinLoss(WinLoss);
                    Displays a string containing the win and loss members in the format of "wins-losses".
    d.	Team getTeam();
                    Inputs the team name
                    Inputs home wins and losses using getWinLoss()
                    Inputs away wins and losses using getWinLoss()
                    Stores the home wins/losses in the appropriate team structure
                    Stores the away wins/losses in the appropriate team structure
                    Calculates the total wins/losses and stores those in the appropriate structure
                    Returns all of this in a single Team structure
    e.	void displayTeam(Team);
                    Displays the team name, total wins and losses, home wins and losses, and away wins and losses.  Use the displayWinLoss function described above.
    f.	void findTeam(Team[], int);
                    Prompt the user for the team name
                    Search the array for a match
                    If there is a match, display the team information using the displayTeam function described above.
                    If there is no match, display an error message.

*/