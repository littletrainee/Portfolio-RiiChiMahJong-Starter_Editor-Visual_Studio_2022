#ifndef __SOURCE_MELD_H__
#define __SOURCE_MELD_H__
#include <SFML/Graphics.hpp>
#include <string>
#include <utility>
#include <vector>

#include "tile.h"
// meld class
class Meld {
 public:
  // delcare
  std::vector<std::string> hand;
  std::string typeofnaki;
  // set meld scale function
  void SetScale(float f) {
    this->meld1.setScale(f, f);
    this->meld2.setScale(f, f);
    this->meld3.setScale(f, f);
    this->meld4.setScale(f, f);
  };
  // set original and concealed kang position function
  void OriginalAndConcealedKangPosition(float x, float y) {
    this->position[0] = std::make_pair(x, y);
    this->position[1] = std::make_pair(x - 29, y);
    this->position[2] = std::make_pair(x + 29, y);
    this->position[3] = std::make_pair(x - 58, y);
  };
  // set tyep of naki function
  void SetTypeOfNaki(std::string typeofnaki) { this->typeofnaki = typeofnaki; };
  // set chi, pong and big kang position function
  void ChiPongAndBigKangPosition() {
    this->position[0].second += 40;
    this->position[2].first += 12;
    this->meld1.setRotation(-90);
  };
  // set small kang position function
  void SmallKangPosition() {
    this->position[3].first = this->position[0].first;
    this->meld4.setRotation(-90);
    this->position[3].second += 12;
  };

  // set sprite
  void SetTexture(Tile &t) {
    std::string blank = "";
    std::string tileback = "back";
    this->meld1.setPosition(this->position[0].first, this->position[0].second);
    this->meld2.setPosition(this->position[1].first, this->position[1].second);
    this->meld3.setPosition(this->position[2].first, this->position[2].second);
    this->meld4.setPosition(this->position[3].first, this->position[3].second);
    if (!this->hand.empty()) {
      t.SwitchTexture(this->hand[0], this->meld1);
      t.SwitchTexture(this->hand[1], this->meld2);
      if (this->typeofnaki == "concealed") {
        t.SwitchTexture(tileback, this->meld3);
        t.SwitchTexture(tileback, this->meld4);
      } else {
        t.SwitchTexture(this->hand[2], this->meld3);
        if (this->hand.size() > 3)
          t.SwitchTexture(this->hand[3], this->meld4);
        else
          t.SwitchTexture(blank, this->meld4);
      }
    } else {
      t.SwitchTexture(blank, this->meld1);
      t.SwitchTexture(blank, this->meld2);
      t.SwitchTexture(blank, this->meld3);
      t.SwitchTexture(blank, this->meld4);
    }
  };
  // draw meld
  void Meld_Window_Draw(sf::RenderWindow &window) {
    window.draw(this->meld1);
    window.draw(this->meld2);
    window.draw(this->meld3);
    window.draw(this->meld4);
  };

 private:
  std::pair<float, float> position[4];
  sf::Sprite meld1;
  sf::Sprite meld2;
  sf::Sprite meld3;
  sf::Sprite meld4;
};
#endif