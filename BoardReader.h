//
// Created by Sihan Yu on 18/08/2024.
//

#ifndef BOARDREADER_H
#define BOARDREADER_H
#include <iostream>


class BoardReader {
public:
    static std::vector<std::vector<char>> initialise_board();
private:
    static bool is_valid(const std::vector<char>& row);
};



#endif //BOARDREADER_H
