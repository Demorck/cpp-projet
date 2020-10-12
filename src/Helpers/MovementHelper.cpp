#include <Helpers/MovementHelper.hpp>

MovementHelper::MovementHelper(float maxVelocity, float minVelocity)
{
    this->maxVelocity = maxVelocity;
    this->minVelocity = minVelocity;
}

MovementHelper::~MovementHelper()
{

}

const sf::Vector2f& MovementHelper::getVelocity() const
{
    return this->velocity;
}

void MovementHelper::move(const float directionX, const float directionY)
{
    this->velocity.x = this->maxVelocity * directionX;
    this->velocity.y = this->maxVelocity * directionY;
}

void MovementHelper::update(const float &dt)
{

}

