/*
 * ThistleSamm4Map.h
 *
 *  Created on: Apr 28, 2018
 *      Author: joosep
 */

#ifndef THISTLESAMM4MAP_H_
#define THISTLESAMM4MAP_H_

#include "ValemMap.h"

class ThistleSamm4Map: public ValemMap {
protected:
	std::map<int,std::string> data;
public:
	valem getValem(int voti);
	ThistleSamm4Map (bool kylgKorras, int kaksTsykleid, int kolmTsykleid, int neliTsykleid);
	int suurus;
};

#endif /* THISTLESAMM4MAP_H_ */
