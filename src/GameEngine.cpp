#include "GameEngine.h"

GameEngine::GameEngine(int width,int height,string title,unsigned int style)
{
    //ctor
    m_width = width;
    m_height = height;
    m_title = title;
    m_running = false;
    m_style = style;
}
GameEngine::~GameEngine()
{
    //dtor
}

int GameEngine::run(){
    m_window.create(sf::VideoMode(m_width,m_height),m_title,m_style);
    m_running = true;
    return 0;
}

int GameEngine::close(){
    m_running = false;
    return 0;
}

bool GameEngine::isRunning(){
    return m_running;
}

