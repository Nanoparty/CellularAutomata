#pragma once
#include "State.h"
#include <array>
#include "Global.h"
#include <SFML/Graphics.hpp>

class BriansBrain : public State {
	
public:

	BriansBrain();

	void Init();

	void Render(sf::RenderWindow& window);

	void Update();

	void LateUpdate();

	void Cleanup();

	void Clear();

	std::array<std::array<unsigned char, MAP_HEIGHT>, MAP_WIDTH> buffer1;
	std::array<std::array<unsigned char, MAP_HEIGHT>, MAP_WIDTH> buffer2;
};