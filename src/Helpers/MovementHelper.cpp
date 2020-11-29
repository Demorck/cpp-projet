#include <Helpers/MovementHelper.hpp>

MovementHelper::MovementHelper(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration)
    : sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration)
{
    this->minVelocity = -maxVelocity;
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

    if(this->velocity.x > this->maxVelocity)
        this->velocity.x = this->maxVelocity;
    if(this->velocity.x < this->minVelocity)
        this->velocity.x = this->minVelocity;
    

    this->velocity.y = this->maxVelocity * directionY;

    if(this->velocity.y > this->maxVelocity)
        this->velocity.y = this->maxVelocity;
    if(this->velocity.y < this->minVelocity)
        this->velocity.y = this->minVelocity;
}

void MovementHelper::update(const float &dt)
{
    if (this->velocity.x > 0.f)
	{
		if (this->velocity.x > this->maxVelocity)
			this->velocity.x = this->maxVelocity;

		this->velocity.x -= deceleration * dt;
		if (this->velocity.x < 0.f)
			this->velocity.x = 0.f;
	}
	else if(this->velocity.x < 0.f)
	{
		if (this->velocity.x < -this->maxVelocity)
			this->velocity.x = -this->maxVelocity;

		this->velocity.x += deceleration * dt;
		if (this->velocity.x > 0.f)
			this->velocity.x = 0.f;
	}
	
	if (this->velocity.y > 0.f)
	{
		if (this->velocity.y > this->maxVelocity)
			this->velocity.y = this->maxVelocity;

		this->velocity.y -= deceleration * dt;
		if (this->velocity.y < 0.f)
			this->velocity.y = 0.f;
	}
	else if (this->velocity.y < 0.f)
	{
		if (this->velocity.y < -this->maxVelocity)
			this->velocity.y = -this->maxVelocity;

		this->velocity.y += deceleration * dt;
		if (this->velocity.y > 0.f)
			this->velocity.y = 0.f;
	}


    this->sprite.move(this->velocity * dt);
}

