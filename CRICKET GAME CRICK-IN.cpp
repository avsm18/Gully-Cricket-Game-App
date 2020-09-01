//============================================================================
// Name        : 6.cpp
// Author      : aviral mahajan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "GAME1.h"
using namespace std;

int main() {



		Game game;
		game.welcome();
		cout << " Press enter to continue.. " << endl << endl << endl;
		getchar();
		game.showAllPlayers();
		cout << " Press enter to continue.. " << endl << endl << endl;
		getchar();
		game.selectPlayers();
		cout << endl << endl << endl;
		game.showTeamPlayers();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << " Press enter to toss" << endl << endl << endl;
		getchar();
		game.toss();
		game.startFirstInnings();
		game.initialisePlayers();
		game.startSecondInnings();
		game.displayMatchSummary();















}


