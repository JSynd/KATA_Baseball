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

	explicit Baseball(const string& answer) : answer(answer) {}
	Result guess(const string& guessNumber) {
		setGuessValue(guessNumber);
		
		checkValidity();

		int strikeCnt = getStrikeCount();
		if (strikeCnt == 0) return { false, 0, 2 };
		return { strikeCnt == LEN_ANSWER, strikeCnt , 0 };
	}

private:
	string answer;
	string guessValue;

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

	int getStrikeCount() {
		int num_strikes = 0;
		for (int i = 0; i < answer.size(); i++) {
			if (answer[i] == guessValue[i]) num_strikes++;
		}
		return num_strikes;
	}
};