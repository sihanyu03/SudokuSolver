//
// Created by Sihan Yu on 18/08/2024.
//

#include "board_reader.h"
#include <iostream>
#include <vector>
#include <sstream>


bool BoardReader::is_valid(const std::vector<char>& row) {
    if (row.size() != 9) {
        return false;
    }

    return std::ranges::all_of(row, [](const auto elem) {
       return (elem >= '1' && elem <= '9') || elem == '-';
    });
}

std::vector<std::vector<char>> BoardReader::initialise_board() {
    std::vector<std::vector<char>> board;
    std::cout << "Please enter the board row by row, indicating empty slots with dashes '-', and separating each"
                 " element with spaces" << std::endl;
    for (int i = 1; i <= 9; i++) {
        std::vector<char> row;
        bool valid {false};
        std::string input_line;
        bool first_attempt {true};

        while (!valid) {
            if (first_attempt) {
                std::cout << "Please enter row " << i << std::endl;
                first_attempt = false;
            }

            row.clear();
            std::getline(std::cin, input_line);
            std::stringstream ss(input_line);

            std::string elem;
            bool invalid_elem = false;
            while (ss >> elem) {
                if (elem.length() != 1) {
                    invalid_elem = true;
                    break;
                }
                row.push_back(elem[0]);
            }

            if (invalid_elem || !is_valid(row)) {
                std::cout << "Invalid input, ensure that you've entered 9 numbers all between 1 and 9, and empty slots"
                             " with dashes '-'. Re-enter row " << i << std::endl;
            } else {
                valid = true;
            }
        }

        board.push_back(row);
    }

    return board;
}
