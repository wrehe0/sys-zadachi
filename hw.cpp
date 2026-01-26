#include <iostream> 
using namespace std;
/*int main(){
    setlocale(LC_ALL, "RU");

   /* cout << "Hello World" << "\n";
    cerr << "ERROR" << "\n";
    int a;
    cin >> a;
    return a;*/

    /*int socks[12];
    for (int i = 0; i < 12; i++){
        socks[i] = i;
    }
    for(int i = 0; i < 12; i++){
        cout << "Socks [" << i << "] = " << socks[i] << "\n";
    }*/
    
    int main (int argc, char* argv[]){
        cout << "Длинна массива : " << argc << endl;
    for (int i = 0; i < argc; ++i) {
        cout << "Аргумент " << i << ": " << argv[i] << endl;
    }
}
/*соло на клавиатуре найти потом*/
/*продолжить на ldd ./hw*/