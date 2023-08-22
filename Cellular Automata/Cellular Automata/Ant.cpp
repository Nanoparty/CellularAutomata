#include "Ant.h"


Ant::Ant()
{
	color = sf::Color(rand() % 255, rand() % 255, rand() % 255);
	direction = rand() % 4;
}

sf::Color Ant::getColor()
{

	return color;

}

void Ant::setLocation(int nx, int ny)
{
	x = nx;
	y = ny;
}

void Ant::update(array<array<sf::Color, MAP_HEIGHT>, MAP_WIDTH>& buffer)
{
	if (buffer[x][y] == sf::Color::Black)
	{
		rotate(1);
		buffer[x][y] = getColor();
		move();
	}
	else
	{
		rotate(-1);
		buffer[x][y] = sf::Color::Black;
		move();
	}
}

void Ant::rotate(int dir)
{
	direction += dir;
	if (direction < 0) direction = 3;
	if (direction > 3) direction = 0;
}

void Ant::move()
{
	if (direction == 0) {
		y -= 1;
	}
	if (direction == 1) {
		x += 1;
	}
	if (direction == 2) {
		y += 1;
	}
	if (direction == 3) {
		x -= 1;
	}

	if (x < 0) x = 0;
	if (x > MAP_WIDTH - 1) x = MAP_WIDTH - 1;
	if (y < 0) y = 0;
	if (y > MAP_HEIGHT - 1) y = MAP_HEIGHT - 1;
}