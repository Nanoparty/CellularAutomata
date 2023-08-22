#pragma once
#include "State.h"
#include <iostream>
#include <array>
#include "Global.h"
#include <SFML/Graphics.hpp>

class Seeds : public State {

public:

	Seeds();

	void Init();

	void Render(sf::RenderWindow& window);

	void Update();

	void LateUpdate();

	void Cleanup();

	void Clear();

	std::array<std::array<unsigned char, MAP_HEIGHT>, MAP_WIDTH> buffer1;
	std::array<std::array<unsigned char, MAP_HEIGHT>, MAP_WIDTH> buffer2;

};