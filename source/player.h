#ifndef __SOURCE_PLAYER_H__
#define __SOURCE_PLAYER_H__
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "meld.h"
#include "naki.h"
#include "tile.h"
#include "wall.h"

class Player {
 public:
  // declare
  bool tenpai = false;
  bool concealed = true;
  bool bookmaker = false;
  int code = -1;
  int meldorder = 0;
  int score = 45000;
  std::string name = "";
  std::vector<std::string> hand;
  std::vector<std::string> river;
  std::vector<sf::Vector2f> position;
  Meld meld1, meld2, meld3, meld4;

  // set player hand and river scale function
  void SetHand_MeldAndRiverScale(float f) {
    // hand
    this->tile1.setScale(f, f);
    this->tile2.setScale(f, f);
    this->tile3.setScale(f, f);
    this->tile4.setScale(f, f);
    this->tile5.setScale(f, f);
    this->tile6.setScale(f, f);
    this->tile7.setScale(f, f);
    this->tile8.setScale(f, f);
    this->tile9.setScale(f, f);
    this->tile10.setScale(f, f);
    this->tile11.setScale(f, f);
    this->tile12.setScale(f, f);
    this->tile13.setScale(f, f);
    this->tile14.setScale(f, f);
    // meld
    this->meld1.SetScale(f);
    this->meld2.SetScale(f);
    this->meld3.SetScale(f);
    this->meld4.SetScale(f);
    // river
    this->river1.setScale(f, f);
    this->river2.setScale(f, f);
    this->river3.setScale(f, f);
    this->river4.setScale(f, f);
    this->river5.setScale(f, f);
    this->river6.setScale(f, f);
    this->river7.setScale(f, f);
    this->river8.setScale(f, f);
    this->river9.setScale(f, f);
    this->river10.setScale(f, f);
    this->river11.setScale(f, f);
    this->river12.setScale(f, f);
    this->river13.setScale(f, f);
    this->river14.setScale(f, f);
    this->river15.setScale(f, f);
    this->river16.setScale(f, f);
    this->river17.setScale(f, f);
    this->river18.setScale(f, f);
    this->river19.setScale(f, f);
    this->river20.setScale(f, f);
  };

