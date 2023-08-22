#include "LangtonsAnt.h"

LangtonsAnt::LangtonsAnt()
{
    Init();
}

void LangtonsAnt::Init()
{
    int NUM_ANTS = 50;

    for (int x = 0; x < MAP_WIDTH; x++)
    {
        for (int y = 0; y < MAP_HEIGHT; y++)
        {
            buffer[x][y] = sf::Color::Black;
        }
    }

    for (int n = 0; n < NUM_ANTS; n++)
    {
        int rx = rand() % MAP_WIDTH;
        int ry = rand() % MAP_HEIGHT;
        Ant ant;
        ant.setLocation(rx, ry);
        ants.push_back(ant);
    }
}

void LangtonsAnt::Render(sf::RenderWindow& window)
{
    // draw world state
    for (int x = 0; x < MAP_WIDTH; x++)
    {
        for (int y = 0; y < MAP_HEIGHT; y++)
        {
            sf::RectangleShape pixel(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            pixel.setPosition(sf::Vector2f(x * CELL_SIZE, y * CELL_SIZE));
            pixel.setFillColor(buffer[x][y]);
            window.draw(pixel);
        }
    }

}

void LangtonsAnt::Update()
{
    // update world state
    for (auto& ant : ants)
    {
        ant.update(buffer);
    }
}

void LangtonsAnt::LateUpdate()
{
    
}

void LangtonsAnt::Cleanup()
{

}

void LangtonsAnt::Clear() {
    
}