#include "Main.h"
#include <malloc.h>


int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), SCREEN_TITLE);

    font.loadFromFile("Roboto-Regular.ttf");

    bool running = false;
    bool mouseHeld = false;

    stateType = GameType::GameOfLife;

    UpdateState();

    initText(gamemodeText, 40);
    initText(controlsText, 60);
    initText(modeText, 80);
    initText(playText, 100);
    initText(resetText, 120);

    controlsText.setString("Controls:");
    modeText.setString("Game Of Life[1], Brian's Brain[2], Langton's Ant[3], Predator And Prey[4], Seeds[5]");
    playText.setString("Play/Pause [Space]");
    resetText.setString("Reset [R]");


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
                running = 1 - running;

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
                running = false;
                UpdateState();
            }
                

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num1) {
                running = false;
                stateType = GameType::GameOfLife;
                UpdateState();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num2) {
                running = false;
                stateType = GameType::BriansBrain;
                UpdateState();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num3) {
                running = false;
                stateType = GameType::LangtonsAnt;
                UpdateState();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num4) {
                running = false;
                stateType = GameType::PredatorAndPrey;
                UpdateState();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num5) {
                running = false;
                stateType = GameType::Seeds;
                UpdateState();
            }

            if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left)
            {
                mouseHeld = true;
                placeCell(event.mouseButton.x, event.mouseButton.y);
            }
            if (event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
            {
                mouseHeld = false;
            }
            if (mouseHeld)
            {
                //placeCell(event.mouseButton.x, event.mouseButton.y, buffer1);
            }
        }

        window.clear();

        activeState->Render(window);

        // update display text
        

        window.draw(gamemodeText);
        window.draw(controlsText);
        window.draw(modeText);
        window.draw(playText);
        window.draw(resetText);

        window.display();

        if (running) {
            activeState->Update();
            activeState->LateUpdate();
        }
    }

    return 0;
}

void UpdateState() {
    if (stateType == GameType::BriansBrain) {
        activeState = new BriansBrain();
        gamemodeText.setString("Current Gamemode: Brian's Brain");
    }
    if (stateType == GameType::GameOfLife) {
        activeState = new GameOfLife();
        gamemodeText.setString("Current Gamemode: Game Of Life");
    }
    if (stateType == GameType::LangtonsAnt) {
        activeState = new LangtonsAnt();
        gamemodeText.setString("Current Gamemode: Langton's Ant");
    }
    if (stateType == GameType::Seeds) {
        activeState = new Seeds();
        gamemodeText.setString("Current Gamemode: Seeds");
    }
    if (stateType == GameType::PredatorAndPrey) {
        activeState = new PredatorAndPrey();
        gamemodeText.setString("Current Gamemode: Predator And Prey");
    }
}

void placeCell(int x, int y)
{
    

    int cell_x = x / CELL_SIZE;
    int cell_y = y / CELL_SIZE;

    if (cell_x < 0 || cell_x > MAP_WIDTH - 1 || cell_y < 0 || cell_y > MAP_HEIGHT - 1)
        return;

    std::cout << "Adding cell " << cell_x << " " << cell_y << "\n";

    static_cast<GameOfLife&>((*activeState)).buffer1[cell_x][cell_y] = 1;
}

void initText(sf::Text& text, float y) {
    text.move(10, y);
    text.setFillColor(sf::Color::White);
    text.setFont(font);
    text.setCharacterSize(18);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2);
}