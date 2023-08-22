#pragma once
#include <SFML/Graphics.hpp>
#include "Global.h"
#include <array>


// Base State Class
class State
{
public:
	

	State();

	virtual void Init();

	virtual void Render(sf::RenderWindow &window);

	virtual void Update();

	virtual void LateUpdate();

	virtual void Cleanup();

	virtual void Clear();

	std::array<std::array<unsigned char, MAP_HEIGHT>, MAP_WIDTH> buffer1;
	std::array<std::array<unsigned char, MAP_HEIGHT>, MAP_WIDTH> buffer2;
};