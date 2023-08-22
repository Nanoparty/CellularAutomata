#include "BriansBrain.h"

BriansBrain::BriansBrain()
{
    Init();
}

void BriansBrain::Init()
{
    int NUM_CELLS = 500;

    // set initial world state
    for (int x = 0; x < MAP_WIDTH; x++)
    {
        for (int y = 0; y < MAP_HEIGHT; y++)
        {
            buffer1[x][y] = 2;
        }
    }

    for (int n = 0; n < NUM_CELLS; n++)
    {
        int rx = rand() % MAP_WIDTH;
        int ry = rand() % MAP_HEIGHT;
        buffer1[rx][ry] = 0;
    }
}

void BriansBrain::Render(sf::RenderWindow& window)
{
    // draw world state
    for (unsigned int x = 0; x < MAP_WIDTH; x++)
    {
        for (unsigned int y = 0; y < MAP_HEIGHT; y++)
        {
            sf::RectangleShape pixel(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            pixel.setPosition(sf::Vector2f(x * CELL_SIZE, y * CELL_SIZE));
            unsigned char value = buffer1[x][y];
            if (value == 0) pixel.setFillColor(sf::Color(179, 66, 245));
            if (value == 1) pixel.setFillColor(sf::Color(97, 42, 130));
            if (value == 2) pixel.setFillColor(sf::Color(15, 7, 20));

            window.draw(pixel);
        }
    }

}

void BriansBrain::Update()
{
    for (int x = 0; x < MAP_WIDTH; x++)
    {
        for (int y = 0; y < MAP_HEIGHT; y++)
        {
            // Alive to Dying
            if (buffer1[x][y] == 0)
            {
                buffer2[x][y] = 1;
                continue;
            }

            // Dying to Dead
            if (buffer1[x][y] == 1)
            {
                buffer2[x][y] = 2;
                continue;
            }

            //Dead to Alive
            int neighbors = 0;

            int lx = x - 1;
            int rx = x + 1;
            int ty = y - 1;
            int by = y + 1;

            if (ty < 0) ty = MAP_HEIGHT - 1;
            if (by > MAP_HEIGHT - 1) by = 0;
            if (lx < 0) lx = MAP_WIDTH - 1;
            if (rx > MAP_WIDTH - 1) rx = 0;

            if (buffer1[lx][ty] == 0) neighbors++;
            if (buffer1[x][ty] == 0) neighbors++;
            if (buffer1[rx][ty] == 0) neighbors++;

            if (buffer1[lx][y] == 0) neighbors++;
            if (buffer1[x][y] == 0) neighbors++;
            if (buffer1[rx][y] == 0) neighbors++;

            if (buffer1[lx][by] == 0) neighbors++;
            if (buffer1[x][by] == 0) neighbors++;
            if (buffer1[rx][by] == 0) neighbors++;

            if (neighbors == 2) {
                buffer2[x][y] = 0;
            }
            else {
                buffer2[x][y] = 2;
            }
        }
    }
}

void BriansBrain::LateUpdate()
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

void BriansBrain::Cleanup()
{

}

void BriansBrain::Clear() {
    for (unsigned int x = 0; x < MAP_WIDTH; x++)
    {
        for (unsigned int y = 0; y < MAP_HEIGHT; y++)
        {
            buffer1[x][y] = 0;
            buffer2[x][y] = 1;
        }
    }
}