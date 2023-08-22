#pragma once
#include "State.h"
#include <iostream>
#include <array>
#include "Global.h"
#include <SFML/Graphics.hpp>
#include "Ant.h"

class LangtonsAnt : public State {

public:

	LangtonsAnt();

	void Init();

	void Render(sf::RenderWindow& window);

	void Update();

	void LateUpdate();

	void Cleanup();

	void Clear();

	array<array<sf::Color, MAP_HEIGHT>, MAP_WIDTH> buffer;

	std::vector<Ant> ants;

};