#pragma once 
 
#include <string>
#include <iostream>
#include <complex>


using namespace std;

namespace solver{

	

	class RealVariable{
		public:	
			
			double a;
			double b;
			double c;
			RealVariable *e = NULL;

			
			RealVariable(){
				a=0;
				b=1;
				c=0;
			}

			RealVariable(double _a, double _b, double _c){
				a = _a;
				b = _b;
				c = _c;
			}


			friend RealVariable& operator^(RealVariable& x, int y);
			
			friend RealVariable& operator+(RealVariable& x, double y);
			friend RealVariable& operator+(double x, RealVariable& y);
			friend RealVariable& operator+(RealVariable& x, RealVariable& y);
		
			friend RealVariable& operator-(RealVariable& x, double y);
			friend RealVariable& operator-(double x, RealVariable& y);
			friend RealVariable& operator-(RealVariable& x, RealVariable& y);

			friend RealVariable& operator/(RealVariable& x, double y);
			friend RealVariable& operator*(double x, RealVariable& y);
		
			friend RealVariable& operator==(RealVariable& x, RealVariable& y);
			friend RealVariable& operator==(RealVariable& x, double y);
			friend RealVariable& operator==(double x, RealVariable& y);
	};

	double solve(RealVariable& f);



	class ComplexVariable{

		public:

			
			std::complex<double> a;
			std::complex<double> b;	
			std::complex<double> c;
			ComplexVariable *e = NULL; 
		

			ComplexVariable(){
				a=0;
				b=1;
				c=0;
			}


			ComplexVariable(std::complex<double> _a, std::complex<double> _b, std::complex<double> _c){
				a=_a;
				b=_b;
				c=_c;
			}
		
			friend ComplexVariable& operator^(ComplexVariable& x, int y);
			
			friend ComplexVariable& operator+(ComplexVariable& x, std::complex<double> y);
			friend ComplexVariable& operator+(std::complex<double> x, ComplexVariable& y);
			friend ComplexVariable& operator+(ComplexVariable& x, ComplexVariable& y);
		
			friend ComplexVariable& operator-(ComplexVariable& x, std::complex<double> y);
			friend ComplexVariable& operator-(std::complex<double> x, ComplexVariable& y);
			friend ComplexVariable& operator-(ComplexVariable& x, ComplexVariable& y);

			friend ComplexVariable& operator/(ComplexVariable& x, std::complex<double> y);
			friend ComplexVariable& operator*(std::complex<double> x, ComplexVariable& y);
		
			friend ComplexVariable& operator==(ComplexVariable& x, ComplexVariable& y);
			friend ComplexVariable& operator==(ComplexVariable& x, std::complex<double> y);
			friend ComplexVariable& operator==(std::complex<double> x, ComplexVariable& y);
	};

	std::complex<double> solve(ComplexVariable& f);
}
