#ifndef __SOURCE_WALL_H__
#define __SOURCE_WALL_H__
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>


// sort playerhand by sortby
void Sort(std::vector<std::string> sortby,
          std::vector<std::string> &playerhand) {
  std::vector<std::string> temphand;
  for (std::vector<std::string>::iterator s = sortby.begin(); s != sortby.end();
       s++)
    if (find(playerhand.begin(), playerhand.end(), *s) != playerhand.end())
      for (int i = 0; i < count(playerhand.begin(), playerhand.end(), *s); i++)
        temphand.push_back(*s);
  playerhand = temphand;
}

class Wall {
 public:
  std::vector<std::string> hand;
  bool walltailtop = true;
  void AppendToWallHand(std::vector<std::string> sortby) {
    for (std::vector<std::string>::iterator s = sortby.begin();
         s != sortby.end(); s++)
      for (int i = 0; i < 4; ++i) this->hand.push_back(*s);
  };
  // draw card from wallhand to palyerhand
  void DrawCard(std::vector<std::string> &playerhand) {
    playerhand.push_back(this->hand.front());
    this->hand.erase(this->hand.begin());
  };
};

#endif