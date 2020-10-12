#ifndef ANIMATION_HELPER_H
#define ANIMATION_HELPER_H

#include <Helpers/MovementHelper.hpp>
#include <iostream>

class AnimationHelper {
    private:
        class Animation
        {
            private:
                sf::IntRect startRect;
                sf::IntRect currentRect;
                sf::IntRect endRect;
                int width;
                int height;
                bool done;

            public:
                Animation(sf::Sprite& sprite, sf::Texture& textureSheet, float speedAnimation, int startFrameX, int startFrameY, int endFrameX, int endFrameY, int width, int height)
                    : sprite(sprite), textureSheet(textureSheet), speedAnimation(speedAnimation), width(width), height(height) 
                {
                    this->timer = 0.f;
                    this->done = false;
                    this->startRect = sf::IntRect(startFrameX * width, startFrameY * height, width, height);
                    this->currentRect = this->startRect;
                    this->endRect = sf::IntRect(endFrameX * width, endFrameY * height, width, height);
                    this->sprite.setTexture(this->textureSheet, true);
                    this->sprite.setTextureRect(this->startRect);
                }

                virtual ~Animation(){}

                void play(const float& dt)
                {
                    this->timer += 10.f * dt;
                    if (this->timer >= this->speedAnimation)
                    {
                        this->timer = 0.f;

                        if(this->currentRect != this->endRect)
                        {
                            this->currentRect.left += this->width;
                        }
                        else
                        {
                            this->currentRect.left = this->startRect.left;
                            this->done = true;
                        }
                        
                        this->sprite.setTextureRect(this->currentRect);
                    }
                    else
                    {
                        this->done = true;
                    }
                    
                }

                const bool& isDone() const
                {
                    return this->done;
                }

                void pause(){}

                void reset()
                {
                    this->currentRect = this->startRect;
                    this->timer = 0.f;
                }

                sf::Sprite& sprite;
                sf::Texture& textureSheet;
                float speedAnimation;
                float timer;

        };

        sf::Sprite& sprite;
        sf::Texture& textureSheet;
        std::map<std::string, Animation*> animation;

    public:
        AnimationHelper(sf::Sprite& sprite, sf::Texture& textureSheet);
        virtual ~AnimationHelper();

        void addAnimation(const std::string key, float speedAnimation, int startX, int startY, int endX, int endY, int width, int height);
        bool& isDone();
        void play(const std::string key, const float& dt);
        void render();
};

#endif