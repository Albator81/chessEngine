#pragma once

typedef unsigned char RankIndex;
typedef unsigned char FileIndex;
typedef unsigned char SquareIndex;
typedef unsigned char DiagIndex;
typedef unsigned long long U64;
typedef bool Bit;
typedef bool Turn;

// tkt

const Turn WHITETURN = 1;
const Turn BLACKTURN = 0;



// Other Bitboards
namespace Bitboard {
    extern const U64 emptyBitboard;
    extern const U64 universalBitboard;

    extern const U64 notAFile;
    extern const U64 notHFile;
    extern const U64 fileA;
    extern const U64 fileB;
    extern const U64 fileC;
    extern const U64 fileD;
    extern const U64 fileE;
    extern const U64 fileF;
    extern const U64 fileG;
    extern const U64 fileH;

    extern const U64 rank1;
    extern const U64 rank2;
    extern const U64 rank3;
    extern const U64 rank4;
    extern const U64 rank5;
    extern const U64 rank6;
    extern const U64 rank7;
    extern const U64 rank8;

    extern const std::array<U64, 8> ranks;
    extern const std::array<U64, 8> files;

    extern const U64 diag0;
    extern const U64 diag1;
    extern const U64 diag2;
    extern const U64 diag3;
    extern const U64 diag4;
    extern const U64 diag5;
    extern const U64 diag6;
    extern const U64 diag7;
    extern const U64 diag8;
    extern const U64 diag9;
    extern const U64 diag10;
    extern const U64 diag11;
    extern const U64 diag12;
    extern const U64 diag13;
    extern const U64 diag14;
    extern const U64 diag15;

    extern const std::array<U64, 16> diags;

    extern const U64 antiDiag0;
    extern const U64 antiDiag1;
    extern const U64 antiDiag2;
    extern const U64 antiDiag3;
    extern const U64 antiDiag4;
    extern const U64 antiDiag5;
    extern const U64 antiDiag6;
    extern const U64 antiDiag7;
    extern const U64 antiDiag8;
    extern const U64 antiDiag9;
    extern const U64 antiDiag10;
    extern const U64 antiDiag11;
    extern const U64 antiDiag12;
    extern const U64 antiDiag13;
    extern const U64 antiDiag14;
    extern const U64 antiDiag15;

    extern const std::array<U64, 16> antiDiags;

    SquareIndex fileRankIndexToSquareIndex(FileIndex file, RankIndex rank); // thiss
    FileIndex squareIndexToFileIndex(SquareIndex square);
    RankIndex squareIndexToRankIndex(SquareIndex square);
    DiagIndex squareIndexToDiagIndex(SquareIndex square);
    DiagIndex squareIndexToAntiDiagIndex(SquareIndex square);

    void clearBitboard(U64& bitboard);

    void setBitTo1(U64& bitboard, SquareIndex square);
    Bit getBitValue(U64 bitboard, SquareIndex square);

    U64 squareIndexToBitboard(SquareIndex square);

    U64 getIsolatedLeastSignificantSetBit(U64 bitboard);
    U64 getIsolatedMostSignificantSetBit(U64 bitboard);

    SquareIndex getIndexOfLeastSignificantSetBit(U64 bitboard);

    void resetIsolatedLeastSignificantSetBit(U64& bitboard);
    void resetIsolatedMostSignificantSetBit(U64& v);
    int bitCount(U64 bb);

    // visualize
    void visualizeBitboard(U64 bitboard);
}


/// <summary>
/// It's the bitboards required to make the board.
/// This is gettings worse
/// </summary>
class Board_Bitboards {
private:
    enum ChessPiece { PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING };

    std::array<U64, 6> aWhite;
    std::array<U64, 6> aBlack;

    Turn turn;
    U64  whiteBb;
    U64  blackBb;
    U64  occupied;
    U64  empty;

public:
    Board_Bitboards(std::array<U64, 6> wPBNRQK, std::array<U64, 6> bPBNRQK, Turn turn); // Constructor
    ~Board_Bitboards(); // Destructor

    // (side to move)'s pieces array
    std::array<U64, 6> playingPieces();
    // (side that waits for its turn)'s pieces array
    std::array<U64, 6> waitingPieces();

    // Rotations
    // I think these will be useless
    U64 flipVertical(U64 bitboard);
    U64 flipDiagA1H8(U64 x);
    U64 rotation180(U64 bitboard);
    U64 rotationClockWise90(U64 bitboard);
    U64 rotationAntiClockWise90(U64 bitboard);


    // one square movements
    U64 southOne(U64 bitboard);
    U64 northOne(U64 bitboard);
    U64 eastOne(U64  bitboard);
    U64 northEastOne(U64 bitboard);
    U64 southEastOne(U64 bitboard);
    U64 westOne(U64 bitboard);
    U64 southWestOne(U64 bitboard);
    U64 northWestOne(U64 bitboard);

    // Unlimited moves functions

    /// @brief Gives the Unlimited Knight's moves indexes on the Bitboard. NOT Using knightOffsets.
    U64 getUKnightMovesBitboard(SquareIndex square);
    U64 getUKnightsMovesBitboard(U64 bitboard);

    /// @brief Gives the Unlimited King's moves indexes on the Bitboard. NOT Using kingOffsets. 
    U64 getUKingMovesBitboard(SquareIndex square);
    U64 getUKingsMovesBitboard(U64 bitboard);
    U64 getUQueenMovesBitboard(SquareIndex square);
    U64 getURookMovesBitboard(SquareIndex square);
    U64 getURooksMovesBitboard(U64 bitboard);
    
    U64 uBishopTopRightRay(SquareIndex square);
    U64 uBishopTopLeftRay(SquareIndex square);
    U64 uBishopBottomRightRay(SquareIndex square);
    U64 uBishopBottomLeftRay(SquareIndex square);
    U64 getUBishopMovesBitboard(SquareIndex square);
    U64 getUBishopsMovesBitboard(U64 bb);
    /// @brief Gives the Unlimited Pawn's moves indexes on the Bitboard. Using PawnOffsets. NOT including captures
    U64 getUPawnMovesBitboard(SquareIndex square, bool hasMoved, bool isWhite);
    U64 getUPawnsMovesBitboard(U64 bb, bool hasMoved, bool isWhite);


    bool isLegal(U64 squareBb, U64 movesBitboard);
    U64 getLegalMoves(U64 squareBb, U64 moveBitboard);
    bool isInCheck();
    bool isPinned(U64 ownKingBb, U64 pieceBb, bool isWhite, U64 whiteBb, U64 blackBb, U64 bishopsBb, U64 rookBb, U64 queenBb);

    // moves that need to be checked by getLegalMoves(movesBitboard) to see if they are legal

    U64 getKnightMovesBitboard(SquareIndex square);

    U64 bishopTopRightRay(SquareIndex square);
    U64 bishopTopLeftRay(SquareIndex square);
    U64 bishopBottomRightRay(SquareIndex square);
    U64 bishopBottomLeftRay(SquareIndex square);
    U64 getBishopMovesBitboard(SquareIndex square);
};
