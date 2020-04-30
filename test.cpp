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
	CHECK(solve(10 == 2*x-4) == 7);
	CHECK(solve(10*x-5 == 10) == 1.5);
	CHECK(solve(3*x-1 == 8) == 3);
	CHECK(solve(0.2*x-4 == 2) == 30);
	CHECK(solve(5*x-1 == 9) == 2);
}


//20
TEST_CASE("solving polnomial equation") {
	RealVariable x;
	CHECK(solve(2*x+(x^2)+1 == 0) == -1);
	CHECK(solve(6*(x^2) == 1.5) == 0.5);
	CHECK(solve(5*(x^2)-5 == 10) == sqrt(3));
	CHECK(solve((x^2)-4 == 12) == 4);
	CHECK(solve((x^2) == 10) == sqrt(10));
	CHECK(solve(0 == 2*(x^2)) == 0);
	CHECK(solve((x^2)-x == 12) == 4);
	CHECK(solve((x^2) == 8) == sqrt(8));
	CHECK(solve(0.1*(x^2)-1 == 0) == sqrt(10));
	CHECK(solve(2*(x^2) == 9) == sqrt(4.5));
}

//40
TEST_CASE("various equation") {
	RealVariable x;
	CHECK(solve(2*x+1 == 0) == -0.5);
	CHECK(solve(6*x == 1.5) == 0.25);
	CHECK(solve(5*(x^2) == 125) == 5);
	CHECK(solve(5*x-4 == 12) == 4.2);
	CHECK(solve((x^2) == 25) == 5);
	CHECK(solve(2 == 2*(x^2)) == 1);
	CHECK(solve(2*x-x == 12) == 12);
	CHECK(solve(2*x+2 == 8) == 3);
	CHECK(solve(0.1*x == 0) == 0);
	CHECK(solve((x^2)-8 == 1) == 3);
	CHECK(solve(-2*x+(x^2)+1 == 0) == 1);
	CHECK(solve(6*2*x == 6) == 0.5);
	CHECK(solve((x^2)-5 == 10) == sqrt(15));
	CHECK(solve((x^2)-4 == 12) == 4);
	CHECK(solve((x^2) == 121) == 11);
	CHECK(solve(4 == 2*(x^2)) == sqrt(2));
	CHECK(solve((x^2)-x == 12) == 4);
	CHECK(solve((x^2)-1 == 8) == 3);
	CHECK(solve((x^2)-2*x == 0) == 0);
	CHECK(solve(x == 9) == 9);
}

//50
TEST_CASE("throw exceptions") {
	RealVariable x;
	CHECK_THROWS(solve((x^2) == -16));
	CHECK_THROWS(solve((x^2)-x == -16));
	CHECK_THROWS(solve((x^2)-5 == -16));
	CHECK_THROWS(solve((x^2)+3*x == -9));
	CHECK_THROWS(solve(3*(x^2)-2*x == -15));
	CHECK_THROWS(solve(-3*(x^2) == 30));
	CHECK_THROWS(solve((x^2) == -1));
	CHECK_THROWS(solve((x^2)-10*x == -26));
	CHECK_THROWS(solve((x^2)-15 == -16));
	CHECK_THROWS(solve((-1*x^2) == -16));

}




