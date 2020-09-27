#include "Player.hpp"

Player::Player() {
    this->shape.setSize(sf::Vector2f(50.0f, 90.0f));
    this->movementSpeed = 100.0f;

}

Player::~Player() {

}

void Player::move(const float& dt, const float east, const float north)
{
    this->shape.move(east * this->movementSpeed * dt, north * this->movementSpeed * dt);
}

void Player::update(const float& dt)
{
    
}

void Player::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
}