#ifndef __SOURCE_APPEND_TILE_TO_WALL_H__
#define __SOURCE_APPEND_TILE_TO_WALL_H__
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

std::vector<std::string> sortby = {"1m", "2m", "3m", "4m", "5m", "6m",
                                   "7m", "8m", "9m", "1z", "2z", "3z",
                                   "4z", "5z", "6z", "7z"};

void AppendToWallHand(std::vector<std::string> sortby,
                      std::vector<std::string> &wallhand) {
  for (std::vector<std::string>::iterator s = sortby.begin(); s != sortby.end();
       s++)
    for (int i = 0; i < 4; ++i) wallhand.push_back(*s);
}

// draw card from wallhand to palyerhand
void DrawCard(std::vector<std::string> &wallhand,
              std::vector<std::string> &playerhand) {
  playerhand.push_back(wallhand.front());
  wallhand.erase(wallhand.begin());
}

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
#endif
