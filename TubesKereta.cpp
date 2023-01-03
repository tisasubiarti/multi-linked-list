#include "TubesKereta.h"

void createListPenumpang ( MLLPenumpang &P){
    firstPenumpang(P) = nil;
}

void createListGerbong( MLLGerbong &G){
    firstGerbong(G) = nil;
}

adrPenumpang createElmPenumpang(infotype_penumpang dataPenumpang){
    adrPenumpang P = new elmPenumpang;
    infoPenumpang(P) = dataPenumpang;
    nextPenumpang(P) = nil;
    return P;
}

adrGerbong createElmGerbong(infotype_gerbong dataGerbong){
    adrGerbong G = new elmGerbong;
    infoGerbong(G) = dataGerbong;
    nextPenumpang(G) = nil;
    nextGerbong(G) = nil;
    return G;
}

void showGerbong (MLLGerbong G){
    adrGerbong Gerbong;
    adrPenumpang orang;
    Gerbong = firstGerbong(G);
    if(firstGerbong(G) == nil){
        cout<<"List Kosong"<<endl;
    }else{
        while(Gerbong != nil){
            cout<<"Nomor Gerbong :"<<infoGerbong(Gerbong).nomor_gerbong<<endl;
            cout<<"Kapasitas :"<<infoGerbong(Gerbong).kapasitas<<endl;
            orang = nextPenumpang(Gerbong);
            cout<<endl;
            while(orang != nil) {
                cout<<"Nama Penumpang :"<<infoPenumpang(orang).nama_penumpang<<endl;
                cout<<"Nomor Kursi :" <<infoPenumpang(orang).nomor_kursi<<endl;
                cout<<"Kode Kursi :" <<infoPenumpang(orang).kode_kursi<<endl;
                orang = nextPenumpang(orang);
                cout<<endl;
            }
            Gerbong = nextGerbong(Gerbong);
        }
        cout<<endl;
    }
}

void insertLastPenumpang(MLLPenumpang &P, adrPenumpang Penumpang){
    if(firstPenumpang(P) == nil){
        firstPenumpang(P) = Penumpang;
        nextPenumpang(Penumpang) = nil;
    }else if(nextPenumpang(firstPenumpang(P))==nil){
        nextPenumpang(firstPenumpang(P)) = Penumpang;
        nextPenumpang(Penumpang) = nil;
    }else{
        adrPenumpang AP = firstPenumpang(P);
        while(nextPenumpang(AP)!= nil){
            AP = nextPenumpang(AP);
        }
        nextPenumpang(AP)= Penumpang;
        nextPenumpang(Penumpang) = nil;
    }

}

void insertLastGerbong(MLLGerbong &G, adrGerbong gerbong, MLLPenumpang &P){
     if(firstGerbong(G) == nil){
        nextPenumpang(gerbong) = firstPenumpang(P);
        firstGerbong(G) = gerbong;
    }else if(nextGerbong(firstGerbong(G))==nil){
        nextPenumpang(gerbong) = firstPenumpang(P);
        nextGerbong(firstGerbong(G)) = gerbong;
    }else{
        adrGerbong AG = firstGerbong(G);
        while(nextGerbong(AG)!= nil){
            AG = nextGerbong(AG);
        }
        nextPenumpang(gerbong) = firstPenumpang(P);
        nextGerbong(AG) = gerbong;
    }
    firstPenumpang(P) = nil;
}


void deleteFirstGerbong(MLLGerbong &G, adrGerbong &Gerbong){
    if(firstGerbong(G)==nil){
        cout<<"List Kosong"<<endl;
    }else if(nextGerbong(firstGerbong(G))==nil){
        firstGerbong(G) = nil;
    }else{
        Gerbong = firstGerbong(G);
        firstGerbong(G) = nextGerbong(Gerbong);
    }
}

