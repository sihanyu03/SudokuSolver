//
// Created by Sihan Yu on 18/08/2024.
//

#include <gtest/gtest.h>
#include "../src/solver.h"

class SolverTest : public :: testing::Test {
protected:
	Solver solver;

	void SetUp() override {}

	void TearDown() override {}
};

TEST_F(SolverTest, test_solve1) {
	std::vector<std::vector<char>> board = {
		{'-', '-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-', '-'}
	};
	const auto return_code {solver.solve(board)};
	const auto actual_result = solver.get_board();

	const std::vector<std::vector<char>> expected_result = {
		{'1', '2', '3', '4', '5', '6', '7', '8', '9'},
		{'4', '5', '6', '7', '8', '9', '1', '2', '3'},
		{'7', '8', '9', '1', '2', '3', '4', '5', '6'},
		{'2', '1', '4', '3', '6', '5', '8', '9', '7'},
		{'3', '6', '5', '8', '9', '7', '2', '1', '4'},
		{'8', '9', '7', '2', '1', '4', '3', '6', '5'},
		{'5', '3', '1', '6', '4', '2', '9', '7', '8'},
		{'6', '4', '2', '9', '7', '8', '5', '3', '1'},
		{'9', '7', '8', '5', '3', '1', '6', '4', '2'}
	};

	EXPECT_EQ(1, return_code);
	EXPECT_EQ(expected_result, actual_result);
}

TEST_F(SolverTest, test_solve2) {
	std::vector<std::vector<char>> board = {
		{'-', '-', '-', '-', '-', '-', '-', '-', '2'},
		{'-', '-', '-', '-', '-', '-', '9', '4', '-'},
		{'-', '-', '3', '-', '-', '-', '-', '-', '5'},
		{'-', '9', '2', '3', '-', '5', '-', '7', '4'},
		{'8', '4', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '6', '7', '-', '9', '8', '-', '-', '-'},
		{'-', '-', '-', '7', '-', '6', '-', '-', '-'},
		{'-', '-', '-', '9', '-', '-', '-', '2', '-'},
		{'4', '-', '8', '5', '-', '-', '3', '6', '-'}
	};
	const auto return_code {solver.solve(board)};
	const auto actual_result = solver.get_board();

	const std::vector<std::vector<char>> expected_result = {
		{'6', '8', '4', '1', '5', '9', '7', '3', '2'},
		{'7', '5', '1', '8', '3', '2', '9', '4', '6'},
		{'9', '2', '3', '6', '7', '4', '1', '8', '5'},
		{'1', '9', '2', '3', '6', '5', '8', '7', '4'},
		{'8', '4', '5', '2', '1', '7', '6', '9', '3'},
		{'3', '6', '7', '4', '9', '8', '2', '5', '1'},
		{'2', '3', '9', '7', '4', '6', '5', '1', '8'},
		{'5', '1', '6', '9', '8', '3', '4', '2', '7'},
		{'4', '7', '8', '5', '2', '1', '3', '6', '9'}
	};

	EXPECT_EQ(0, return_code);
	EXPECT_EQ(expected_result, actual_result);
}

TEST_F(SolverTest, test_solve3) {
	std::vector<std::vector<char>> board = {
		{'4', '-', '6', '-', '-', '-', '-', '5', '9'},
		{'-', '-', '-', '-', '4', '-', '2', '-', '-'},
		{'-', '7', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '5', '9', '1', '-', '-', '6', '-'},
		{'-', '1', '3', '-', '-', '-', '8', '9', '4'},
		{'-', '-', '-', '2', '-', '-', '-', '-', '1'},
		{'5', '-', '8', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '3', '-', '-', '-', '8'},
		{'-', '4', '-', '-', '6', '-', '1', '-', '-'}
	};
	const auto return_code {solver.solve(board)};
	const auto actual_result = solver.get_board();

	const std::vector<std::vector<char>> expected_result = {
		{'4', '3', '6', '1', '2', '8', '7', '5', '9'},
		{'9', '5', '1', '7', '4', '6', '2', '8', '3'},
		{'8', '7', '2', '3', '5', '9', '4', '1', '6'},
		{'7', '8', '5', '9', '1', '4', '3', '6', '2'},
		{'2', '1', '3', '6', '7', '5', '8', '9', '4'},
		{'6', '9', '4', '2', '8', '3', '5', '7', '1'},
		{'5', '2', '8', '4', '9', '1', '6', '3', '7'},
		{'1', '6', '7', '5', '3', '2', '9', '4', '8'},
		{'3', '4', '9', '8', '6', '7', '1', '2', '5'}
	};

	EXPECT_EQ(0, return_code);
	EXPECT_EQ(expected_result, actual_result);
}

TEST_F(SolverTest, test_solve4) {
	// Invalid board
	std::vector<std::vector<char>> board = {
		{'4', '-', '6', '-', '-', '-', '-', '5', '9'},
		{'-', '-', '-', '-', '4', '-', '2', '-', '-'},
		{'-', '7', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '5', '9', '1', '-', '-', '6', '-'},
		{'-', '1', '3', '-', '-', '-', '8', '9', '4'},
		{'-', '-', '-', '2', '-', '-', '-', '-', '1'},
		{'5', '-', '8', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '3', '-', '-', '-', '8'},
		{'-', '4', '-', '-', '5', '-', '1', '-', '-'}
	};
	const auto return_code {solver.solve(board)};
	const auto actual_result = solver.get_board();

	EXPECT_EQ(-1, return_code);
}

TEST_F(SolverTest, test_solve5) {
	std::vector<std::vector<char>> board = {
		{'2', '7', '1', '4', '5', '6', '8', '9', '3'},
		{'8', '5', '6', '1', '3', '9', '7', '2', '4'},
		{'3', '4', '9', '8', '2', '7', '1', '5', '6'},
		{'6', '3', '8', '2', '9', '4', '5', '1', '7'},
		{'9', '2', '5', '3', '7', '1', '4', '6', '8'},
		{'4', '1', '7', '6', '8', '5', '2', '3', '9'},
		{'1', '8', '3', '9', '4', '2', '6', '7', '5'},
		{'5', '9', '2', '7', '6', '8', '3', '4', '1'},
		{'7', '6', '4', '5', '1', '3', '9', '8', '2'}
	};
	const auto return_code {solver.solve(board)};
	const auto actual_result = solver.get_board();

	const std::vector<std::vector<char>> expected_result = {
		{'2', '7', '1', '4', '5', '6', '8', '9', '3'},
		{'8', '5', '6', '1', '3', '9', '7', '2', '4'},
		{'3', '4', '9', '8', '2', '7', '1', '5', '6'},
		{'6', '3', '8', '2', '9', '4', '5', '1', '7'},
		{'9', '2', '5', '3', '7', '1', '4', '6', '8'},
		{'4', '1', '7', '6', '8', '5', '2', '3', '9'},
		{'1', '8', '3', '9', '4', '2', '6', '7', '5'},
		{'5', '9', '2', '7', '6', '8', '3', '4', '1'},
		{'7', '6', '4', '5', '1', '3', '9', '8', '2'}
	};

	EXPECT_EQ(0, return_code);
	EXPECT_EQ(expected_result, actual_result);
}
