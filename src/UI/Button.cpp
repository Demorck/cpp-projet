#include <UI/Button.hpp>

Button::Button(float x, float y, float width, float height,
                std::string text, sf::Font* font,
                sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
    this->type = BTN_TEXT;
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

Button::Button(float x, float y, float width, float height,
                sf::Texture buttonTexture, sf::Texture buttonTextureHover)
{
    this->type = BTN_IMG;
    this->state = BTN_IDLE;

    this->shape.setPosition(sf::Vector2f(x, y));
    this->shape.setSize(sf::Vector2f(width, height));

    this->textureShape = buttonTexture;
    this->textureShapeHover = buttonTextureHover;
    this->shape.setTexture(&this->textureShape, true);

}

Button::~Button()
{
    if (this->type == BTN_TEXT)
        delete this->font;
    
}

bool Button::isHovered() const
{
    return this->state == BTN_HOVER;
}

bool Button::isPressed() const
{
    return this->state == BTN_ACTIVE;
}

void Button::update(const sf::Vector2f mousePosition)
{
    this->state = BTN_IDLE;
    

    if (this->shape.getGlobalBounds().contains(mousePosition))
    {
        
        this->state = BTN_HOVER;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            
            this->state = BTN_ACTIVE;
        }
    } 

    if (this->type == BTN_TEXT)
    {
        switch (this->state)
        {
        case BTN_IDLE:
            this->shape.setFillColor(this->idleColor);
            break;
        case BTN_HOVER:
            this->shape.setFillColor(this->hoverColor);
            break;
        case BTN_ACTIVE:
            this->shape.setFillColor(this->activeColor);
            break;
        default:
            this->shape.setFillColor(sf::Color::Red);
            break;
        }
    }
    else
    {
        switch (this->state)
        {
        case BTN_IDLE:
            this->shape.setTexture(&this->textureShape);
            break;
        case BTN_HOVER:
            this->shape.setTexture(&this->textureShapeHover);
            break;
        case BTN_ACTIVE:
            this->shape.setFillColor(this->activeColor);
            break;
        default:
            this->shape.setFillColor(sf::Color::Red);
            break;
        }
    }
    
    
}

void Button::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
    target->draw(this->text);
}