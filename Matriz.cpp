#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

#define N 100

void cargar(int m[N][N], int f, int c) {
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            cout << "Ingrese un valor para la fila " << i << ", columna " << j << endl;
            cin >> m[i][j];
        }
    }
}

void printa(int a[N][N], int f, int c) {
        for(int i = 0; i < f; i++) {
            for(int j = 0; j < c; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
}

void printb(int b[N][N], int f, int c) {
        for(int i = 0; i < f; i++) {
            for(int j = 0; j < c; j++) {
                cout << b[i][j] << " ";
            }
            cout << endl;
        }
}

void suma(int a[N][N], int b[N][N], int f, int c) {
    int cs[f][c];
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            cs[i][j] = a[i][j] + b[i][j];
        }
    }
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            cout << cs[i][j] << " ";
        }
        cout << endl;
    }
}

void multiplicar(int a[N][N], int b[N][N], int f, int c,int cb) {
    int cs[N][N];
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            for(int k = 0; k < cb; k++) {
                cs[i][k] += a[i][j] * b[j][k];
            }
        }
    }
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            cout << cs[i][j] << " ";
        }
        cout << endl;
    }
}

void determinantes(int m[N][N]) {
    double determinante;
    determinante = m.determinant();
   cout << determinante << endl;
}

int main(void) {
    int f, c, choice, fb, cb;
    int a[N][N];
    int b[N][N];
    while(1) {
        cout << "Que quiere hacer?" << endl;
    cout << "1)Cargar matrices" << endl;
    cout << "2)Imprimir matrices" << endl;
    cout << "3)Sumar matrices" << endl;
    cout << "4)Multiplicar matrices" << endl;
    cout << "5)Determinante matrices" << endl;
    cout << "6)Traspuesta matrices" << endl;
    cout << "7)Salir" << endl;
    cin >> choice;
    switch(choice) {
        case 1:
            cout << "De cuantas filas queres que sea la matriz A?" << endl;
            cin >> f;
            cout << "De cuantas columnas queres que sea la matriz A?" << endl;
            cin >> c;
            
            cargar(a,f,c);
            cout << "De cuantas filas queres que sea la matriz B?" << endl;
            cin >> fb;
            cout << "De cuantas columnas queres que sea la matriz B?" << endl;
            cin >> cb;

            cargar(b,fb,cb);
            break;
        case 2:
            printa(a,f,c);
            cout << endl;
            printb(b,fb,cb);
            break;
        case 3:
            if(f == fb && c == cb) {
                suma(a,b,f,c);
            }
            else cout << "Para realizar una suma entre matrices tienen que tener las mismas filas y columnas" << endl;
            break;
        case 4:
        if(c == fb) multiplicar(a,b,f,c,cb);
        else cout << "Para realizar la multipliacion las columnas de a tienen que ser igual a las filas de b" << endl;
            break;
        case 5:
            cout << "Determinante de A: " << determinantes(a) << endl;
            cout << "Determinante de B: " << determinantes(b) << endl; 
            break;
        case 6:
            printa(a,c,f);
            cout << endl;
            printb(b,cb,fb);
            break;
        case 7:
            return 1;
        default:
        cout << "Elija una opcion existente" << endl;
        break;
     }
    }
    return 0;
}