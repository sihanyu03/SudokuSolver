//
// Created by Sihan Yu on 18/08/2024.
//

#include "solver.h"

Solver::Solver() {
    return_code = -1;
    std::vector<std::vector<char>> ans;
    invalid = false;
    end = {-1, -1};

    rows = std::vector(9, 0);
    cols = std::vector(9, 0);
    squares = std::vector(9, 0);
}

int Solver::solve(std::vector<std::vector<char>> &board) {
    rows = std::vector(9, 0);
    cols = std::vector(9, 0);
    squares = std::vector(9, 0);
    end = {-1, -1};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '-') {
                continue;
            }
            const int square_no {get_square_no(i, j)};
            const int num {board[i][j] - '0'};
            if (rows[i] & 1 << num || cols[j] & 1 << num || squares[square_no] & 1 << num) {
                return -1;
            }
            rows[i] = rows[i] | 1 << num;
            cols[j] = cols[j] | 1 << num;
            squares[square_no] = squares[square_no] | 1 << num;
        }
    }

    std::pair coords = {0, 0};
    while (board[coords.first][coords.second] != '-' && coords != end) {
        coords = get_next_coords(coords);
    }

    return backtrack(coords.first, coords.second, board);
}

int Solver::backtrack(int i, int j, std::vector<std::vector<char>> &board) {
    if (return_code == 1) {
        return 1;
    }
    if (i == -1 && j == -1) {
        if (return_code == -1) {
            ans = board;
            return_code = 0;
        } else if (return_code == 0) {
            return_code = 1;
        }
        return return_code;
    }

    for (int num = 1; num <= 9; num++) {
        const auto square_no = get_square_no(i, j);
        if (rows[i] & 1 << num || cols[j] & 1 << num || squares[square_no] & 1 << num) {
            continue;
        }

        rows[i] = rows[i] | 1 << num;
        cols[j] = cols[j] | 1 << num;
        squares[square_no] = squares[square_no] | 1 << num;

        board[i][j] = static_cast<char>('0' + num);
        std::pair new_coords = {i, j};
        while (new_coords != end && board[new_coords.first][new_coords.second] != '-') {
            new_coords = get_next_coords(new_coords);
        }
        if (backtrack(new_coords.first, new_coords.second, board) == 1) {
            return 1;
        }

        board[i][j] = '-';

        rows[i] = rows[i] & ~(1 << num);
        cols[j] = cols[j] & ~(1 << num);
        squares[square_no] = squares[square_no] & ~(1 << num);
    }
    return return_code;
}

int Solver::get_square_no(const int i, const int j) {
    return i / 3 * 3 + j / 3;
}

std::pair<int, int> Solver::get_next_coords(std::pair<int, int> coords) {
    if (coords.first == 8 && coords.second == 8) {
        return {-1, -1};
    }
    if (coords.second == 8) {
        return {coords.first + 1, 0};
    }
    return {coords.first, coords.second + 1};
}

std::vector<std::vector<char>> Solver::get_board() {
    return ans;
}