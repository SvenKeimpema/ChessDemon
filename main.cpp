#include <iostream>
using namespace std;

#define ULL unsigned long long
#define getBit(bb, sq) (0 <= sq && sq < 64 ? bb & (1ULL << sq) : 0)
#define setBit(bb, sq) (0 <= sq && sq < 64 ? bb | (1ULL << sq) : bb)

#define AFILE 72340172838076673ULL
#define ABFILE 217020518514230019ULL
#define HFILE 9259542123273814144ULL
#define GHFILE 13889313184910721216ULL

ULL getKnight(int sq) {
    ULL attacks = 0ULL;

    if(!getBit(ABFILE, sq-6)) attacks = setBit(attacks, sq-6);
    if(!getBit(GHFILE, sq-10)) attacks = setBit(attacks, sq-10);
    if(!getBit(AFILE,  sq-15)) attacks = setBit(attacks, sq-15);
    if(!getBit(HFILE,  sq-17)) attacks = setBit(attacks, sq-17);

    if(!getBit(GHFILE, sq+6)) attacks = setBit(attacks, sq+6);
    if(!getBit(ABFILE, sq+10)) attacks = setBit(attacks, sq+10);
    if(!getBit(HFILE,  sq+15)) attacks = setBit(attacks, sq+15);
    if(!getBit(AFILE,  sq+17)) attacks = setBit(attacks, sq+17);

    return attacks;
}

ULL getPawn(int sq, int side) {
    ULL attacks = 0ULL;
    if(side == 0) {
        if(!getBit(AFILE, sq-7)) attacks = setBit(attacks, sq-7);
        if(!getBit(HFILE, sq-9)) attacks = setBit(attacks, sq-9);
    }else {
        if(!getBit(HFILE, sq+7)) attacks = setBit(attacks, sq+7);
        if(!getBit(AFILE, sq+9)) attacks = setBit(attacks, sq+9);
    }
    return attacks;
}

void printBB(ULL bb) {
    for(int x = 0; x < 8; x++) {
        for(int y = 0; y < 8; y++) {
            int sq = x*8+y;
//          if getBit == 0 there is no bit found on that sq else there is
            if(getBit(bb, sq) != 0) {
                cout << "X ";
            }else {
                cout << "- ";
            }
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "bb(ull): " << bb << "ULL\n";
}

int main() {
//    cout << (0 <= -1);
//    sq 52 = e2
    printBB(getKnight(52));
    return 0;
}