  // set hand position, vector<Vector2f>position and rotation function
  void SetHand_MeldAndRiverPositionAndRotation(float handx, float handy,
                                               float riverx, float rivery,
                                               float meldx, float meldy) {
    // player1
    if (this->code == 0) {
      // set hand position
      this->tile1.setPosition(handx, handy);
      this->tile2.setPosition(handx + 32, handy);
      this->tile3.setPosition(handx + 64, handy);
      this->tile4.setPosition(handx + 96, handy);
      this->tile5.setPosition(handx + 128, handy);
      this->tile6.setPosition(handx + 160, handy);
      this->tile7.setPosition(handx + 192, handy);
      this->tile8.setPosition(handx + 224, handy);
      this->tile9.setPosition(handx + 256, handy);
      this->tile10.setPosition(handx + 288, handy);
      this->tile11.setPosition(handx + 320, handy);
      this->tile12.setPosition(handx + 352, handy);
      this->tile13.setPosition(handx + 384, handy);
      this->tile14.setPosition(handx + 416, handy);
      // set std::vector<sf::Vector2f> position
      this->position.push_back(this->tile1.getPosition());
      this->position.push_back(this->tile2.getPosition());
      this->position.push_back(this->tile3.getPosition());
      this->position.push_back(this->tile4.getPosition());
      this->position.push_back(this->tile5.getPosition());
      this->position.push_back(this->tile6.getPosition());
      this->position.push_back(this->tile7.getPosition());
      this->position.push_back(this->tile8.getPosition());
      this->position.push_back(this->tile9.getPosition());
      this->position.push_back(this->tile10.getPosition());
      this->position.push_back(this->tile11.getPosition());
      this->position.push_back(this->tile12.getPosition());
      this->position.push_back(this->tile13.getPosition());
      this->position.push_back(this->tile14.getPosition());
      // set river position
      this->river1.setPosition(riverx, rivery + 30);
      this->river2.setPosition(riverx + 32, rivery + 30);
      this->river3.setPosition(riverx + 64, rivery + 30);
      this->river4.setPosition(riverx + 96, rivery + 30);
      this->river5.setPosition(riverx + 128, rivery + 30);
      this->river6.setPosition(riverx + 160, rivery + 30);
      this->river7.setPosition(riverx, rivery + 78);
      this->river8.setPosition(riverx + 32, rivery + 78);
      this->river9.setPosition(riverx + 64, rivery + 78);
      this->river10.setPosition(riverx + 96, rivery + 78);
      this->river11.setPosition(riverx + 128, rivery + 78);
      this->river12.setPosition(riverx + 160, rivery + 78);
      this->river13.setPosition(riverx, rivery + 126);
      this->river14.setPosition(riverx + 32, rivery + 126);
      this->river15.setPosition(riverx + 64, rivery + 126);
      this->river16.setPosition(riverx + 96, rivery + 126);
      this->river17.setPosition(riverx + 128, rivery + 126);
      this->river18.setPosition(riverx + 160, rivery + 126);
      this->river19.setPosition(riverx + 192, rivery + 126);
      this->river20.setPosition(riverx + 224, rivery + 126);
      // player2
    } else if (this->code == 1) {
      // hand position
      this->tile14.setPosition(handx, handy);
      this->tile13.setPosition(handx + 32, handy);
      this->tile12.setPosition(handx + 64, handy);
      this->tile11.setPosition(handx + 96, handy);
      this->tile10.setPosition(handx + 128, handy);
      this->tile9.setPosition(handx + 160, handy);
      this->tile8.setPosition(handx + 192, handy);
      this->tile7.setPosition(handx + 224, handy);
      this->tile6.setPosition(handx + 256, handy);
      this->tile5.setPosition(handx + 288, handy);
      this->tile4.setPosition(handx + 320, handy);
      this->tile3.setPosition(handx + 352, handy);
      this->tile2.setPosition(handx + 384, handy);
      this->tile1.setPosition(handx + 416, handy);
      // hand rotation
      this->tile1.setRotation(180);
      this->tile2.setRotation(180);
      this->tile3.setRotation(180);
      this->tile4.setRotation(180);
      this->tile5.setRotation(180);
      this->tile6.setRotation(180);
      this->tile7.setRotation(180);
      this->tile8.setRotation(180);
      this->tile9.setRotation(180);
      this->tile10.setRotation(180);
      this->tile11.setRotation(180);
      this->tile12.setRotation(180);
      this->tile13.setRotation(180);
      this->tile14.setRotation(180);
      // river position
      this->river1.setPosition(riverx + 444, rivery - 80);
      this->river2.setPosition(riverx + 412, rivery - 80);
      this->river3.setPosition(riverx + 380, rivery - 80);
      this->river4.setPosition(riverx + 348, rivery - 80);
      this->river5.setPosition(riverx + 316, rivery - 80);
      this->river6.setPosition(riverx + 284, rivery - 80);
      this->river7.setPosition(riverx + 444, rivery - 128);
      this->river8.setPosition(riverx + 412, rivery - 128);
      this->river9.setPosition(riverx + 380, rivery - 128);
      this->river10.setPosition(riverx + 348, rivery - 128);
      this->river11.setPosition(riverx + 316, rivery - 128);
      this->river12.setPosition(riverx + 284, rivery - 128);
      this->river13.setPosition(riverx + 444, rivery - 176);
      this->river14.setPosition(riverx + 412, rivery - 176);
      this->river15.setPosition(riverx + 380, rivery - 176);
      this->river16.setPosition(riverx + 348, rivery - 176);
      this->river17.setPosition(riverx + 316, rivery - 176);
      this->river18.setPosition(riverx + 284, rivery - 176);
      this->river19.setPosition(riverx + 252, rivery - 176);
      this->river20.setPosition(riverx + 220, rivery - 176);
      // river rotation
      this->river1.setRotation(180);
      this->river2.setRotation(180);
      this->river3.setRotation(180);
      this->river4.setRotation(180);
      this->river5.setRotation(180);
      this->river6.setRotation(180);
      this->river7.setRotation(180);
      this->river8.setRotation(180);
      this->river9.setRotation(180);
      this->river10.setRotation(180);
      this->river11.setRotation(180);
      this->river12.setRotation(180);
      this->river13.setRotation(180);
      this->river14.setRotation(180);
      this->river15.setRotation(180);
      this->river16.setRotation(180);
      this->river17.setRotation(180);
      this->river18.setRotation(180);
      this->river19.setRotation(180);
      this->river20.setRotation(180);
    }
  };
  // set meld original position function
  void SetMeldOriginalPosition(float x, float y) {
    this->meld1.OriginalAndConcealedKangPosition(x, y);
    this->meld2.OriginalAndConcealedKangPosition(x, y - 57);
    this->meld3.OriginalAndConcealedKangPosition(x, y - 114);
    this->meld4.OriginalAndConcealedKangPosition(x, y - 171);
  };

