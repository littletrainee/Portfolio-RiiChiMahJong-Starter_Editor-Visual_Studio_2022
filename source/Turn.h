#ifndef __SOURCE_TURN_H__
#define __SOURCE_TURN_H__
#include <SFML/Graphics.hpp>

class Turn {
 public:
  int turn = 0;
  sf::Sprite arrow;
  void LoadArrowImg() {
    this->up.loadFromFile("image/arrow-up.png");
    this->down.loadFromFile("image/arrow-down.png");
  };
  void SetArrowScaleAndPosition(float f, float x, float y) {
    this->arrow.setScale(f, f);
    this->arrow.setPosition(x, y);
  };
  void WindowDraw(sf::RenderWindow &window) {
    if (this->turn == 0)
      this->arrow.setTexture(this->down);
    else if (this->turn == 1)
      this->arrow.setTexture(this->up);
    window.draw(this->arrow);
  }

 private:
  sf::Texture up;
  sf::Texture down;
};
#endif
