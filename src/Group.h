#include "EnumPiece.h"
#include <set>
#include <utility>


#ifndef GROUP
#define GROUP

class Group {
    // Defines a group in go
    // Collection of coordinates of pieces which belong in a group and the piece type (black or white)
    private:
        // Groups consist of adjacent pieces of the same piece type
        EnumPiece pieceType;

        // List of pieces in the group
        std::set<std::pair<int,int>> pieces;

        // List of liberties in the group
        std::set<std::pair<int,int>> liberties;
        
    public:
        // Constructor
        Group(EnumPiece pieceType);

        // Getter for pieceType
        EnumPiece get_pieceType();

        // Getter for list of pieces in the group
        std::set<std::pair<int,int>> get_pieces();

        // Getter for list of liberties in the group
        std::set<std::pair<int,int>> get_liberties();

        // Add a piece to the group
        void add_piece(std::pair<int,int>);

        // Add a liberty to the group
        void add_liberty(std::pair<int,int>);

        // Returns true if the group has no remaining liberties
        bool is_captured();

        // Returns true if the piece exists in the group
        bool piece_is_present(std::pair<int,int>, EnumPiece pieceType);

        // Print all coordinates of pieces within the group
        void print_pieces(); 

        // Print all coordinates of liberties within the group
        void print_liberties();
};

#endif