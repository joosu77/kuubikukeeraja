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
	bool operator<(const valem& val2){
		valem val1 = *this;
		if (val1.rida.size() != val2.rida.size()){
			return val1.rida.size() < val2.rida.size();
		} else {
			int sum1=0;
			int sum2=0;
			for (unsigned int i=0;i<val1.rida.size();i++){
				sum1 *= 12;
				sum2 *= 12;
				std::string poorded = "ULFRDB";
				sum1 += poorded.find(val1.rida[i].first);
				sum1 += (val1.rida[i].second)?(0):(6);
				sum2 += poorded.find(val2.rida[i].first);
				sum2 += (val2.rida[i].second)?(0):(6);
			}
			return sum1 < sum2;
		}
	}
	valem& operator=(const valem& val2){
		this->rida = val2.rida;
		return *this;
	}
};



#endif /* VALEM_H_ */
