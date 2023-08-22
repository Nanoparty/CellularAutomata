#include "Seeds.h"

Seeds::Seeds()
{
    Init();
}

void Seeds::Init()
{

    // set initial world state
    int num = 0;
    for (int x = 0; x < MAP_WIDTH; x++)
    {
        for (int y = 0; y < MAP_HEIGHT; y++)
        {
            bool spawn = (rand() % 100) <= 1;
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

void Seeds::Render(sf::RenderWindow& window)
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
                pixel.setFillColor(sf::Color(240, 175, 22));
                window.draw(pixel);
            }
        }
    }

}

void Seeds::Update()
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

            if (startState == 0)
            {
                if (liveNeighbours == 2) {
                    buffer2[x][y] = 1;
                    continue;
                }
            }
            buffer2[x][y] = 0;
        }
    }
}

void Seeds::LateUpdate()
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

void Seeds::Cleanup()
{

}

void Seeds::Clear() {
    for (unsigned int x = 0; x < MAP_WIDTH; x++)
    {
        for (unsigned int y = 0; y < MAP_HEIGHT; y++)
        {
            buffer1[x][y] = 0;
            buffer2[x][y] = 1;
        }
    }
}