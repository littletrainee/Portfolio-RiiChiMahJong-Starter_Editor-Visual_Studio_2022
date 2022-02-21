#ifndef __SOURCE_CHI_MORE_THAN_TWO_H__
#define __SOURCE_CHI_MORE_THAN_TWO_H__
#include <SFML/Graphics.hpp>
#include <string>
#include <utility>
#include <vector>

#include "tile.h"
class Chi_More_Than_Two {
 public:
  void SetScaleAndPosition(float f) {
    // scale
    this->meld1.first.setScale(f, f);
    this->meld1.second.setScale(f, f);
    this->meld2.first.setScale(f, f);
    this->meld2.second.setScale(f, f);
    this->meld3.first.setScale(f, f);
    this->meld3.second.setScale(f, f);
    // position
    this->meld1.first.setPosition(650, 220);
    this->meld1.second.setPosition(680, 220);
    this->meld2.first.setPosition(650, 270);
    this->meld2.second.setPosition(680, 270);
    this->meld3.first.setPosition(650, 320);
    this->meld3.second.setPosition(680, 320);
  };

  void SetChiTexture(Tile &t,
                     std::vector<std::vector<std::string>> &probablysequence) {
    std::string blank = "";
    if (probablysequence.size() == 2) {
      t.SwitchTexture(probablysequence[0][0], this->meld1.first);
      t.SwitchTexture(probablysequence[0][1], this->meld1.second);
      t.SwitchTexture(probablysequence[1][0], this->meld2.first);
      t.SwitchTexture(probablysequence[1][1], this->meld2.second);
      t.SwitchTexture(blank, this->meld3.first);
      t.SwitchTexture(blank, this->meld3.second);
    } else if (probablysequence.size() == 3) {
      t.SwitchTexture(probablysequence[0][0], this->meld1.first);
      t.SwitchTexture(probablysequence[0][1], this->meld1.second);
      t.SwitchTexture(probablysequence[1][0], this->meld2.first);
      t.SwitchTexture(probablysequence[1][1], this->meld2.second);
      t.SwitchTexture(probablysequence[2][0], this->meld3.first);
      t.SwitchTexture(probablysequence[2][1], this->meld3.second);
    } else {
      t.SwitchTexture(blank, this->meld1.first);
      t.SwitchTexture(blank, this->meld1.second);
      t.SwitchTexture(blank, this->meld2.first);
      t.SwitchTexture(blank, this->meld2.second);
      t.SwitchTexture(blank, this->meld3.first);
      t.SwitchTexture(blank, this->meld3.second);
    }
  };

  void Chi_Window_Draw(sf::RenderWindow &window) {
    window.draw(this->meld1.first);
    window.draw(this->meld1.second);
    window.draw(this->meld2.first);
    window.draw(this->meld2.second);
    window.draw(this->meld3.first);
    window.draw(this->meld3.first);
  };

  int Select(sf::Vector2i &mousepos,
             std::vector<std::vector<std::string>> probablysequence) {
    // meld1
    if (mousepos.x > 650 && mousepos.x < 708 && mousepos.y > 220 &&
        mousepos.y < 260)
      return 11;
    if (mousepos.x > 650 && mousepos.x < 708 && mousepos.y > 270 &&
        mousepos.y < 310)
      return 12;
    if (probablysequence.size() > 2 && mousepos.x > 650 && mousepos.x < 708 &&
        mousepos.y > 320 && mousepos.y < 360)
      return 13;
    return 0;
  };

 private:
  std::pair<sf::Sprite, sf::Sprite> meld1;
  std::pair<sf::Sprite, sf::Sprite> meld2;
  std::pair<sf::Sprite, sf::Sprite> meld3;
};

#endif
