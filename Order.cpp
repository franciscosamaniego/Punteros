#include <iostream>

using namespace std;

void order(int *a) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 4; j++) {
            if(a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main(void) {
    int n[5];
    for(int i = 0; i < 5; i++) {
        cout << "Ingresa un numero" << endl;
        cin >> n[i];
    }
    order(n);
    int a = n[0];
    int b = n[1];
    int c = n[2];
    int d = n[3];
    int e = n[4];

    cout << "A: " << a << endl;
    cout << "B: " << b << endl;
    cout << "C: " << c << endl;
    cout << "D: " << d << endl;
    cout << "E: " << e << endl;
    return 0;
}