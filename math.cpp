#include<iostream>   
#include<string>     
#include<algorithm>  
#include<cstdlib>
using namespace std;

bool check_n(int n) {
    bool flag = true;
    if (n == 2)  flag = false;
    if (n == 8)  flag = false; 
    if (n == 10) flag = false;  
    if (n == 16) flag = false;  
    if (n > 30) flag = false; 
    if (n < 3)  flag = false;
    return flag;
}

string to_base_n(int num, int base) {
    if (num == 0) return "0";
    string r = "", d = "0123456789ABCDEFGHIJKLMNOPQRST";
    while (num > 0) {
        r = d[num % base] + r;
        num /= base;
    }
    return r;
}
void gethelp();
string =="--help"
int main() {
    int n;
    cout << "n = ";
    cin >> n;

    if (!check_n(n)) {
        cout << "n -- not correct \n";
        return 1;
    }
    
    cout << "\nТаблица умножения (основание " << n << "):\n\n";
    
    // Первая строка - заголовок
    cout << "   ";
    for (int j = 1; j < n; j++) {
        cout << " " << to_base_n(j, n);
    }
    cout << "\n";
    
    // Таблица
    for (int i = 1; i < n; i++) {
        cout << to_base_n(i, n) << ": ";
        for (int j = 1; j < n; j++) {
            cout << to_base_n(i * j, n) << " ";
        }
        cout << "\n";
    }
    
    return 0;
}