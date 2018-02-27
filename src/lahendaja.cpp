/*
 * lahendaja.cpp
 *
 *  Created on: Jan 7, 2018
 *      Author: joosep
 */

#include "lahendaja.h"

#include <iostream>
#include <vector>


valem lahendaja::lahenda(asend c){
	valem val { };
	return val;
}

void lahendaja::printValem(valem &sisend){
	std::cout << "Prindin valemit: ";
	for (int i=0;i<sisend.rida.size();i++){
		std::cout << sisend.rida[i].first << (sisend.rida[i].second?' ':'*');
	}
	std::cout << "\n";
}
