#include "EnumPiece.h"
#include "Piece.h"
#include "Group.h"
#include <list>
#include <set>
#include <queue>

#ifndef BOARD
#define BOARD

class Board {
    private:
        int size;

        // Allocate the board as a contiguous block of memory
        EnumPiece* board;

        // Track the previous state for ko rule
        EnumPiece* prev_state;

        // Returns true if the target position is in the board
        bool move_within_bounds(std::pair<int,int> position);

        // Returns true if the position is empty
        bool is_not_occupied(Piece piece); 

        // Returns true if the move does not result in a suicide
        bool is_not_self_capture(Piece piece);

        // Returns true if the move does not replicate the last state (ko rule)
        bool results_in_ko(Piece piece);

        // Get residing piece of a board position
        EnumPiece get_state(std::pair<int,int> position);

        // Get neighbours of a position
        std::list<std::pair<int,int>> get_neighbouring_positions(std::pair<int,int> position);

        // Get neighbouring pieces of a position
        std::list<Piece> get_neighbouring_pieces(std::pair<int,int> position);

        // Given a board state, return a set of all existing groups
        
        // Given a board state, return a set of all captured groups
        std::list<Group> get_captured_groups(EnumPiece * board_state);

        // Determine whether a coordinate is present within a set of coordinates
        bool position_is_present(std::set<std::pair<int,int>> positions, std::pair<int,int> position);

        // Remove groups from the board 
        void remove_groups(std::list<Group> groups);

    public:
        // Constructor
        Board(int size);

        // Returns board size
        int get_size();
        
        // Return board state
        EnumPiece* get_board_state();

        // Modify board state by applying a move
        void apply_move(Piece piece);

        // Obtain all legal moves for a player
        Piece* get_legal_moves(EnumPiece player);

        // Returns true if the move is legal
        bool is_move_legal(Piece piece);

        // Move back after
        std::list<Group> get_groups(EnumPiece * board_state);

        // 
};      

#endif