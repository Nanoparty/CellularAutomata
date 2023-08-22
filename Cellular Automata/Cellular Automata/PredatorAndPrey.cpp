#include "PredatorAndPrey.h"

PredatorAndPrey::PredatorAndPrey()
{
    Init();
}

void PredatorAndPrey::Init()
{
    for (int x = 0; x < MAP_WIDTH; x++)
    {
        for (int y = 0; y < MAP_HEIGHT; y++)
        {
            buffer1[x][y] = new Creature();
        }
    }
}

void PredatorAndPrey::Render(sf::RenderWindow& window)
{
    // draw world state
    for (int x = 0; x < MAP_WIDTH; x++)
    {
        for (int y = 0; y < MAP_HEIGHT; y++)
        {
            sf::RectangleShape pixel(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            pixel.setPosition(sf::Vector2f(x * CELL_SIZE, y * CELL_SIZE));
            pixel.setFillColor(buffer1[x][y]->getColor());
            window.draw(pixel);

        }
    }

}

void PredatorAndPrey::Update()
{
    for (int x = 0; x < MAP_WIDTH; x++)
    {
        for (int y = 0; y < MAP_HEIGHT; y++)
        {
            Creature* thisCreature = buffer1[x][y];

            CreatureType thisType = thisCreature->getType();

            if (thisType == CreatureType::Nothing)
                continue;

            int dx = rand() % 3 - 1;
            int dy = rand() % 3 - 1;

            int newX = x + dx;
            int newY = y + dy;

            if (newX < 0 || newX > MAP_WIDTH - 1) continue;
            if (newY < 0 || newY > MAP_HEIGHT - 1) continue;

            Creature* otherCreature = buffer1[newX][newY];

            thisCreature->update();

            switch (thisType)
            {
            case CreatureType::Predator:
                updatePredator(thisCreature, otherCreature);
                break;
            case CreatureType::Prey:
                updatePrey(thisCreature, otherCreature);
                break;
            default:
                break;
            }
        }
    }
}

void PredatorAndPrey::LateUpdate()
{

}

void PredatorAndPrey::Cleanup()
{

}

void PredatorAndPrey::Clear() {

}

void PredatorAndPrey::updatePredator(Creature* thisCreature, Creature* otherCreature)
{
    if (thisCreature->getHealth() <= 0) {
        thisCreature->setType(CreatureType::Nothing);
        return;
    }

    CreatureType otherType = otherCreature->getType();

    if (otherType == CreatureType::Prey)
    {
        otherCreature->setType(CreatureType::Predator);
        thisCreature->heal(otherCreature->getHealth());
    }
    else if (otherType == CreatureType::Nothing)
    {
        otherCreature->setType(CreatureType::Predator);
        otherCreature->setHealth(thisCreature->getHealth());
        thisCreature->setType(CreatureType::Nothing);
    }
}

void PredatorAndPrey::updatePrey(Creature* thisCreature, Creature* otherCreature)
{
    CreatureType otherType = otherCreature->getType();

    bool reproduce = false;
    if (thisCreature->getHealth() >= Creature::MAX_HEALTH) {
        thisCreature->setHealth(10);
        reproduce = true;
    }

    if (otherType == CreatureType::Nothing)
    {
        if (reproduce)
        {
            otherCreature->setType(CreatureType::Prey);
            otherCreature->setHealth(10);
        }
        else
        {
            otherCreature->setType(CreatureType::Prey);
            otherCreature->setHealth(thisCreature->getHealth());
            thisCreature->setType(CreatureType::Nothing);
        }
    }
}