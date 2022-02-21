#ifndef __PRINT_ALL_H__
#define __PRINT_ALL_H__
#include "player_struct.h"
#include "win_check.h"
#include "append_tile_to_wall.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#endif

// PrintAll class
class PrintAll {
	public:
		// set name and map function
		void PrintAll_SetNameAndMap(std::string player1, std::string player2, 
																std::string wall, std::string river, 
																std::map<std::string, std::string> tile) {
			this->player1 = player1;
			this->player2 = player2;
			this->wall = wall;
			this->river = river;
			this->tile = tile;
		};
		// print hand function
		void PrintHand(int whitchplayer, std::vector<std::string> hand, 
									 bool shownumber) {
			// -1 = river, 0 = wall, 1 = player1, 2 = player2,
			switch (whitchplayer) { 
				case -1:
					std::cout << this->river;
					break;
				case 0:
					std::cout << this->wall;
					break;
				case 1:
					std::cout << this->player1;
					break;
				case 2:
					std::cout << this->player2;
					break;
			}
			if (whitchplayer >  0)
				std::cout << "手牌";
			std::cout << ":";
			if (shownumber)
				for (int i = 0; i < hand.size(); i++)
					std::cout << i + 1 << "." << this->tile[hand[i]] << "  ";
			else {
				for (std::vector<std::string>::iterator target = hand.begin(); target != hand.end();
						target++){
					if ((target - hand.begin()) % 12 == 0)
						std::cout << std::endl;
					std::cout << this->tile[*target] << ' ';
				}
			}
			std::cout << std::endl << std::endl;
		};
		// print all hand function
		void PrintAll_Print(Player player1, Player player2,	
												std::vector<std::string> wallhand, 
												std::vector<std::string> riverhand) {
			// print wall
			std::cout << 
				"============================================================" << std::endl;
			PrintHand(0, wallhand, false);
			// print player1 and player1meld
			std::cout << 
				"============================================================" << std::endl;
			PrintHand(1, player1.hand, false);
			std::cout << 
				"------------------------------------------------------------" << std::endl;
			PrintMeldHand(1, player1.meldhand);
			// print river
			std::cout << 
				"============================================================" << std::endl;
			PrintHand(-1, riverhand, false);
			// print player2 and player2meld
			std::cout << 
				"============================================================" << std::endl;
			PrintMeldHand(2, player2.meldhand);
			std::cout << 
				"------------------------------------------------------------" << std::endl;
			PrintHand(2, player2.hand, false);
			std::cout << 
				"============================================================" << std::endl;
		};
	private:
		// declare type
		std::string											  player1;
		std::string											  player2;
		std::string											  wall;
		std::string											  river;
		std::map<std::string,std::string> tile;
		// print meldhand function
		void PrintMeldHand(int whitchplayermeldhand, 
				std::vector<std::vector<std::string>> meldhand) {
			std::vector<std::string> tempmeld;
			switch (whitchplayermeldhand) {
				case 1:
					std::cout << this->player1;
					break;
				case 2:
					std::cout << this->player2;
					break;
			}
			std::cout << "組合手牌:";
			for (std::vector<std::vector<std::string>>::iterator meld = meldhand.begin();
					meld != meldhand.end(); meld++) {
				std::cout << "{ ";
				tempmeld = *meld;
				for (std::vector<std::string>::iterator m = tempmeld.begin();
					   m != tempmeld.end();	m++)
					std::cout << this->tile[*m] << ' ';
				std::cout << '}';
			}
			std::cout << std::endl << std::endl;
		};
};

// check keyin is number
bool CheckKeyinIsNumber(std::string keyin){
	bool rt = true;
	for(std::string::iterator k = keyin.begin(); k != keyin.end(); k ++)
		std::isdigit(*k) ? rt = true : rt = false;
	return rt;
}

int SetNumber(std::string keyin){
	int temp = 0;
	for(std::string::iterator k = keyin.begin(); k != keyin.end(); k++){
		switch (*k){
			case '0':
			  temp += 0;	
				break;
			case '1':
				temp += 1;
				break;
			case '2':
				temp += 2;
				break;
			case '3':
				temp += 3;
				break;
			case '4':
				temp += 4;
			  break;
			case '5':
				temp += 5;
			  break;
			case '6':
				temp += 6;
			  break;
			case '7':
				temp += 7;
			  break;
			case '8':
				temp += 8;
			  break;
			case '9':
				temp += 9;
			  break;
			case '-':
				temp *= -1;
		}
		if (k != keyin.end() - 1)
			temp *= 10;
	}
	return temp;
}

