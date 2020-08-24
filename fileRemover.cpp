#include <iostream>
#include <filesystem>

int main(int argc, char** args){
    if(argc == 1){
        std::cout << "You have to enter a file.\n";
        exit(0);
    }
    for(int i = 1; i < argc;i++){
        if(std::filesystem::is_directory(args[i])){
            try{
                std::filesystem::remove_all(args[i]);
                std::filesystem::remove(args[i]);
                std::cout << "Succesfully deleted directory: " << args[i] << std::endl;
            }catch(...){
                std::cout << "Couldn't delete directory: " << args[i] << std::endl;
            }
        }else{
            try{
                std::filesystem::remove(args[i]);
                std::cout << "Succesfully deleted file: " << args[i] << std::endl;
            }catch(...){
                std::cout << "Couldn't delete file " << args[i] << std::endl;
            }
        }
    }
}