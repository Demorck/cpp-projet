#ifndef ANIMATION_HELPER_H
#define ANIMATION_HELPER_H

#include <Helpers/MovementHelper.hpp>
#include <iostream>

class AnimationHelper {
    private:
        // Animation class
        class Animation
        {
            private:
                // Variables
                sf::IntRect startRect; // First rectangle to save for looping animation 
                sf::IntRect currentRect; // Current rectangle 
                sf::IntRect endRect; // Last rectangle to save for testing if we need to start over

                sf::Sprite& sprite;
                sf::Texture& textureSheet;

                float speedAnimation;
                float timer;

                int width; // width of 1 frame
                int height; // height of 1 frame
                bool done; // if anim is done 

            public:
                /**
                 * @brief Construct a new Animation object
                 * 
                 * @param sprite Current sprite for object
                 * @param textureSheet textureSheet to cut with rectangles
                 * @param speedAnimation animation speed
                 * @param startFrameX first frame in x 
                 * @param startFrameY first frame in y
                 * @param endFrameX last frame in x (Number of frame horizontally - 1)
                 * @param endFrameY last frame in y (Number of frame vertically - 1)
                 * @param width width of 1 frame
                 * @param height height of 1 frame
                 */
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

                /**
                 * @brief Destroy the Animation object
                 * 
                 */
                virtual ~Animation(){}

                /**
                 * @brief Play the current animation (only horizontally at the time)
                 * 
                 * @param dt delta time
                 */
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

                /**
                 * @brief Check if the animation is done (not used yet)
                 * 
                 * @return true if it's done
                 * @return false otherwise
                 */
                const bool& isDone() const
                {
                    return this->done;
                }

                /**
                 * @brief Pause animation (not used yet)
                 * 
                 */
                void pause(){}

                /**
                 * @brief Reset the current Animation
                 * 
                 */
                void reset()
                {
                    this->currentRect = this->startRect;
                    this->timer = 0.f;
                }
        };

        sf::Sprite& sprite;
        sf::Texture& textureSheet;
        std::map<std::string, Animation*> animation;

    public:
        /**
         * @brief Construct a new Animation Helper object
         * 
         * @param sprite object's sprite
         * @param textureSheet textureSheet to anim
         */
        AnimationHelper(sf::Sprite& sprite, sf::Texture& textureSheet);

        /**
         * @brief Destroy the Animation Helper object & all animations
         * 
         */
        virtual ~AnimationHelper();

        /**
         * @brief add an animation with key string
         * 
         * @param key the name of animation
         * @param speedAnimation the speed of animation
         * @param startFrameX first frame in x 
         * @param startFrameY first frame in y
         * @param endFrameX last frame in x (Number of frame horizontally - 1)
         * @param endFrameY last frame in y (Number of frame vertically - 1)
         * @param width width of 1 frame
         * @param height height of 1 frame
         */
        void addAnimation(const std::string key, float speedAnimation, int startFrameX, int startFrameY, int endFrameX, int endFrameY, int width, int height);

        /**
         * @brief Check if the current animation is done
         * 
         * @return true if it's done
         * @return false otherwise
         */
        bool& isDone();

        /**
         * @brief Play an animation
         * 
         * @param key the name of animation to play
         * @param dt delta time
         */
        void play(const std::string key, const float& dt);
};

#endif