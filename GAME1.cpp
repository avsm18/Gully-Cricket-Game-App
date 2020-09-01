#include "GAME1.h"
#include <unistd.h>


using namespace std;
Game::Game() {



	isFirstInnings = false;
	teamA.name = "Team-A";
	teamB.name = "Team-B";

		playersPerTeam = 4;
		totalPlayers = 11;
		maxBalls = 6;
		players[0] = "Virat";
		players[1] = "Rohit";
		players[2] = "Dhawan";
		players[3] = "Pant";
		players[4] = "Karthik";
		players[5] = "KLRahul";
		players[6] = "Jadeja";
		players[7] = "Hardik";
		players[8] = "Bumrah";
		players[9] = "BKumar";
		players[10] = "Ishant";


}
void Game::welcome() {

	cout << " --------------------------------" << endl << endl;
	cout << "  ---CRIC-IN---"<< endl << endl << endl;
	cout << "   Welcome to Virtual Cricket Game" << endl << endl;
	cout << " --------------------------------" << endl << endl << endl << endl << endl;
	cout << " ---------------------------------------" << endl << endl;
	cout << " -----Instructions-----"<< endl << endl;
	cout << " ---------------------------------------" << endl << endl << endl;
	cout << " 1.Create 2 teams (Team-A and Team-B with four players each) from a given pool of 11 players."<< endl;
	cout << " 2.Lead the toss and decide the choice of play." << endl;
	cout << " 3.Each innings will be of 6 balls." << endl;
	cout << " ---------------------------------------" << endl << endl << endl;


}
void Game::showAllPlayers() {
	cout << " ---------------------------------------" << endl << endl;
	cout << " -----Pool of Players-----" << endl << endl;
	cout << " ---------------------------------------" << endl << endl << endl;
	for (int i = 0 ; i < totalPlayers ; i++) {
		cout  << " [" << i << "]  "  << players[i] << endl;




	}
}

int	Game::takeIntegerInput() {

		int n;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');


		while (!(cin >> n)) {

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << " Invalid input! Please enter again with valid input : " ;





	}

	return n;




	}
