#include <iostream>
using namespace std ;

struct khs {
    int nim ;
    float ipk ;
} ;
void update (struct khs *k, float ipkBaru){
    k -> ipk = ipkBaru ;
}

void printkhs(struct khs *k){
    cout << "nim : " << k -> nim << "\n" ;
    cout << "ipk : " << k -> ipk << "\n\n" ;
}

int main (){
    khs p ;
    p.nim = 23090 ;
    p.ipk = 3.75 ;
    cout << "Sebelum ipk diperbaharui: \n" ;
    printkhs(&p);

    update(&p, 3.65);

    cout << "Steleah ip diperbaharui: \n" ;
    printkhs(&p);

    return 0 ;

}