/********************************************************************
  * Homework 1: rational.hpp
  *
  * Author: Istvan Gates
  *         ig11@zips.uakron.edu
  *
  * Purpose: create a rational number calculator with proper input validation and error handling
  *
  ********************************************************************/

#ifndef RATIONAL_HPP
#define RATIONAL_HPP
  class Rational {
  public:
  	int num, den;
	Rational() : num(0), den(1)
	{}

  	Rational(int n, int d) : num(n), den(d)
	{}

  	Rational(Rational const &r) : num(r.num), den(r.den)
  	{}

  	Rational& operator = (Rational const &r){}
  };


  int abs(int n);
  
  int findGCD(int a, int b);

  Rational operator +(Rational a, Rational b);
  Rational operator -(Rational a, Rational b);
  Rational operator *(Rational a, Rational b);
  Rational operator /(Rational a, Rational b);
  bool operator ==(Rational a, Rational b);
  bool operator !=(Rational a, Rational b);
  bool operator <(Rational a, Rational b);
  bool operator >(Rational a, Rational b);
  bool operator <=(Rational a, Rational b);
  bool operator >=(Rational a, Rational b);
  std::ostream& operator <<(std::ostream &os, Rational a);
  std::istream& operator >>(std::istream &is, Rational &a);
  
#endif

