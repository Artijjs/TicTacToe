#include "Kvadrats.h"



void Kvadrats::draw(sf::RenderWindow &window)
{
	window.draw(kubiks);

}

void Kvadrats::setTexture(sf::Texture &t, int state)
{
	kubiks.setTexture(&t);
	this->state = state;

}

int Kvadrats::getState()
{
	return state;
}

sf::RectangleShape Kvadrats::getShape()
{
	return kubiks;

}

Kvadrats::Kvadrats(sf::Vector2f pozicija)
{
	kubiks.setSize(sf::Vector2f(200, 200));
	kubiks.setFillColor(sf::Color::White);
	kubiks.setOutlineThickness(5);
	kubiks.setOutlineColor(sf::Color::Black);
	kubiks.setPosition(pozicija);
	
}



Kvadrats::~Kvadrats()
{

}
