#include "../headers/image.hpp"

Image::Image() = default;

bool Image::loadImage(std::string file_path)
{
    if(file_path!=""){
        this->image_texture = sf::Texture();
        this->image_texture.loadFromFile(file_path);
        this->image_w = this->image_texture.getSize().x;
        this->image_h = this->image_texture.getSize().y;
        return true;
    }
    std::cout<<"failed to load image\n";
    return false;
}

void Image::readjust()
{
    this->sprite_scale = 1.f;
    this->image_sprite = sf::Sprite();
    this->image_sprite.setTexture(this->image_texture, true);
    this->image_sprite.setOrigin(this->image_w/2, this->image_h/2);
    this->image_sprite.setPosition(this->image_w/2, this->image_h/2);
}

sf::Vector2u Image::returnSize()
{
    return sf::Vector2u(this->image_w, this->image_h);
}

void Image::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->image_sprite, states);
}

sf::Sprite Image::returnSprite()
{
    return this->image_sprite;
}

void Image::scale(float delta)
{
    if(this->sprite_scale>0.1 && delta<0.f){this->sprite_scale+=delta;}
    else if(this->sprite_scale<5.f && delta>0.f){this->sprite_scale+=delta;}
    this->image_sprite.setScale(this->sprite_scale, this->sprite_scale);
}