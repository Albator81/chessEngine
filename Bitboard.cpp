#include <iostream>
#include <string>
#include <array>
#include <cmath>
#include "Bitboard.h"


// Other Bitboards
const U64 Bitboard::emptyBitboard = 0ULL;
const U64 Bitboard::universalBitboard = 0b1111111111111111111111111111111111111111111111111111111111111111;

const U64 Bitboard::notAFile = 0b1111111011111110111111101111111011111110111111101111111011111110;
const U64 Bitboard::notHFile = 0b0111111101111111011111110111111101111111011111110111111101111111;
const U64 Bitboard::fileA = 0x0101010101010101;
const U64 Bitboard::fileB = 0x0202020202020202;
const U64 Bitboard::fileC = 0x0404040404040404;
const U64 Bitboard::fileD = 0x0808080808080808;
const U64 Bitboard::fileE = 0x1010101010101010;
const U64 Bitboard::fileF = 0x2020202020202020;
const U64 Bitboard::fileG = 0x4040404040404040;
const U64 Bitboard::fileH = 0x8080808080808080;

const U64 Bitboard::rank1 = 0x00000000000000FF;
const U64 Bitboard::rank2 = 0x000000000000FF00;
const U64 Bitboard::rank3 = 0x0000000000FF0000;
const U64 Bitboard::rank4 = 0x00000000FF000000;
const U64 Bitboard::rank5 = 0x000000FF00000000;
const U64 Bitboard::rank6 = 0x0000FF0000000000;
const U64 Bitboard::rank7 = 0x00FF000000000000;
const U64 Bitboard::rank8 = 0xFF00000000000000;

const std::array<U64, 8> Bitboard::ranks = { rank1, rank2, rank3, rank4, rank5, rank6, rank7, rank8 };
const std::array<U64, 8> Bitboard::files = { fileA, fileB, fileC, fileD, fileE, fileF, fileG, fileH };

const U64 Bitboard::diag0 = 0b1000000001000000001000000001000000001000000001000000001000000001;
const U64 Bitboard::diag1 = 0b0100000000100000000100000000100000000100000000100000000100000000;
const U64 Bitboard::diag2 = 0b0010000000010000000010000000010000000010000000010000000000000000;
const U64 Bitboard::diag3 = 0b0001000000001000000001000000001000000001000000000000000000000000;
const U64 Bitboard::diag4 = 0b0000100000000100000000100000000100000000000000000000000000000000;
const U64 Bitboard::diag5 = 0b0000010000000010000000010000000000000000000000000000000000000000;
const U64 Bitboard::diag6 = 0b0000001000000001000000000000000000000000000000000000000000000000;
const U64 Bitboard::diag7 = 0b0000000100000000000000000000000000000000000000000000000000000000;
const U64 Bitboard::diag9 = 0b0000000000000000000000000000000000000000000000000000000010000000;
const U64 Bitboard::diag10 = 0b0000000000000000000000000000000000000000000000001000000001000000;
const U64 Bitboard::diag11 = 0b0000000000000000000000000000000000000000100000000100000000100000;
const U64 Bitboard::diag12 = 0b0000000000000000000000000000000010000000010000000010000000010000;
const U64 Bitboard::diag13 = 0b0000000000000000000000001000000001000000001000000001000000001000;
const U64 Bitboard::diag14 = 0b0000000000000000100000000100000000100000000100000000100000000100;
const U64 Bitboard::diag15 = 0b0000000010000000010000000010000000010000000010000000010000000010;

const std::array<U64, 16> Bitboard::diags = { diag0, diag1, diag2, diag3, diag4, diag5, diag6, diag7, emptyBitboard, diag9, diag10, diag11, diag12, diag13, diag14, diag15 };


