#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>


#define ULL unsigned long long
#define getBit(bb, sq) (bb & (1ULL << sq))
#define setBit(bb, sq) (bb |= (1ULL << sq))
#define clearBit(bb, sq) (getBit(bb, sq) ? bb ^= (1ULL << sq) : bb)

#define AFILE 72340172838076673ULL
#define ABFILE 217020518514230019ULL
#define HFILE 9259542123273814144ULL
#define GHFILE 13889313184910721216ULL

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

enum {
    a8, b8, c8, d8, e8, f8, g8, h8,
    a7, b7, c7, d7, e7, f7, g7, h7,
    a6, b6, c6, d6, e6, f6, g6, h6,
    a5, b5, c5, d5, e5, f5, g5, h5,
    a4, b4, c4, d4, e4, f4, g4, h4,
    a3, b3, c3, d3, e3, f3, g3, h3,
    a2, b2, c2, d2, e2, f2, g2, h2,
    a1, b1, c1, d1, e1, f1, g1, h1
};

ULL rook_magic_numbers[64] = {
        0x8a80104000800020ULL,
        0x140002000100040ULL,
        0x2801880a0017001ULL,
        0x100081001000420ULL,
        0x200020010080420ULL,
        0x3001c0002010008ULL,
        0x8480008002000100ULL,
        0x2080088004402900ULL,
        0x800098204000ULL,
        0x2024401000200040ULL,
        0x100802000801000ULL,
        0x120800800801000ULL,
        0x208808088000400ULL,
        0x2802200800400ULL,
        0x2200800100020080ULL,
        0x801000060821100ULL,
        0x80044006422000ULL,
        0x100808020004000ULL,
        0x12108a0010204200ULL,
        0x140848010000802ULL,
        0x481828014002800ULL,
        0x8094004002004100ULL,
        0x4010040010010802ULL,
        0x20008806104ULL,
        0x100400080208000ULL,
        0x2040002120081000ULL,
        0x21200680100081ULL,
        0x20100080080080ULL,
        0x2000a00200410ULL,
        0x20080800400ULL,
        0x80088400100102ULL,
        0x80004600042881ULL,
        0x4040008040800020ULL,
        0x440003000200801ULL,
        0x4200011004500ULL,
        0x188020010100100ULL,
        0x14800401802800ULL,
        0x2080040080800200ULL,
        0x124080204001001ULL,
        0x200046502000484ULL,
        0x480400080088020ULL,
        0x1000422010034000ULL,
        0x30200100110040ULL,
        0x100021010009ULL,
        0x2002080100110004ULL,
        0x202008004008002ULL,
        0x20020004010100ULL,
        0x2048440040820001ULL,
        0x101002200408200ULL,
        0x40802000401080ULL,
        0x4008142004410100ULL,
        0x2060820c0120200ULL,
        0x1001004080100ULL,
        0x20c020080040080ULL,
        0x2935610830022400ULL,
        0x44440041009200ULL,
        0x280001040802101ULL,
        0x2100190040002085ULL,
        0x80c0084100102001ULL,
        0x4024081001000421ULL,
        0x20030a0244872ULL,
        0x12001008414402ULL,
        0x2006104900a0804ULL,
        0x1004081002402ULL
};

ULL bishop_magic_numbers[64] = {
        0x40040844404084ULL,
        0x2004208a004208ULL,
        0x10190041080202ULL,
        0x108060845042010ULL,
        0x581104180800210ULL,
        0x2112080446200010ULL,
        0x1080820820060210ULL,
        0x3c0808410220200ULL,
        0x4050404440404ULL,
        0x21001420088ULL,
        0x24d0080801082102ULL,
        0x1020a0a020400ULL,
        0x40308200402ULL,
        0x4011002100800ULL,
        0x401484104104005ULL,
        0x801010402020200ULL,
        0x400210c3880100ULL,
        0x404022024108200ULL,
        0x810018200204102ULL,
        0x4002801a02003ULL,
        0x85040820080400ULL,
        0x810102c808880400ULL,
        0xe900410884800ULL,
        0x8002020480840102ULL,
        0x220200865090201ULL,
        0x2010100a02021202ULL,
        0x152048408022401ULL,
        0x20080002081110ULL,
        0x4001001021004000ULL,
        0x800040400a011002ULL,
        0xe4004081011002ULL,
        0x1c004001012080ULL,
        0x8004200962a00220ULL,
        0x8422100208500202ULL,
        0x2000402200300c08ULL,
        0x8646020080080080ULL,
        0x80020a0200100808ULL,
        0x2010004880111000ULL,
        0x623000a080011400ULL,
        0x42008c0340209202ULL,
        0x209188240001000ULL,
        0x400408a884001800ULL,
        0x110400a6080400ULL,
        0x1840060a44020800ULL,
        0x90080104000041ULL,
        0x201011000808101ULL,
        0x1a2208080504f080ULL,
        0x8012020600211212ULL,
        0x500861011240000ULL,
        0x180806108200800ULL,
        0x4000020e01040044ULL,
        0x300000261044000aULL,
        0x802241102020002ULL,
        0x20906061210001ULL,
        0x5a84841004010310ULL,
        0x4010801011c04ULL,
        0xa010109502200ULL,
        0x4a02012000ULL,
        0x500201010098b028ULL,
        0x8040002811040900ULL,
        0x28000010020204ULL,
        0x6000020202d0240ULL,
        0x8918844842082200ULL,
        0x4010011029020020ULL
};

