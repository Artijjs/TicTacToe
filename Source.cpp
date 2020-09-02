#include <SFML/Graphics.hpp>
#include <iostream>
#include "Kvadrats.h"



#define SCREEN_WIDTH 615
#define SCREEN_HEIGHT 615

int CheckWinner(Kvadrats *BrickMatrix[9])
{

	if (BrickMatrix[0]->getState() == 1 && BrickMatrix[1]->getState() == 1 && BrickMatrix[2]->getState() == 1) return 1;
	if (BrickMatrix[0]->getState() == 2 && BrickMatrix[1]->getState() == 2 && BrickMatrix[2]->getState() == 2) return 2;
	if (BrickMatrix[3]->getState() == 1 && BrickMatrix[4]->getState() == 1 && BrickMatrix[5]->getState() == 1) return 1;
	if (BrickMatrix[3]->getState() == 2 && BrickMatrix[4]->getState() == 2 && BrickMatrix[5]->getState() == 2) return 2;
	if (BrickMatrix[6]->getState() == 1 && BrickMatrix[7]->getState() == 1 && BrickMatrix[8]->getState() == 1) return 1;
	if (BrickMatrix[6]->getState() == 2 && BrickMatrix[7]->getState() == 2 && BrickMatrix[8]->getState() == 2) return 2;
	if (BrickMatrix[0]->getState() == 1 && BrickMatrix[3]->getState() == 1 && BrickMatrix[6]->getState() == 1) return 1;
	if (BrickMatrix[0]->getState() == 2 && BrickMatrix[3]->getState() == 2 && BrickMatrix[6]->getState() == 2) return 2;
	if (BrickMatrix[1]->getState() == 1 && BrickMatrix[4]->getState() == 1 && BrickMatrix[7]->getState() == 1) return 1;
	if (BrickMatrix[1]->getState() == 2 && BrickMatrix[4]->getState() == 2 && BrickMatrix[7]->getState() == 2) return 2;
	if (BrickMatrix[2]->getState() == 1 && BrickMatrix[5]->getState() == 1 && BrickMatrix[8]->getState() == 1) return 1;
	if (BrickMatrix[2]->getState() == 2 && BrickMatrix[5]->getState() == 2 && BrickMatrix[8]->getState() == 2) return 2;
	if (BrickMatrix[0]->getState() == 1 && BrickMatrix[4]->getState() == 1 && BrickMatrix[8]->getState() == 1) return 1;
	if (BrickMatrix[0]->getState() == 2 && BrickMatrix[4]->getState() == 2 && BrickMatrix[8]->getState() == 2) return 2;
	if (BrickMatrix[2]->getState() == 1 && BrickMatrix[4]->getState() == 1 && BrickMatrix[6]->getState() == 1) return 1;
	if (BrickMatrix[2]->getState() == 2 && BrickMatrix[4]->getState() == 2 && BrickMatrix[6]->getState() == 2) return 2;
	if (BrickMatrix[0]->getState() != 0 && BrickMatrix[1]->getState() != 0 && BrickMatrix[2]->getState() != 0 &&
		BrickMatrix[3]->getState() != 0 && BrickMatrix[4]->getState() != 0 && BrickMatrix[5]->getState() != 0 &&
		BrickMatrix[6]->getState() != 0 && BrickMatrix[7]->getState() != 0 && BrickMatrix[8]->getState() != 0)
		return 3; // 
	else return 0;

}


int main() {

	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Tic Tac Toe");

	sf::RectangleShape mouse(sf::Vector2f(1, 1));

	sf::RectangleShape kubiks[9];

	sf::Texture circle;

	sf::Texture cross;

	bool parbaude = false;
	bool clicked = false;


	if (!circle.loadFromFile("circle.png"))
		std::cout << "Kluda aplu bildes iegusana" << std::endl;

	if (!cross.loadFromFile("cross.png"))
		std::cout << "Kluda krustinu bildes iegusana " << std::endl;

	Kvadrats *laukumi[9];

	for (int i = 0; i < 9; i++) {

		if (i < 3)
			laukumi[i] = new Kvadrats(sf::Vector2f(5 + 200 * i, 5));
		
		else if (i < 6)
			laukumi[i] = new Kvadrats(sf::Vector2f(5 + 200 * (i - 3), 205));

		else 
			laukumi[i] = new Kvadrats(sf::Vector2f(5 + 200 * (i - 6), 405));
	}

	while (window.isOpen())
	{
		sf::Event event;    // notikumu switch

		while (window.pollEvent(event)) {

			switch (event.type)
			{
			case sf::Event::Closed:
	
				window.close();

				break;

			case sf::Event::MouseButtonReleased:

				clicked = false;
				std::cout << "Malacis" << std::endl;
				break;
		
			case sf::Event::KeyPressed:  // Esc izeja

				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Escape)
					{
						std::cout << "the escape key was pressed" << std::endl;
						window.close();
					}
				}
				break;
			}
		}

		mouse.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));

		window.clear(sf::Color::White);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !clicked)      //kvadrata noteiksana ar peles kliski
		{
			for (int i = 0; i < 9; i++)
			{
				if (laukumi[i]->getShape().getGlobalBounds().intersects(mouse.getGlobalBounds()) && laukumi[i]->getShape().getTexture() == nullptr)
				{
					if (parbaude)
						laukumi[i]->setTexture(circle, 1);
					else
						laukumi[i]->setTexture(cross, 2);

					parbaude = !parbaude;
					

					std::cout << "Kubiks nr: " << i << std::endl;
					std::cout << "State: " << laukumi[i]->getState() << std::endl;
				}
			}

			clicked = true;
		}

		if (CheckWinner(laukumi)) {

			std::cout << "Uzvaretajs: " << CheckWinner(laukumi) << std::endl;
		}

		for (int i = 0; i < 9; i++)
		{
			laukumi[i]->draw(window);   // laukumu zimesana ekrana
		}


		//objektu zimesana

		window.display();

	}

}