const U64 Bitboard::antiDiag0 = 0b0000000100000010000001000000100000010000001000000100000010000000;
const U64 Bitboard::antiDiag1 = 0b0000000000000001000000100000010000001000000100000010000001000000;
const U64 Bitboard::antiDiag2 = 0b0000000000000000000000010000001000000100000010000001000000100000;
const U64 Bitboard::antiDiag3 = 0b0000000000000000000000000000000100000010000001000000100000010000;
const U64 Bitboard::antiDiag4 = 0b0000000000000000000000000000000000000001000000100000010000001000;
const U64 Bitboard::antiDiag5 = 0b0000000000000000000000000000000000000000000000010000001000000100;
const U64 Bitboard::antiDiag6 = 0b0000000000000000000000000000000000000000000000000000000100000010;
const U64 Bitboard::antiDiag7 = 0b0000000000000000000000000000000000000000000000000000000000000001;
const U64 Bitboard::antiDiag9 = 0b1000000000000000000000000000000000000000000000000000000000000000;
const U64 Bitboard::antiDiag10 = 0b0100000010000000000000000000000000000000000000000000000000000000;
const U64 Bitboard::antiDiag11 = 0b0010000001000000100000000000000000000000000000000000000000000000;
const U64 Bitboard::antiDiag12 = 0b0001000000100000010000001000000000000000000000000000000000000000;
const U64 Bitboard::antiDiag13 = 0b0000100000010000001000000100000010000000000000000000000000000000;
const U64 Bitboard::antiDiag14 = 0b0000010000001000000100000010000001000000100000000000000000000000;
const U64 Bitboard::antiDiag15 = 0b0000001000000100000010000001000000100000010000001000000000000000;

const std::array<U64, 16> Bitboard::antiDiags = { antiDiag0, antiDiag1, antiDiag2, antiDiag3, antiDiag4, antiDiag5, antiDiag6, antiDiag7, emptyBitboard, antiDiag9, antiDiag10, antiDiag11, antiDiag12, antiDiag13, antiDiag14, antiDiag15 };


Board_Bitboards::Board_Bitboards(std::array<U64, 6> wPNBRQK, std::array<U64, 6> bPNBRQK, Turn turn) {
    for (int i = 0; i < 6; ++i) {
        aWhite[i] = wPNBRQK[i];
        aBlack[i] = bPNBRQK[i];
    }


    whiteBb = wPNBRQK[PAWN] | wPNBRQK[KNIGHT] | wPNBRQK[BISHOP] | wPNBRQK[ROOK] | wPNBRQK[QUEEN] | wPNBRQK[KING];
    blackBb = bPNBRQK[PAWN] | bPNBRQK[KNIGHT] | bPNBRQK[BISHOP] | bPNBRQK[ROOK] | bPNBRQK[QUEEN] | bPNBRQK[KING];


    turn = turn;

    occupied = whiteBb | blackBb;
    empty = ~occupied;
}



Board_Bitboards::~Board_Bitboards()
{
}


SquareIndex Bitboard::fileRankIndexToSquareIndex(FileIndex file, RankIndex rank) {
    return 8 * rank + file;
}

FileIndex Bitboard::squareIndexToFileIndex(SquareIndex square) {
    return square & 7;
}

RankIndex Bitboard::squareIndexToRankIndex(SquareIndex square) {
    return square >> 3;
}

DiagIndex Bitboard::squareIndexToDiagIndex(SquareIndex square) {
    return (squareIndexToRankIndex(square) - squareIndexToFileIndex(square)) & 15;
}

DiagIndex Bitboard::squareIndexToAntiDiagIndex(SquareIndex square) {
    return (squareIndexToRankIndex(square) + squareIndexToFileIndex(square)) ^ 7;
}


void Bitboard::clearBitboard(U64& bitboard) {
    bitboard ^= bitboard;
}

void Bitboard::setBitTo1(U64 &bitboard, SquareIndex square) {
    bitboard |=  squareIndexToBitboard(square);
}

Bit Bitboard::getBitValue(U64 bitboard, SquareIndex square) {
    return (bitboard >> square) & 1;
}

U64 Bitboard::squareIndexToBitboard(SquareIndex square) {
    return 1ULL << square;
}