const int bishop_relevant_bits[64] = {
        6, 5, 5, 5, 5, 5, 5, 6,
        5, 5, 5, 5, 5, 5, 5, 5,
        5, 5, 7, 7, 7, 7, 5, 5,
        5, 5, 7, 9, 9, 7, 5, 5,
        5, 5, 7, 9, 9, 7, 5, 5,
        5, 5, 7, 7, 7, 7, 5, 5,
        5, 5, 5, 5, 5, 5, 5, 5,
        6, 5, 5, 5, 5, 5, 5, 6
};

const int rook_relevant_bits[64] = {
        12, 11, 11, 11, 11, 11, 11, 12,
        11, 10, 10, 10, 10, 10, 10, 11,
        11, 10, 10, 10, 10, 10, 10, 11,
        11, 10, 10, 10, 10, 10, 10, 11,
        11, 10, 10, 10, 10, 10, 10, 11,
        11, 10, 10, 10, 10, 10, 10, 11,
        11, 10, 10, 10, 10, 10, 10, 11,
        12, 11, 11, 11, 11, 11, 11, 12
};

ULL rookMasks[64];
ULL bishopMasks[64];
ULL bishopAttacks[64][512];
ULL rookAttacks[64][4096];

ULL get_random_u64() {
    srand(time(NULL));

    return ((ULL)rand() << 32) | rand();
}

int get_ls1b(ULL bb) {
    return __builtin_ctzll(bb);
}

int get_bit_count(ULL bb) {
    return __builtin_popcountll(bb);
}

void convertToBinary(int n) {
    if (n / 2 != 0) {
        convertToBinary(n / 2);
    }
}

ULL set_occupancy(int index, int bits_in_mask, ULL attack_mask) {
    ULL occupancy = 0ULL;
    for (int count = 0; count < bits_in_mask; count++) {
        int square = get_ls1b(attack_mask);
        clearBit(attack_mask, square);

        if (index & (1 << count)) {
            occupancy |= (1ULL << square);
        }
    }
    return occupancy;
}


ULL get_full_rook(int sq, ULL occ) {
    ULL attacks = 0ULL;

    int rank = sq / 8;
    int file = sq % 8;


    for(int r = rank+1; r <= 7; r++) {
        setBit(attacks, r*8+file);
        if(getBit(occ, r*8+file)) break;
    }
    for(int r = rank-1; r >= 0; r--) {
        setBit(attacks, r*8+file);
        if(getBit(occ, r*8+file)) break;
    }
    for(int f = file+1; f <= 7; f++) {
        setBit(attacks, rank*8+f);
        if(getBit(occ, rank*8+f)) break;
    }
    for(int f = file-1; f >= 0; f--) {
        setBit(attacks, rank*8+f);
        if(getBit(occ, rank*8+f)) break;
    }
    return attacks;
}

ULL get_full_bishop(int sq, ULL occ) {
    ULL attacks = 0ULL;

    int rank = sq / 8;
    int file = sq % 8;

    for(int r = rank+1, f = file+1; r <= 7 && f <= 7; r++, f++) {
        setBit(attacks, r*8+f);
        if(getBit(occ, r*8+f)) break;
    }
    for(int r = rank+1, f = file-1; r <= 7 && f >= 0; r++, f--) {
        setBit(attacks, r*8+f);
        if(getBit(occ, r*8+f)) break;
    }
    for(int r = rank-1, f = file+1; r >= 0 && f <= 7; r--, f++) {
        setBit(attacks, r*8+f);
        if(getBit(occ, r*8+f)) break;
    }
    for(int r = rank-1, f = file-1; r >= 0 && f >= 0; r--, f--) {
        setBit(attacks, r*8+f);
        if(getBit(occ, r*8+f)) break;
    }

    return attacks;
}


