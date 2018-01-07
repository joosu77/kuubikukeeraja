/*
 * IDAlahendaja.h
 *
 *  Created on: Jan 7, 2018
 *      Author: joosep
 */

#include "valem.h"
#include "asend.h"
#include "lahendaja.h"

#ifndef IDALAHENDAJA_H_
#define IDALAHENDAJA_H_

class IDAlahendaja: public lahendaja {
	public:
		valem lahenda(asend);
		~IDAlahendaja(){};
};

#endif /* IDALAHENDAJA_H_ */
