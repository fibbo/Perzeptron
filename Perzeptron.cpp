#include <iostream>
#include <vector>
#include "Paar.h"
#include <stdio.h>
#include "random_gen.h"
#include <math.h>


#define N 3
#define M 1500000

using namespace boost::assign;

void PressEnterToContinue()
  {
  int c;
  printf( "Press ENTER to continue... " );
  fflush( stdout );
  do c = getchar(); while ((c != '\n') && (c != EOF));
  }

int UnitStep(double x) {
	if (x > 0) return 1;
	else return 0;
}

void copyToBoost(std::vector<int> source, boost::numeric::ublas::vector<int> &result) {
		for (unsigned int i = 0; i < source.size(); i++) {
		result[i] = source[i];
	}
}

double f(double x) {
	double a = 1;
	return 1/(1+exp(-a*x));
}

double fprime(double x) {
	double a = 1;
	return a*f(x)*(1-f(x));
}
void Example24() {
	Paar p0(N), p1(N), p2(N), p3(N);
	
	
	// intermediate vectors - easier to assign a list of values. they then get copied to boost vectors
	std::vector<int> vv001, vv011, vv101, vv111;
	vv001 += 0,0,1;
	vv011 += 0,1,1;
	vv101 += 1,0,1;
	vv111 += 1,1,1;


	// copy to boost vectors of the Paar objects & assigning output values
	copyToBoost(vv001,p0.input); p0.output = 0;
	copyToBoost(vv011,p1.input); p1.output = 0;
	copyToBoost(vv101,p2.input); p2.output = 0;
	copyToBoost(vv111,p3.input); p3.output = 1;

	// creating list for input Pairs and filling it with all the inputs
	std::vector<Paar*> paarList;
	paarList.push_back(&p0);
	paarList.push_back(&p1);
	paarList.push_back(&p2);
	paarList.push_back(&p3);

	/*for (unsigned int i = 0; i<4; i++) {
		std::cout << paarList[i]->input << std::endl;
	}*/

	double eta = 0.2; // learning rate eta

	// w = weights of the single inputs - initialized with random numbers
	boost::numeric::ublas::vector<double> w(3);
	for (unsigned int i = 0; i<w.size(); i++) {
		w(i) = RandomNGenerator::returnRandomD(0,1);
	}

	//std::cout << w << std::endl;
	//std::cout << v001 << std::endl;
	//std::cout << v011 << std::endl;
	//std::cout << v101 << std::endl;
	//std::cout << v111 << std::endl;


	// learning steps - chose a pair randomly and test it's input with the current weights and compare to target value. UnitStep is the learning function
	for (unsigned int i = 0; i<M; i++) {
		Paar* cur = paarList[RandomNGenerator::returnRandomI(0,3)];
		double y = boost::numeric::ublas::inner_prod(w,cur->input);
		int e = cur->output - UnitStep(y);
		w += eta*e*cur->input;
		cur = NULL;
		delete cur;
	}

	for (unsigned int i=0; i<4; i++) {
		std::cout << UnitStep(boost::numeric::ublas::inner_prod(w, paarList[i]->input)) << std::endl;
	}
	std::cout << "########" << std::endl;
}

void Example28() {
	Paar p0(N), p1(N), p2(N), p3(N);
	
	
	// intermediate vectors - easier to assign a list of values. they then get copied to boost vectors
	std::vector<int> vv001, vv011, vv101, vv111;
	vv001 += 0,0,1;
	vv011 += 0,1,1;
	vv101 += 1,0,1;
	vv111 += 1,1,1;

	copyToBoost(vv001,p0.input); p0.output = 0;
	copyToBoost(vv011,p1.input); p1.output = 0;
	copyToBoost(vv101,p2.input); p2.output = 0;
	copyToBoost(vv111,p3.input); p3.output = 1;

	std::vector<Paar*> paarList;

	paarList.push_back(&p0);
	paarList.push_back(&p1);
	paarList.push_back(&p2);
	paarList.push_back(&p3);

	/*for (unsigned int i = 0; i<4; i++) {
		std::cout << paarList[i]->input << std::endl;
	}*/

	double eta = 0.5;
	boost::numeric::ublas::vector<double> w(3);

	for (unsigned int i = 0; i<w.size(); i++) {
		w(i) = RandomNGenerator::returnRandomD(0,1);
	}

	//std::cout << w << std::endl;
	//std::cout << v001 << std::endl;
	//std::cout << v011 << std::endl;
	//std::cout << v101 << std::endl;
	//std::cout << v111 << std::endl;

	for (unsigned int i = 0; i<M; i++) {
		Paar* cur = paarList[RandomNGenerator::returnRandomI(0,3)];
		double y = boost::numeric::ublas::inner_prod(w,cur->input);
		double e = cur->output - f(y);
		w += eta*e*fprime(y)*cur->input;
		cur = NULL;
		delete cur;
	}

	for (unsigned int i=0; i<4; i++) {
		std::cout << f(boost::numeric::ublas::inner_prod(w, paarList[i]->input)) << std::endl;
	}
	std::cout << "########" << std::endl;
}

int main() {
	for (unsigned int i = 0; i<1; i++) {
		Example28();
	}
	PressEnterToContinue();
return 0;
}

