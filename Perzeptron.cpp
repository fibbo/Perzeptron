#include <iostream>
#include <vector>
#include "Paar.h"
#include <stdio.h>
#include "random_gen.h"
#include <math.h>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/assign/std/vector.hpp>
#include <fstream>



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
	return (x>0);
 } 

void copyToBoost(std::vector<double> source, boost::numeric::ublas::vector<double> &result) {
		for (unsigned int i = 0; i < source.size(); i++) {
		result[i] = source[i];
	}
}

double sigmoid(double x) {
	return 1/(1+exp(-x));
}

boost::numeric::ublas::vector<double> * sigmoid(boost::numeric::ublas::vector<double> x) {
	boost::numeric::ublas::vector<double>* result = new boost::numeric::ublas::vector<double>(x.size());
	for (unsigned int i = 0; i<x.size();i++) 
	{
		result[i] = 1/(1+exp(-x[i])); // find a solution for vector function
	}
	return result;
}


double f(double x) {
	double a = 1;
	return 1/(1+exp(-a*x));
}

double fprime(double x) {
	double a = 1;
	return a*f(x)*(1-f(x));
}

void initWeights(boost::numeric::ublas::matrix<double> &m) {
	for (unsigned i = 0; i < m.size1 (); ++ i)
        for (unsigned j = 0; j < m.size2 (); ++ j)
            m (i, j) = RandomNGenerator::returnRandomD(-0.1, 0.1);
}

void Example24() {
	int N = 3;
	Paar p0(N), p1(N), p2(N), p3(N);
	
	
	// intermediate vectors - easier to assign a list of values. they then get copied to boost vectors
	std::vector<double> vv001, vv011, vv101, vv111;
	vv001 += 0,0,1; //+= only possible due to boost::assign
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
		double y = inner_prod(w,cur->input);
		int e = cur->output - UnitStep(y);
		w += eta*e*cur->input;
		cur = NULL;
		delete cur;
	}

	for (unsigned int i=0; i<4; i++) {
		std::cout << UnitStep(inner_prod(w, paarList[i]->input)) << std::endl;
	}
	std::cout << "########" << std::endl;
}

void Example28() {
	int N = 3;
	Paar p0(N), p1(N), p2(N), p3(N);
	
	
	// intermediate vectors - easier to assign a list of values. they then get copied to boost vectors
	std::vector<double> vv001, vv011, vv101, vv111;
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
		double y = inner_prod(w,cur->input);
		double e = cur->output - f(y);
		w += eta*e*fprime(y)*cur->input;
		cur = NULL;
		delete cur;
	}

	for (unsigned int i=0; i<4; i++) {
		std::cout << f(inner_prod(w, paarList[i]->input)) << std::endl;
	}
	std::cout << "########" << std::endl;
}

void Example29() {
	int N = 9;
	Paar p0(N), p1(N), p2(N), p3(N), p4(N), p5(N), p6(N), p7(N); //p0-3 are C's, p4-7 are T's
	
	
	// intermediate vectors - easier to assign a list of values. they then get copied to boost vectors
	std::vector<double> vvC0, vvC1, vvC2, vvC3, vvT0, vvT1, vvT2, vvT3;
	vvC0 += 0.9, 0.9, 0.9, 0.9, 0.1, 0.1, 0.9, 0.9, 0.9;
	vvC1 += 0.9, 0.9, 0.9, 0.9, 0.1, 0.9, 0.9, 0.1, 0.9;
	vvC2 += 0.9, 0.9, 0.9, 0.1, 0.1, 0.9, 0.9, 0.9, 0.9;
	vvC3 += 0.9, 0.1, 0.9, 0.9, 0.1, 0.9, 0.9, 0.9, 0.9;

	vvT0 += 0.9, 0.9, 0.9, 0.1, 0.9, 0.1, 0.1, 0.9, 0.1;
	vvT1 += 0.1, 0.1, 0.9, 0.9, 0.9, 0.9, 0.1, 0.1, 0.9;
	vvT2 += 0.1, 0.9, 0.1, 0.1, 0.9, 0.1, 0.9, 0.9, 0.9;
	vvT3 += 0.9, 0.1, 0.1, 0.9, 0.9, 0.9, 0.9, 0.1, 0.1;

	copyToBoost(vvC0,p0.input); p0.output = 0.1;
	copyToBoost(vvC1,p1.input); p1.output = 0.1;
	copyToBoost(vvC2,p2.input); p2.output = 0.1;
	copyToBoost(vvC3,p3.input); p3.output = 0.1;

	copyToBoost(vvT0,p4.input); p4.output = 0.9;
	copyToBoost(vvT1,p5.input); p5.output = 0.9;
	copyToBoost(vvT2,p6.input); p6.output = 0.9;
	copyToBoost(vvT3,p7.input); p7.output = 0.9;


	std::vector<Paar*> paarList;

	paarList.push_back(&p0);
	paarList.push_back(&p1);
	paarList.push_back(&p2);
	paarList.push_back(&p3);
	paarList.push_back(&p4);
	paarList.push_back(&p5);
	paarList.push_back(&p6);
	paarList.push_back(&p7);

	for (unsigned int i = 0; i<4; i++) {
		std::cout << paarList[i]->input << std::endl;
	}
	unsigned int innum = 9, hidnum = 3, outnum = 1;
	boost::numeric::ublas::matrix<double> wh (innum, hidnum);
	boost::numeric::ublas::matrix<double> wo (hidnum, outnum);
	initWeights(wh); initWeights(wo);
	double eta = 0.5;

	for (unsigned int i = 0; i<M; i++) {
		Paar* cur = paarList[RandomNGenerator::returnRandomI(0,7)];
		boost::numeric::ublas::vector<double> outhid = sigmoid(prod(wh,cur->input)); // length of this vector is 'hidnum'
		//boost::numeric::ublas::vector<double> out = sigmoid(prod(wo,outhid)); // out is usually of length 1 because the final output is just from one neuron
		//boost::numeric::ublas::vector<double> e = boost::numeric::ublas::vector<double>(boost::numeric::ublas::vector<double>(cur->output) - out); // e is also of length one
		//boost::numeric::ublas::vector<double> outdelta = boost::numeric::ublas::vector<double>(e[0]*out[0]*(1-out[0]));
		//boost::numeric::ublas::vector<double> onevec(hidnum,1);
		//boost::numeric::ublas::vector<double> hiddelta = inner_prod(outhid,(onevec-outhid))*prod(trans(wo),outdelta);
		/* #####  part below TBD  ##### */

	}
	
	std::cout << "########" << std::endl;
}


int main() {
	/*for (unsigned int i = 0; i<1; i++) {
		Example28();
	}*/
			//boost::numeric::ublas::vector<double> onevec(3);
			std::cout << "1";
	PressEnterToContinue();
return 0;
}

