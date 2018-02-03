/*
 * asend.cpp
 *
 *  Created on: Jan 7, 2018
 *      Author: joosep
 */

#include "asend.h"

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

