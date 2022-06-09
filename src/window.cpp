#include "../headers/window.hpp"

Window::Window(int w, int h, std::string window_name)
{
    window.create(sf::VideoMode(w, h), window_name);
}

void Window::readjust(sf::Vector2u size, std::string window_name)
{
    sf::View window_size(sf::Vector2f(size.x/2.f, size.y/2.f), sf::Vector2f(size));
    window.clear();
    window.setSize(size);
    window.setView(window_size);
    window.setTitle(window_name);
}

void Window::clear()
{
    window.clear();
}

void Window::display()
{
    window.display();
}

sf::RenderWindow& Window::returnHandle()
{
    return window;
}