#pragma warning(disable : 4146) // because the compiler thinks -(some unsigned int) is an error, which should only be a warning
U64 Bitboard::getIsolatedLeastSignificantSetBit(U64 bitboard) {
    return bitboard & -bitboard;

}
U64 Bitboard::getIsolatedMostSignificantSetBit(U64 x)
{
    if (!x) { return emptyBitboard; }

    x |= x >> 32;
    x |= x >> 16;
    x |= x >> 8;
    x |= x >> 4;
    x |= x >> 2;
    x |= x >> 1;
    return (x >> 1) + 1;

}

SquareIndex Bitboard::getIndexOfLeastSignificantSetBit(U64 bitboard) {
    if (!bitboard) { return -1; }
    int index = 0;
    while ((bitboard & 1) == 0) {
        bitboard >>= 1;
        index++;
    }
    return index;
}

void Bitboard::resetIsolatedLeastSignificantSetBit(U64& bitboard) {
    bitboard &= (bitboard - 1);
}
void Bitboard::resetIsolatedMostSignificantSetBit(U64& v) {
    U64 x = v;

    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v |= v >> 32;
    v = (v >> 1) & x;
}


int Bitboard::bitCount(U64 bb)
{
    if (!bb) { return 0; }
    int count = 0;
    for (SquareIndex index = 0; index < 64; index++) {
        if (bb >> index & 1) { count += 1; }
    }
    return count;
}


std::array<U64, 6> Board_Bitboards::playingPieces() {
    return this->turn == WHITETURN ? this->whiteBb : this->blackBb;
}

std::array<U64, 6> Board_Bitboards::waitingPieces() {
    return this->turn == BLACKTURN ? this->whiteBb : this->blackBb;
}

// Rotations

U64 Board_Bitboards::flipVertical(U64 bitboard) {
    return  ((bitboard << 56)) |
        ((bitboard << 40) & Bitboard::rank7) |
        ((bitboard << 24) & Bitboard::rank6) |
        ((bitboard << 8)  & Bitboard::rank5) |
        ((bitboard >> 8)  & Bitboard::rank4) |
        ((bitboard >> 24) & Bitboard::rank3) |
        ((bitboard >> 40) & Bitboard::rank2) |
        ((bitboard >> 56));
}
U64 Board_Bitboards::flipDiagA1H8(U64 x) {
    U64 t;
    const U64 k1 = 0x5500550055005500;
    const U64 k2 = 0x3333000033330000;
    const U64 k4 = 0x0f0f0f0f00000000;
    t = k4 & (x ^ (x << 28));
    x ^= t ^ (t >> 28);
    t = k2 & (x ^ (x << 14));
    x ^= t ^ (t >> 14);
    t = k1 & (x ^ (x << 7));
    x ^= t ^ (t >> 7);
    return x;
}

U64 Board_Bitboards::rotationClockWise90(U64 bitboard) {
    return this->flipVertical(flipDiagA1H8(bitboard));
}
U64 Board_Bitboards::rotationAntiClockWise90(U64 bitboard)
{
    return this->flipDiagA1H8(flipVertical(bitboard));
}
U64 Board_Bitboards::rotation180(U64 bitboard) {
    return this->rotationClockWise90(this->rotationClockWise90(bitboard));
}

// Print board

void Bitboard::visualizeBitboard(U64 bitboard) {
    std::string rankString = "";
    for (RankIndex rank = 0; rank < 8; rank++) {
        rankString.clear();
        for (FileIndex file = 0; file < 8; file++) {
            rankString += bitboard >> fileRankIndexToSquareIndex(file, 7 - rank) & 1 ? '1' : '.';
            rankString += ' ';
        }
        std::cout << rankString << '\n';
    }
    std::cout << std::endl;
}