void Game::selectPlayers() {

	cout << " -----------------------------------------" << endl;
	cout << "---------Create Team-A and Team-B---------" << endl;
	cout << "------------------------------------------" << endl << endl;
	int playerIndexTeamA , playerIndexTeamB;
	for (int i = 0 ; i < playersPerTeam ; i++) {

				teamASelection:


				cout << "Select player " << (i + 1) << " of Team A -  ";


				 playerIndexTeamA = takeIntegerInput();
				 cout << endl << endl;


				 if (playerIndexTeamA < 0 ||  playerIndexTeamA > 10) {

					cout << "Please select from the given players only." << endl;
					goto teamASelection;
				}

				 else if (!validateSelectedPlayer(playerIndexTeamA)) {

				 cout << "Player has been already selected. Please select other player" << endl << endl;
				 goto teamASelection;


				 }

				 else {

				Player teamAPlayer;
				teamAPlayer.id = playerIndexTeamA;
				teamAPlayer.name = players[playerIndexTeamA];
				teamA.players.push_back(teamAPlayer);


				 }







				teamBSelection:


				cout << "Select player " << (i + 1) << " of Team B -  ";
				playerIndexTeamB = takeIntegerInput();

					cout << endl << endl;
				if (playerIndexTeamB < 0 ||  playerIndexTeamB > 10) {

									cout << "Please select from the given players only." << endl;
									goto teamBSelection;

								}

				else if (!validateSelectedPlayer(playerIndexTeamB)) {


		cout << "Player has been already selected.Please select other player." << endl << endl;
		goto teamBSelection;



}

				else {
				Player teamBPlayer;
				teamBPlayer.id = playerIndexTeamB;
				teamBPlayer.name = players[playerIndexTeamB];
				teamB.players.push_back(teamBPlayer);
				}
	}

}
bool Game::validateSelectedPlayer(int index) {


	int n;
	vector<Player> players;
	players = teamA.players;
	n = players.size();
	for (int i = 0 ; i < n ; i++) {

		if (players[i].id == index ) {


			return false;

		}


		}
	players = teamB.players;
	n = players.size();
	for (int j = 0 ; j < n ; j++) {

			if (players[j].id == index ) {


				return false;

			}


			}

return true;



















}
void Game::showTeamPlayers() {
		cout << "----------------------                        -------------------------"	<< endl << endl;
		cout << " -------TEAM-A-------                          ---------TEAM-B--------" << endl << endl;
		cout << "----------------------                        ------------------------" << endl << endl;
				for (int j = 0 ; j < playersPerTeam ; j++) {

			cout << " " <<  teamA.players[j].name << "       " << "                                   " << teamB.players[j].name << "          " << endl;



		}
		cout << endl << endl;
		cout << "----------------------                        -------------------------"	<< endl ;

}
void Game::toss() {

	cout << "-------------------------" << endl << endl;
	cout << "-------Let's Toss-------" << endl << endl;
	cout << "-------------------------" << endl << endl << endl ;
	cout << "Tossing the coin... " << endl << endl << endl;
	usleep(1000000);
	srand(time(NULL));
	int randomValue = rand() % 2 ; // 0 and 1
	switch(randomValue) {

	case 0:
	cout << "TEAM-A won the toss" << endl << endl << endl;
	tossChoice(teamA);
	break;
	case 1:
	cout << "TEAM-B won the toss" << endl << endl << endl;
	tossChoice(teamB);
	break;





	}
}
void Game::tossChoice(Team tossWinnerTeam) {



	cout << "Enter 1 to bat or 2 to bowl." << endl << "1. Bat" << endl << "2. Bowl" << endl;

	int m = takeIntegerInput();
	cout << endl << endl;
	switch (m) {

		case 1:
		cout << tossWinnerTeam.name << " won the toss and elected to bat first" << endl << endl;
		if (tossWinnerTeam.name.compare("Team-A")){

			battingTeam = &teamA;
			bowlingTeam = &teamB;


		}
		else if (tossWinnerTeam.name.compare("Team-B") ) {

			battingTeam = &teamB;
			bowlingTeam = &teamA;



		}
		break;
		case 2:
		cout << tossWinnerTeam.name << " won the toss and elected to bowl first" << endl << endl;
		if (tossWinnerTeam.name.compare("Team-A")){

			bowlingTeam = &teamA;
			battingTeam = &teamB;


		}
		else if (tossWinnerTeam.name.compare("Team-B")) {

			bowlingTeam = &teamB;
			battingTeam = &teamA;


		}


		break;

		default:
		cout << "Invalid input! Please try again : " << endl << endl;
		tossChoice(tossWinnerTeam);
		break;



	}
}

void Game::startFirstInnings() {

	cout << "\t\t    ||| FIRST INNINGS STARTS ||| " << endl << endl;
	isFirstInnings = true;
	initialisePlayers();
	playInnings();





}

void Game::initialisePlayers() {


	batsman = &(battingTeam->players[0]); // first player object stored in the batting team is the one who will bat and we want that batsman pointer should point towards this player
	bowler =  &(bowlingTeam->players[0]);
	cout << battingTeam->name << " - " << batsman->name << " is batting" << endl;
	cout << bowlingTeam->name << " - " << bowler->name << " is bowling" << endl <<endl;




}


void Game::playInnings() {

	for (int i = 0 ; i < maxBalls ; i++) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max() , '\n');
		cout << "Press Enter to bowl...." << endl;
		getchar();
		cout << "Bowling...." << endl << endl;
		bat();
		if (!validateInningsScore())
		break;



	}





}
void Game::bat() {


	srand(time(NULL));
	int runsScored = rand() % 7; // 0 , 1 ,2 , 3 , 4 , 5 , 6
	batsman->runsScored = batsman->runsScored + runsScored;
	battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;
	batsman->ballsPlayed = batsman->ballsPlayed + 1;

	bowler->ballsBowled = bowler->ballsBowled + 1;
	bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;
	bowler->runsGiven = bowler->runsGiven + runsScored;

	if (runsScored != 0){
	cout << bowler->name << " to " << batsman->name <<  " " << runsScored << " runs!" << endl << endl;
	showGameScoreCard();

	}
	else {

	cout << bowler->name << " to " << batsman->name <<  " OUT!"  << endl << endl;
	battingTeam->wicketsLost = 	battingTeam->wicketsLost + 1;
	bowler->wicketsTaken = bowler->wicketsTaken + 1;
	batsman = &(battingTeam->players[battingTeam->wicketsLost]);

	showGameScoreCard();



	}
}

