/*
 * valem.h
 *
 *  Created on: Jan 5, 2018
 *      Author: joosep
 */

#include <string>
#include <utility>
#include <vector>

#ifndef VALEM_H
#define VALEM_H

struct valem{
	std::vector <std::pair <char, bool> > rida;
};

bool operator<(const valem& val1, const valem& val2);

#endif /* VALEM_H_ */
