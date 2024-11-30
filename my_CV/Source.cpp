#include <SFML/Graphics.hpp>

using namespace sf; 
int main()
{
    int wallSize = 25; 
    int map[] = {1,1,1,1,1,1,
                 1,0,0,0,0,1,
                 1,0,0,0,0,1,
                 1,0,0,0,0,1,
                 1,1,1,1,1,1};

    
    float dX = 0;
    float dY = 0;
    int wight = 640;
    int height = 480;
    RenderWindow window(sf::VideoMode(wight, height), "Olya's CV");
    CircleShape shape(25.f);
    shape.setPosition(wight / 2, height / 2);
    //shape.setOrigin(320, 240);
    shape.setFillColor(sf::Color::Green);
    
    CircleShape eye(50, 3);
    eye.setOrigin(shape.getOrigin() + Vector2f(50,10));
    eye.setPosition(shape.getPosition());
    eye.setScale(1, 2);
    while (window.isOpen())
    {
        Vector2i pixelPos = Mouse::getPosition(window);
        Vector2f pos = window.mapPixelToCoords(pixelPos);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        float dX = pos.x - eye.getPosition().x;
        float dY = pos.y - eye.getPosition().y;
        float rotation = (atan2(dY, dX)) * 180 / 3.14159265;
        eye.setRotation(rotation);
        if (Keyboard::isKeyPressed(Keyboard::Left)) { shape.move(-0.1, 0); eye.move(-0.1, 0);}
        if (Keyboard::isKeyPressed(Keyboard::Right)) { shape.move(+0.1, 0); eye.move(+0.1, 0);}
        if (Keyboard::isKeyPressed(Keyboard::Up)) { shape.move(0, -0.1); eye.move(0, -0.1);}
        if (Keyboard::isKeyPressed(Keyboard::Down)) { shape.move(0, +0.1); eye.move(0, +0.1); }
        window.clear();
        window.draw(shape);
        window.draw(eye);
        window.display();
    }

    return 0;
} 