U64 Board_Bitboards::southOne    (U64 bitboard) { return  bitboard >> 8; }
U64 Board_Bitboards::northOne    (U64 bitboard) { return  bitboard << 8; }
U64 Board_Bitboards::eastOne     (U64 bitboard) { return (bitboard & Bitboard::notHFile) << 1; }
U64 Board_Bitboards::northEastOne(U64 bitboard) { return (bitboard & Bitboard::notHFile) << 9; }
U64 Board_Bitboards::southEastOne(U64 bitboard) { return (bitboard & Bitboard::notHFile) >> 7; }
U64 Board_Bitboards::westOne     (U64 bitboard) { return (bitboard & Bitboard::notAFile) >> 1; }
U64 Board_Bitboards::southWestOne(U64 bitboard) { return (bitboard & Bitboard::notAFile) >> 9; }
U64 Board_Bitboards::northWestOne(U64 bitboard) { return (bitboard & Bitboard::notAFile) << 7; }

U64 Board_Bitboards::getUKnightMovesBitboard(SquareIndex square) {
    U64 movesBitboard = Bitboard::emptyBitboard;
    U64 posBitboard   = Bitboard::squareIndexToBitboard(square);
    U64 partialMove;
    
    partialMove    = westOne(posBitboard);
    movesBitboard |= northWestOne(partialMove) | southWestOne(partialMove);
    
    partialMove    = eastOne(posBitboard);
    movesBitboard |= northEastOne(partialMove) | southEastOne(partialMove);
    
    movesBitboard |= ((posBitboard >> 17) & Bitboard::notAFile) | ((posBitboard >> 15) & Bitboard::notAFile) | 
                     ((posBitboard << 17) & Bitboard::notHFile) | ((posBitboard << 15) & Bitboard::notHFile);

    return movesBitboard;
}
U64 Board_Bitboards::getUKnightsMovesBitboard(U64 bitboard) {
    if (!bitboard) { return bitboard; }

    U64 movesBitboard = Bitboard::emptyBitboard;
    U64 partialMove;

    partialMove       = westOne(bitboard);
    movesBitboard    |= northWestOne(partialMove) | southWestOne(partialMove);
    
    partialMove       = eastOne(bitboard);
    movesBitboard    |= northEastOne(partialMove) | southEastOne(partialMove);
    
    movesBitboard    |= ((bitboard >> 17) & Bitboard::notAFile) | ((bitboard >> 15) & Bitboard::notAFile) | 
                        ((bitboard << 17) & Bitboard::notHFile) | ((bitboard << 15) & Bitboard::notHFile);

    return movesBitboard;
}

U64 Board_Bitboards::getUKingMovesBitboard(SquareIndex square) {
    U64 movesBitboard = Bitboard::emptyBitboard;
    U64 posBitboard   = Bitboard::squareIndexToBitboard(square);
    
    movesBitboard |= westOne(posBitboard)  | eastOne(posBitboard);
    posBitboard   |= movesBitboard;
    movesBitboard |= northOne(posBitboard) | southOne(posBitboard);
    
    return movesBitboard;
}
U64 Board_Bitboards::getUKingsMovesBitboard(U64 bitboard) {
    U64 movesBitboard = Bitboard::emptyBitboard;
    
    movesBitboard    |= westOne(bitboard)  | eastOne(bitboard);
    bitboard         |= movesBitboard;
    movesBitboard    |= northOne(bitboard) | southOne(bitboard);

    return movesBitboard;
}
 
U64 Board_Bitboards::getURookMovesBitboard(SquareIndex square) {
    if (square > 64) { return Bitboard::universalBitboard; }

    U64 horizontal = Bitboard::ranks[Bitboard::squareIndexToRankIndex(square)]; // horizontal
    U64 vertical   = Bitboard::files[Bitboard::squareIndexToFileIndex(square)]; // vertical

    return (horizontal | vertical);
}
U64 Board_Bitboards::getURooksMovesBitboard(U64 bitboard) {
    if (!bitboard) { return bitboard; }

    U64 movesBitboard  = Bitboard::emptyBitboard;
    SquareIndex square;

    while (bitboard) {
        square         = Bitboard::getIndexOfLeastSignificantSetBit(bitboard);
        movesBitboard |= getURookMovesBitboard(square);
        Bitboard::resetIsolatedLeastSignificantSetBit(bitboard);
    }

    return movesBitboard;
}

