#include <Helpers/AnimationHelper.hpp>

AnimationHelper::AnimationHelper(sf::Sprite& sprite, sf::Texture& textureSheet)
    :sprite(sprite), textureSheet(textureSheet), lastAnimation(NULL), priorityAnimation(NULL)
{

}

AnimationHelper::~AnimationHelper()
{
    for (auto &i : this->animations)
    {
        delete i.second;
    }
}

void AnimationHelper::addAnimation(const std::string key, float speedAnimation, int startFrameX, int startFrameY, int endFrameX, int endFrameY, int width, int height)
{
    this->animations[key] = new Animation(this->sprite, this->textureSheet, speedAnimation, startFrameX, startFrameY, endFrameX, endFrameY, width, height);
}

const bool& AnimationHelper::play(const std::string key, const float& dt, const bool priority)
{
    // this->animation[key]->play(dt);

    if (this->priorityAnimation)
    {
        if (this->priorityAnimation == this->animations[key])
        {
            if (this->lastAnimation != this->animations[key])
            {
                if (this->lastAnimation == NULL)
                {
                    this->lastAnimation = this->animations[key];
                }
                else
                {
                    this->lastAnimation->reset();
                    this->lastAnimation = this->animations[key];
                }
            }

            if (this->animations[key]->play(dt))
            {
                this->priorityAnimation = NULL;
            }
        }   
    }
    else
    {
        if (priority)
        {
            this->priorityAnimation = this->animations[key];
        }

        if (this->lastAnimation != this->animations[key])
        {
            if (this->lastAnimation == NULL)
            {
                this->lastAnimation = this->animations[key];
            }
            else
            {
                this->lastAnimation->reset();
                this->lastAnimation = this->animations[key];
            }
        }

        this->animations[key]->play(dt);
        
    }
    
    return this->animations[key]->isDone();
    
}
