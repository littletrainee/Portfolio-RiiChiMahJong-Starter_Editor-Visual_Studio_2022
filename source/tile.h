#ifndef __SOURCE_TILE_H__
#define __SOURCE_TILE_H__
#include <SFML/Graphics.hpp>
#include <string>

// tile struct
class Tile {
 public:
  sf::Texture t1m;
  sf::Texture t2m;
  sf::Texture t3m;
  sf::Texture t4m;
  sf::Texture t5m;
  sf::Texture t6m;
  sf::Texture t7m;
  sf::Texture t8m;
  sf::Texture t9m;
  sf::Texture t1z;
  sf::Texture t2z;
  sf::Texture t3z;
  sf::Texture t4z;
  sf::Texture t5z;
  sf::Texture t6z;
  sf::Texture t7z;
  sf::Texture blank;
  sf::Texture tileback;

  // load tile from file function
  void LoadTileImg() {
    this->t1m.loadFromFile("image/1m.png");
    this->t2m.loadFromFile("image/2m.png");
    this->t3m.loadFromFile("image/3m.png");
    this->t4m.loadFromFile("image/4m.png");
    this->t5m.loadFromFile("image/5m.png");
    this->t6m.loadFromFile("image/6m.png");
    this->t7m.loadFromFile("image/7m.png");
    this->t8m.loadFromFile("image/8m.png");
    this->t9m.loadFromFile("image/9m.png");
    this->t1z.loadFromFile("image/1z.png");
    this->t2z.loadFromFile("image/2z.png");
    this->t3z.loadFromFile("image/3z.png");
    this->t4z.loadFromFile("image/4z.png");
    this->t5z.loadFromFile("image/5z_blank.png");
    this->t6z.loadFromFile("image/6z.png");
    this->t7z.loadFromFile("image/7z.png");
    this->blank.loadFromFile("image/empty140x200.png");
    this->tileback.loadFromFile("image/back.png");
  };
  // switch texture function
  void SwitchTexture(std::string &target, sf::Sprite &s) {
    if (target == "1m")
      s.setTexture(this->t1m);
    else if (target == "2m")
      s.setTexture(this->t2m);
    else if (target == "3m")
      s.setTexture(this->t3m);
    else if (target == "4m")
      s.setTexture(this->t4m);
    else if (target == "5m")
      s.setTexture(this->t5m);
    else if (target == "6m")
      s.setTexture(this->t6m);
    else if (target == "7m")
      s.setTexture(this->t7m);
    else if (target == "8m")
      s.setTexture(this->t8m);
    else if (target == "9m")
      s.setTexture(this->t9m);
    else if (target == "1z")
      s.setTexture(this->t1z);
    else if (target == "2z")
      s.setTexture(this->t2z);
    else if (target == "3z")
      s.setTexture(this->t3z);
    else if (target == "4z")
      s.setTexture(this->t4z);
    else if (target == "5z")
      s.setTexture(this->t5z);
    else if (target == "6z")
      s.setTexture(this->t6z);
    else if (target == "7z")
      s.setTexture(this->t7z);
    else if (target == "")
      s.setTexture(this->blank);
    else if (target == "back")
      s.setTexture(this->tileback);
  };
};
#endif
