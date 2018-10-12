#include "Animation.h"
using namespace sf;
Animation::Animation(Texture *texture,Vector2u countImage,float switchTime)
{
    //ctor
    imageCount = countImage;
    uvRect.width = texture->getSize().x/countImage.x;
    uvRect.height = texture->getSize().y/countImage.y;
    currentImage.x = 0;
    currentImage.y = 0;
    totalTime = 0;
}

Animation::~Animation()
{
    //dtor
}

void Animation::update(int rowImage,float deltaTime)
{
    currentImage.y = rowImage;
    totalTime+=deltaTime;
    if(totalTime >= switchTime)
    {
        currentImage.x++;
        if(currentImage.x>= imageCount.x)
        {
            currentImage.x = 0;
        }
        totalTime-= switchTime;
    }
    uvRect.left = currentImage.y*uvRect.height;
    uvRect.top = currentImage.x*uvRect.width;
}
