/********************************************************************
  * Homework 1: rational.cpp
  *
  * Author: Istvan Gates
  *         ig11@zips.uakron.edu
  *
  * Purpose: create a rational  aber calculator with proper input validation and error handling
  *
  ********************************************************************/
#include <iostream>
#include <string>
#include <cctype>
#include <cstddef>
#include <stdio.h>
#include "rational.hpp"


	
  	void Rational (int n, int d) {
  		if(d < 0) {
  			n = (n * -1);
  			d = (d * -1);
  		}
  		int gcd = findGCD(n, d);

  		n = n / gcd;
  		d = d / gcd;
  	}

  	Rational (Rational const &r) : num(r.num), den(r.den) {
	if (denominator == 0){
	cout << "" << endl;
	std::cerr << "ERROR: Divide by 0";
	cin.setstate(ios::ios_base::failbit);
		}
	}

  	void Rational &operator = (Rational const &r) {
  		num = r.num;
  		num = r.den;
  		*this;
  	}
  


  int abs(int n) {
  	if (n < 0)
  		return -n;
  	else
  		return n;
  }


  int findGCD(int a, int b) {
  	a = abs(a);
  	b = abs(b);
  	if (b == 0){
  		return a;
  	} 
  	else {
  		findGCD(b, a % b);
  	}
  }

  Rational operator +(Rational a, Rational b) {

  	Rational c(a.num*b.den + b.num*a.den, 
  		a.den*b.den);
  	return c;
  }

  Rational operator -(Rational a, Rational b) {
  	Rational c(a.num*b.den - b.num*a.den, 
  		a.den*b.den);

  	return c;
  }

  Rational operator *(Rational a, Rational b) {
  	Rational c(a.num*b.num,	a.den*b.den);

  	return c;
  }

  Rational operator /(Rational a, Rational b) {
  	Rational c(a.num*b.den, a.den*b.num);

  	return c;
  }

  bool operator ==(Rational a, Rational b) {
  	return (a.num == b.num) && (a.den == b.den);
  }

  bool operator !=(Rational a, Rational b) {
  	return !((a.num == b.num) && (a.den == b.den));

  }

  bool operator <(Rational a, Rational b) {
  	int anum, bnum;

  	anum = a.num * b.den;
  	bnum = b.num * a.den;

  	return (anum < bnum);
  }

  bool operator >(Rational a, Rational b) {
  	int anum, bnum;

  	anum = a.num * b.den;
  	bnum = b.num * a.den;

  	return !(anum < bnum);

  }

  bool operator <=(Rational a, Rational b) {
  	int anum, bnum;

  	anum = a.num * b.den;
  	bnum = b.num * a.den;

  	return !(bnum < anum);
  }

  bool operator >=(Rational a, Rational b) {
  	int anum, bnum;

  	anum = a.num * b.den;
  	bnum = b.num * a.den;
  	return (!(anum < bnum));
  }    		


  std::ostream& operator <<(std::ostream &os, Rational a) {
  	if(a.den == 0){
  		fprintf (stderr, "error, zero in denominator\n");
  	}
  	else if(a.den == 1){
    		// os << a.num;
  		os << a.num;

  	} else{
  		os << a.num << "/" << a.den;
  	}

  	return os;
  }

  std::istream& operator >>(std::istream &is, Rational &a) {
  	char c;

  	is >> a.num >> c >> a.den;
  	if(!(c == '/')){
  		a.den = 1;
  	}

  	int	gcd = findGCD(a.num, a.den);

  	a.num = a.num / gcd;
  	a.den = a.den / gcd;

  	if(a.den < 0){
  		a.den = -a.den;
  		a.num = -a.num;
  	} 

  	return is;
  }
