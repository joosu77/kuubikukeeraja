/*
 * lahendaja.h
 *
 *  Created on: Jan 7, 2018
 *      Author: joosep
 */

#include "asend.h"
#include "valem.h"

#ifndef LAHENDAJA_H_
#define LAHENDAJA_H_

class lahendaja {
	public:
			virtual valem lahenda(asend);
			virtual ~lahendaja(){};
};

#endif /* LAHENDAJA_H_ */