  // set player texture function
  void SetPlayerTexture(Tile &t) {
    // set blank string
    std::string blank = "";
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////// hand ////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    // tile 1
    if (this->hand.size() >= 1)
      t.SwitchTexture(this->hand[0], this->tile1);
    else
      t.SwitchTexture(blank, this->tile1);
    // tile 2
    if (this->hand.size() >= 2)
      t.SwitchTexture(this->hand[1], this->tile2);
    else
      t.SwitchTexture(blank, this->tile2);
    // tile 3
    if (this->hand.size() >= 3)
      t.SwitchTexture(this->hand[2], this->tile3);
    else
      t.SwitchTexture(blank, this->tile3);
    // tile 4
    if (this->hand.size() >= 4)
      t.SwitchTexture(this->hand[3], this->tile4);
    else
      t.SwitchTexture(blank, this->tile4);
    // tile 5
    if (this->hand.size() >= 5)
      t.SwitchTexture(this->hand[4], this->tile5);
    else
      t.SwitchTexture(blank, this->tile5);
    // tile 6
    if (this->hand.size() >= 6)
      t.SwitchTexture(this->hand[5], this->tile6);
    else
      t.SwitchTexture(blank, this->tile6);
    // tile 7
    if (this->hand.size() >= 7)
      t.SwitchTexture(this->hand[6], this->tile7);
    else
      t.SwitchTexture(blank, this->tile7);
    // tile 8
    if (this->hand.size() >= 8)
      t.SwitchTexture(this->hand[7], this->tile8);
    else
      t.SwitchTexture(blank, this->tile8);
    // tile 9
    if (this->hand.size() >= 9)
      t.SwitchTexture(this->hand[8], this->tile9);
    else
      t.SwitchTexture(blank, this->tile9);
    // tile 10
    if (this->hand.size() >= 10)
      t.SwitchTexture(this->hand[9], this->tile10);
    else
      t.SwitchTexture(blank, this->tile10);
    // tile 11
    if (this->hand.size() >= 11)
      t.SwitchTexture(this->hand[10], this->tile11);
    else
      t.SwitchTexture(blank, this->tile11);
    // tile 12
    if (this->hand.size() >= 12)
      t.SwitchTexture(this->hand[11], this->tile12);
    else
      t.SwitchTexture(blank, this->tile12);
    // tile 13
    if (this->hand.size() >= 13)
      t.SwitchTexture(this->hand[12], this->tile13);
    else
      t.SwitchTexture(blank, this->tile13);
    // tile 14
    if (this->hand.size() >= 14)
      t.SwitchTexture(this->hand[13], this->tile14);
    else
      t.SwitchTexture(blank, this->tile14);
    ///////////////////////////////////////////////////////////////////////////
    ////////////////////////////// river //////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    // river 1
    if (this->river.size() >= 1)
      t.SwitchTexture(this->river[0], this->river1);
    else
      t.SwitchTexture(blank, this->river1);
    // river 2
    if (this->river.size() >= 2)
      t.SwitchTexture(this->river[1], this->river2);
    else
      t.SwitchTexture(blank, this->river2);
    // river 3
    if (this->river.size() >= 3)
      t.SwitchTexture(this->river[2], this->river3);
    else
      t.SwitchTexture(blank, this->river3);
    // river 4
    if (this->river.size() >= 4)
      t.SwitchTexture(this->river[3], this->river4);
    else
      t.SwitchTexture(blank, this->river4);
    // river 5
    if (this->river.size() >= 5)
      t.SwitchTexture(this->river[4], this->river5);
    else
      t.SwitchTexture(blank, this->river5);
    // river 6
    if (this->river.size() >= 6)
      t.SwitchTexture(this->river[5], this->river6);
    else
      t.SwitchTexture(blank, this->river6);
    // river 7
    if (this->river.size() >= 7)
      t.SwitchTexture(this->river[6], this->river7);
    else
      t.SwitchTexture(blank, this->river7);
    // river 8
    if (this->river.size() >= 8)
      t.SwitchTexture(this->river[7], this->river8);
    else
      t.SwitchTexture(blank, this->river8);
    // river 9
    if (this->river.size() >= 9)
      t.SwitchTexture(this->river[8], this->river9);
    else
      t.SwitchTexture(blank, this->river9);
    // river 10
    if (this->river.size() >= 10)
      t.SwitchTexture(this->river[9], this->river10);
    else
      t.SwitchTexture(blank, this->river10);
    // river 11
    if (this->river.size() >= 11)
      t.SwitchTexture(this->river[10], this->river11);
    else
      t.SwitchTexture(blank, this->river11);
    // river 12
    if (this->river.size() >= 12)
      t.SwitchTexture(this->river[11], this->river12);
    else
      t.SwitchTexture(blank, this->river12);
    // river 13
    if (this->river.size() >= 13)
      t.SwitchTexture(this->river[12], this->river13);
    else
      t.SwitchTexture(blank, this->river13);
    // river 14
    if (this->river.size() >= 14)
      t.SwitchTexture(this->river[13], this->river14);
    else
      t.SwitchTexture(blank, this->river14);
    // river 15
    if (this->river.size() >= 15)
      t.SwitchTexture(this->river[14], this->river15);
    else
      t.SwitchTexture(blank, this->river15);
    // river 16
    if (this->river.size() >= 16)
      t.SwitchTexture(this->river[15], this->river16);
    else
      t.SwitchTexture(blank, this->river16);
    // river 17
    if (this->river.size() >= 17)
      t.SwitchTexture(this->river[16], this->river17);
    else
      t.SwitchTexture(blank, this->river17);
    // river 18
    if (this->river.size() >= 18)
      t.SwitchTexture(this->river[17], this->river18);
    else
      t.SwitchTexture(blank, this->river18);
    // river 19
    if (this->river.size() >= 19)
      t.SwitchTexture(this->river[18], this->river19);
    else
      t.SwitchTexture(blank, this->river19);
    // river 20
    if (this->river.size() >= 20)
      t.SwitchTexture(this->river[19], this->river20);
    else
      t.SwitchTexture(blank, this->river20);
    ///////////////////////////////////////////////////////////////////////////
    /////////////////////////////// meld //////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    this->meld1.SetTexture(t);
    this->meld2.SetTexture(t);
    this->meld3.SetTexture(t);
    this->meld4.SetTexture(t);
  }

