#include <Helpers/AnimationHelper.hpp>

AnimationHelper::AnimationHelper(sf::Sprite& sprite, sf::Texture& textureSheet)
    :sprite(sprite), textureSheet(textureSheet)
{

}

AnimationHelper::~AnimationHelper()
{
    for (auto &i : this->animation)
    {
        delete i.second;
    }
}

void AnimationHelper::addAnimation(const std::string key, float speedAnimation, int startFrameX, int startFrameY, int endFrameX, int endFrameY, int width, int height)
{
    this->animation[key] = new Animation(this->sprite, this->textureSheet, speedAnimation, startFrameX, startFrameY, endFrameX, endFrameY, width, height);
}

void AnimationHelper::play(const std::string key, const float& dt)
{
    this->animation[key]->play(dt);
}
