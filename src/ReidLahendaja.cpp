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
	char* valjund = optimalLahendaja(asend2string(sisAsend));
	valem tulem;
	int i =0;
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

char* ReidLahendaja::asend2string(asend &sisAsend){
	// eraldame mälu piisavalt, et mahuks ära kogu kuubiku olek
	char *out = (char*) malloc (100);
	// kirjutame eraldautd puhvrisse olekumuutujad
	sprintf(out, "%1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c%1c %1c%1c%1c %1c%1c%1c %1c%1c%1c %1c%1c%1c %1c%1c%1c %1c%1c%1c %1c%1c%1c",
			sisAsend.kuljed[0][2][1], sisAsend.kuljed[2][0][1],
			sisAsend.kuljed[0][1][2],sisAsend.kuljed[3][0][1],
			sisAsend.kuljed[0][0][1],sisAsend.kuljed[5][2][1],
			sisAsend.kuljed[0][1][0],sisAsend.kuljed[1][0][1],
			sisAsend.kuljed[4][0][1],sisAsend.kuljed[2][2][1],
			sisAsend.kuljed[4][1][2],sisAsend.kuljed[3][2][1],
			sisAsend.kuljed[4][2][1],sisAsend.kuljed[5][0][1],
			sisAsend.kuljed[4][1][0],sisAsend.kuljed[1][2][1],
			sisAsend.kuljed[2][1][2],sisAsend.kuljed[3][1][0],
			sisAsend.kuljed[2][1][0],sisAsend.kuljed[1][1][2],
			sisAsend.kuljed[5][1][2],sisAsend.kuljed[3][1][2],
			sisAsend.kuljed[5][1][0],sisAsend.kuljed[1][1][0],
			sisAsend.kuljed[0][2][2],sisAsend.kuljed[2][0][2],sisAsend.kuljed[3][0][0],
			sisAsend.kuljed[0][0][2],sisAsend.kuljed[3][0][2],sisAsend.kuljed[5][2][2],
			sisAsend.kuljed[0][0][0],sisAsend.kuljed[5][2][0],sisAsend.kuljed[1][0][0],
			sisAsend.kuljed[0][2][0],sisAsend.kuljed[1][0][2],sisAsend.kuljed[2][0][0],
			sisAsend.kuljed[4][0][2],sisAsend.kuljed[3][2][0],sisAsend.kuljed[2][2][2],
			sisAsend.kuljed[4][0][0],sisAsend.kuljed[2][2][0],sisAsend.kuljed[1][2][2],
			sisAsend.kuljed[4][2][0],sisAsend.kuljed[1][2][0],sisAsend.kuljed[5][0][0],
			sisAsend.kuljed[4][2][2],sisAsend.kuljed[5][0][2],sisAsend.kuljed[3][2][2]
	);
	for(int i=0;i<67;i++){
		if (out[i] != ' '){
			out[i]="ULFRDB"[(int)out[i]];
		}
	}
	//std::cout <<"\n" << out << std::endl;

	return out;
}
