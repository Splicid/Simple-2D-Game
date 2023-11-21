#include <iostream>
#include <SFML/Graphics.hpp>
// Version 0.1


int main()
{
    // Window Size 
    sf::RenderWindow window(sf::VideoMode(900, 700), "Box World");
    sf::RectangleShape rectangle;

    // Setting the size and origin of the rectangle
    rectangle.setSize(sf::Vector2f(100.0f, 100.0f));
    rectangle.setOrigin(sf::Vector2f(50.0f, 50.0f));

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


        std::cout << pos.x << "," << pos.y << " " << window.getSize().y << " " << curPos.x << std::endl;
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


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        {
            //Gun Switch
         
        }
        window.clear();
        window.draw(rectangle);
        window.display();
    }

    return 0;
}

