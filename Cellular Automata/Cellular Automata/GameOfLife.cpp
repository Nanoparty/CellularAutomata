#include "GameOfLife.h"

GameOfLife::GameOfLife()
{
    Init();
}

void GameOfLife::Init()
{

    // set initial world state
    int num = 0;
    for (int x = 0; x < MAP_WIDTH; x++)
    {
        for (int y = 0; y < MAP_HEIGHT; y++)
        {
            bool spawn = (rand() % 100) <= 10;
            if (spawn)
            {
                buffer1[x][y] = 1;
                num++;
            }
            else
            {
                buffer1[x][y] = 0;
            }
        }
    }
}

void GameOfLife::Render(sf::RenderWindow &window)
{
    // draw world state
    for (unsigned int x = 0; x < MAP_WIDTH; x++)
    {
        for (unsigned int y = 0; y < MAP_HEIGHT; y++)
        {
            if (buffer1[x][y] == 1)
            {
                sf::RectangleShape pixel(sf::Vector2f(CELL_SIZE, CELL_SIZE));
                pixel.setPosition(sf::Vector2f(x * CELL_SIZE, y * CELL_SIZE));
                pixel.setFillColor(sf::Color(21, 169, 207));
                window.draw(pixel);
            }
        }
    }

}

void GameOfLife::Update()
{
    for (int x = 0; x < MAP_WIDTH; x++)
    {
        for (int y = 0; y < MAP_HEIGHT; y++)
        {
            int startState = buffer1[x][y];
            int endState = 0;

            int liveNeighbours = 0;

            if (x > 0) {
                liveNeighbours += buffer1[x - 1][y];
            }
            if (x < MAP_WIDTH - 1) {
                liveNeighbours += buffer1[x + 1][y];
            }
            if (y > 0) {
                liveNeighbours += buffer1[x][y - 1];
            }
            if (y < MAP_HEIGHT - 1) {
                liveNeighbours += buffer1[x][y + 1];
            }
            if (x > 0 && y > 0) {
                liveNeighbours += buffer1[x - 1][y - 1];
            }
            if (x > 0 && y < MAP_HEIGHT - 1) {
                liveNeighbours += buffer1[x - 1][y + 1];
            }
            if (x < MAP_WIDTH - 1 && y > 0) {
                liveNeighbours += buffer1[x + 1][y - 1];
            }
            if (x < MAP_WIDTH - 1 && y < MAP_HEIGHT - 1) {
                liveNeighbours += buffer1[x + 1][y + 1];
            }

            if (startState)
            {
                if (liveNeighbours < 2) endState = 0;
                if (liveNeighbours == 2 || liveNeighbours == 3) endState = 1;
                if (liveNeighbours > 3) endState = 0;
            }
            else {
                if (liveNeighbours == 3) endState = 1;
                else endState = 0;
            }

            buffer2[x][y] = endState;
        }
    }
}

void GameOfLife::LateUpdate()
{
    // swap buffers
    for (unsigned int x = 0; x < MAP_WIDTH; x++)
    {
        for (unsigned int y = 0; y < MAP_HEIGHT; y++)
        {
            buffer1[x][y] = buffer2[x][y];
        }
    }
}

void GameOfLife::Cleanup()
{

}

void GameOfLife::Clear() {
    for (unsigned int x = 0; x < MAP_WIDTH; x++)
    {
        for (unsigned int y = 0; y < MAP_HEIGHT; y++)
        {
            buffer1[x][y] = 0;
            buffer2[x][y] = 1;
        }
    }
}