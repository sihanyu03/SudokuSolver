#include <iostream>
#include <vector>
#include "board_reader.h"
#include "solver.h"

void print_board(const std::vector<std::vector<char>>& board, const int return_code) {
    std::cout << std::endl;
    if (return_code == 0) {
        std::cout<< "Answer:" << std::endl;
    } else {
        std::cout << "Invalid input as more than one solution was found." << std::endl <<
            "One of the answers:" << std::endl << std::endl;
    }
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) {
            std::cout << "------+-------+------" << std::endl;
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) {
                std::cout << "| ";
            }
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int return_code {-1};
    std::vector<std::vector<char>> board;
    bool first_attempt {true};

    while (return_code == -1) {
        if (first_attempt) {
            first_attempt = false;
        } else {
            std::cout << "The board you submitted is not solvable. Try again" << std::endl;
        }
        board = BoardReader::initialise_board();
        Solver solver;
        return_code = solver.solve(board);
        board = solver.get_board();
    }

    print_board(board, return_code);

    return 0;
}