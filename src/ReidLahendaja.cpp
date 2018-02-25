/*
 * ReidLahendaja.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: joosep
 */

#include "ReidLahendaja.h"

#include <stdio.h>
#include <stdlib.h>


ReidLahendaja::ReidLahendaja() {
	lahendaja();

}

/*ReidLahendaja::~ReidLahendaja() {
	~lahendaja();
}

valem ReidLahendaja::lahenda(asend sisAsend){


}*/

char* ReidLahendaja::asend2string(asend &sisAsend){
	// eraldame mälu piisavalt, et mahuks ära kogu kuubiku olek
	char *out = (char*) malloc (100);
	// kirjutame eraldautd puhvrisse olekumuutujad
	sprintf(out, "%1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c%1c %1c%1c%1c %1c%1c%1c %1c%1c%1c %1c%1c%1c %1c%1c%1c %1c%1c%1c %1c%1c%1c",
			sisAsend.kuljed[0][2][1], sisAsend.kuljed[2][0][1],
			sisAsend.kuljed[0][1][2],sisAsend.kuljed[3][0][1],
			sisAsend.kuljed[0][0][1],sisAsend.kuljed[5][0][1],
			sisAsend.kuljed[0][1][0],sisAsend.kuljed[1][0][1],
			sisAsend.kuljed[4][0][1],sisAsend.kuljed[2][2][1],
			sisAsend.kuljed[4][1][2],sisAsend.kuljed[3][2][1],
			sisAsend.kuljed[4][2][1],sisAsend.kuljed[5][2][1],
			sisAsend.kuljed[4][1][0],sisAsend.kuljed[1][2][1],
			sisAsend.kuljed[2][2][1],sisAsend.kuljed[3][0][1],
			sisAsend.kuljed[2][0][1],sisAsend.kuljed[1][2][1],
			sisAsend.kuljed[5][2][1],sisAsend.kuljed[3][0][1],
			sisAsend.kuljed[5][0][1],sisAsend.kuljed[1][2][1],
			sisAsend.kuljed[0][2][2],sisAsend.kuljed[2][0][2],sisAsend.kuljed[3][0][0],
			sisAsend.kuljed[0][0][2],sisAsend.kuljed[3][0][2],sisAsend.kuljed[5][2][2],
			sisAsend.kuljed[0][0][0],sisAsend.kuljed[5][2][0],sisAsend.kuljed[1][0][0],
			sisAsend.kuljed[0][2][0],sisAsend.kuljed[1][0][2],sisAsend.kuljed[2][0][0],
			sisAsend.kuljed[4][0][2],sisAsend.kuljed[3][2][0],sisAsend.kuljed[2][2][2],
			sisAsend.kuljed[4][0][0],sisAsend.kuljed[2][0][2],sisAsend.kuljed[1][2][2],
			sisAsend.kuljed[4][2][0],sisAsend.kuljed[1][2][0],sisAsend.kuljed[5][0][0],
			sisAsend.kuljed[4][2][2],sisAsend.kuljed[5][0][2],sisAsend.kuljed[3][2][2]
	);
	for(int i=0;i<67;i++){
		if (out[i] != ' '){
			out[i]="ULFRDB"[(int)out[i]];
		}
	}


	return out;
}
