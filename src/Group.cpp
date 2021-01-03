#include "Group.h"
#include <iostream>

// Private Methods

// Public Methods
Group::Group(EnumPiece pieceType) {
    this->pieceType = pieceType;
}

EnumPiece Group::get_pieceType() {
    return this->pieceType;
}

std::set<std::pair<int,int>> Group::get_pieces() {
    return this->pieces;
}

std::set<std::pair<int,int>> Group::get_liberties() {
    return this->pieces;
}

void Group::add_piece(std::pair<int,int> position) {
    this->pieces.insert(position);
}

void Group::add_liberty(std::pair<int,int> position) {
    this->liberties.insert(position);
}

bool Group::is_captured() {
    return this->liberties.size() == 0;
}

bool Group::piece_is_present(std::pair<int,int> position, EnumPiece pieceType) {
    if (pieceType != this->pieceType) {
        return false;
    }
    // Duplication of position_is_present in Board class. 
    for(std::set<std::pair<int,int>>::iterator it = this->pieces.begin(); it != this->pieces.end(); it++) {
        if (it->first == position.first && it->second == position.second) {
            return true;
        }
    }
    return false;
}

void Group::print_pieces() {
    for(std::set<std::pair<int,int>>::iterator it = this->pieces.begin(); it != this->pieces.end(); it++) {
        std::cout << "(" << it->first << "," << it->second << ") ";
    }
    std::cout << "\n";
}

void Group::print_liberties() {
    for(std::set<std::pair<int,int>>::iterator it = this->liberties.begin(); it != this->liberties.end(); it++) {
        std::cout << "(" << it->first << "," << it->second << ") ";
    }
    std::cout << "\n";
}