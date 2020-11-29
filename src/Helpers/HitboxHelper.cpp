#include <Helpers/HitboxHelper.hpp>

HitboxHelper::HitboxHelper(sf::Sprite& sprite, float offsetX, float offsetY, float width, float height)
    : sprite(sprite), offsetX(offsetX), offsetY(offsetY)
{
    this->nextPosition.left = 0.f;
	this->nextPosition.top = 0.f;
	this->nextPosition.width = width;
	this->nextPosition.height = height;

	this->hitbox.setPosition(this->sprite.getPosition().x + offsetX, this->sprite.getPosition().y + offsetY);
	this->hitbox.setSize(sf::Vector2f(width, height));
	this->hitbox.setFillColor(sf::Color::Transparent);

	this->hitbox.setOutlineThickness(-1.f);
	this->hitbox.setOutlineColor(sf::Color::Green);
}

HitboxHelper::~HitboxHelper()
{

}

const sf::Vector2f& HitboxHelper::getPosition() const
{
    return this->hitbox.getPosition();
}

const sf::FloatRect HitboxHelper::getGlobalBounds() const
{
    return this->hitbox.getGlobalBounds();
}

const sf::FloatRect& HitboxHelper::getNextPosition(const sf::Vector2f& velocity)
{
    this->nextPosition.left = this->hitbox.getPosition().x + velocity.x;
    this->nextPosition.top = this->hitbox.getPosition().y + velocity.y;

	return this->nextPosition;
}

void HitboxHelper::setPosition(const sf::Vector2f& position)
{
    this->hitbox.setPosition(position);
	this->sprite.setPosition(position.x - this->offsetX, position.y - this->offsetY);
}

void HitboxHelper::setPosition(const float x, const float y)
{
    this->hitbox.setPosition(x, y);
	this->sprite.setPosition(x - this->offsetX, y - this->offsetY);
}


bool HitboxHelper::isIntersect(const sf::FloatRect& fRect)
{
    return this->hitbox.getGlobalBounds().intersects(fRect);
}

void HitboxHelper::textIntersect()
{
    this->hitbox.setOutlineThickness(-2.f);
	this->hitbox.setOutlineColor(sf::Color::Red);
}

void HitboxHelper::update()
{
    this->hitbox.setPosition(this->sprite.getPosition().x + this->offsetX, this->sprite.getPosition().y + this->offsetY);
    
    this->hitbox.setOutlineThickness(-1.f);
	this->hitbox.setOutlineColor(sf::Color::Green);
}

void HitboxHelper::render(sf::RenderTarget* target)
{
    target->draw(this->hitbox);
}
