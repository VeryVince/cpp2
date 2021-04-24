/*
	Your Name: Vincent Apanovitch
	Date: 2/25/21
	Program Name: CIS 1202
	Description: 
		Write a program that uses an array of structs to represent a card deck, 
			where the card values are represented by enumerated types for the suit and rank. 
		Your program will use functions to create the card deck, print a single card, 
			print the card deck, deal two cards, then determine which card is the winner.
	Notes: 
		- uses <ctime> time(0) to <cstdlib> srand() rand()
			Usage: srand(time(0)) somewhere else:  ( rand() % (MAX+1) )
			DONT srand(time(0)) in the same sec or else you get same result!
		- casts ints to enums
			Usage: static_cast<the enum>thingToCast
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

//I never even use the enums lol
enum suits { HEARTS, DIAMONDS, SPADES, CLUBS };
enum ranks { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
struct cards
{
	suits suit;
	ranks rank;
};

void createDeck(cards deck[]) {
	int i = 0;
	for (int s = 0; s < 4; s++) //for each of the 4 suits
		for (int r = 0; r < 13; r++) { //for each of the 13 ranks
			deck[i++] = { //make a card in the deck
				static_cast<suits>(s),
				static_cast<ranks>(r)
			};
			//cout << "C# " << (--i)++ <<" Suit " <<s << " Rank " << r << endl;
		}
}

string cardName(cards card) {
	string
		rankNames[] = {
			"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"
		},
		suitNames[] = {
			"Hearts", "Diamonds", "Spades", "Clubs"
		};
	return rankNames[card.rank] + " of " + suitNames[card.suit];
}

void printCards(cards deck[], int n) {
	cout << "The deck has been made!!" << endl;
	for (int i = 0; i < n; i++)
		cout << cardName(deck[i]) << endl;
}

cards dealCard(cards deck[]) {
	return deck[ rand() % (52+1) ];
}

string winnerCard(cards c1, cards c2) {
	if (c1.rank > c2.rank)
		return "the: " + cardName(c1);
	else if (c1.rank < c2.rank)
		return "the: " + cardName(c2);
	else
		return "a Tie";
}

int main()
{
	srand(time(0));
	cards deck[52];
	cards card1, card2;

	createDeck(deck);
	printCards(deck, 52);

	card1 = dealCard(deck);
	card2 = dealCard(deck);

	cout << "\nCard 1 is the: " << cardName(card1)
		<<"\nCard 2 is the: " << cardName(card2)
		<< "\nThe Winner is " << winnerCard(card1,card2) << "!!!"
		<<endl;


	system("pause");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
