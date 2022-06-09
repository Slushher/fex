#include <SFML/Graphics.hpp>
#include <string>

class Window{
    sf::RenderWindow window;
public:
    Window(int w = 800, int h = 600, std::string window_name = "Window");
    void clear();
    void display();
    sf::RenderWindow& returnHandle();
    void update();
    void readjust(sf::Vector2u size, std::string window_name);
};