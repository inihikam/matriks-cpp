/*
    Muhammad Maulana Hikam
    A11.2021.13550 - A11.43UG2
    Universitas Dian Nuswantoro
*/

#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>

using namespace std;

//INISIALISASI BARIS DAN KOLOM
int baris_1, kolom_1, baris_2, kolom_2, sizeArr;
int matriks1[100][100];
int matriks2[100][100];
int matriksAdjoint[100][100];
float matriksInvers[100][100];

//KONFIRMASI MATRIKS KOSONG
bool terisi = false;

//FUNGSI INISIALISASI MATRIKS
void matriks_1(){
    cout << "Masukkan jumlah baris matriks 1 : ";cin >> baris_1;
    cout << "Masukkan jumlah kolom matriks 1 : ";cin >> kolom_1;
    for (int i = 0; i < baris_1; i++){
        for (int j = 0; j < kolom_1; j++){
            cout << "Masukkan data matriks1 baris-" << i+1 << " kolom-" << j+1 << " : ";
            cin >> matriks1[i][j];
        }
    }
    terisi = true;
    cout << "\nMatriks 1 berhasil dibuat!\n";
}

//FUNGSI PERKALIAN MATRIKS
void multiplyMatriks(){
    cout << "Masukkan jumlah baris matriks 2 : ";cin >> baris_2;
    if(baris_2 != kolom_1){
        cout << "Maaf baris matriks 2 tidak sesuai dengan kolom matriks 1!\n";
    } else {
        cout << "Masukkan jumlah kolom matriks 2 : ";cin >> kolom_2;
        for (int i = 0; i < baris_2; i++){
            for (int j = 0; j < kolom_2; j++){
                cout << "Masukkan data matriks2 baris-" << i+1 << " kolom-" << j+1 << " : ";
                cin >> matriks2[i][j];
            }
        }

        cout << "\nMatriks 2 : \n";
        for (int i = 0; i < baris_2; i++){
            cout << "[ ";
            for (int j = 0; j < kolom_2; j++){
                cout << matriks2[i][j] << " ";
            }
            cout << "]\n";
        }
        getch();
        
        int mulMatriks[baris_1][kolom_2];
        for (int i = 0; i < baris_1; i++){
            for (int j = 0; j < kolom_2; j++){
                mulMatriks[i][j] = 0;
                for (int k = 0; k < baris_2; k++){
                    mulMatriks[i][j] += matriks1[i][k] * matriks2[k][j];
                }
            }
        }

        cout << "\nHasil Perkalian Matriks : \n";
        for (int i = 0; i < baris_1; i++){
            cout << "[ ";
            for (int j = 0; j < kolom_2; j++){
                cout << mulMatriks[i][j] << " ";
            }
            cout << "]\n";
        }
    }
}

//FUNGSI KOFAKTOR MATRIKS
void cofactorMatriks(int mat[100][100], int temp[100][100], int a, int b, int sizeArr){
    int i = 0;
    int j = 0;

    for (int baris = 0; baris < sizeArr; baris++){
        for (int kolom = 0; kolom < sizeArr; kolom++){
            if (baris != a && kolom != b){
                temp[i][j++] = mat[baris][kolom];

                if (j == sizeArr - 1){
                    j = 0;
                    i++;
                }
            }
        }
    }
}

// FUNGSI DETERMINAN MATRIKS
int determinantMatriks(int det[100][100], int sizeArr){
    int D = 0;

    if (sizeArr == 1){
        return det[0][0];
    }

    int temp[100][100];

    int sign = 1;
    
    for (int i = 0; i < sizeArr; i++){
        cofactorMatriks(det, temp, 0, i, sizeArr);
        D += sign * det[0][i] * determinantMatriks(temp, sizeArr - 1);

        sign = -sign;
    }
    
    return D;
}

// FUNGSI MATRIKS ADJOIN
void adjoinMatriks(int mat[100][100], int adj[100][100]){
    if (sizeArr == 1){
        adj[0][0] = 1;
        return;
    }
    
    int sign = 1;
    int temp[100][100];

    for (int i = 0; i < sizeArr; i++){
        for (int j = 0; j < sizeArr; j++){
            cofactorMatriks(mat, temp, i, j, sizeArr);

            sign = ((i + j) % 2 == 0) ? 1 : -1;

            adj[j][i] = (sign) * (determinantMatriks(temp, sizeArr - 1));
        }
    }
}

// FUNGSI INVERS MATRIKS
bool inverse(int mat[100][100], float inv[100][100]){
    int det = determinantMatriks(mat, sizeArr);
    if(det == 0){
        cout << "Matriks bersifat singular, jadi tidak dapat dicari inverse-nya";
        return false;
    }

    int adj[100][100];
    adjoinMatriks(mat, adj);

    for (int i = 0; i < sizeArr; i++){
        for (int j = 0; j < sizeArr; j++){
            inv[i][j] = adj[i][j] / float(det);
        }
    }

    return true;
}

//FUNGSI TRANPOSE MATRIKS
void tranposeMatriks(){
    int tranpose[100][100];
    int baris_tranpose = 0;
    int kolom_tranpose = 0;
    
    if (baris_1 < kolom_1){
        for (int i = 0; i < baris_1+(kolom_1-baris_1); i++){
            for (int j = 0; j < kolom_1; j++){
                tranpose[i][j] = matriks1[j][i];
                if (i < 1 && tranpose[i][j] != 0){
                    kolom_tranpose++;
                }
            }
            baris_tranpose++;
        }
    } else if (baris_1 > kolom_1){
        for (int i = 0; i < baris_1; i++){
            for (int j = 0; j < kolom_1+(baris_1-kolom_1); j++){
                tranpose[i][j] = matriks1[j][i];
                if (i < 1 && tranpose[i][j] != 0){
                    kolom_tranpose++;
                }
            }
            if (i < (baris_1-(baris_1-kolom_1))){
                baris_tranpose++;
            }
        }
    } else {
        for (int i = 0; i < baris_1; i++){
            for (int j = 0; j < kolom_1; j++){
                tranpose[i][j] = matriks1[j][i];
                if (i < 1){
                    kolom_tranpose++;
                }
            }
            baris_tranpose++;
        }
    }

    cout << "\nTranpose dari matriks 1 : \n";
    for (int i = 0; i < baris_tranpose; i++){
        cout << "[ ";
        for (int j = 0; j < kolom_tranpose; j++){
            cout << tranpose[i][j] << " ";
        }
        cout << "]\n";
    }
}

//FUNGSI UNTUK MENAMPILKAN MATRIKS
void showMatriks(int mat[100][100]){
    for (int i = 0; i < baris_1; i++){
        cout << "[ ";
        for (int j = 0; j < kolom_1; j++){
            cout << mat[i][j] << " ";
        }
        cout << "]\n";
    }
}

// FUNGSI MENAMPILKAN MATRIKS INVERS
void showMatriksInvers(float inv[100][100]){
    for (int i = 0; i < sizeArr; i++){
        cout << "[ ";
        for (int j = 0; j < sizeArr; j++){
            cout << inv[i][j] << " ";
        }
        cout << "]\n";
    }
    
}