  // choose hightlight function
  void ChooseHighLightOrNot(sf::Vector2i &mousepos) {
    // tile 1
    if (mousepos.x > 175 && mousepos.x < 199 && mousepos.y > 530 &&
        mousepos.y < 550)
      this->tile1.setPosition(this->position[0].x, this->position[0].y - 10);
    else
      this->tile1.setPosition(this->position[0].x, this->position[0].y);
    // tile 2
    if (mousepos.x > 207 && mousepos.x < 235 && mousepos.y > 530 &&
        mousepos.y < 550)
      this->tile2.setPosition(this->position[1].x, this->position[1].y - 10);
    else
      this->tile2.setPosition(this->position[1].x, this->position[1].y);
    // tile 3
    if (mousepos.x > 239 && mousepos.x < 267 && mousepos.y > 530 &&
        mousepos.y < 550)
      this->tile3.setPosition(this->position[2].x, this->position[2].y - 10);
    else
      this->tile3.setPosition(this->position[2].x, this->position[2].y);
    // tile 4
    if (mousepos.x > 271 && mousepos.x < 299 && mousepos.y > 530 &&
        mousepos.y < 550)
      this->tile4.setPosition(this->position[3].x, this->position[3].y - 10);
    else
      this->tile4.setPosition(this->position[3].x, this->position[3].y);
    // tile 5
    if (mousepos.x > 303 && mousepos.x < 331 && mousepos.y > 530 &&
        mousepos.y < 550)
      this->tile5.setPosition(this->position[4].x, this->position[4].y - 10);
    else
      this->tile5.setPosition(this->position[4].x, this->position[4].y);
    // tile 6
    if (mousepos.x > 335 && mousepos.x < 363 && mousepos.y > 530 &&
        mousepos.y < 550)
      this->tile6.setPosition(this->position[5].x, this->position[5].y - 10);
    else
      this->tile6.setPosition(this->position[5].x, this->position[5].y);
    // tile 7
    if (mousepos.x > 367 && mousepos.x < 395 && mousepos.y > 530 &&
        mousepos.y < 550)
      this->tile7.setPosition(this->position[6].x, this->position[6].y - 10);
    else
      this->tile7.setPosition(this->position[6].x, this->position[6].y);
    // tile 8
    if (mousepos.x > 399 && mousepos.x < 427 && mousepos.y > 530 &&
        mousepos.y < 550)
      this->tile8.setPosition(this->position[7].x, this->position[7].y - 10);
    else
      this->tile8.setPosition(this->position[7].x, this->position[7].y);
    // tile 9
    if (mousepos.x > 431 && mousepos.x < 459 && mousepos.y > 530 &&
        mousepos.y < 550)
      this->tile9.setPosition(this->position[8].x, this->position[8].y - 10);
    else
      this->tile9.setPosition(this->position[8].x, this->position[8].y);
    // tile 10
    if (mousepos.x > 463 && mousepos.x < 491 && mousepos.y > 530 &&
        mousepos.y < 550)
      this->tile10.setPosition(this->position[9].x, this->position[9].y - 10);
    else
      this->tile10.setPosition(this->position[9].x, this->position[9].y);
    // tile 11
    if (mousepos.x > 495 && mousepos.x < 523 && mousepos.y > 530 &&
        mousepos.y < 550)
      this->tile11.setPosition(this->position[10].x, this->position[10].y - 10);
    else
      this->tile11.setPosition(this->position[10].x, this->position[10].y);
    // tile 12
    if (mousepos.x > 527 && mousepos.x < 555 && mousepos.y > 530 &&
        mousepos.y < 550)
      this->tile12.setPosition(this->position[11].x, this->position[11].y - 10);
    else
      this->tile12.setPosition(this->position[11].x, this->position[11].y);
    // tile 13
    if (mousepos.x > 559 && mousepos.x < 587 && mousepos.y > 530 &&
        mousepos.y < 550)
      this->tile13.setPosition(this->position[12].x, this->position[12].y - 10);
    else
      this->tile13.setPosition(this->position[12].x, this->position[12].y);
    // tile 14
    if (mousepos.x > 591 && mousepos.x < 619 && mousepos.y > 530 &&
        mousepos.y < 550)
      this->tile14.setPosition(this->position[13].x, this->position[13].y - 10);
    else
      this->tile14.setPosition(this->position[13].x, this->position[13].y);
  }