U64 Board_Bitboards::uBishopTopRightRay(SquareIndex square) {
    U64       ray  = Bitboard::emptyBitboard;
    FileIndex file = Bitboard::squareIndexToFileIndex(square) + 1;
    RankIndex rank = Bitboard::squareIndexToRankIndex(square) + 1;

    while (8 > file && file >= 0 && 8 > rank && rank >= 0) {
        ray |= Bitboard::squareIndexToBitboard(Bitboard::fileRankIndexToSquareIndex(file, rank));
        rank++; file++;
    }
    return ray;
}
U64 Board_Bitboards::uBishopTopLeftRay(SquareIndex square) {
    U64       ray  = Bitboard::emptyBitboard;
    FileIndex file = Bitboard::squareIndexToFileIndex(square) - 1;
    RankIndex rank = Bitboard::squareIndexToRankIndex(square) + 1;

    while (8 > file && file >= 0 && 8 > rank && rank >= 0) {
        ray |= Bitboard::squareIndexToBitboard(Bitboard::fileRankIndexToSquareIndex(file, rank));
        rank++; file--;
    }
    return ray;
}
U64 Board_Bitboards::uBishopBottomRightRay(SquareIndex square) {
    U64       ray  = Bitboard::emptyBitboard;
    FileIndex file = Bitboard::squareIndexToFileIndex(square) + 1;
    RankIndex rank = Bitboard::squareIndexToRankIndex(square) - 1;

    while (8 > file && file >= 0 && 8 > rank && rank >= 0) {
        ray |= Bitboard::squareIndexToBitboard(Bitboard::fileRankIndexToSquareIndex(file, rank));
        rank--; file++;
    }
    return ray;
}
U64 Board_Bitboards::uBishopBottomLeftRay(SquareIndex square) {
    U64       ray  = Bitboard::emptyBitboard;
    FileIndex file = Bitboard::squareIndexToFileIndex(square) - 1;
    RankIndex rank = Bitboard::squareIndexToRankIndex(square) - 1;

    while (8 > file && file >= 0 && 8 > rank && rank >= 0) {
        ray |= Bitboard::squareIndexToBitboard(Bitboard::fileRankIndexToSquareIndex(file, rank));
        rank--; file--;
    }
    return ray;
}
U64 Board_Bitboards::getUBishopMovesBitboard(SquareIndex square) {
    U64 diag     = Bitboard::diags[Bitboard::squareIndexToDiagIndex(square)];
    U64 antiDiag = Bitboard::antiDiags[Bitboard::squareIndexToAntiDiagIndex(square)];

    return (diag | antiDiag);
}
U64 Board_Bitboards::getUBishopsMovesBitboard(U64 bb) {
    U64         movesBb = Bitboard::emptyBitboard;
    U64         diag;
    U64         antiDiag;
    SquareIndex square;
    while (bb) {
        square   = Bitboard::getIndexOfLeastSignificantSetBit(bb);
        diag     = Bitboard::diags[Bitboard::squareIndexToDiagIndex(square)];
        antiDiag = Bitboard::antiDiags[Bitboard::squareIndexToAntiDiagIndex(square)];
        movesBb |= diag | antiDiag;
        
        Bitboard::resetIsolatedLeastSignificantSetBit(bb);
    }
    return movesBb;
}

U64 Board_Bitboards::getUQueenMovesBitboard(SquareIndex square) {
    return getURookMovesBitboard(square) | getUBishopMovesBitboard(square);
}

U64 Board_Bitboards::getUPawnMovesBitboard(SquareIndex square, bool hasMoved, bool isWhite) {
    U64 movesBitboard = emptyBitboard;
    int direction = isWhite ? 1 : -1;

    //not checking if the pawn's movesBitboard outside of range // nvm it's useless

    Board_Bitboards::setBitTo1(movesBitboard, square + 8 * direction);
    if (!hasMoved) {
        Board_Bitboards::setBitTo1(movesBitboard, square + 16 * direction);
    }
    return movesBitboard;
}

