/*
 * ThistleSamm3TeineMap.h
 *
 *  Created on: Mar 11, 2018
 *      Author: joosep
 */

#ifndef THISTLESAMM3TEINEMAP_H_
#define THISTLESAMM3TEINEMAP_H_

#include "ValemMap.h"
#include "ThistleLahendaja.h"

class ThistleSamm3TeineMap: public ValemMap {
public:
	ThistleSamm3TeineMap(ALPHA a, BETA b);
	ThistleSamm3TeineMap();
	valem getValem(std::string voti);
};

#endif /* THISTLESAMM3TEINEMAP_H_ */
