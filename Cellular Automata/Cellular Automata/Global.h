#pragma once

#include <string>



const int MAP_WIDTH = 400;
const int MAP_HEIGHT = 250;
const int CELL_SIZE = 3;

const int SCREEN_WIDTH = MAP_WIDTH * CELL_SIZE;
const int SCREEN_HEIGHT = MAP_HEIGHT * CELL_SIZE;
const std::string SCREEN_TITLE = "Nathan's Game Of Life";

const float UPDATE_RATE = 1.f;