ULL get_rook_mask(int sq) {
    ULL attacks = 0ULL;

    int rank = sq / 8;
    int file = sq % 8;


    for(int r = rank+1; r < 7; r++) {
        setBit(attacks, r*8+file);
    }
    for(int r = rank-1; r > 0; r--) {
        setBit(attacks, r*8+file);
    }
    for(int f = file+1; f < 7; f++) {
        setBit(attacks, rank*8+f);
    }
    for(int f = file-1; f > 0; f--) {
        setBit(attacks, rank*8+f);
    }
    return attacks;
}

ULL get_bishop_mask(int sq) {
    ULL attacks = 0ULL;

    int rank = sq / 8;
    int file = sq % 8;

    for(int r = rank+1, f = file+1; r < 7 && f < 7; r++, f++) {
        setBit(attacks, r*8+f);
    }
    for(int r = rank+1, f = file-1; r < 7 && f > 0; r++, f--) {
        setBit(attacks, r*8+f);
    }
    for(int r = rank-1, f = file+1; r > 0 && f < 7; r--, f++) {
        setBit(attacks, r*8+f);
    }
    for(int r = rank-1, f = file-1; r > 0 && f > 0; r--, f--) {
        setBit(attacks, r*8+f);
    }

    return attacks;
}


ULL get_knight(int sq) {
    ULL attacks = 0ULL;

    if(!getBit(ABFILE, sq-6)) setBit(attacks, sq-6);
    if(!getBit(GHFILE, sq-10)) setBit(attacks, sq-10);
    if(!getBit(AFILE,  sq-15)) setBit(attacks, sq-15);
    if(!getBit(HFILE,  sq-17)) setBit(attacks, sq-17);

    if(!getBit(GHFILE, sq+6)) setBit(attacks, sq+6);
    if(!getBit(ABFILE, sq+10)) setBit(attacks, sq+10);
    if(!getBit(HFILE,  sq+15)) setBit(attacks, sq+15);
    if(!getBit(AFILE,  sq+17)) setBit(attacks, sq+17);

    return attacks;
}

ULL get_pawn(int sq, int side) {
    ULL attacks = 0ULL;
    if(side == 0) {
        if(!getBit(AFILE, sq-7)) setBit(attacks, sq-7);
        if(!getBit(HFILE, sq-9)) setBit(attacks, sq-9);
    }else {
        if(!getBit(HFILE, sq+7)) setBit(attacks, sq+7);
        if(!getBit(AFILE, sq+9)) setBit(attacks, sq+9);
    }
    return attacks;
}

void init_sliders_attacks(int bishop) {
    for (int square = 0; square < 64; square++) {
        ULL attack_mask = bishop ? bishopMasks[square] : rookMasks[square];
        int relevant_bits_count = get_bit_count(attack_mask);
        int occupancy_indicies = (1 << relevant_bits_count);

        for (int index = 0; index < occupancy_indicies; index++) {
            if (bishop) {
                ULL occupancy = set_occupancy(index, relevant_bits_count, attack_mask);
                int magic_index = (occupancy * bishop_magic_numbers[square]) >> (64 - bishop_relevant_bits[square]);
                bishopAttacks[square][magic_index] = get_full_bishop(square, occupancy);
            }else {
                ULL occupancy = set_occupancy(index, relevant_bits_count, attack_mask);
                int magic_index = (occupancy * rook_magic_numbers[square]) >> (64 - rook_relevant_bits[square]);
                rookAttacks[square][magic_index] = get_full_rook(square, occupancy);

            }
        }
    }
}

static inline ULL get_bishop_attacks(int square, ULL occupancy) {
    occupancy &= bishopMasks[square];
    occupancy *= bishop_magic_numbers[square];
    occupancy >>= 64 - bishop_relevant_bits[square];

    return bishopAttacks[square][occupancy];
}

static inline ULL get_rook_attacks(int square, ULL occupancy) {
    occupancy &= rookMasks[square];
    occupancy *= rook_magic_numbers[square];
    occupancy >>= 64 - rook_relevant_bits[square];

    return rookAttacks[square][occupancy];
}

void init() {
    for(int sq = 0; sq < 64; sq++) {
        bishopMasks[sq] = get_bishop_mask(sq);
        rookMasks[sq] = get_rook_mask(sq);
    }
    init_sliders_attacks(0);
    init_sliders_attacks(1);
}

int main() {
    init();
    print_bb(get_bishop_attacks(52, 1ULL << 25ULL));

    return 0;
}
