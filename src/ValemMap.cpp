/*
 * ValemMap.cpp
 *
 *  Created on: Mar 2, 2018
 *      Author: naks
 */

#include "ValemMap.h"

ValemMap::ValemMap() {
	// TODO Auto-generated constructor stub

}

ValemMap::~ValemMap() {
	data.clear();
}

valem ValemMap::getValem(std::string voti){
	if(data.count(voti)){
		return *(new valem {data[voti]});
	} else {
		return *(new valem { });
	}
}
