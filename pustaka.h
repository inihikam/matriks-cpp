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
int baris_1, kolom_1, baris_2, kolom_2, size;
int matriks1[100][100];
int matriks2[100][100];

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

//FUNGSI PENJUMLAHAN MATRIKS
void sumMatriks(){
    int sum[100][100];
    cout << "Masukkan jumlah baris matriks 1 : ";cin >> baris_2;
    cout << "Masukkan jumlah kolom matriks 1 : ";cin >> kolom_2;
    if (baris_1 != baris_2 || kolom_1 != kolom_2){
        cout << "Maaf, kedua matriks tidak dapat dijumlahkan!";
    } else {
        for (int i = 0; i < baris_2; i++){
            for (int j = 0; j < kolom_2; j++){
                cout << "Masukkan data matriks2 baris-" << i+1 << " kolom-" << j+1 << " : ";
                cin >> matriks2[i][j];
            }
        }
        for (int i = 0; i < baris_1; i++){
            for (int j = 0; j < kolom_1; j++){
                sum[i][j] = matriks1[i][j] + matriks2[i][j];
            }
        }
        cout << "\nHasil Penjumlahan Matriks : \n";
        for (int i = 0; i < baris_1; i++){
            cout << "[ ";
            for (int j = 0; j < kolom_1; j++){
                cout << sum[i][j] << " ";
            }
            cout << "]\n";
        }
    }
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

//FUNGSI DETERMINAN MATRIKS
void determinanMatriks(){
    int index, data1, data2;
    int D = 0;
    int total = 1;
    int det = 1;
    int temp[size + 1];

    for (int i = 0; i < size; i++){
        index = i;

        while (index < size && matriks1[index][i] == 0){
            index++;
        }
        if (index == size){
            continue;
        }
        if (index != i){
            for (int j = 0; j < size; j++){
                swap(matriks1[index][j], matriks1[i][j]);
            }
            det = det * pow(-1, index - i);
        }

        for (int j = 0; j < size; j++){
            temp[j] = matriks1[i][j];
        }
        
        for (int j = i + 1; j < size; j++){
            data1 = temp[i];
            data2 = matriks1[j][i];
            for (int k = 0; k < size; k++){
                matriks1[j][k] = (data1 * matriks1[j][k]) - (data2 * temp[k]);
            }
            total = total * data1;
        }    
    }

    for (int i = 0; i < size; i++){
        det = det * matriks1[i][i];
    }
    
    D = (det/total);
    cout << "Determinan Matriks yaitu " << D;
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
void showMatriks(){
    cout << "\nMatriks 1 : \n";
    for (int i = 0; i < baris_1; i++){
        cout << "[ ";
        for (int j = 0; j < kolom_1; j++){
            cout << matriks1[i][j] << " ";
        }
        cout << "]\n";
    }
}