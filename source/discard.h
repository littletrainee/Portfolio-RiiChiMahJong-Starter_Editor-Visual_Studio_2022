#ifndef __SOURCE_DISCARD_H__
#define __SOURCE_DISCARD_H__
#include <vector>
#include "river.h"
#include "player_struct.h"

// player discard from hand to river
void PlayerDisCardFromHandToRiver(Player &player, int player_select, 
																					std::vector<std::string> &river){
	river.push_back(player.hand[player_select - 1]);
	player.hand.erase(player.hand.begin() + player_select - 1);
}
#endif
