#include <string>
#include <iostream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

class Directory{
    std::vector<std::string> image_name_arr;
public:
    Directory();
    bool loadDir(std::string dir = ".");
    std::string getimageDir(int n);
    bool directoryExists(std::string p, fs::file_status s = fs::file_status{});
    int retImgQuantity();
};