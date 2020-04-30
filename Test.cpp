#include "doctest.h"
#include "solver.hpp"
#include <string>
#include <complex>


using namespace std;
using namespace solver;


//10
TEST_CASE("solving linear equation") {
	RealVariable x;
	CHECK(solve(2*x-4 == 10) == 7);
	CHECK(solve(6*x == 3) == 0.5);
	CHECK(solve(5*x-5 == 10) == 3);
	CHECK(solve(6*x-4 == 8) == 2);
	CHECK(solve(4-2*x == 10) == 7);
	CHECK(solve(2-4*x == 10) == -2);
	CHECK(solve(10*x-5 == 10) == 1.5);
	CHECK(solve(3*x-1 == 8) == 3);
	CHECK(solve(0.2*x-4 == 2) == 30);
	CHECK(solve(5*x-1 == 9) == 2);
}
