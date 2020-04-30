#include "solver.hpp"
#include <complex>
#include <stdexcept>

using namespace std;
using namespace solver;



double solver::solve(RealVariable& f){
	double result = 0;
	if(f.a == 0 && f.b == 0){
		delete f.e;
		throw invalid_argument("There is no vriable in this equasion");
	}
	
		

	else if(f.a == 0){
		result = f.c/f.b;
		result = result - (2*result);
		delete f.e;
	}

	else{
		result = (f.b*f.b)-(4*f.a*f.c);
		if(result < 0){
			delete f.e;
			throw invalid_argument("There is no real solution");
				
		}

		result = sqrt(result);
		result = result - f.b;
		result = result/(2*f.a);
		delete f.e;
	}
	return result;	
}

RealVariable& solver::operator^(RealVariable& x, int y){
	if(!x.e){
		RealVariable *tmp = new RealVariable(1,0,0);
		tmp->e = tmp;
		return *tmp;
	}
		
	else{
		x.a = x.b*x.b;
		x.b = 0;
		x.c *= x.c;		
		return x;
	}	
}

RealVariable& solver::operator+(RealVariable& x, double y){
	
	if(!x.e){
		RealVariable *tmp = new RealVariable(0,1,y);
		tmp->e = tmp;
		return *tmp;
	}

	else{	
		x.c += y;
		return x;
	}
}

RealVariable& solver::operator+(double x, RealVariable& y){

	if(!y.e){
		RealVariable *tmp = new RealVariable(0,1,x);
		tmp->e = tmp;
		return *tmp;
	}

	else{	
		y.c += x;
		return y;
	}

}

RealVariable& solver::operator+(RealVariable& x, RealVariable& y){
	
	if(!x.e){
		RealVariable *tmp = new RealVariable(y.a, 1+y.b, y.c);
		tmp->e = tmp;
		delete y.e;
		return *tmp;
	}

	else{
		x.a+=y.a;
		x.b+=y.b;
		x.c+=y.c;
		delete y.e;
		return x;
	}
}

RealVariable& solver::operator-(RealVariable& x, double y){
	if(!x.e){
		RealVariable *tmp = new RealVariable(0,1,-y);
		tmp->e = tmp;
		return *tmp;
	}

	else{	
		x.c -= y;
		return x;
	}
}

RealVariable& solver::operator-(double x, RealVariable& y){
	if(!y.e){
		RealVariable *tmp = new RealVariable(0,1,-x);
		tmp->e = tmp;
		return *tmp;
	}

	else{	
		y.c -= x;
		return y;
	}
}

RealVariable& solver::operator-(RealVariable& x, RealVariable& y){
	if(!x.e){
		RealVariable *tmp = new RealVariable(y.a, 1-y.b, y.c);
		tmp->e = tmp;
		delete y.e;
		return *tmp;
	}

	else{
		x.a-=y.a;
		x.b-=y.b;
		x.c-=y.c;
		delete y.e;
		return x;
	}
}

RealVariable& solver::operator/(RealVariable& x, double y){
	if(!x.e){
		RealVariable *tmp = new RealVariable(0,1/y,0);
		tmp->e = tmp;
		return *tmp;
	}

	else{	
		x.a /= y;
		x.b /= y; 
		x.c /= y;
		return x;
	}
}

RealVariable& solver::operator*(double x, RealVariable& y){
	if(!y.e){
		RealVariable *tmp = new RealVariable(0,x,0);
		tmp->e = tmp;
		return *tmp;
	}

	else{	

		y.a *= x;
		y.b *= x; 
		y.c *= x;
		return y;
	}
}

RealVariable& solver::operator==(RealVariable& x, RealVariable& y){
	if(!x.e){
		RealVariable *tmp = new RealVariable(y.a, 1-y.b, y.c);
		tmp->e = tmp;
		delete y.e;
		return *tmp;
	}

	else{
		x.a-=y.a;
		x.b-=y.b;
		x.c-=y.c;
		delete y.e;
		return x;
	}
	
}

RealVariable& solver::operator==(RealVariable& x, double y){
	if(!x.e){
		RealVariable *tmp = new RealVariable(0,1,-y);
		tmp->e = tmp;
		return *tmp;
	}

	else{	
		x.c -= y;
		return x;
	}
}


RealVariable& solver::operator==(double x, RealVariable& y){
	if(!y.e){
		RealVariable *tmp = new RealVariable(0,1,-x);
		tmp->e = tmp;
		return *tmp;
	}

	else{	
		y.c -= x;
		return y;
	}
}

//------------------------------------------------------------------------------------------------------------

