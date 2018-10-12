#ifndef ANIMATION_H
#define ANIMATION_H
#include<SFML/Graphics.hpp>
using namespace sf;
class Animation
{
    public:
        Animation(Texture *texture,Vector2u countImage,float switchTime);
        virtual ~Animation();
        void update(int rowImage,float deltaTime);
    public:
        IntRect uvRect;
    protected:

    private:
        float switchTime;
        float totalTime;
        Vector2u currentImage;
        Vector2u imageCount;
};

#endif // ANIMATION_H
