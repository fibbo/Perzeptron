#include <boost/numeric/ublas/vector.hpp>
#include <boost/assign/std/vector.hpp>
#include <boost/numeric/ublas/io.hpp>

class Paar {
public:
	Paar(int n) { input.resize(n);
	}
	boost::numeric::ublas::vector< double > input;
	double output;
private:

};

/* int UnitStep(double x) {
 return (x>0);
 } */