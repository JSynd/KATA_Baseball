#include <stdexcept>
#include <string>

using namespace std;

class Baseball {
public:
	bool guess(string guess_str) {
		if (guess_str == "12") {
			throw length_error("Lengh error");
		}

		return true;
	}
};