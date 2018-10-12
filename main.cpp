#include <SFML/Graphics.hpp>
#include<iostream>
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(400,400),"Animation");
    window.setVerticalSyncEnabled(true);
    RectangleShape animation(Vector2f(100,100));
    animation.setPosition(Vector2f(100,100));
    Texture texture;
    texture.setRepeated(true);
    texture.setSmooth(true);
    texture.loadFromFile("explosion1.png");
    animation.setTexture(&texture);
    Event event;
    Clock clock;
    float totalTime = 0,switchTime = 0.3;
    Vector2u currentBox(0,2);
    IntRect boxRec;
    boxRec.width = texture.getSize().x/10;
    boxRec.height = texture.getSize().y/5;
    boxRec.left = currentBox.x;
    boxRec.top = currentBox.y*boxRec.height;
    while(window.isOpen())
    {
        totalTime += clock.restart().asSeconds();
        if(totalTime >= switchTime)
        {
            currentBox.x++;
            if(currentBox.x >= 10)
            {
                currentBox.x = 0;
            }
            boxRec.left = currentBox.x*boxRec.width;
            totalTime -= switchTime;
        }
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
            {
                window.close();
            }

        }
        animation.setTextureRect(boxRec);
        window.clear();
        window.draw(animation);
        window.display();
    }
    return 0;
}
