#include "pch.h"
#include "../KATA_Baseball/Baseball.cpp"

TEST(BaseballGame, ThrowExeptionCases) {
	Baseball game{ "123" };
	EXPECT_THROW(game.guess(string("12")), length_error);
	EXPECT_THROW(game.guess(string("12s")), invalid_argument);
	EXPECT_THROW(game.guess(string("121")), invalid_argument);
}

TEST(BaseballGame, CorrectCases) {
	Baseball game{ "123" };
	Result result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}