U64 Board_Bitboards::getUPawnsMovesBitboard(U64 bb, bool hasMoved, bool isWhite)
{
    U64 movesBb;

    if (isWhite) { movesBb = northEastOne(bb) | northWestOne(bb); if (!hasMoved) { movesBb = northOne(bb); } } 
    else { movesBb = southEastOne(bb) | southWestOne(bb); if (!hasMoved) { movesBb = southOne(bb); } }
    
    return movesBb;
}

// important
bool Board_Bitboards::isLegal(U64 startingSquareBb, U64 moveBitboard, U64 ownKingSquareBb, bool isWhite, std::array<U64, 5> opponentsPawnKnightBishopRookQueenBitboards) {
    U64 pawn, knight, bishop, rook, queen;
    pawn   = opponentsPawnKnightBishopRookQueenBitboards[0];
    knight = opponentsPawnKnightBishopRookQueenBitboards[1];
    bishop = opponentsPawnKnightBishopRookQueenBitboards[2];
    rook   = opponentsPawnKnightBishopRookQueenBitboards[3];
    queen  = opponentsPawnKnightBishopRookQueenBitboards[4];

    U64 pAttack, kAttack, bAttack, rAttack, qAttack;
    
    pAttack = isWhite ? northEastOne(pawn) | northWestOne(pawn) : southEastOne(pawn) | southWestOne(pawn);
    kAttack = getUKnightsMovesBitboard(knight);
    bAttack = getUBishopsMovesBitboard(bishop);
    rAttack = getURooksMovesBitboard(rook);

    
    return isInCheck(ownKingSquareBb, );
}

U64 Board_Bitboards::getLegalMoves(U64 square, U64 movesBitboard, U64 ownKingSquareBb, bool isWhite, std::array<U64, 5> opponentsPawnKnightBishopRookQueenBitboards) {
    U64 legalMovesBitboard = emptyBitboard;
    U64 moveBitboard;

    while (movesBitboard) {
        moveBitboard = getIsolatedLeastSignificantSetBit(movesBitboard);

        if (isLegal(square, moveBitboard, ownKingSquareBb, isWhite, opponentsPawnKnightBishopRookQueenBitboards)) { legalMovesBitboard |= moveBitboard; }

        resetIsolatedLeastSignificantSetBit(movesBitboard);
    }
    return legalMovesBitboard;
}

bool Board_Bitboards::isInCheck() {

    return bool(this->opponentPieces & ownKingBb);
}

// you can abandon this function
bool Board_Bitboards::isPinned(U64 ownKingBb, U64 pieceBb, bool isWhite, U64 whiteBb, U64 blackBb, U64 bishopsBb, U64 rookBb, U64 queenBb)
{
    //bishop
    SquareIndex bishopIndex;
    U64 bishopAttack;
    while (bishopsBb) {
        bishopIndex = Bitboard::getIndexOfLeastSignificantSetBit(bishopsBb);
        bishopAttack = getBishopMovesBitboard(bishopIndex, !isWhite, whiteBb, blackBb);
        if (bishopAttack & pieceBb) { // piece is in the path of ray attack
            if (!(bishopAttack & ownKingBb)) { // king isn't already in the path of ray attack
                if (isWhite) { bishopAttack = getBishopMovesBitboard(bishopIndex, false, whiteBb ^ pieceBb, blackBb); }
                else { bishopAttack = getBishopMovesBitboard(bishopIndex, true, whiteBb, blackBb ^ pieceBb); }
                
                if (bishopAttack & ownKingBb) { return true; }
            }
        }

        Bitboard::resetIsolatedLeastSignificantSetBit(bishopsBb);
    }

    return false;
}


// legal moves

