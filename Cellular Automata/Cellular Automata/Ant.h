#pragma once

#include <SFML/Graphics.hpp>
#include "Global.h"
#include <array>

using std::array;

class Ant
{
public:
	Ant();

	sf::Color getColor();

	void setLocation(int x, int y);

	void update(array<array<sf::Color, MAP_HEIGHT>, MAP_WIDTH>& buffer);

	void rotate(int dir);

	void move();

private:
	int direction = 0;
	int x = 0;
	int y = 0;
	sf::Color color = sf::Color::Green;
};