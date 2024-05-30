#include "pch.h"
#include "../KATA_Baseball/Baseball.cpp"

TEST(BaseballGame, ThrowExeptionCases) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
	EXPECT_THROW(game.guess(string("12s")), invalid_argument);
	EXPECT_THROW(game.guess(string("121")), invalid_argument);
}