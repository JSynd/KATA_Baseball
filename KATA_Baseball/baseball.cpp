#include <stdexcept>
#include <string>

using namespace std;

class Baseball {
public:
	bool guess(const string& guessNumber) {
		if (guessNumber.size() != LEN_ANSWER) {
			throw length_error("Lengh error");
		}

		for (char ch : guessNumber) {
			if (ch < '0' || ch > '9') {
				throw invalid_argument("Must be numbers");
			}
		}
		if (guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2]) {
			throw invalid_argument("Gussed String has Duplicated numbers");
		}

		return true;
	}
private:
	const int LEN_ANSWER = 3;
	string answer;

};