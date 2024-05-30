#include <stdexcept>
#include <string>

using namespace std;

struct Result {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	const int LEN_ANSWER = 3;

	explicit Baseball(const string& answer) : answer(answer), strike_cnt(0), ball_cnt(0) {}
	Result guess(const string& guessNumber) {
		setGuessValue(guessNumber);

		checkValidity();
		
		checkAnswer();
		return makeResult();
	}

private:
	string answer;
	string guessValue;

	int strike_cnt;
	int ball_cnt;

	void setGuessValue(const string& guessNumber) {
		guessValue = guessNumber;
	}

	void checkValidity(){
		if (guessValue.size() != LEN_ANSWER) {
			throw length_error("Lengh error");
		}

		for (char ch : guessValue) {
			if (ch < '0' || ch > '9') {
				throw invalid_argument("Must be numbers");
			}
		}
		if (isDuplicatedNumber()) {
			throw invalid_argument("Gussed String has Duplicated numbers");
		}
	}

	bool isDuplicatedNumber() {
		return guessValue[0] == guessValue[1]
			|| guessValue[0] == guessValue[2]
			|| guessValue[1] == guessValue[2];
	}

	void checkAnswer() {
		strike_cnt = getStrikeCount();
		ball_cnt = getBallCount();
	}

	int getStrikeCount() {
		int num_strikes = 0;
		for (int i = 0; i < answer.size(); i++) {
			if (answer[i] == guessValue[i]) num_strikes++;
		}
		return num_strikes;
	}

	int getBallCount() {
		int num_balls = 0;
		for (int i = 0; i < answer.size(); i++) {
			for (int j = 0; j < answer.size(); j++) {
				if (i != j && answer[i] == guessValue[j]) num_balls++;
			}
		}
		return num_balls;
	}

	Result makeResult() {
		return { strike_cnt == LEN_ANSWER, strike_cnt , ball_cnt };
	}
};