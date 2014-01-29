#include <stdio.h>
#include <math.h>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <fstream>

class Paar {
public:
	Paar(int n) { input.resize(n);
	}
	boost::numeric::ublas::vector< double > input;
	double  output;
private:

};
