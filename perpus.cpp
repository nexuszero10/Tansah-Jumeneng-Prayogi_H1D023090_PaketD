#include <iostream>
using namespace std ;

struct node {
    struct node *prev ;
    int data ;
    struct node *next ;
} 

struct node *first = NULL ;
struct node *last = NULL ;

struct node alokasi (int datanya){
    struct node *hasil = new node ;
    hasil -> data = datanya ;
    hasil -> next = hasil -> prev = NULL ;
    return hasil ;
}

void insertFirst(struct node *baru){
    if(first == NULL){
        first = last = baru 
    } else {
        baru -> next = first ;
        first -> prev = baru ;
        first = baru ;
    }
}

void insertLast(struct node *baru){
    if(first == NULL){
        fisrt = last = baru ;
        baru -> prev = last ;
        last = baru ;
    }
}

void deleteFirst(){
    if (first == NULL){
        cout << "Daftar buku kosong.\n" ;
        return
    }

    fisrt = first -> next ;
    delete(first -> prev);
    first -> prev = NULL ;
}

void deleteLast(){
    if (first == NULL){
        cout << "Daftar buku kosong \n";
        return ;
    }

    last = last -> prev ;
    delete(last -> next);
    last -> next = NULL ;
}

void cetak(){
    struct node *p = first ;
    while(p != NULL){
        cout << "ID buku : " << p -> data << "\n" ;
        p = p -> next ;
    }
}

bool isPrime(int n){
    if (n %2 != 0 && n %3 ! = 0 && n % 5 != 0 && n %7 != 0){
        return true ;
    } else {
        return false ; 
    }
} 

void printPrimeBooksIDs(){
    struct node *jalan = fisrt ;

    while (jalan != NULL){
        if(isPrime(jalan -> data) == true){
            cout << "ID buku : " << jalan -> data "\n" ;
        }
        jalan = jalan -> next ;
    }
}

struct node cariBuku(int id){
    struct node *cari = first ;

    while (cari != NULL){
        if (cari -> data == id){
            return true ;
        } else {
            return false ;
        }
        cari = cari -> next ; 
    }
    return cari ;
}

void hapusBuku(int id){
    if (cariBuku(id) == true){
        if (cariBuku == first){
            deleteFirst();
            cout << "Buku dengan ID " << id << "telah dihapus\n";
        } else if (cariBuku == last){
            deleteLast();
            cout << "Buku dengan ID " << id << "telah dihapus\n";
        } else {
            if (cariBuku -> next && cariBuku -> prev != NULL){
                struct node *lama = cariBuku -> next ;
                struct node *baru = cariBuku -> prev ;

                lama -> next = baru ;
                baru -> prev = lama ;
                cariBuku -> next = cariBuku -> prev = NULL ;
                delete(cariBuku); 
            }
        } 
    } else {
        cout << "Buku dngan ID " << id << "tidak ditemukan\n" ;
    }
}

int main (){
    insertLast(alokasi(10));
    insertFirst(alokasi(30));
    insertLast(alokasi(50));
    insertLast(alokasi(19));
    insertFirst(alokasi(90));
    insertLast(alokasi(11));

    cout << "Daftar buku awal: \n" ;
    cetak();

    hapusBuku(20);
    hapusBuku(10);

    cout << "\nDaftar buku setelah penghapusan: \n" ;
    cetak();

    cout << "Daftar Buku dengan ID Bilangan Prima : \n" ;
    printPrimeBooksIDs();
    return 0 ;
}