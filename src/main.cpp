#include <iostream>
#include "Board.h"

int main()
{
  std::cout << "Hello Go!\n";

  // Test case
  #define SMALL_BOARD_SIZE 5
  Board board = Board(SMALL_BOARD_SIZE);

  board.apply_move(Piece(std::make_pair(3,0), black));
  board.apply_move(Piece(std::make_pair(4,0), white));
  board.apply_move(Piece(std::make_pair(2,1), white));
  board.apply_move(Piece(std::make_pair(4,1), white));
  board.apply_move(Piece(std::make_pair(1,2), white));
  board.apply_move(Piece(std::make_pair(2,2), black));
  board.apply_move(Piece(std::make_pair(3,2), white));
  board.apply_move(Piece(std::make_pair(4,2), black));
  board.apply_move(Piece(std::make_pair(2,3), white));
  board.apply_move(Piece(std::make_pair(3,3), black));
  board.apply_move(Piece(std::make_pair(4,3), black));

  std::list<Group> groups = board.get_groups(board.get_board_state());
  for (std::list<Group>::iterator it = groups.begin(); it != groups.end(); it++) {
    std::cout << "Pieces\n";
    it->print_pieces();
    std::cout << "Liberties\n";
    it->print_liberties();
    if (it->is_captured()) std:: cout << "captured\n";
    else std:: cout << "not captured\n";
    std::cout << "\n";
  }

}