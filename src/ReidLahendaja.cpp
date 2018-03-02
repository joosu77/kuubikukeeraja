/*
 * ReidLahendaja.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: joosep
 */

#include "ReidLahendaja.h"

#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

#include "optimal.h"

ReidLahendaja::ReidLahendaja() {
	lahendaja();

}

/*ReidLahendaja::~ReidLahendaja() {
	~lahendaja();
}*/

valem ReidLahendaja::lahenda(asend sisAsend){
	const char* sisend = sisAsend.toString().c_str();
	char* valjund = optimalLahendaja(sisend);
	valem tulem { };
	int i { 0 };
	while ((int)valjund[i*3] != 0){
		if (valjund[i*3+1] == '2'){
			tulem.rida.push_back(std::make_pair(valjund[i*3],true));
			tulem.rida.push_back(std::make_pair(valjund[i*3],true));
		}else {
			tulem.rida.push_back(std::make_pair(valjund[i*3],valjund[i*3+1]==' '));
		}
		i++;
	}
	tulem.print();
	return tulem;
}
