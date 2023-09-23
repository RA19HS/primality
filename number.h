#include <valarray>
#include <string>

class Number {
	static constexpr int max_length = 1000;
	std::valarray<unsigned char> n;
public:
	Number() {n.resize(max_length);}
	Number(size_t n);
	Number& operator++();
	Number operator+(const Number &m) const;
	bool operator==(const Number &m) const;
	size_t length() const;
	std::string string() const;
};
