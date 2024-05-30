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
		checkValidity(guessNumber);
		if (answer == guessNumber) return { true, 3, 0 };
		return { false, 2, 0 };
	}

private:
	string answer;

	void checkValidity(const std::string& guessNumber){
		if (guessNumber.size() != LEN_ANSWER) {
			throw length_error("Lengh error");
		}

		for (char ch : guessNumber) {
			if (ch < '0' || ch > '9') {
				throw invalid_argument("Must be numbers");
			}
		}
		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Gussed String has Duplicated numbers");
		}
	}

	bool isDuplicatedNumber(const std::string& guessNumber) {
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}
};