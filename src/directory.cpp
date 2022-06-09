#include "../headers/directory.hpp"

Directory::Directory() = default;

bool Directory::directoryExists(std::string p, fs::file_status s)
{
    const fs::path& path = p;
    if(fs::status_known(s) ? fs::exists(s) : fs::exists(path))
        return true;
    else{
        std::cout << p << " does not exist!\n";
        std::cout << "falling back\n";
        return false;
    }
}

bool Directory::loadDir(std::string dir)
{
    if(directoryExists(dir)){
        for (const auto & entry : fs::directory_iterator(dir))
        {
            std::string buf = entry.path();
            if(buf.find(".jpg") != std::string::npos || buf.find(".bmp") != std::string::npos || buf.find(".png") != std::string::npos){
                this->image_name_arr.push_back(buf);
            }
        }
        return true;
    }
    return false;
}

std::string Directory::getimageDir(int n)
{
    if(n<image_name_arr.size()){
        return this->image_name_arr[n];
    }
    return "";
}

int Directory::retImgQuantity()
{
    return this->image_name_arr.size();
}