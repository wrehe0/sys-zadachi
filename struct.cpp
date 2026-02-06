#include <iostream>
#include <iomanip>  
#include <string>   
using namespace std;

struct CELL {   
    unsigned short foreground : 3;  
    unsigned short character  : 8;  
    unsigned short blink      : 1;  
    unsigned short intensity  : 1;  // 4 БИТ  УРА УРА УРА 
    unsigned short background : 3;  
    
} ;

int main(int argc, char* argv[]) {
    CELL my_cell;
    
    
    my_cell.character = 125;
    my_cell.foreground = 4;
    my_cell.background = 2;
    my_cell.blink = 0;
    my_cell.intensity = 0;

    cout << "=== Программа для работы со структурой CELL ===" << endl;
    cout << "Инициализация структуры:" << endl;
    cout << "character: " << my_cell.character << endl;
    cout << "foreground: " << my_cell.foreground << endl;
    cout << "background: " << my_cell.background << endl;
    cout << "intensity: " << my_cell.intensity << endl;
    cout << "blink: " << my_cell.blink << endl;
    cout << "Размер структуры в байтах: " << sizeof(my_cell) << endl;
    
    
    cout << "\nHex значение структуры в памяти: 0x" 
         << hex << uppercase << setfill('0') << setw(4)
         << *reinterpret_cast<unsigned short*>(&my_cell) 
         << dec << endl << endl;

    unsigned short input_hex;
    bool all_ok = false;
    
   
    unsigned short orig_character = my_cell.character;
    unsigned short orig_foreground = my_cell.foreground;
    unsigned short orig_background = my_cell.background;
    unsigned short orig_blink = my_cell.blink;
    unsigned short orig_intensity = my_cell.intensity;  

    
    while (!all_ok){
        cout << "\nИтерация ввода:" << endl;
        cout << "Введите hex значение для структуры CELL (или 0xFFFF для выхода): ";
        
       
        if (!(cin >> hex >> input_hex)) {
            cout << "Ошибка ввода! Попробуйте еще раз." << endl;
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            continue;
        }
        cin >> dec;  
        
        if (input_hex == 0xFFFF) {
            cout << "Выход из программы." << endl;
            break;
        }
        
        cout << "\nИсходные значения для сравнения:" << endl;
        cout << "character=125, foreground=4, background=2, blink=0, intensity=0" << endl;

        
        my_cell = *reinterpret_cast<CELL*>(&input_hex);
        
        cout << "\nПосле присвоения hex значения:" << endl;
        cout << "my_cell.character = " << my_cell.character << endl;
        cout << "my_cell.foreground = " << my_cell.foreground << endl;
        cout << "my_cell.background = " << my_cell.background << endl;
        cout << "my_cell.blink = " << my_cell.blink << endl;
        cout << "my_cell.intensity = " << my_cell.intensity << endl;
        
        
        cout << "Новое hex значение структуры: 0x" 
             << hex << uppercase << setfill('0') << setw(4) 
             << *reinterpret_cast<unsigned short*>(&my_cell) 
             << dec << endl;

        
        bool only_intensity_changed = 
            (my_cell.character == orig_character) &&
            (my_cell.foreground == orig_foreground) &&
            (my_cell.background == orig_background) &&
            (my_cell.blink == orig_blink) &&
            (my_cell.intensity != orig_intensity); 

        if (only_intensity_changed) {
            cout << "\n✓ УСПЕХ! Изменилось только поле intensity!" << endl;
            all_ok = true;
        } else {
            cout << "\n✗ Проблема: изменились другие поля помимо intensity" << endl;
            cout << "Попробуйте другое значение." << endl;
        }
        cout << "\n" << string(50, '-') << endl;
    }
    
    return 0;
}