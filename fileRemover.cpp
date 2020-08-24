#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

bool fileRemover(fs::directory_entry map) {
    if(!map.is_directory()){
        return fs::remove(map);
    }
	try {
		for (const fs::directory_entry& entry : fs::directory_iterator(map)) {
			if (!entry.is_directory()) {
                fs::remove(entry);
			}else{
                if(map != entry){
                    fileRemover(entry);
                }
            }
		}
	}
	catch (...) {
		std::cout << "Couldn't find: " << fs::path(map) << "\n" << std::endl;
		return false;
	}
	return fs::remove(map);
}

int main(int argc, char** args){
    if(argc == 1){
        std::cout << "You have to enter a file.\n";
        exit(0);
    }
    for(int i = 1;i < argc;i++){
        clock_t start = clock();
        if(fileRemover(fs::directory_entry(args[i]))){
            std::cout << "Succesfully deleted " << args[i] << std::endl;
        }else{
            std::cout << "Couldn't delete " << args[i] << std::endl;
        }
    }
}