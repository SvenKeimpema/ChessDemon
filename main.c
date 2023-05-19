#include <stdio.h>

#define ULL unsigned long long
#define getBit(bb, sq) (bb & (1ULL << sq))
#define setBit(bb, sq) (bb | (1ULL << sq))

#define AFILE 72340172838076673ULL
#define ABFILE 217020518514230019ULL
#define HFILE 9259542123273814144ULL
#define GHFILE 13889313184910721216ULL

ULL get_rook(int sq) {
    ULL attacks = 0ULL;

    int rank = sq / 8;
    int file = sq % 8;

    for(int r = rank+1; r < 7; r++) {
        attacks = setBit(attacks, r*8+file);
    }
    for(int r = rank-1; r > 0; r--) {
        attacks = setBit(attacks, r*8+file);
    }
    for(int f = file+1; f < 7; f++) {
        attacks = setBit(attacks, rank*8+f);
    }
    for(int f = file-1; f > 0; f--) {
        attacks = setBit(attacks, rank*8+f);
    }
    return attacks;
}

ULL get_bishop(int sq) {
    ULL attacks = 0ULL;

    int rank = sq / 8;
    int file = sq % 8;

    for(int r = rank+1, f = file+1; r < 7 && f < 7; r++, f++) {
        attacks = setBit(attacks, r*8+f);
    }
    for(int r = rank+1, f = file-1; r < 7 && f > 0; r++, f--) {
        attacks = setBit(attacks, r*8+f);
    }
    for(int r = rank-1, f = file+1; r > 0 && f < 7; r--, f++) {
        attacks = setBit(attacks, r*8+f);
    }
    for(int r = rank-1, f = file-1; r > 0 && f > 0; r--, f--) {
        attacks = setBit(attacks, r*8+f);
    }

    return attacks;
}


ULL get_knight(int sq) {
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

ULL get_pawn(int sq, int side) {
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

void print_bb(ULL bb) {
    for(int x = 0; x < 8; x++) {
        for(int y = 0; y < 8; y++) {
            int sq = x*8+y;
//          if getBit == 0 there is no bit found on that sq else there is
            if(getBit(bb, sq) != 0) {
                printf("X ");
            }else {
                printf("- ");
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("bb(ull): %lld ULL\n", bb);
}

int main() {
//    printf((0 <= -1);
//    sq 52 = e2
    print_bb(get_rook(52));
    return 0;
}
