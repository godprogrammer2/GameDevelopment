#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include<string>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
using namespace std;
class GameEngine
{
    public:
        sf::Event m_event;
        sf::RenderWindow m_window;
        GameEngine(int,int,string,unsigned int);
        virtual ~GameEngine();
        int run();
        int close();
        bool isRunning();
    protected:

    private:
        int m_width;
        int m_height;
        string m_title;
        bool m_running;
        unsigned int m_style;
};

#endif // GAMEENGINE_H