  // player select one function
  int Select(sf::Vector2i &mousepos) {
    // tile 1
    if (mousepos.x > 175 && mousepos.x < 199 && mousepos.y > 530 &&
        mousepos.y < 550)
      return 1;
    // tile 2
    else if (mousepos.x > 207 && mousepos.x < 235 && mousepos.y > 530 &&
             mousepos.y < 550)
      return 2;
    // tile 3
    else if (mousepos.x > 239 && mousepos.x < 267 && mousepos.y > 530 &&
             mousepos.y < 550)
      return 3;
    // tile 4
    else if (mousepos.x > 271 && mousepos.x < 299 && mousepos.y > 530 &&
             mousepos.y < 550)
      return 4;
    // tile 5
    else if (mousepos.x > 303 && mousepos.x < 331 && mousepos.y > 530 &&
             mousepos.y < 550)
      return 5;
    // tile 6
    else if (mousepos.x > 335 && mousepos.x < 363 && mousepos.y > 530 &&
             mousepos.y < 550)
      return 6;
    // tile 7
    else if (mousepos.x > 367 && mousepos.x < 395 && mousepos.y > 530 &&
             mousepos.y < 550)
      return 7;
    // tile 8
    else if (mousepos.x > 399 && mousepos.x < 427 && mousepos.y > 530 &&
             mousepos.y < 550)
      return 8;
    // tile 9
    else if (mousepos.x > 431 && mousepos.x < 459 && mousepos.y > 530 &&
             mousepos.y < 550)
      return 9;
    // tile 10
    else if (mousepos.x > 463 && mousepos.x < 491 && mousepos.y > 530 &&
             mousepos.y < 550)
      return 10;
    // tile 11
    else if (mousepos.x > 495 && mousepos.x < 523 && mousepos.y > 530 &&
             mousepos.y < 550)
      return 11;
    // tile 12
    else if (mousepos.x > 527 && mousepos.x < 555 && mousepos.y > 530 &&
             mousepos.y < 550)
      return 12;
    // tile 13
    else if (mousepos.x > 559 && mousepos.x < 587 && mousepos.y > 530 &&
             mousepos.y < 550)
      return 13;
    // tile 14
    else if (mousepos.x > 591 && mousepos.x < 619 && mousepos.y > 530 &&
             mousepos.y < 550)
      return 14;
    else
      return 0;
  }

