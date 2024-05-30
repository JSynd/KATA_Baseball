#include "pch.h"
#include "../KATA_Baseball/Baseball.cpp"

TEST(BaseballGame, ThrowExeptionCases) {
	Baseball game{ "123" };
	EXPECT_THROW(game.guess(string("12")), length_error);
	EXPECT_THROW(game.guess(string("12s")), invalid_argument);
	EXPECT_THROW(game.guess(string("121")), invalid_argument);
}

class BaseballFixture : public testing::Test {
public:
	Baseball game{ "123" };
	void checkResult(string input, int num_strike, int num_ball) {
		Result ret = game.guess(input);
		if (num_strike == game.LEN_ANSWER) EXPECT_TRUE(ret.solved);
		else EXPECT_FALSE(ret.solved);
		EXPECT_EQ(num_strike, ret.strikes);
		EXPECT_EQ(num_ball, ret.balls);
	}
};

TEST_F(BaseballFixture, Case_Solved) {
	checkResult("123", 3, 0);
}

TEST_F(BaseballFixture, Case_2Strike_0Ball) {
	checkResult("124", 2, 0);
}

TEST_F(BaseballFixture, Case_0Strike_2Ball) {
	checkResult("512", 0, 2);
}

TEST_F(BaseballFixture, Case_1Strike_2Ball) {
	checkResult("132", 1, 2);
}