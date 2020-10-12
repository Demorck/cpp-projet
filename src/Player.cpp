#include "Player.hpp"

Player::Player(float x, float y, sf::Texture& textureSheet) {
    // this->shape.setSize(sf::Vector2f(50.0f, 90.0f));
    this->movementHelper = NULL;

    this->createSprite(textureSheet);
    this->setPosition(x, y);

    this->createMovementHelper(20.0f, -20.0f);
    this->createAnimationHelper(textureSheet);
    this->animationHelper->addAnimation("WALK_LEFT", 1.f, 0, 0, 11, 0, 84, 120);

}

Player::~Player()
{
    delete this->animationHelper;
    delete this->movementHelper;
}

void Player::createSprite(sf::Texture& texture)
{
    this->texture = texture;
    this->sprite.setTexture(this->texture);
    // this->sprite->setColor(sf::Color(255, 255, 255));
}

void Player::createAnimationHelper(sf::Texture& textureSheet)
{
    this->animationHelper = new AnimationHelper(this->sprite, textureSheet);
}

void Player::createMovementHelper(const float maxVelocity, const float minVelocity)
{
    this->movementHelper = new MovementHelper(maxVelocity, minVelocity);
}

void Player::setPosition(const float x, const float y)
{
        this->sprite.setPosition(x, y);
}

void Player::move(const float& dt, const float directionX, const float directionY)
{
    // if (directionX < 0)
    //     this->sprite.setTextureRect(sf::IntRect(this->sprite.getTexture()->getSize().x, 0, -this->sprite.getTexture()->getSize().x, this->sprite.getTexture()->getSize().y));

    // if (directionX > 0)
    //     this->sprite.setTextureRect(sf::IntRect(0, 0, this->sprite.getTexture()->getSize().x, this->sprite.getTexture()->getSize().y));

    // this->sprite.move(directionX * 10.f * dt, directionY * 10.f * dt);

    if (this->movementHelper)
    {
        this->movementHelper->move(directionX, directionY);
        this->sprite.move(this->movementHelper->getVelocity() * dt);
    }
    
}

void Player::update(const float& dt)
{
    this->animationHelper->play("WALK_LEFT", dt);
}

void Player::render(sf::RenderTarget* target)
{
    target->draw(this->sprite);
}