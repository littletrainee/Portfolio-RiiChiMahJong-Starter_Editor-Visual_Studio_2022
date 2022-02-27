#ifndef __SOURCE_WIN_CHECK_H__
#define __SOURCE_WIN_CHECK_H__
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "player.h"
#include "wall.h"

// CheckWin  class
class CheckWin {
 public:
  void SetSortby(std::vector<std::string> sortby) { this->sortby = sortby; };
  // check function
  bool Win(Player mainplayer, Player otherplayer) {
    // declare type
    // set hand
    this->hand = mainplayer.hand;
    // set group count
    this->number_of_groups = mainplayer.meldorder;
    // #1 = recheck meld, #2 = not meld and not empty, #3 = empty
    int check_combined = 1;
    std::string temptile;
    std::vector<std::string> temp;
    // check player need append tile from riverhand back
    switch (this->number_of_groups) {
      case 0:
        if (this->hand.size() != 14)
          this->hand.push_back(otherplayer.river.back());
        break;
      case 1:
        if (this->hand.size() != 11)
          this->hand.push_back(otherplayer.river.back());
        break;
      case 2:
        if (this->hand.size() != 8)
          this->hand.push_back(otherplayer.river.back());
        break;
      case 3:
        if (this->hand.size() != 5)
          this->hand.push_back(otherplayer.river.back());
        break;
      case 4:
        if (this->hand.size() != 2)
          this->hand.push_back(otherplayer.river.back());
        break;
    }
    // clone playerhand to temp and this->hand
    temp = this->hand;
    // check eye
    this->probablyeye.clear();
    for (std::vector<std::string>::iterator target = this->sortby.begin();
         target != this->sortby.end(); target++)
      if (std::find(this->hand.begin(), this->hand.end(), *target) !=
              this->hand.end() &&
          std::count(this->hand.begin(), this->hand.end(), *target) >= 2)
        this->probablyeye.push_back(*target);
    // check 7pair
    if (this->probablyeye.size() == 7) {
      // 7 pair win
      this->eye = "7pair";
      // return is win(true)
      return true;
    } else {
      // check the eye guide to clear temp
      for (std::vector<std::string>::iterator eye = this->probablyeye.begin();
           eye != this->probablyeye.end(); eye++) {
        // remove the eye pair
        for (int i = 0; i < 2; i++)
          temp.erase(find(temp.begin(), temp.end(), *eye));
        do {
          check_combined = 0;
          // check temp is empty
          if (temp.empty()) {
            // set checkmeld bool to false
            check_combined = 3;
            // temp isn't empty
          } else {
            // check the triple meld
            if (count(temp.begin(), temp.end(), temp[0]) == 3) {
              // set eraseby tile
              std::string eraseby = temp[0];
              // erase tile from temp three time
              for (int i = 0; i < 3; i++)
                temp.erase(find(temp.begin(), temp.end(), eraseby));
              check_combined = 1;
              // check the sequence meld and kind isn't equal to 'z'
            } else if (temp[0][1] != 'z' && !temp.empty()) {
              // check the +1+2 in hand
              if (find(temp.begin(), temp.end(),
                       std::to_string((int)temp[0][0] - 47) + temp[0][1]) !=
                      temp.end() &&
                  find(temp.begin(), temp.end(),
                       std::to_string((int)temp[0][0] - 46) + temp[0][1]) !=
                      temp.end()) {
                // erase +1
                temp.erase(
                    find(temp.begin(), temp.end(),
                         std::to_string((int)temp[0][0] - 47) + temp[0][1]));
                // erase +2
                temp.erase(
                    find(temp.begin(), temp.end(),
                         std::to_string((int)temp[0][0] - 46) + temp[0][1]));
                // erase [0]
                temp.erase(find(temp.begin(), temp.end(), temp[0]));
                // set check_combined to 1 to check temp again
                check_combined = 1;
                // doesn't have meld in hand
              } else
                // set check_combined to 2 to break the loop
                check_combined = 2;
            } else
              // set check_combined to 2 to break the loop
              check_combined = 2;
          }
          // checkmeld is true to do it again
        } while (check_combined == 1);
        // check temphand is empty
        if (check_combined == 3) {
          this->eye = *eye;
          return true;
        } else if (check_combined == 2) {
          // reset temphand
          temp = this->hand;
        }
      }
    }
    return false;
  };
  // get eye function
  void GetEye(std::string &eye) { eye = this->eye; };

 private:
  // declare type
  std::vector<std::string> sortby;
  std::vector<std::string> hand;
  std::vector<std::string> probablyeye;
  int number_of_groups = -1;
  std::string eye;
};
#endif
