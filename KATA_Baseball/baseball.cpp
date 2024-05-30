#include <stdexcept>
#include <string>

using namespace std;

class Baseball {
public:
	bool guess(const string& guess_str) {
		if (guess_str.size() != LEN_ANSWER) {
			throw length_error("Lengh error");
		}

		return true;
	}
private:
	const int LEN_ANSWER = 3;
	string answer;

};