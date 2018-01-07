/*
 * IDAlahendaja.cpp
 *
 *  Created on: Jan 7, 2018
 *      Author: joosep
 */

#include "IDAlahendaja.h"

#include <deque>
#include <iostream>

#include "kuubik.h"
#include "asend.h"
#include "valem.h"

valem IDAlahendaja::lahenda(asend sisAsend) {
	std::deque<std::pair<kuubik, valem> > rivi { };
	int min { 21 };
	char kaigud[6] = { 'F', 'B', 'L', 'R', 'U', 'D' };
	kuubik sisKuup(sisAsend);
	valem tyhi {};
	rivi.push_back(std::make_pair(sisKuup, tyhi));
	long attempts { 0 };
	while (min > 20) {
		kuubik prgKuup = rivi.back().first;
		valem val = rivi.back().second;
		rivi.pop_back();
		for (int i = 0; i < 6; i++) {
			for (int o = 0; o < 2; o++) {
				attempts++;
				kuubik uus(prgKuup.kuup);
				valem kaik { };
				kaik.rida.push_back(std::make_pair(kaigud[i], o));
				uus.turn(kaik);
				if (uus.check()) {
					min = val.rida.size();
					std::cout << "Kokku katseid: " << attempts;
					std::cout << "Lahendamiseks kulus " << val.rida.size() << " kaiku";
					return val;
				}
				val.rida.push_back(std::make_pair(kaigud[i],o));
				rivi.push_back(std::make_pair(uus, val));
			}
		}
	}

	std::cout << "Kokku katseid: " << attempts;
	return tyhi;
}
