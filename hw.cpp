#include <iostream> 
#include <string>
#include <cstdlib>
void getHelp();


int main (int argc, char* argv[]){
    if (const char* env_p = std::getenv("PATH")){
    std::cout << "PATH:" << env_p << "\n";
}
bool needHelp=false;
        setlocale(LC_ALL, "RU");
        std::cout << "Длинна массива : " << argc << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::string arg = argv[i];
        std::cout << "Аргумент " << i << ": " << argv[i] << std::endl;
        if(arg == "--help"){
            needHelp = true;
        }
    }
    if (needHelp){
        getHelp();
    }
    return 0;
}
/*void getHelp (){
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
}*/


/*соло на клавиатуре найти потом*/
/*продолжить на ldd ./hw

int main(){
    cout << "Hello World" << "\n";
    cerr << "ERROR" << "\n";
    int a;
    cin >> a;
    return a;
int socks[12];
    for (int i = 0; i < 12; i++){
        socks[i] = i;
    }
    for(int i = 0; i < 12; i++){
        cout << "Socks [" << i << "] = " << socks[i] << "\n";
    }
}*/