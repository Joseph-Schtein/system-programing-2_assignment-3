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


//60
TEST_CASE("solving linear equation with real numbers") {
	ComplexVariable x;
	CHECK(solve(2*x-4 == 10) == std::complex<double>(7,0));
	CHECK(solve(6*x == 3) == std::complex<double>(0.5,0));
	CHECK(solve(5*x-5 == 10) == std::complex<double>(3,0));
	CHECK(solve(6*x-4 == 8) == std::complex<double>(2,0));
	CHECK(solve(4-2*x == 10) == std::complex<double>(3,0));
	CHECK(solve(10 == 2*x-4) == std::complex<double>(7,0));
	CHECK(solve(10*x-5 == 10) == std::complex<double>(1.5,0));
	CHECK(solve(3*x-1 == 8) == std::complex<double>(3,0));
	CHECK(solve(0.2*x-4 == 2) == std::complex<double>(30,0));
	CHECK(solve(5*x-1 == 9) == std::complex<double>(2,0));
}


//70
TEST_CASE("solving polnomial equatiol") {
	ComplexVariable x;
	CHECK(solve((x^2) == -1) == std::complex<double>(0,1));
	CHECK(solve(6*(x^2) == -1.5) == std::complex<double>(0,0.5));
	CHECK(solve(5*(x^2)-5 == -10) == std::complex<double>(0,1));
	CHECK(solve((x^2)-4 == -12) == std::complex<double>(0,sqrt(8)));
	CHECK(solve((x^2) == -10) == std::complex<double>(0,sqrt(10)));
	CHECK(solve(2*x == 2*(x^2)+3) == std::complex<double>(0.5,sqrt(5)/2));
	CHECK(solve((x^2)-x == 12) == std::complex<double>(0.5,sqrt(47)/2));
	CHECK(solve((x^2) == -9) == std::complex<double>(0,3));
	CHECK(solve(0.1*(x^2)+1 == 0) == std::complex<double>(0,sqrt(10)));
	CHECK(solve(2*(x^2) == -128) == std::complex<double>(0,8));
}

//90
TEST_CASE("various equation") {
	ComplexVariable x;
	CHECK(solve(2*x-1 == 0) == std::complex<double>(0.5,0));
	CHECK(solve(6*x+5 == 1.5) == std::complex<double>(-7/12,0));
	CHECK(solve(5*(x^2) == (x^2)-5) == std::complex<double>(0,sqrt(5)/2));
	CHECK(solve((x^2)-4 == 12) == std::complex<double>(4,0));
	CHECK(solve((x^2) == -25) == std::complex<double>(0,5));
	CHECK(solve(2 == 2*(x^2)) == std::complex<double>(1,0));
	CHECK(solve((x^2)-x == -12) == std::complex<double>(0.5,sqrt(47)/2));
	CHECK(solve((x^2)+2 == -8) == std::complex<double>(0,sqrt(10)));
	CHECK(solve(0.1*x == 0) == std::complex<double>(0,0));
	CHECK(solve((x^2)+3 == -1) == std::complex<double>(0,2));
	CHECK(solve(-2*x+(x^2)+1 == (x^2)) == std::complex<double>(0.5,0));
	CHECK(solve(6*2*x == 6*(x^2)) == std::complex<double>(0,0));
	CHECK(solve((x^2)+5*x == -10) == std::complex<double>(-2.5,sqrt(15)/2));
	CHECK(solve((x^2)-4 == 12) == std::complex<double>(4,0));
	CHECK(solve((x^2) == -121) == std::complex<double>(0,11));
	CHECK(solve(-4 == -2*(x^2)) == std::complex<double>(sqrt(2),0));
	CHECK(solve((x^2) == -1) == std::complex<double>(0,1));
	CHECK(solve((x^2) == 1) == std::complex<double>(1,0));
	CHECK(solve((x^2)-2*x == 3) == std::complex<double>(1,sqrt(2)));
	CHECK(solve(x == 9) == std::complex<double>(9,0));
}

//100
TEST_CASE("throw exceptions") {
	ComplexVariable x;
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





