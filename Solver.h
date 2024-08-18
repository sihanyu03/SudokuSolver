//
// Created by Sihan Yu on 18/08/2024.
//

#ifndef SOLVER_H
#define SOLVER_H
#include <vector>


class Solver {
public:
    Solver();
    int solve(std::vector<std::vector<char> > &);
    std::vector<std::vector<char>> get_board();
private:
    int return_code; // -1: answer not found, 0: 1 answer found, 1: more than 1 answers exist, one found
    std::vector<std::vector<char>> ans;
    bool invalid;
    std::pair<int, int> end;
    std::vector<int> rows;
    std::vector<int> cols;
    std::vector<int> squares;

    int backtrack(int, int, std::vector<std::vector<char>>&);
    static int get_square_no(int, int);
    static std::pair<int, int> get_next_coords(std::pair<int, int>);
};



#endif //SOLVER_H
