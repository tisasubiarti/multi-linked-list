#define TUBESKERETA_H_INCLUDED

#include <iostream>
using namespace std;

#define infoGerbong(G) (G)->infoGerbong
#define nextGerbong(G) (G)->nextGerbong
//#define penumpang(G) (G)->penumpang
#define infoPenumpang(P) (P)->infoPenumpang
#define nextPenumpang(P) (P)->nextPenumpang
#define firstGerbong(G) ((G).firstGerbong)
#define firstPenumpang(P) ((P).firstPenumpang)
#define nil NULL

struct infotype_gerbong{
    int nomor_gerbong;
    int kapasitas;
};

struct infotype_penumpang{
    string nama_penumpang;
    int nomor_kursi;
    char kode_kursi;
};

typedef struct elmPenumpang *adrPenumpang;
typedef struct elmGerbong *adrGerbong;


struct elmGerbong{
    infotype_gerbong infoGerbong;
    adrGerbong nextGerbong;
    adrPenumpang nextPenumpang;
};

struct elmPenumpang{
    infotype_penumpang infoPenumpang;
    adrPenumpang nextPenumpang;
};

struct MLLPenumpang{
    adrPenumpang firstPenumpang;
};

struct MLLGerbong{
    adrGerbong firstGerbong;
};

void createListPenumpang(MLLPenumpang &P);
void createListGerbong(MLLGerbong &G);
infotype_gerbong Newgerbong(infotype_gerbong &G);
adrGerbong createElmGerbong(infotype_gerbong dataGerbong);
void insertLastGerbong(MLLGerbong &G, adrGerbong Gerbong, MLLPenumpang &P);
void showGerbong(MLLGerbong G);
infotype_penumpang NewPenumpang(infotype_penumpang &P);
adrPenumpang createElmPenumpang(infotype_penumpang dataPenumpang);
void insertLastPenumpang(MLLPenumpang &P, adrPenumpang Penumpang);
void deleteFirstGerbong(MLLGerbong &G, adrGerbong &Gerbong);
bool searchPenumpang (MLLGerbong G, string namaPenumpang);
int jumlahGerbong (MLLGerbong &G);
int jumlahPenumpang (MLLGerbong &G);
void showKapasitasGerbongMin(MLLGerbong G);
void showKapasitasGerbongMaks (MLLGerbong G);
int selectMenu();

