#ifndef __SOURCE_SCORE_H___
#define __SOURCE_SCORE_H___
#include <SFML/Graphics.hpp>

// score struct
struct Score{
	sf::Text p1s;
	sf::Text p2s;
	sf::Font font;
};

// set score function
void SetScore(Score &s){
	s.font.loadFromFile("./font/msjhbd.ttc");
	// set text
	s.p1s.setFont(s.font);
	s.p2s.setFont(s.font);
	s.p1s.setCharacterSize(20);
	s.p2s.setCharacterSize(20);
	s.p1s.setFillColor(sf::Color::Black);
	s.p2s.setFillColor(sf::Color::Black);
	s.p1s.setStyle(sf::Text::Bold);
	s.p2s.setStyle(sf::Text::Bold);
	s.p1s.setString("45000");
	s.p2s.setString("45000");
	s.p1s.setPosition(350,310);
	s.p2s.setPosition(415,260);
	s.p2s.setRotation(180);
}

// window.draw function
void Score_Window_Draw(sf::RenderWindow &window, Score &score){
	window.draw(score.p1s);
	window.draw(score.p2s);
}

#endif
