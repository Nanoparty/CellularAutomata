#pragma once

#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>

#include "Global.h"
#include "State.h"
#include "GameOfLife.h"
#include "BriansBrain.h"
#include "LangtonsAnt.h"
#include "PredatorAndPrey.h"
#include "Seeds.h"

using namespace std;

enum class GameType { GameOfLife, BriansBrain, LangtonsAnt, PredatorAndPrey, Seeds};

GameType stateType;

State* activeState;

sf::Text gamemodeText;
sf::Text controlsText;
sf::Text playText;
sf::Text resetText;
sf::Text clearText;
sf::Text modeText;
sf::Text placeText;

sf::Font font;

void initText(sf::Text& text, float y);

void placeCell(int x, int y);

void UpdateState();