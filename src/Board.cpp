#include "Board.h"
#include <iostream>

// Private Methods
bool Board::move_within_bounds(std::pair<int,int> position) {
    return position.first >= 0 && position.first < this->size && position.second >= 0 && position.second < this->size;
}

bool Board::is_not_occupied(Piece piece) {
    return this->get_state(piece.get_position()) == empty;
}

bool Board::is_not_self_capture(Piece piece) {
    // to do
    return true;
}

bool Board::results_in_ko(Piece piece) {
    // to do
    return true;
}

EnumPiece Board::get_state(std::pair<int,int> position) {
    return this->board[(position.second * size) + position.first];
}

std::list<std::pair<int,int>> Board::get_neighbouring_positions(std::pair<int,int> position) {
    int x = position.first;
    int y = position.second;
    std::list<std::pair<int,int>> filtered_positions;
    std::list<std::pair<int,int>> neighbouring_positions({{x,y+1},{x,y-1},{x+1,y},{x-1,y}});
    
    // Filter for illegal positions
    // Poor way of doing this. Should consider using predicates and remove_if.
    for (std::list<std::pair<int,int>>::iterator it = neighbouring_positions.begin(); it != neighbouring_positions.end(); it++) {
        std::pair<int,int> position = std::make_pair(it->first,it->second);
        if (move_within_bounds(position)) {
            filtered_positions.push_back(position);
        }
    }
    
    return filtered_positions;
}

std::list<Piece> Board::get_neighbouring_pieces(std::pair<int,int> position) {
    EnumPiece piece_type;
    std::list<Piece> neighbouring_pieces;
    std::list<std::pair<int,int>> neighbouring_positions = get_neighbouring_positions(position);

    for (std::list<std::pair<int,int>>::iterator it = neighbouring_positions.begin(); it != neighbouring_positions.end(); it++) {
        position = std::make_pair(it->first,it->second);
        piece_type = this->get_state(position);
        neighbouring_pieces.push_back(Piece(position,piece_type));
    }
    return neighbouring_pieces;
}

std::list<Group> Board::get_groups(EnumPiece * board_state) {
    // Used to navigate the board
    std::pair<int,int> nav;
    EnumPiece type;

    // Track indicies visited
    std::set<std::pair<int,int>> visited;

    // Track existing groups
    std::list<Group> groups;

    for (int y = 0; y < this->size; y++) {
        for (int x = 0; x < this->size; x++) {
            // std::cout << "coord " << x << " " << y << "\n";
            // Current piece
            type = get_state(std::make_pair(x,y));
            // std::cout << "type " << type << "\n";

            if (type != empty && !position_is_present(visited, std::make_pair(x,y)) ) {
                // std::cout << "new group son\n";
                // We have a new group! Begin searching for other group members via BFS
                Group group = Group(type);

                // Track the neighbouring positions we need to visit in the BFS
                std::queue<std::pair<int,int>> to_visit;

                // Initialise the queue
                to_visit.push(std::make_pair(x,y));

                while (!to_visit.empty()) {
                    nav = to_visit.front();
                    to_visit.pop();

                    // std::cout << "the queue isn't empty! " << "coord  " << nav.first << " " << nav.second << "\n";

                    // If we have already visited this element skip it
                    if ( position_is_present(visited, nav) ) {
                        // std::cout << "coord  " << nav.first << " " << nav.second << " ALREADY VISITED\n";
                        to_visit.pop();
                        continue;
                    }

                    // If it is empty, then it must be a liberty of this group! Add it to the liberty set
                    if ( get_state(nav) == empty ) { 
                        // std::cout << "coord  " << nav.first << " " << nav.second << " IS A LIBERTY OF THIS GROUP\n";
                        group.add_liberty(nav);
                        // Do not mark the element as visited because liberties can be shared between groups
                    }

                    // If it is the same piece as the group type
                    else if ( get_state(nav) == type ) { 
                        // Add it to the pieces set
                        //std::cout << "coord  " << nav.first << " " << nav.second << " IS OF SAME TYPE AS GROUP. ADDING.\n";
                        group.add_piece(nav); 

                        // Add it's neighbours to the to_visit queue
                        std::list<std::pair<int,int>> neighbours = get_neighbouring_positions(nav);

                        for (std::list<std::pair<int,int>>::iterator it = neighbours.begin(); it != neighbours.end(); it++) {
                            // std::cout << "Adding neighbour " << it->first << " " << it->second << "\n";

                            // Only add the neighbour if it hasn't already been visited
                            if (!position_is_present(visited,std::make_pair(it->first, it->second))) {
                                to_visit.push(std::make_pair(it->first, it->second));
                            }
                        }
                        // Mark the element as visited
                        visited.insert(nav);
                    }
                }

                // Add the created group to the set
                groups.push_back(group);
            }
        }
    }
    return groups;
}

std::list<Group> Board::get_captured_groups(EnumPiece* board_state) {
    std::list<Group> groups = get_groups(board_state);
    std::list<Group> captured_groups;

    // Should implement a cleaner filtering operation
    for (std::list<Group>::iterator it = groups.begin(); it != groups.end(); it++) {
        if (it->is_captured()) {
            captured_groups.push_back(*it);
        }
    }
    return captured_groups;
}

bool Board::position_is_present(std::set<std::pair<int,int>> positions, std::pair<int,int> position) {
    // This might already exist.
    for (std::set<std::pair<int,int>>::iterator it = positions.begin(); it != positions.end(); it++) {
        if (it->first == position.first && it->second == position.second) {
            return true;
        }
    }
    return false;
}

// Public Methods
Board::Board(int size) {
    this->size = size;
    this->board = new EnumPiece[size*size];
    this->prev_state = new EnumPiece[size*size];
    for (int i = 0; i < size * size; i++) {
        this->board[i] = empty;
        this->prev_state[i] = empty;
    }
}

int Board::get_size() {
    return this->size;
}

EnumPiece* Board::get_board_state() {
    return this->board;
}

void Board::apply_move(Piece piece) {
    // Unsafe. Does not check for out of bounds access. Only use in conjunction with is_move_legal().
    this->board[(piece.get_position().second * size) + piece.get_position().first] = piece.get_piece();
}

Piece* Board::get_legal_moves(EnumPiece player) {
    return nullptr;
}

bool Board::is_move_legal(Piece piece) {
    return (
        move_within_bounds(piece.get_position()) 
        && is_not_occupied(piece) 
        && is_not_self_capture(piece) 
        && !results_in_ko(piece)
    );
}