std::complex<double> solver::solve(ComplexVariable& f){
	std::complex<double> result = 0;
	if(real(f.a) == 0 && imag(f.a) == 0 && real(f.b) == 0 && imag(f.b) == 0){
		delete f.e;
		throw invalid_argument("There is no vriable in this equasion");
	}
	
		

	else if(real(f.a) == 0 && imag(f.a) == 0){
		result = -f.c/f.b;
		delete f.e;
	}

	else{
		result = (f.b*f.b) - std::complex<double>(-4*(f.a.real()*f.c.real()+f.a.imag()*f.c.imag()), 
							 (f.a.real()*f.c.imag()+f.a.imag()*f.c.real()));
		result = sqrt(result);
		result = result - f.b;
		result = result / std::complex<double>(2*f.a.real(),2*f.a.imag());
		delete f.e;
	}
	return result;	
}

ComplexVariable& solver::operator^(ComplexVariable& x, int y){

	if(!x.e){
		ComplexVariable *tmp = new ComplexVariable(1,0,0);
		tmp->e = tmp;
		return *tmp;
	}
		
	else{
		x.a = x.b*x.b;
		x.b = 0;
		x.c = x.c*x.c;
		return x;
	}

}

ComplexVariable& solver::operator+(ComplexVariable& x, std::complex<double> y){
	
	if(!x.e){
		ComplexVariable *tmp = new ComplexVariable(0,1,y);
		tmp->e = tmp;
		return *tmp;
	}

	else{	
		x.c += y;
		return x;
	}
}	

ComplexVariable& solver::operator+(std::complex<double> x, ComplexVariable& y){
	
	if(!y.e){
		ComplexVariable *tmp = new ComplexVariable(0,1,x);
		tmp->e = tmp;
		return *tmp;
	}

	else{	
		y.c += x; 
		return y;
	}
}



ComplexVariable& solver::operator+(ComplexVariable& x, ComplexVariable& y){
	
	if(!x.e){
		ComplexVariable *tmp = new ComplexVariable(y.a ,std::complex<double>(1+y.b.real(), y.b.imag()), y.c);
		tmp->e = tmp;
		delete y.e;
		return *tmp;
	}

	else{
		x.a += y.a;
		x.b += y.b;
		x.c += y.c;
		delete y.e;
		return x;
	}
}


ComplexVariable& solver::operator-(ComplexVariable& x, std::complex<double> y){
	
	if(!x.e){
		ComplexVariable *tmp = new ComplexVariable(0,1,-y);
		tmp->e = tmp;
		return *tmp;
	}

	else{	
		x.c -= y;
		return x;
	}
}	

ComplexVariable& solver::operator-(std::complex<double> x, ComplexVariable& y){
	
	if(!y.e){
		ComplexVariable *tmp = new ComplexVariable(0,1,-x);
		tmp->e = tmp;
		return *tmp;
	}

	else{	
		y.c -= x;
		return y;
	}
}



ComplexVariable& solver::operator-(ComplexVariable& x, ComplexVariable& y){
	
	if(!x.e){
		ComplexVariable *tmp = new ComplexVariable(y.a ,std::complex<double>(1-y.b.real(),y.b.imag()), y.c);
		tmp->e = tmp;
		delete y.e;
		return *tmp;
	}

	else{
		x.a -= y.a;
		x.b -= y.b;
		x.c -= y.c;
		delete y.e;
		return x;
	}
}

ComplexVariable& solver::operator/(ComplexVariable& x, std::complex<double> y){
	if(!x.e){
		ComplexVariable *tmp = new ComplexVariable(0,std::complex<double>(1/y.real(),1/y.imag()),0);
		tmp->e = tmp;
		return *tmp;
	}

	else{	
		x.a /= y;
		x.b /= y;
		x.c /= y;
		return x;
	}
}



ComplexVariable& solver::operator*(std::complex<double> x, ComplexVariable& y){
	if(!y.e){
		ComplexVariable *tmp = new ComplexVariable(0,x,0);
		tmp->e = tmp;
		return *tmp;
	}

	else{	

		y.a *= x;
		y.b *= x;
		y.c *= x;
		return y;
	}
}


ComplexVariable& solver::operator==(ComplexVariable& x, ComplexVariable& y){
	
	if(!x.e){
		ComplexVariable *tmp = new ComplexVariable(y.a ,std::complex<double>(1-y.b.real(),y.b.imag()), y.c);
		tmp->e = tmp;
		delete y.e;
		return *tmp;
	}

	else{
		x.a -= y.a;
		x.b -= y.b;
		x.c -= y.c;
		delete y.e;
		return x;
	}
}


ComplexVariable& solver::operator==(ComplexVariable& x, std::complex<double> y){
	
	if(!x.e){
		ComplexVariable *tmp = new ComplexVariable(0,1,-y);
		tmp->e = tmp;
		return *tmp;
	}

	else{	
		x.c -= y;
		return x;
	}
}



ComplexVariable& solver::operator==(std::complex<double> x, ComplexVariable& y){
	
	if(!y.e){
		ComplexVariable *tmp = new ComplexVariable(0,1,-x);
		tmp->e = tmp;
		return *tmp;
	}

	else{	
		y.c -= x;
		return y;
	}
}

