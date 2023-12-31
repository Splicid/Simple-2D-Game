#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h> 
#include <cmath>
// Version 0.1
// To Do
// Bullet life -- Maybe use time to determine its death?


int main()
{
    // Window Size 
    sf::RenderWindow window(sf::VideoMode(900, 700), "Box World");
    sf::RectangleShape rectangle;

    sf::Clock Clock;

    // Setting the size and origin of the rectangle
    rectangle.setSize(sf::Vector2f(50.0f, 50.0f));
    rectangle.setOrigin(sf::Vector2f(25.0f, 25.0f));
    rectangle.setPosition(450.0f, 350.0f);

    sf::CircleShape circle;
    circle.setFillColor(sf::Color::Red);
    circle.setRadius(30.0f);
    circle.setOrigin(30, 30);
    std::vector<sf::CircleShape> bullets;
    std::vector<float> angles;

    rectangle.setOutlineColor(sf::Color::Red);
    rectangle.setFillColor(sf::Color::Green);

    const float PI = 3.14159265;

    while (window.isOpen())
    {
        window.setFramerateLimit(120);
        sf::Event event;
        sf::Vector2f pos = rectangle.getPosition();

        // Get postion of mouse 
        sf::Vector2i curPos = sf::Mouse::getPosition(window);
        float dx = curPos.x - pos.x;
        float dy = curPos.y - pos.y;
        float rotation = (atan2(dy, dx)) * 180 / PI;

        std::vector<sf::Vector2f>position;

        //std::cout << pos.x << "," << pos.y << " " << window.getSize().y << " " << curPos.x << std::endl;
        rectangle.setRotation(rotation);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        //Player movement 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && pos.x >= 0)
        {
            rectangle.move(-1.0f, 0.0f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && pos.x <= window.getSize().x - 50.0f)
        {
            rectangle.move(1.0f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && pos.y >= 0)
        {
            rectangle.move(0.0f, -1.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && pos.y <= window.getSize().y - 50.0f)
        {
            rectangle.move(0.0f, 1.0f);
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && Clock.getElapsedTime().asSeconds() > 1.0)
        {
            bullets.push_back(sf::CircleShape());
            bullets.back().setRadius(5);
            bullets.back().setOrigin(5, 5);
            bullets.back().setPosition(rectangle.getPosition());
            angles.push_back(atan2(dy, dx));

            Clock.restart();

        }

        window.clear();
        window.draw(rectangle);
        for (int i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);
            bullets[i].move(20*cos(angles[i]),20*sin(angles[i]));
            //std::cout << "Start" << bullets[i].getPosition().x << "End";


        }
        window.display();
    }

    return 0;
}

