#ifndef __SOURCE_NAKI_H__
#define __SOURCE_NAKI_H__
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

#include "player.h"
#include "wall.h"

class Naki {
 public:
  // delcare
  std::vector<std::vector<std::string>> probablysequence;
  bool hascombined = false;
  std::string themeldone;
  int whitchmeld = 0;
  // load naki texture
  void LoadNakiImg() {
    this->chi_texture.loadFromFile("image/chi.png");
    this->pong_texture.loadFromFile("image/pong.png");
    this->kang_texture.loadFromFile("image/kong.png");
    this->skip_texture.loadFromFile("image/skip.png");
    this->none_texture.loadFromFile("image/empty140x140.png");
  };
  // set naki scale function
  void SetNakiScale(float f) {
    this->chi_sprite.setScale(f, f);
    this->pong_sprite.setScale(f, f);
    this->kang_sprite.setScale(f, f);
    this->skip_sprite.setScale(f, f);
  };
  // set naki position function
  void SetNakiPosition(float x, float y) {
    this->chi_sprite.setPosition(x, y);
    this->pong_sprite.setPosition(x + 50, y);
    this->kang_sprite.setPosition(x, y + 50);
    this->skip_sprite.setPosition(x + 50, y + 50);
  };
  // naki window draw function
  void Naki_Window_Draw(sf::RenderWindow &window) {
    window.draw(this->chi_sprite);
    window.draw(this->pong_sprite);
    window.draw(this->kang_sprite);
    window.draw(this->skip_sprite);
  };
  // check chi, pong and big kang combined in hand function
  void CheckChiPongBigKang(std::vector<std::string> river, Player &player) {
    this->riverlastone = river.back();
    this->hand = player.hand;
    // call CheckTripleAndQuadruple function
    CheckTripleAndQuadruple();
    if (this->riverlastone[1] != 'z') CheckSequence();
    if (!this->probablysequence.empty() || this->triple || this->quadruple)
      this->hascombined = true;
    else
      this->hascombined = false;
  };
  // check small and concealed kang function
  int CheckSmallAndConcealedKang(Player &player) {
    for (std::vector<std::string>::iterator target = player.hand.begin();
         target != player.hand.end(); target++) {
      // check concealed kang
      if (std::count(player.hand.begin(), player.hand.end(), *target) == 4) {
        this->quadruple = true;
        this->themeldone = *target;
        return 2;
        // check small kang
      } else {
        // meld1
        if (player.meld1.hand.size() != 0 &&
            std::count(player.meld1.hand.begin(), player.meld1.hand.end(),
                       *target) == 3) {
          this->quadruple = true;
          this->themeldone = *target;
          this->whitchmeld = 1;
          return 3;
        // meld2
        } else if (player.meld2.hand.size() != 0 &&
                   std::count(player.meld2.hand.begin(),
                              player.meld2.hand.end(), *target) == 3) {
          this->quadruple = true;
          this->themeldone = *target;
          this->whitchmeld = 2;
          return 3;
        // meld3
        } else if (player.meld3.hand.size() != 0 &&
                   std::count(player.meld3.hand.begin(),
                              player.meld3.hand.end(), *target) == 3) {
          this->quadruple = true;
          this->themeldone = *target;
          this->whitchmeld = 3;
          return 3;
        // meld4
        } else if (player.meld4.hand.size() != 0 &&
                   std::count(player.meld4.hand.begin(),
                              player.meld4.hand.end(), *target) == 3) {
          this->quadruple = true;
          this->themeldone = *target;
          this->whitchmeld = 4;
          return 3;
        }
      }
    }
    return 0;
  };
  // select naki function
  int Select(sf::Vector2i &mousepos) {
    // chi
    if (!this->probablysequence.empty() && mousepos.x > 650 &&
        mousepos.x < 692 && mousepos.y > 100 && mousepos.y < 142)
      return 1;
    // pong
    if (this->triple && mousepos.x > 700 && mousepos.x < 742 &&
        mousepos.y > 100 && mousepos.y < 142)
      return 2;
    // big kang
    if (this->quadruple && mousepos.x > 650 && mousepos.x < 692 &&
        mousepos.y > 150 && mousepos.y < 192)
      return 3;
    // skip
    if (!this->probablysequence.empty() || this->triple ||
        this->quadruple && mousepos.x > 700 && mousepos.x < 742 &&
            mousepos.y > 150 && mousepos.y < 192)
      return -1;
    return -1;
  };
  // set naki texture
  void SetNakiTextureShow() {
    // skip
    if (!this->probablysequence.empty() || this->triple || this->quadruple)
      this->skip_sprite.setTexture(this->skip_texture);
    else
      this->skip_sprite.setTexture(this->none_texture);
    // chi
    if (!this->probablysequence.empty())
      this->chi_sprite.setTexture(this->chi_texture);
    else
      this->chi_sprite.setTexture(this->none_texture);
    // pong
    if (this->triple)
      this->pong_sprite.setTexture(this->pong_texture);
    else
      this->pong_sprite.setTexture(this->none_texture);
    // kang
    if (this->quadruple)
      this->kang_sprite.setTexture(this->kang_texture);
    else
      this->kang_sprite.setTexture(this->none_texture);
  };

