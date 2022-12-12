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
        cout << " = 2. Perkalian Matriks      =" << endl;
        cout << " = 3. Tranpose Matriks       =" << endl;
        cout << " = 4. Determinan Matriks     =" << endl;
        cout << " = 5. Invers Matriks         =" << endl;
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
                    cout << "\nMatriks 1 : \n";
                    showMatriks(matriks1);
                }
                getch();
                break;
            }
            case 2 : system("cls");{
                multiplyMatriks();
                getch();
                break;
            }
            case 3 : system("cls");{
                tranposeMatriks();
                getch();
                break;
            }
            case 4 : system("cls");{
                if (baris_1 != kolom_1){
                    cout << "Maaf, matriks tidak bisa dicari determinan-nya!\n";
                } else {
                    sizeArr = baris_1;
                    int det = determinantMatriks(matriks1, sizeArr);
                    cout << "Determinan Matriks yaitu : " << det << "\n";
                }
                getch();
                break;
            }
            case 5 : system("cls");{
                if (baris_1 != kolom_1){
                    cout << "Maaf, matriks tidak bisa dicari inverse-nya!\n";
                } else {
                    sizeArr = baris_1;
                    if (inverse(matriks1, matriksInvers) == true){
                        showMatriksInvers(matriksInvers);
                    }
                }
                getch();
                break;
            }
            case 6 : system("cls");{
                if (terisi == true){
                    showMatriks(matriks1);
                } else {
                    cout << "Maaf belum ada matriks untuk ditampilkan!\n";
                }
                
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