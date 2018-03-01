/*
 * ThistleLahendaja.h
 *
 *  Created on: Feb 26, 2018
 *      Author: joosep
 */

#ifndef THISTLELAHENDAJA_H_
#define THISTLELAHENDAJA_H_

#include <set>

#include "asend.h"
#include "lahendaja.h"

class ThistleLahendaja: public lahendaja {
public:
	//ThistleLahendaja();
	//virtual ~ThistleLahendaja();
	valem lahenda(asend sisAsend);
	char* asend2string(asend &);
	std::set <int> servaKontroll(asend sisAsend);
	bool serviKuljel(int kulg, std::set <int> servad);
	void samm1(asend sisAsend, std::set<valem> &lahendid);
	void samm1proovimiseta(asend sisAsend, std::set<valem> &lahendid);
	std::set<int> LRservaotsing(asend sisAsend);
	void samm2osa1(asend sisAsend, std::set<valem> &lahendid);
	void samm2osa2(asend sisAsend, std::set<valem> &lahendid);
	valem samm3(asend sisAsend);
	valem samm4(asend sisAsend);
};

#endif /* THISTLELAHENDAJA_H_ */
