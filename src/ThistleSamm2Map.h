/*
 * ThistleSamm2Map.h
 *
 *  Created on: Mar 1, 2018
 *      Author: joosep
 */

#ifndef THISTLESAMM2MAP_H_
#define THISTLESAMM2MAP_H_

#include <map>
#include <string>

#include "valem.h"

class ThistleSamm2Map {
public:
	ThistleSamm2Map();
	virtual ~ThistleSamm2Map();
	valem getValem(std::string voti);
private:
	std::map<std::string,std::string> data;
};

#endif /* THISTLESAMM2MAP_H_ */
