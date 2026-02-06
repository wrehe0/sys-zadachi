#include "libHelp.h"
#include <iostream> 
#include <string>
#include <cstdlib>
void getHelp (){
    std::cout << "HEHEHEHEHEHELP \n";
    const char* author_ptr = std::getenv("AUTHOR");
    const char* version_ptr = std::getenv("VERSION");
    std::string author = "";
    std::string version = "";
    if(author_ptr){
        author = author_ptr;
    }else{
        std::cerr << "author not get!";
    }
    if(version_ptr){
        version = version_ptr;
    }else{
        std::cerr << "version not get!";
    }
}