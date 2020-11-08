#include <UI/Button.hpp>

Button::Button(float x, float y, float width, float height,
                std::string text, sf::Font* font,
                sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
    this->state = BTN_IDLE;

    this->shape.setPosition(sf::Vector2f(x, y));
    this->shape.setSize(sf::Vector2f(width, height));
    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(15);
    this->text.setPosition(
        (this->shape.getPosition().x + this->shape.getGlobalBounds().width/2.f - this->text.getGlobalBounds().width/2.f), 
        (this->shape.getPosition().y + this->shape.getGlobalBounds().height/2.f - this->text.getGlobalBounds().height/2.f)
    );

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;

    this->shape.setFillColor(this->idleColor);

}

Button::~Button()
{
    delete this->font;
}

sf::RectangleShape Button::sh()
{
    return this->shape;
}

bool Button::isHovered() const
{
    return this->state == BTN_HOVER;
}

bool Button::isPressed() const
{
    return this->state == BTN_PRESSED;
}

void Button::update(const sf::Vector2f mousePosition)
{
    this->state = BTN_IDLE;
    

    if (this->shape.getGlobalBounds().contains(mousePosition))
    {
        
        this->state = BTN_HOVER;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            
            this->state = BTN_PRESSED;
        }
    } 

    switch (this->state)
    {
    case BTN_IDLE:
    default:
        this->shape.setFillColor(this->idleColor);
        break;
    case BTN_HOVER:
        this->shape.setFillColor(this->hoverColor);
        break;
    case BTN_PRESSED:
        this->shape.setFillColor(this->activeColor);
        break;
    }
}

void Button::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
    target->draw(this->text);
}