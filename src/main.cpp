#include <iostream>
#include "Board.h"

#define SMALL_BOARD_SIZE 9
#define MEDIUM_BOARD_SIZE 13
#define LARGE_BOARD_SIZE 17

// Play a game of Go with 2 human players
void play_2p() {
  int player_choice;
  Board * board;
  std::cout << "Select board size:\n(1) 9x9\n(2) 13x13\n(3) 17x17\n Enter option number: ";
  std::cin >> player_choice;

  switch(player_choice) {
    case 1:
      board = new Board(SMALL_BOARD_SIZE);
      break;
    case 2:
      board = new Board(MEDIUM_BOARD_SIZE);
      break;
    case 3:
      board = new Board(LARGE_BOARD_SIZE);
      break;
    default:
      std::cout << "Invalid board size. Terminating.";
      return;

    
  }

  free(board);
}

int main()
{
  std::cout << "Hello Go!\n";

  // Test case
  #define TEST_BOARD_SIZE 5
  Board board = Board(TEST_BOARD_SIZE);
  board.print_board(board.get_board_state());

  printf("Move (1,0) is %s\n", board.is_move_legal(Piece(std::make_pair(1,0), black)) ? "legal" : "illegal");
  board.apply_move(Piece(std::make_pair(1,0), black));
  board.print_board(board.get_board_state());


  printf("Move (0,1) is %s\n", board.is_move_legal(Piece(std::make_pair(0,1), black)) ? "legal" : "illegal");
  board.apply_move(Piece(std::make_pair(0,1), black));
  board.print_board(board.get_board_state());

  printf("Move (0,0) is %s\n", board.is_move_legal(Piece(std::make_pair(0,0), black)) ? "legal" : "illegal");
  board.apply_move(Piece(std::make_pair(0,0), black));
  board.print_board(board.get_board_state());

  board.print_groups();
  board.print_board(board.get_board_state());

}

