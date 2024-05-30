#include "pch.h"
#include "../KATA_Baseball/Baseball.cpp"

TEST(BaseballGame, ThrowExeptionWhenInputLenthNotMatched) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}