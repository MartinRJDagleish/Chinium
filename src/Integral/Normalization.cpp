#include <Eigen/Dense>
#include <libint2.hpp>
#include <vector>
#include <string>
#include <iostream>

#include "../Macro.h"
#include "../Multiwfn/Multiwfn.h" // Requires <Eigen/Dense>, <vector>, <string>, "Macro.h".

#include "Macro.h"

void Normalize(Multiwfn* mwfn){
	__Make_Basis_Set__(mwfn)
	int ishell = 0;
	for ( MwfnCenter& center : mwfn->Centers ) for ( MwfnShell& shell : center.Shells ){
		std::copy(obs[ishell].contr[0].coeff.begin(), obs[ishell].contr[0].coeff.end(), shell.NormalizedCoefficients.begin());
		ishell++;
	}
}
