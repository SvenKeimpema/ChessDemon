#include <iostream>
using namespace std;

#define ULL unsigned long long
#define getBit(bb, sq) (bb & (1ULL << sq))
#define setBit(bb, sq) (bb | (1ULL << sq))

#define AFILE 72340172838076673ULL
#define ABFILE 217020518514230019ULL
#define HFILE 9259542123273814144ULL
#define GHFile 13889313184910721216ULL

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
//    sq 52 = e2
    printBB(getPawn(52, 0));
    return 0;
}
