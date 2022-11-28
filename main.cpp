#include "pustaka.h"

int main(){
    int pilih;
    do{
        system("cls");
        cout << endl;
        cout << " =============================" << endl;
        cout << " =      Program Matriks      =" << endl;
        cout << " =============================" << endl;
        cout << " = 1. Buat Matriks           =" << endl;
        cout << " = 2. Penjumlahan Matriks    =" << endl;
        cout << " = 3. Perkalian Matriks      =" << endl;
        cout << " = 4. Tranpose Matriks       =" << endl;
        cout << " = 5. Determinan Matriks     =" << endl;
        cout << " = 6. Tampil Matriks         =" << endl;
        cout << " = 7. Keluar                 =" << endl;
        cout << " =============================" << endl;
        cout << " Select Menu : ";
        //memilih menu
        cin >> pilih;
        switch (pilih){
            case 1 : system("cls");{
                matriks_1();
                if (terisi == true){
                    showMatriks();
                }
                getch();
                break;
            }
            case 2 : system("cls");{
                sumMatriks();
                getch();
                break;
            }
            case 3 : system("cls");{
                multiplyMatriks();
                getch();
                break;
            }
            case 4 : system("cls");{
                tranposeMatriks();
                getch();
                break;
            }
            case 5 : system("cls");{
                if (baris_1 != kolom_1){
                    cout << "Maaf, matriks tidak bisa dicari determinan-nya!\n";
                } else {
                    size = baris_1;
                    determinanMatriks();
                }
                getch();
                break;
            }
            case 6 : system("cls");{
                showMatriks();
                getch();
                break;
            }
            case 7 : system("cls");{
                cout << "Terima Kasih telah menggunakan program ini!\n";
                return 0;
                break;
            }
        
            default : system("cls");{
                cout << "Maaf, pilihan tidak ada!\n";
                break;
            }
        }
    } while (pilih != 7);
    
    

    return 0;
}