/*
 * ValemMap.h
 *
 *  Created on: Mar 2, 2018
 */

#ifndef VALEMMAP_H_
#define VALEMMAP_H_

#include <map>
#include <string>
#include "valem.h"

/**
 * Baasklass valemitabelite salvestamiseks
 *
 */
class ValemMap {
public:
	ValemMap();
	virtual ~ValemMap();
	virtual valem getValem(std::string voti);
protected:
	std::map<std::string,std::string> data;
};

#endif /* VALEMMAP_H_ */
