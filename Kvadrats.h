#pragma once
#include <SFML/Graphics.hpp>


class Kvadrats
{

private:
	sf::RectangleShape kubiks;
	int state = 0;
	
public:
	void draw(sf::RenderWindow &window);
	void setTexture(sf::Texture &t, int state);
	int getState();
	sf::RectangleShape getShape();
	Kvadrats(sf::Vector2f pozicija);
	~Kvadrats();
};

