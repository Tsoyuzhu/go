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

        // Modify board state by applying a move
        

        // Get neighbours of a position
        std::list<std::pair<int,int>> get_neighbouring_positions(std::pair<int,int> position);

        // Get neighbouring pieces of a position
        std::list<Piece> get_neighbouring_pieces(std::pair<int,int> position);

        // Given a board state, return a set of all existing groups
        std::list<Group> get_groups(EnumPiece * board_state);
        
        // Given a board state, return a set of all captured groups
        std::list<Group> get_captured_groups();

        // Determine whether a coordinate is present within a set of coordinates
        bool position_is_present(std::set<std::pair<int,int>> positions, std::pair<int,int> position);

        // Remove groups from the board
        void remove_groups(std::list<Group> groups);

        // Given two board states, returns true if the states are equal
        bool board_states_equal(EnumPiece* b1, EnumPiece* b2);

        // Given a board state, board, modify cloned to be a deep clone of board
        void clone_board_state(EnumPiece* board, EnumPiece* cloned);

    public:
        // Constructor
        Board(int size);

        // Returns board size
        int get_size();
        
        // Return board state
        EnumPiece* get_board_state();

        void set_board_state(EnumPiece * board_state);

        // Returns true if the move is legal
        bool is_move_legal(Piece piece);

        // Move back after
        void apply_move(Piece piece);

        // Print board state for debugging
        void print_board(EnumPiece * board_state);

        // Print groups for debugging
        void print_groups();
};      

#endif