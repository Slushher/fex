#include "../headers/controls.hpp"

bool handleKeyboard(sf::Event &event, float &zoom, int &image_n, int max_imgs)
{
    switch(event.key.code)
    {
        case sf::Keyboard::Subtract:
            zoom=-0.1;
        return false;

        case sf::Keyboard::Add:
            zoom=0.1;
        return false;

        case sf::Keyboard::Left:
            if(image_n>1){image_n--;}
        return true;

        case sf::Keyboard::Right:
            if(image_n<max_imgs){image_n++;}
        return true;
    }
    return false;
}