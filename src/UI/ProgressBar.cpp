#include <UI/ProgressBar.hpp>

ProgressBar::ProgressBar(float x, float y, float width, float height, sf::Color innerColor, sf::Font* font)
{
    this->maxWidth = width;

    this->back.setSize(sf::Vector2f(width, height));
    this->back.setFillColor(sf::Color(50, 50, 50, 50));
    this->back.setPosition(x, y);

    this->inner.setSize(sf::Vector2f(width, height));
    this->inner.setFillColor(innerColor);
    this->inner.setPosition(this->back.getPosition());

    if (font)
    {
        this->text.setFont(*font);
        this->text.setCharacterSize(15);
        this->text.setPosition
        (
            this->inner.getPosition().x,
            this->inner.getPosition().y
        );
    }
    
}

ProgressBar::~ProgressBar()
{

}

void ProgressBar::update(const int currentValue, const int maxValue)
{
    float currentPercent = static_cast<float>(currentValue) / static_cast<float>(maxValue);

    this->inner.setSize
    (
        sf::Vector2f
        (
            static_cast<float>(std::floor(maxValue * currentPercent)),
            this->inner.getSize().y
        )
    );

    this->barString = std::to_string(currentValue) + " / " + std::to_string(maxValue);
    this->text.setString(this->barString);
}

void ProgressBar::render(sf::RenderTarget* target)
{
    target->draw(this->back);
    target->draw(this->inner);
    target->draw(this->text);
}