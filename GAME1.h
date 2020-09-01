#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "TEAM1.h" // <vector> "PLAYER1.h""
class Game {

	public:
	Game();
	bool isFirstInnings ;
	Team teamA , teamB;
	int playersPerTeam;
	int maxBalls;
	int totalPlayers;
	std::string players[11];
	Team *battingTeam , *bowlingTeam;

	Player *batsman , *bowler;

	void welcome();
	void showAllPlayers();
	void selectPlayers();
	bool validateSelectedPlayer(int);


	int takeIntegerInput();
	void showTeamPlayers();
	void toss();
	void tossChoice(Team);
	void startFirstInnings();
	void initialisePlayers();
	void playInnings();
	void bat();
	bool validateInningsScore();
	void showGameScoreCard();
	void startSecondInnings();
	void displayMatchSummary();








};
