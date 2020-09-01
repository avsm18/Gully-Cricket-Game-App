#include <vector>
#include "PLAYER1.h"		// <string>


class Team {

		public:
		Team();
		std::string name;
		int totalRunsScored;
		int wicketsLost;
		int totalBallsBowled;
		std::vector<Player> players;

};