  // player discard from hand to river function
  void DisCardFromHandToRiver(int player_select) {
    this->river.push_back(
        this->hand[static_cast<std::vector<
                       std::string, std::allocator<std::string>>::size_type>(
                       player_select) -
                   1]);
    this->hand.erase(this->hand.begin() + player_select - 1);
  }
  // switch order to meld function
  void SwitchOrderToMeld(std::vector<std::string> tempmeld,
                         std::string typeofnaki) {
    // switch meldorder number
    switch (this->meldorder) {
        // number = 0
      case 0:
        this->meld1.hand = tempmeld;
        this->meld1.typeofnaki = typeofnaki;
        if (this->meld1.typeofnaki == "chi" ||
            this->meld1.typeofnaki == "pong" || this->meld1.typeofnaki == "big")
          this->meld1.ChiPongAndBigKangPosition();
        break;
        // number = 1
      case 1:
        this->meld2.hand = tempmeld;
        this->meld2.typeofnaki = typeofnaki;
        if (this->meld2.typeofnaki == "chi" ||
            this->meld2.typeofnaki == "pong" || this->meld2.typeofnaki == "big")
          this->meld2.ChiPongAndBigKangPosition();
        break;
        // number = 2
      case 2:
        this->meld3.hand = tempmeld;
        this->meld3.typeofnaki = typeofnaki;
        if (this->meld3.typeofnaki == "chi" ||
            this->meld3.typeofnaki == "pong" || this->meld3.typeofnaki == "big")
          this->meld3.ChiPongAndBigKangPosition();
        break;
        // number =3
      case 3:
        this->meld4.hand = tempmeld;
        this->meld4.typeofnaki = typeofnaki;
        if (this->meld4.typeofnaki == "chi" ||
            this->meld4.typeofnaki == "pong" || this->meld4.typeofnaki == "big")
          this->meld4.ChiPongAndBigKangPosition();
        break;
    }

    // this->meldorder +1
    this->meldorder++;
  };

  // make chi combined function
  void Chi_Combined(std::vector<std::string> targetmeld,
                    std::vector<std::string> &otherplayerriver) {
    // declare
    std::vector<std::string> tempmeld;
    // append target to tempmeld from other player river last one and erase it
    tempmeld.push_back(otherplayerriver.back());
    otherplayerriver.pop_back();
    // append targetmeld to temphand and erase from player hand
    for (int i = 0; i < targetmeld.size(); i++) {
      tempmeld.push_back(targetmeld[i]);
      this->hand.erase(
          std::find(this->hand.begin(), this->hand.end(), targetmeld[i]));
    }

    // append tempmeld to this->meld1~4
    SwitchOrderToMeld(tempmeld, "chi");
  };

  // make pong combined function
  void Pong_Combined(std::vector<std::string> &otherplayerriver) {
    // declare
    std::vector<std::string> tempmeld;
    // append target to tempmeld three time
    for (int i = 0; i < 3; i++) tempmeld.push_back(otherplayerriver.back());
    // erase target from hand two time
    for (int i = 0; i < 2; i++)
      this->hand.erase(std::find(this->hand.begin(), this->hand.end(),
                                 otherplayerriver.back()));
    // erase other player river last
    otherplayerriver.pop_back();
    // append tempmeld to this->meld1~4
    SwitchOrderToMeld(tempmeld, "pong");
  };

  // draw wall tail top or button
  void DrawWallTailTile(Wall &wall) {
    if (wall.walltailtop) {
      this->hand.push_back(*(wall.hand.rbegin() + 1));
      wall.hand.erase(wall.hand.end() - 2);
    } else {
      this->hand.push_back(wall.hand.back());
      wall.hand.erase(wall.hand.end()-1);
    }
    wall.walltailtop = !wall.walltailtop;
  };