// discard function
void DisCard(Player &player, std::vector<std::string> &riverhand) {
	// declare type
	std::string                        keyin;
	int                      					 target;
	std::vector<std::string>::iterator it;
	std::cout << "輪到" << player.name << std::endl;
	std::cout << "請選擇您要打出牌的編號(1-" << player.hand.size() << "):";
	std::cin >> keyin;
	// check isdigit
	while(!CheckKeyinIsNumber(keyin) && SetNumber(keyin) >
			player.hand.size() || SetNumber(keyin) < 0){
		std::cout << "請重新輸入:";
		std::cin >> keyin;
	}
	target = SetNumber(keyin); // set select number
	it = player.hand.begin() + target - 1;
	riverhand.push_back(player.hand[target - 1]);
	player.hand.erase(it);
}

// ten pai check function
void TenPaiCheck(Player &player, std::vector<std::string> tiles, 
								 std::vector<std::string> riverhand) {
	// declare type
	char           				   key;
	std::vector<std::string> probablywintile;
	std::vector<std::string> checkhand;
	std::vector<std::string> poponetilehand;
	Player         					 temp = player;
	// declare class
	CheckWin       					 cw;
	// set cw tile
	cw.CheckWin_SetTile(tiles);
	// pop one by one from checkhand and append one by one from tile to check win
	for (std::vector<std::string>::iterator compareby = player.hand.begin();
			compareby != player.hand.end(); compareby++) {
		// reset checkhand from playerhand 
		checkhand = player.hand;
		// try to pop one of checkhand for check win
		checkhand.erase(std::find(checkhand.begin(), checkhand.end(), *compareby));
		// clone checkhand to poponetilehand(hand minus one)
		poponetilehand = checkhand;
		// try to append tile to hand for check win one by one  
		for (std::vector<std::string>::iterator tile = tiles.begin(); 
				 tile != tiles.end();	tile++) {
			// reset checkhand from poponetilehand
			checkhand = poponetilehand;
			// append tile to checkhand equal to hand amont
			checkhand.push_back(*tile);
			// sort checkhand for check win
			Sort(tiles, checkhand);
			// copy to clonecheckhand from checkhand
			temp.hand = checkhand;
			if (!cw.CheckWin_Check(temp, riverhand)) {
				// check the tile isn't in probablywintile
				if (std::find(probablywintile.begin(), probablywintile.end(), *tile) ==
						probablywintile.end()) {
					// then add to probablywintile
					probablywintile.push_back(*tile);
				}
			}
		}
	}
	// probablywintile isn't empty
	if (!probablywintile.empty()) {
		std::cout << "要宣告聽牌嗎(y/n)? ";
		std::cin >> key;
		std::cout << std::endl;
		// check key is equal to y or n
		while (key != 'y' && key != 'n'){
			std::cout << "請重新輸入選擇: ";
			std::cin >> key;
			std::cout << std::endl;
		}
		// set tenpai
		player.tenpai = key == 'y' ? true : false;
	}
}

// AutoDiscard function
void AutoDisCard(std::vector<std::string> &playerhand, 
								 std::vector<std::string> &riverhand) {
	riverhand.push_back(playerhand.back());
	playerhand.pop_back();
}

// discard and print all hand function
void DiscardAndPrintHand(std::vector<std::string> sortby, 
												 std::map<std::string,std::string> tile, int &gameround,
												 std::vector<std::string> &riverhand, 
												 std::vector<std::string> wallhand, Player &player1,
												 Player player2){
	// declare class	
	bool ismeld = false;
	PrintAll pa;
	// pa class set name and map
	pa.PrintAll_SetNameAndMap(player1.name, player2.name, "牌山", "牌河", tile);
	// increase round and print
	if (player1.bookmaker){
		// print round
		std::cout << "第 " << gameround << " 巡" << std::endl;
		gameround += 1;
	}
	// player1 is tenpai
	if (player1.tenpai){
		AutoDisCard(player1.hand, riverhand);
	// player1 isn't tenpai
	}else{
		// print player1hand with number index
		pa.PrintHand(1, player1.hand, true);
		// check player1 is tenpai and declare
		TenPaiCheck(player1, sortby, riverhand);
		// discard from player1hand to riverhand
		DisCard(player1, riverhand);
	}
	// sort player1hand
	Sort(sortby, player1.hand);
	// print all hand
	pa.PrintAll_Print(player1, player2, wallhand, riverhand);
}