bool searchPenumpang (MLLGerbong G, string namaPenumpang){
    adrGerbong AG;
    AG = firstGerbong(G);
    if(AG == nil){
        cout << "Penumpang masih kosong" << endl;
    }else{
        while(AG != nil){
            adrPenumpang p = nextPenumpang(AG);
            while(p != nil){
                if(infoPenumpang(p).nama_penumpang == namaPenumpang){
                    cout << "Nomor gerbong dan nama penumpang ditemukan" << endl;
                    cout << "Nama Penumpang:" << infoPenumpang(p).nama_penumpang << endl;
                    cout << "Nomor Kursi:" << infoPenumpang(p).nomor_kursi << endl;
                    cout << "Kode Kursi:"<<infoPenumpang(p).kode_kursi<<endl;
                }
                p = nextPenumpang(p);
            }
            AG = nextGerbong(AG);
        }
    }
}


int jumlahPenumpang (MLLGerbong &G){
    adrGerbong gerbong;
    adrPenumpang penumpang;
    gerbong = firstGerbong(G);
    int jumlah;
    jumlah = 0;
    while(gerbong != nil){
        penumpang = nextPenumpang(gerbong);
        while(penumpang != nil){
            jumlah = jumlah +  1;
            penumpang = nextPenumpang(penumpang);
        }
        gerbong = nextGerbong(gerbong);
    }
    return jumlah;

}

int jumlahGerbong (MLLGerbong &G){
    adrGerbong gerbong;
    gerbong = firstGerbong(G);
    int jumlah;
    jumlah = 0;
    while(gerbong != nil){
        jumlah = jumlah +  1;
        gerbong = nextGerbong(gerbong);
    }
    return jumlah;
}

void showKapasitasGerbongMaks (MLLGerbong G){
    if(firstGerbong(G) != nil){
        adrGerbong MAKS;
        adrGerbong P;
        MAKS = firstGerbong(G);
        P = nextGerbong(MAKS);
        while(P != nil){
            if(infoGerbong(P).kapasitas > infoGerbong(MAKS).kapasitas){
                MAKS = P;
            }
            P = nextGerbong(P);
        }
        cout<<"Kapasitas Gerbong paling banyak :"<<infoGerbong(MAKS).kapasitas;
    }
    cout<<endl;
}

void showKapasitasGerbongMin(MLLGerbong G){
    adrGerbong MIN;
    adrGerbong P;
    if(firstGerbong(G) != nil){
        MIN = firstGerbong(G);
        P = nextGerbong(MIN);
        while(P != nil){
            if(infoGerbong(P).kapasitas < infoGerbong(MIN).kapasitas){
                MIN = P;
            }
            P = nextGerbong(P);
        }
        cout<<"Kapasitas Gerbong paling sedikit :"<<infoGerbong(MIN).kapasitas;
    }
    cout<<endl;
}

infotype_gerbong Newgerbong(infotype_gerbong &G){
    cout<<"Nomor Gerbong :";
    cin >> G.nomor_gerbong;
    cout<<"Kapasitas :";
    cin>>G.kapasitas;

    return G;
}

infotype_penumpang NewPenumpang(infotype_penumpang &P){
    cout<<"Nama Penumpang :";
    cin >> P.nama_penumpang;
    cout<<"Nomor Kursi :";
    cin>>P.nomor_kursi;
    cout<<"Kode Kursi :";
    cin>>P.kode_kursi;

    return P;
}

int selectMenu(){
    cout<<" ==========================MENU============================"<<endl;
    cout<<"|1.Menambahkan Data                                        |"<<endl;
    cout<<"|2.Menampilkan semua data                                  |"<<endl;
    cout<<"|3.Mencari kode dan nomor kursi berdasarkan nama penumpang |"<<endl;
    cout<<"|4.Menampilkan jumlah gerbong                              |"<<endl;
    cout<<"|5.Menampilkan jumlah penumpang                            |"<<endl;
    cout<<"|6.Mencari kapasitas gerbong paling sedikit                |"<<endl;
    cout<<"|7.Mencari kapasitas gerbong paling banyak                 |"<<endl;
    cout<<"|8.Menghapus Gerbong                                       |"<<endl;
    cout<<" ========================================================== "<<endl;
    cout<<endl;
    cout<<"Masukan nomor menu :";

    int input;
    cin>>input;
    cout<<endl;

    return input;
}
