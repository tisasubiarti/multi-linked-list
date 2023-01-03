#include "TubesKereta.h"
#include <iostream>

using namespace std;

int main()
{
    adrGerbong gerbong;
    adrPenumpang penumpang;
    infotype_penumpang penumpangBaru;
    infotype_gerbong gerbongBaru;
    MLLPenumpang P;
    MLLGerbong G;
    int grb;
    int i = 1;
    int p = 1;
    int nomorGerbong;
    string namaPenumpang;
    int menu;
    char returnBack;

    createListGerbong(G);
    createListPenumpang(P);
    menu = selectMenu();

    while(menu != 0){
        if(menu == 1){
            cout<<"Tambahkan Gerbong Kereta :";
            cin>>grb;
            cout<<endl;

            while(i <= grb){
                cout<<"Gerbong ke : "<<i<<endl;
                gerbongBaru = Newgerbong(gerbongBaru);
                while(p <= gerbongBaru.kapasitas) {
                    penumpangBaru = NewPenumpang(penumpangBaru);
                    penumpang = createElmPenumpang(penumpangBaru);
                    insertLastPenumpang(P, penumpang);
                    p++;
                }
                gerbong = createElmGerbong(gerbongBaru);
                insertLastGerbong(G, gerbong, P);
                p = 1;
                i++;
                cout<<endl;
            };

        }else if(menu == 2){
            cout<<"Show All Kereta"<<endl;
            showGerbong(G);
            cout<<endl;
        }else if(menu == 3){
            cout<<"Mencari kode dan  berdasarkan nama penumpang "<<endl;
            cout<<"Masukan nama penumpang : ";
            cin>>namaPenumpang;
            cout<<endl;

            searchPenumpang(G,namaPenumpang);
            cout<<endl;
        }else if(menu ==4){
            cout<<"Menampilkan jumlah gerbong"<<endl;
            int jmlGerbong = jumlahGerbong(G);
            cout<<"Jumlah gerbong :"<<jmlGerbong<<endl;
            cout<<endl;
            cout<<endl;
        }else if(menu == 5){
            cout<<"Menampilkan jumlah penumpang"<<endl;
            int jmlPenumpang = jumlahPenumpang(G);
            cout<<"Jumlah penumpang :"<<jmlPenumpang<<endl;
            cout<<endl;
        }else if(menu==6){
            cout<<"Mencari kapasitas gerbong paling sedikit"<<endl;
            showKapasitasGerbongMin(G);
            cout<<endl;
        }else if(menu == 7){
            cout<<"Mencari kapasitas gerbong paling banyak"<<endl;
            showKapasitasGerbongMaks(G);
            cout<<endl;
        }else if(menu == 8){
            deleteFirstGerbong(G,gerbong);
            cout<<"Kereta sesudah di hapus"<<endl;
            showGerbong(G);
            cout<<endl;
        }else{
            cout<<"Menu tidak di temukan "<<endl;
        }
        cout<<endl;
        cout<<"Kembali ke menu utama ? (Y/N): ";
        cin>>returnBack;

        if(returnBack == 'Y'){
            cout<<endl;
            menu = selectMenu();
        }else if(returnBack == 'N'){
            menu = 0;
        }
    }
    cout<<endl;
    cout<<"Anda telah keluar dari program"<<endl;
    return 0;
}