  void ClearNaki() {
    this->hand.clear();
    this->riverlastone.clear();
    this->probablysequence.clear();
    this->triple = false;
    this->quadruple = false;
    this->themeldone.clear();
  };

 private:
  // declare
  // bool
  bool triple = false;
  bool quadruple = false;
  // std::string
  std::string riverlastone;
  // std::vector<T>
  std::vector<std::string> hand;
  // sf::Sprite
  sf::Sprite chi_sprite;
  sf::Sprite pong_sprite;
  sf::Sprite kang_sprite;
  sf::Sprite skip_sprite;
  std::vector<sf::Vector2f> position;
  // sf::Texture
  sf::Texture chi_texture;
  sf::Texture pong_texture;
  sf::Texture kang_texture;
  sf::Texture skip_texture;
  sf::Texture none_texture;

  // check triple and quadruple function
  void CheckTripleAndQuadruple() {
    if (std::count(this->hand.begin(), this->hand.end(), this->riverlastone) >=
        2)
      this->triple = true;
    if (std::count(this->hand.begin(), this->hand.end(), this->riverlastone) ==
        3)
      this->quadruple = true;
  };

  // check sequence function
  void CheckSequence() {
    std::string minus2 = std::to_string((int)this->riverlastone[0] - 50) +
                         this->riverlastone[1];  // -2
    std::string minus1 = std::to_string((int)this->riverlastone[0] - 49) +
                         this->riverlastone[1];  // -1
    std::string plus1 = std::to_string((int)this->riverlastone[0] - 47) +
                        this->riverlastone[1];  // +1
    std::string plus2 = std::to_string((int)this->riverlastone[0] - 46) +
                        this->riverlastone[1];  // +2
    if (std::find(this->hand.begin(), this->hand.end(), minus2) !=
            this->hand.end() &&
        std::find(this->hand.begin(), this->hand.end(), minus1) !=
            this->hand.end())
      this->probablysequence.push_back({minus2, minus1});
    if (std::find(this->hand.begin(), this->hand.end(), minus1) !=
            this->hand.end() &&
        std::find(this->hand.begin(), this->hand.end(), plus1) !=
            this->hand.end())
      this->probablysequence.push_back({minus1, plus1});
    if (std::find(this->hand.begin(), this->hand.end(), plus1) !=
            this->hand.end() &&
        std::find(this->hand.begin(), this->hand.end(), plus2) !=
            this->hand.end())
      this->probablysequence.push_back({plus1, plus2});
  };
};

#endif