U64 Board_Bitboards::getKnightMovesBitboard(SquareIndex square) {
    U64 movesBitboard = getUKnightMovesBitboard(square);

    movesBitboard ^= this->turn == WHITETURN ? this->whiteBb : this->blackBb;

    return movesBitboard;


}

U64 Board_Bitboards::bishopTopRightRay(SquareIndex square) {
    U64 ray            = uBishopTopRightRay(square);
    U64 resultRay      = Bitboard::emptyBitboard;
    U64 LSB            = Bitboard::getIsolatedLeastSignificantSetBit(ray);
    U64 ownPieces      = this->turn == WHITETURN ? this->whiteBb : this->blackBb;
    U64 opponentPieces = this->turn == WHITETURN ? this->blackBb : this->whiteBb;

    while (LSB & ~ownPieces) {
        resultRay |= LSB;
        if (LSB & opponentPieces) { break; } // condition not working | fixed, this line was not supposed to be the last line in the loop

        Bitboard::resetIsolatedLeastSignificantSetBit(ray);
        LSB = Bitboard::getIsolatedLeastSignificantSetBit(ray);
    }

    return resultRay;
}
U64 Board_Bitboards::bishopTopLeftRay(SquareIndex square) {
    U64 ray            = uBishopTopLeftRay(square);
    U64 resultRay      = Bitboard::emptyBitboard;
    U64 LSB            = Bitboard::getIsolatedLeastSignificantSetBit(ray);
    U64 ownPieces      = this->turn == WHITETURN ? this->whiteBb : this->blackBb;
    U64 opponentPieces = this->turn == WHITETURN ? this->blackBb : this->whiteBb;

    while (LSB & ~ownPieces) {
        resultRay |= LSB;
        if (LSB & opponentPieces) { break; }

        Bitboard::resetIsolatedLeastSignificantSetBit(ray);
        LSB = Bitboard::getIsolatedLeastSignificantSetBit(ray);
    }

    return resultRay;
}
U64 Board_Bitboards::bishopBottomRightRay(SquareIndex square) {
    U64 ray            = uBishopBottomRightRay(square);
    U64 resultRay      = Bitboard::emptyBitboard;
    U64 MSB            = Bitboard::getIsolatedMostSignificantSetBit(ray);
    U64 ownPieces      = this->turn == WHITETURN ? this->whiteBb : this->blackBb;
    U64 opponentPieces = this->turn == WHITETURN ? this->blackBb : this->whiteBb;

    while (MSB & ~ownPieces) {
        resultRay |= MSB;
        if (MSB & opponentPieces) { break; }

        Bitboard::resetIsolatedMostSignificantSetBit(ray);
        MSB = Bitboard::getIsolatedMostSignificantSetBit(ray);
    }

    return resultRay;
}
U64 Board_Bitboards::bishopBottomLeftRay(SquareIndex square) {
    U64 ray            = uBishopBottomLeftRay(square);
    U64 resultRay      = Bitboard::emptyBitboard;
    U64 MSB            = Bitboard::getIsolatedMostSignificantSetBit(ray);
    U64 ownPieces      = this->turn == WHITETURN ? this->whiteBb : this->blackBb;
    U64 opponentPieces = this->turn == WHITETURN ? this->blackBb : this->whiteBb;

    while (MSB & ~ownPieces) {
        resultRay |= MSB;
        if (MSB & opponentPieces) { break; }

        Bitboard::resetIsolatedMostSignificantSetBit(ray);
        MSB = Bitboard::getIsolatedMostSignificantSetBit(ray);
    }

    return resultRay;
}

U64 Board_Bitboards::getBishopMovesBitboard(SquareIndex square)
{
    U64 rayTR, rayTL, rayBR, rayBL;
    rayTR = bishopTopRightRay   (square);
    rayTL = bishopTopLeftRay    (square);
    rayBR = bishopBottomRightRay(square);
    rayBL = bishopBottomLeftRay (square);

    return rayTR | rayTL | rayBR | rayBL;
}
