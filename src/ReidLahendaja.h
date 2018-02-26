/*
 * ReidLahendaja.h
 *
 *  Created on: Feb 25, 2018
 *      Author: joosep
 */

#ifndef REIDLAHENDAJA_H_
#define REIDLAHENDAJA_H_

#include "asend.h"
#include "lahendaja.h"

class ReidLahendaja: public lahendaja {
public:
	ReidLahendaja();
	//virtual ~ReidLahendaja();
	valem lahenda(asend sisAsend);
	char* asend2string(asend &);
};

#endif /* REIDLAHENDAJA_H_ */
