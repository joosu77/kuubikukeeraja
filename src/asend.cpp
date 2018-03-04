/*
 * asend.cpp
 *
 *  Created on: Jan 7, 2018
 *      Author: joosep
 */

#include "asend.h"

#include <stdlib.h>
#include <cstdio>
#include <string>

/**
 * Algväärtuseks on igal külje ruudl sama nimber mis külg
 */
asend::asend() {
	// kuljed[6][3][3];
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				kuljed[i][j][k] = i;
			}
		}
	}
}

/**
 * Koopia asendist other
 */
asend::asend(asend *other) {
	// kuljed[6][3][3];
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				kuljed[i][j][k] = other->kuljed[i][j][k];
			}
		}
	}
}

/**
 * copy assignment
 */
asend& asend::operator=(const asend& other) {
    if (this != &other) { // self-assignment check expected
    	for (int i = 0; i < 6; i++) {
    		for (int j = 0; j < 3; j++) {
    			for (int k = 0; k < 3; k++) {
    				this->kuljed[i][j][k] = other.kuljed[i][j][k];
    			}
    		}
    	}
    }

    return *this;
}

/**
 * equals
 */
bool asend::operator==(const asend& other) {
    if (this != &other) { // self-assignment check expected
    	for (int i = 0; i < 6; i++) {
    		for (int j = 0; j < 3; j++) {
    			for (int k = 0; k < 3; k++) {
    				if (this->kuljed[i][j][k] != other.kuljed[i][j][k]) {
    					return false;
    				}
    			}
    		}
    	}
    }

    return true;
}

std::string asend::toString() {
	// eraldame mälu piisavalt, et mahuks ära kogu kuubiku olek
	char *out = (char*) malloc (100);
	// kirjutame eraldautd puhvrisse olekumuutujad
	sprintf(out, "%1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c%1c %1c%1c%1c %1c%1c%1c %1c%1c%1c %1c%1c%1c %1c%1c%1c %1c%1c%1c %1c%1c%1c",
			kuljed[0][2][1], kuljed[2][0][1],
			kuljed[0][1][2],kuljed[3][0][1],
			kuljed[0][0][1],kuljed[5][2][1],
			kuljed[0][1][0],kuljed[1][0][1],
			kuljed[4][0][1],kuljed[2][2][1],
			kuljed[4][1][2],kuljed[3][2][1],
			kuljed[4][2][1],kuljed[5][0][1],
			kuljed[4][1][0],kuljed[1][2][1],
			kuljed[2][1][2],kuljed[3][1][0],
			kuljed[2][1][0],kuljed[1][1][2],
			kuljed[5][1][2],kuljed[3][1][2],
			kuljed[5][1][0],kuljed[1][1][0],
			kuljed[0][2][2],kuljed[2][0][2],kuljed[3][0][0],
			kuljed[0][0][2],kuljed[3][0][2],kuljed[5][2][2],
			kuljed[0][0][0],kuljed[5][2][0],kuljed[1][0][0],
			kuljed[0][2][0],kuljed[1][0][2],kuljed[2][0][0],
			kuljed[4][0][2],kuljed[3][2][0],kuljed[2][2][2],
			kuljed[4][0][0],kuljed[2][2][0],kuljed[1][2][2],
			kuljed[4][2][0],kuljed[1][2][0],kuljed[5][0][0],
			kuljed[4][2][2],kuljed[5][0][2],kuljed[3][2][2]
	);
	for(int i=0;i<67;i++){
		if (out[i] != ' '){
			out[i]="ULFRDB"[(int)out[i]];
		}
	}
	//std::cout <<"\n" << out << std::endl;
    std::string strOut {out};
    free(out);
    return strOut;
}

/**
 * Asendi C-stiilis võrdlusoperaator
 * TODO: pole selge, miks objekit võrdlusoperaatoriga linkimisviga tekkis
 * kui on välja selgitatud, miks mõlemat operaatorit tarvis, siis tuleb
 * üks teise väljakutsena realiseerida
 */
bool operator==(const asend& self, const asend& other) {
    if (&self != &other) { // self-assignment check expected
    	for (int i = 0; i < 6; i++) {
    		for (int j = 0; j < 3; j++) {
    			for (int k = 0; k < 3; k++) {
    				if (self.kuljed[i][j][k] != other.kuljed[i][j][k]) {
    					return false;
    				}
    			}
    		}
    	}
    }

    return true;
}

namespace std {

template <>
struct hash<asend>{
std::size_t operator()(const asend& k) const{
	using std::hash;

	std::size_t val = 0;
	int shift { 0 };
	for (int i = 0; i < 6; i++) {
		for (int o = 0; o < 3; o++) {
			for (int u = 0; u < 3; u++) {
				val = (val << shift) | k.kuljed[i][o][u];
				shift += 3;
			}
		}
	}

	return val;
}
};

