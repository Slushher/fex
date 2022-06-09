#include "../headers/window.hpp"
#include "../headers/image.hpp"
#include "../headers/controls.hpp"
#include "../headers/directory.hpp"

std::string dir_path = "./";
std::string image_name = "";
int nth_image = 1;

std::string title(int n1)
{
    return "fex : " + image_name + " " + std::to_string(nth_image) + " of " + std::to_string(n1);
}

int main(int argc, char* argv[])
{

    Directory dir;
    sf::View view;

    if(argc<2)
    {
        dir_path = ".";
        dir.loadDir(dir_path);
        if(dir.retImgQuantity()!=0){
            image_name = dir.getimageDir(0);
        }
    }
    else
    {
        dir_path = ".";
        if(dir.directoryExists(argv[1])){
            dir_path = (std::string)argv[1];
        }
            if(dir_path.find(".jpg") != std::string::npos || dir_path.find(".bmp") != std::string::npos || dir_path.find(".png") != std::string::npos){
                image_name = dir_path;
            }
            else{
                dir.loadDir(dir_path);
                if(dir.retImgQuantity()!=0){
                    image_name = dir.getimageDir(0);
                }
            }
    }

    Image image;
    image.loadImage(image_name);
    image.readjust();
    Window w1(image.returnSize().x,image.returnSize().y, title(dir.retImgQuantity()));

    while (w1.returnHandle().isOpen())
    {
        sf::Event event;
        while (w1.returnHandle().pollEvent(event))
        {
            if(event.type == sf::Event::KeyPressed){
                float delta = 0.f;
                if(handleKeyboard(event, delta, nth_image, dir.retImgQuantity()))
                {
                    image_name = dir.getimageDir(nth_image-1);
                    image.loadImage(dir.getimageDir(nth_image-1));
                    w1.readjust(image.returnSize(), title(dir.retImgQuantity()));
                    image.readjust();
                }
                else{
                    image.scale(delta);
                }
            }
            if (event.type == sf::Event::Closed)
                w1.returnHandle().close();
        }

        w1.clear();
        w1.returnHandle().draw(image.returnSprite());
        w1.display();
    }

    return 0;
}