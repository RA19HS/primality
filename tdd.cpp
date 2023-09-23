#include "number.h"
#include <cassert>
#include <iostream>

class TDD {
	Number zero, one, two, three, four;
public:
	TDD(): one(1), two(2), three(3), four(4) {}
	void test_equality() {
		Number n0, n1(1), n2{2}, n3 = 3, n4{4};
		assert(n0 == zero);
		assert(n1 == one);
		assert(n2 == two);
		assert(n3 == three);
		assert(n4 == four);
		assert(Number(12345) == Number(12345));
	}
	void test_prefix_increment() {
		Number n;
		assert(n == zero);
		++n;
		assert(n == one);
		assert(++n == two);
		assert(++n == three);
		assert(++n == four);
		assert(++Number(19) == Number(20));
	}
	void test_length() {
		assert(zero.length() == 1);
		assert(one.length() == 1);
		assert(two.length() == 2);
		assert(three.length() == 2);
		assert(four.length() == 3);
		assert(Number(1000).length() == 10);
	}
	void test_string() {
		assert(zero.string() == "0");
		assert(one.string() == "1");
		assert(two.string() == "10");
		assert(three.string() == "11");
		assert(four.string() == "100");
		assert(Number(511).string() == "111111111");
	}
	void test_plus_operator() {
		assert(zero + zero == zero);
		assert(one + zero == one);
		assert(zero + two + zero == one + one);
		assert(one + one == two);
		assert(one + two == three);
		assert(three + one == four);
		assert(two + one + zero + one == four);
		assert(Number(7) + Number(40) == Number(47));
	}
	void run_all_tests() {
		test_equality();
		test_prefix_increment();
		test_string();
		test_length();
		test_plus_operator();
	}
};

int main() {
	TDD tdd;
	tdd.run_all_tests();
	return 0;
}
