// Name:       Ankhbayar Enkhtaivan
// Student ID: 1155185142
// Email:      1155185142@link.cuhk.edu.hk

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <climits>
// You may add additional headers if needed

#include "ActionCard.h"
#include "Man.h"
#include "Bot.h"
#include "DrawPile.h"
#include "DiscardPile.h"

using namespace std;

int main()
{
	// Get the game start-up parameters 
	string input;
	unsigned int seed = 123;
	cout << "Enter seed (or hit Enter): ";
	getline(cin, input);
	if (!input.empty()) {
		seed = stoi(input);
	}
	cout << "Seed: " << seed << endl;
	srand(seed);

	bool debugMode = false;
	cout << "Play in debug mode (Y/N)? ";
	getline(cin, input);
	if (input == "Y" || input == "y" || input == "") {
		debugMode = true;
	}
	cout << "Debug mode: " << boolalpha << debugMode << endl;

	int turnsMax = 100;
	cout << "Max. turns to play: ";
	getline(cin, input);
	if (!input.empty()) {
		turnsMax = stoi(input);
	}
	cout << "Max. turns: " << turnsMax << endl;

	int M, B, P;
	while (true) {
		cout << "Enter # man and bot players: ";
		cin >> M >> B;
		P = M + B;
		if (P >= 2 && P <= 5)
			break;
		cout << "Require 2 to 5 players!" << endl;
	}
	cout << "#Men: " << M << "; #Bots: " << B << endl;

	// Create an array of pointers to Player objects
	Player** players = new Player * [P];
	for (int i = 0; i < P; i++) {
		if (i < M)
			players[i] = new Man;
		else
			players[i] = new Bot;
	}
	Player* player = players[0];  // current player

	// Define variables to track the game state
	DrawPile drawPile;
	DiscardPile discardPile;
	bool turnSkipped = false;
	int cardsToDraw = 0;
	int delta = 1;
	int turn = 0;

	GameState uno = { players, &drawPile, &discardPile,
		&turnSkipped, &cardsToDraw, &turn, &delta, P, debugMode
	};

	// Shuffle the deck and deal cards to each player
	if(debugMode){
		cout <<"Cards created:"<<endl;
		drawPile.print();
	}
	drawPile.shuffle();
	for (int i = 0; i < P; i++) {
		players[i]->drawCard(&drawPile, H);
	}

	// Draw the first card onto discard pile
	vector<Card*> firstCard;
	drawPile.draw(firstCard, 1);
	discardPile.stack(firstCard[0]); 
	if (debugMode) {
		cout << "Draw pile after shuffling and dealing:" << endl;
		drawPile.print();
	}
	int turns = 0;
	int counter = 0;
	// Start the game loop
	while (true) {
		// TODO:
		// Print the "turn header" which shows discard pile's top card, 
		// current color and current size of draw pile.
		cout << "=========================================================" << endl;
		cout <<	"Turn " << counter + 1 << ":"<<endl;
		cout << "Discard Pile: " << discardPile.top()->toString() << "  " << "Current Color: " << setw(7) << left << COLORS[int(discardPile.top()->getColor())] << " " << "Draw Pile: " << drawPile.size() << endl;
		cout << "---------------------------------------------------------" << endl;
		// Print the name of the current player.
		// (Hint: you can use the turn integer to index the players array
		//  to get a pointer to the current player.)
		cout << player->getName() << ": " << endl;

		// If cardsToDraw > 0, current player draws the required # cards.
		// If turnSkipped is true, current player skips picking and playing 
		// a card in this turn.
		// Otherwise, call the pickCard() method to get the index of a 
		// selected card in hand.
		// Then call the playCard() method with the obtained index if it is 
		// not PASSED and not DRAWN.

		if(cardsToDraw > 0){
			player->drawCard(&drawPile, cardsToDraw);
			cardsToDraw = 0;
		}
		if(turnSkipped){
			turnSkipped = false;
			cout << "Turn skipped!" << endl;
		}else{
			int index = player->pickCard(uno);
			if(index != PASSED && index != DRAWN){
				player->playCard(index, uno);
				turns = 0;
			}
			if(index == DRAWN){
				turns += 1;
			}
		}

		// Check game over condition. Exit the game loop if either:
		// (1) current player's hand has no cards.
		// (2) all players consecutively passed their turns 
	    //     (i.e., no one can play a card or draw).

		bool gameOver = false;
		for(int i = 0; i < P; i++){
			if(player->handSize() == 0){
				gameOver = true;
			}
		}

		if(turns == P){
			gameOver = true;
		}

		if(gameOver){
			break;
		}
		
		// Update the turn integer to let the next player become current.
		
		counter++;
		turn += delta;
		if (turn < 0)
			turn += P;
		else if (turn >= P)
			turn -= P;
		player = players[turn];
	}
	// TODO:
	// Print the game over message.
	// List all players' hands and the sum of points of all cards in hand.
	// Print the name of the winner. 
	/* 
	**********
	Game Over!
	**********
	*/
	cout << "**********" << endl;
	cout << "Game Over!" << endl;
	cout << "**********" << endl;
	for(int i = 0; i < P; i++){
		cout << players[i]->getName() << " owes ";
		cout << setw(4) << right << players[i]->handPoints() << " point(s): ";
		players[i]->printHand(true);
	}
	int min = INT_MAX;
	int winner = 0;
	for(int i = 0; i < P; i++){
		if(players[i]->handPoints() < min){
			min = players[i]->handPoints();
			winner = i;
		}
	}
	cout << "The winner is " << players[winner]->getName() << "!" << endl;
}