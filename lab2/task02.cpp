#include <iostream>
#include <cstdlib> // For rand() and srand() functions
using namespace std;

void number_1(int first, int second) {
    cout << "first: " << first << ", second: "<< second << "\n\n";
    
}

int number_2(int x) {
    return 1 + x;
}

void number_3() {
    int num = 1;
    int *ptr = &num;
    cout << "Initial value - num : " << num << ", ptr : " << *ptr << "\n";
    *ptr = 3;
    cout << "Updated value - num : " << num << ", ptr : " << *ptr << "\n\n";
}

void number_4() {
    cout << "Odd number between 1-20 : ";
    for (int i = 1; i <= 20; i += 2) {
        cout << i << " ";
    }
    cout << "\n\n";
}

void number_5() {
    int array[5];
    for (int i = 0; i<=4; ++i) {
        array[i] = rand() % 20;
    }
    cout << "array: ";
    for (int i = 0; i <= 4; ++i) {
        cout << array[i] << " ";
    }
    cout << "\n\n";
}

void number_6() {
    string text = "this has spaces in it";
    for (int i= 0; i < text.length(); i++) {
        if (text[i] != ' ') {
            cout << text[i];
        } else {
            cout << endl;
        }
    }
    cout << "\n\n";
}

class Pen {
    private: 
        double tipSize;
    public:
        string color;
        string type;
        Pen (string x, string y, double z) {
            color = x;
            type = y;
            tipSize = z;
        }
        void write(){
            cout << "Writing with a " << color << " " << type << " pen, Tip Size: " << tipSize << "mm" << endl;
        }
    
};


int main()
{
    cout << "number 1 : function wiht 2 value / print on screen\n";
    number_1(1, 2);
    
    cout << "number 2 : function wiht 1 value / alter and call from main\n";
    cout << "Altered value : " << number_2(4) << "\n\n";

    cout << "number 3 : pointer / settign and reading\n";
    number_3();

    cout << "number 4 : function / loop to print out odd in 1-20 in single line\n";
    number_4();

    cout << "number 5 : array / randomly assign vlue and print all\n";
    number_5();

    cout << "number 6 : split the line of text\n";
    number_6();

    cout << "number 7 : declare, create instance and demonstrate class\n";
    Pen myPen("Blue", "Ballpoint", 0.7);
    myPen.write();

    return 0;
}
