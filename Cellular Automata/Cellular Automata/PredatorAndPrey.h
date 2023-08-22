#pragma once
#include "State.h"
#include <iostream>
#include <array>
#include "Global.h"
#include <SFML/Graphics.hpp>
#include "Creature.h"

class PredatorAndPrey : public State {

public:

	PredatorAndPrey();

	void Init();

	void Render(sf::RenderWindow& window);

	void Update();

	void LateUpdate();

	void Cleanup();

	void Clear();

	void updatePredator(Creature* thisCreature, Creature* otherCreature);

	void updatePrey(Creature* thisCreature, Creature* otherCreature);

	std::array<std::array<Creature*, MAP_HEIGHT>, MAP_WIDTH> buffer1;
};