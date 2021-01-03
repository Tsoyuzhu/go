#include "Piece.h"

Piece::Piece(std::pair<int,int> position, EnumPiece type) {
    this->position = position;
    this->piece = type;
};

std::pair<int,int> Piece::get_position() {
    return this->position;
}

EnumPiece Piece::get_piece() {
    return piece;
}