  // make kang combined function
  void BigKangCombined(std::vector<std::string> &otherplayerriver, Wall &wall) {
    // declare
    std::vector<std::string> tempmeld;
    // append target to tempmeld four time
    for (int i = 0; i < 4; i++) tempmeld.push_back(otherplayerriver.back());
    // erase target from hand two time
    for (int i = 0; i < 3; i++)
      this->hand.erase(std::find(this->hand.begin(), this->hand.end(),
                                 otherplayerriver.back()));
    // erase other player river last
    otherplayerriver.pop_back();
    // append tempmeld to this->meld1~4
    SwitchOrderToMeld(tempmeld, "big");
    // append wall tail tile to hand
    DrawWallTailTile(wall);
  };

  // make concealed combined function
  void ConcealedKangCombined(std::string themeldone, Wall &wall) {
    // declare
    std::vector<std::string> tempmeld;
    for (int i = 0; i < 4; i++) {
      tempmeld.push_back(themeldone);
      this->hand.erase(
          std::find(this->hand.begin(), this->hand.end(), themeldone));
    }
    SwitchOrderToMeld(tempmeld, "concealed");
    DrawWallTailTile(wall);
  };

  // make small conbinde function
  void SmallKangCombined(std::string themeldone, int whitchmeld, Wall &wall) {
    std::vector<std::string> tempmeld;
    switch (whitchmeld) {
      case 1:
        this->meld1.hand.push_back(themeldone);
        this->meld1.SmallKangPosition();
        this->meld1.typeofnaki = "small";
        break;
      case 2:
        this->meld2.hand.push_back(themeldone);
        this->meld2.typeofnaki = "small";
        break;
      case 3:
        this->meld3.hand.push_back(themeldone);
        this->meld3.typeofnaki = "small";
        break;
      case 4:
        this->meld4.hand.push_back(themeldone);
        this->meld4.typeofnaki = "small";
        break;
    }
    this->hand.erase(
        std::find(this->hand.begin(), this->hand.end(), themeldone));
    DrawWallTailTile(wall);
  };
  // window.draw function
  void Player_Window_Draw(sf::RenderWindow &window) {
    // hand
    window.draw(this->tile1);
    window.draw(this->tile2);
    window.draw(this->tile3);
    window.draw(this->tile4);
    window.draw(this->tile5);
    window.draw(this->tile6);
    window.draw(this->tile7);
    window.draw(this->tile8);
    window.draw(this->tile9);
    window.draw(this->tile10);
    window.draw(this->tile11);
    window.draw(this->tile12);
    window.draw(this->tile13);
    window.draw(this->tile14);
    // river
    window.draw(this->river1);
    window.draw(this->river2);
    window.draw(this->river3);
    window.draw(this->river4);
    window.draw(this->river5);
    window.draw(this->river6);
    window.draw(this->river7);
    window.draw(this->river8);
    window.draw(this->river9);
    window.draw(this->river10);
    window.draw(this->river11);
    window.draw(this->river12);
    window.draw(this->river13);
    window.draw(this->river14);
    window.draw(this->river15);
    window.draw(this->river16);
    window.draw(this->river17);
    window.draw(this->river18);
    window.draw(this->river19);
    window.draw(this->river20);
    // meld1
    this->meld1.Meld_Window_Draw(window);
    this->meld2.Meld_Window_Draw(window);
    this->meld3.Meld_Window_Draw(window);
    this->meld4.Meld_Window_Draw(window);
  }

 private:
  // hand sprite
  sf::Sprite tile1;
  sf::Sprite tile2;
  sf::Sprite tile3;
  sf::Sprite tile4;
  sf::Sprite tile5;
  sf::Sprite tile6;
  sf::Sprite tile7;
  sf::Sprite tile8;
  sf::Sprite tile9;
  sf::Sprite tile10;
  sf::Sprite tile11;
  sf::Sprite tile12;
  sf::Sprite tile13;
  sf::Sprite tile14;

  // river sprite
  sf::Sprite river1;
  sf::Sprite river2;
  sf::Sprite river3;
  sf::Sprite river4;
  sf::Sprite river5;
  sf::Sprite river6;
  sf::Sprite river7;
  sf::Sprite river8;
  sf::Sprite river9;
  sf::Sprite river10;
  sf::Sprite river11;
  sf::Sprite river12;
  sf::Sprite river13;
  sf::Sprite river14;
  sf::Sprite river15;
  sf::Sprite river16;
  sf::Sprite river17;
  sf::Sprite river18;
  sf::Sprite river19;
  sf::Sprite river20;
};

#endif
