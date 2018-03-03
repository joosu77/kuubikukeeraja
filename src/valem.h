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

class valem{
	public:
		std::vector <std::pair <char, bool> > rida;
		valem(std::string);
		valem();
		void print();
		std::string toString() const;
		bool operator==(const std::string &other);
		valem &operator=(const valem&);
};

bool operator<(const valem& val1, const valem& val2);

#endif /* VALEM_H_ */
