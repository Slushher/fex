#include <SFML/Graphics.hpp>
#include <iostream>

class Image: public sf::Drawable{
    sf::Texture image_texture;
    sf::Sprite image_sprite;
    int image_w = 800;
    int image_h = 600;
    float sprite_scale = 1.f;
public:
    Image();
    sf::Vector2u returnSize();
    sf::Sprite returnSprite();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void scale(float delta);
    void readjust();
    bool loadImage(std::string file_path);
};