void Game::showGameScoreCard() {


	cout << "----------------------------------------------" << endl << endl;
	cout << "       "<< battingTeam->name <<  " " << battingTeam->totalRunsScored << " - " << battingTeam->wicketsLost << " (" << bowler->ballsBowled << ") | " << batsman->name << " " << batsman->runsScored << " (" << batsman->ballsPlayed << ") " << "  " << bowler->name << " " << bowlingTeam->totalBallsBowled << " - " << bowler->runsGiven << " - " << bowler->wicketsTaken << endl << endl;
	cout << "----------------------------------------------" << endl << endl;
}















bool Game::validateInningsScore() {


		if (isFirstInnings) {

		if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls) {
		cout << "\t\t    ||| FIRST INNINGS ENDS ||| " << endl << endl;
		cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - " << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ")" << endl;
		cout << bowlingTeam->name << " needs " << (battingTeam->totalRunsScored) + 1 << " runs to win the match" << endl << endl;

			return false;





		}
	return true;

	}
		else {

			if (battingTeam->totalRunsScored > bowlingTeam->totalRunsScored) {

				cout << battingTeam->name <<  " WON THE MATCH" << endl << endl;
				cout << "       ||| MATCH ENDS |||" << endl << endl;



			return false;

			}
		if (bowlingTeam->totalBallsBowled == maxBalls || battingTeam->wicketsLost == playersPerTeam) {


			cout << bowlingTeam->name <<  " WON THE MATCH" << endl << endl;
			cout << "       ||| MATCH ENDS |||" << endl << endl;
			return false;



		}

		return true;

		}


}
void Game::startSecondInnings() {


	Team *randomTeam;
	cout << "    ||| FIRST INNINGS ENDS |||" << endl << endl;
	randomTeam = bowlingTeam;
	bowlingTeam = battingTeam; // swapping the pointers in these three steps.
	battingTeam = randomTeam;
	cout << battingTeam->name << " - " << batsman->name << " is batting" << endl << bowlingTeam->name << " - " << bowler->name << " is bowling" << endl << endl;
	isFirstInnings = false;
	playInnings();










}
void Game::displayMatchSummary() {


	cout << teamA.name << " " << teamA.totalRunsScored << " - " << teamA.wicketsLost << " (" << teamB.totalBallsBowled << ")" << endl << endl;
	cout << "-----------------------------------------------" << endl << endl;
	cout << "-----------------------------------------------" << endl;
	 cout << "  PLAYER        BATTING        BOWLING" << endl << endl;
	 cout << "--------------------------------------------" << endl << endl;
	 for (int i = 0 ; i < playersPerTeam ; i++) {

cout << " [" << i << "]   " << teamA.players[i].name << "        " <<  teamA.players[i].runsScored << "(" << teamA.players[i].ballsPlayed << ")" << "        " << teamA.players[i].ballsBowled << "-" << teamA.players[i].runsGiven << "-" << teamA.players[i].wicketsTaken << endl << endl;
cout << "--------------------------------------------" << endl << endl;






	 }
	 cout << "--------------------------------------------" << endl << endl << endl;

	 cout << teamB.name << " " << teamB.totalRunsScored << " - " << teamB.wicketsLost << " (" << teamA.totalBallsBowled << ")" << endl << endl;
	 cout << "-----------------------------------------------" << endl << endl;
	 	cout << "-----------------------------------------------" << endl;
	 	 cout << "  PLAYER        BATTING        BOWLING" << endl << endl;
	 	 cout << "--------------------------------------------" << endl << endl;
	 	for (int i = 0 ; i < playersPerTeam ; i++) {

	 	cout << " [" << i << "]   " << teamB.players[i].name << "        " <<  teamB.players[i].runsScored << "(" << teamB.players[i].ballsPlayed << ")" << "        " << teamB.players[i].ballsBowled << "-" << teamB.players[i].runsGiven << "-" << teamB.players[i].wicketsTaken << endl << endl;
	 	cout << "--------------------------------------------" << endl << endl;






	 		 }

	 	cout << "--------------------------------------------" << endl << endl << endl;


}












