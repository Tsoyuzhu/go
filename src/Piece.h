#include "EnumPiece.h"
#include <utility>

#ifndef PIECE
#define PIECE

class Piece {
    private: 
        std::pair<int,int> position;
        EnumPiece piece;
    public:
        // Constructor
        Piece(std::pair<int,int> position, EnumPiece type);

        // Get position of piece
        std::pair<int,int> get_position();

        // Get the piece to be played
        EnumPiece get_piece();
};

#endif