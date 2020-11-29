#ifndef HITBOX_HELPER_H
#define HITBOX_HELPER_H

#include <headers.hpp>

class HitboxHelper
{
    private:
        sf::Sprite& sprite;
        sf::RectangleShape hitbox;
        sf::FloatRect nextPosition;
        float offsetX;
        float offsetY;

    public:
        /**
         * @brief Construct a new Hitbox Helper object
         * 
         * @param sprite Current sprite to have position
         * @param offsetX offset on X for extend hitbox
         * @param offsetY offset on Y for extend hitbox
         * @param width Width of hitbox
         * @param height Height of hitbox
         */
        HitboxHelper(sf::Sprite& sprite, float offsetX, float offsetY, float width, float height);
        virtual ~HitboxHelper();

        /**
         * @brief Get the hitbox position
         * 
         * @return const sf::Vector2f& 
         */
        const sf::Vector2f& getPosition() const;

        /**
         * @brief Get the the hitbox Global Bounds object
         * 
         * @return const sf::FloatRect 
         */
        const sf::FloatRect getGlobalBounds() const;

        /**
         * @brief Get the next position with velocity (for walls, etc)
         * 
         * @param velocity Velocity of the object
         * @return const sf::FloatRect& 
         */
        const sf::FloatRect& getNextPosition(const sf::Vector2f& velocity);

        /**
         * @brief Set the position of hitbox (& the sprite)
         * 
         * @param position New position
         */
        void setPosition(const sf::Vector2f& position);

        /**
         * @brief Set the position of hitbox (& the sprite)
         * 
         * @param x
         * @param y 
         */
        void setPosition(const float x, const float y);

        /**
         * @brief Detect collision with fRect
         * 
         * @param fRect The entity to detect collision with
         * @return true if this intersect with fRect
         * @return false if this doesn't intersect with fRect
         */
        bool isIntersect(const sf::FloatRect& fRect);
        
        /**
         * @brief Misspelled testIntersect (to test if collision works)
         * 
         */
        void textIntersect();

        /**
         * @brief Update hitbox
         * 
         */
        void update();

        /**
         * @brief Render the hitbox
         * 
         * @param target the window
         */
        void render(sf::RenderTarget* target);
};

#endif