/*
 * IDAlahendaja.cpp
 *
 *  Created on: Jan 7, 2018
 *      Author: joosep
 */

#include "IDAlahendaja.h"

#include <deque>
#include <iostream>
#include <utility>

#include "kuubik.h"
#include "asend.h"
#include "valem.h"

valem IDAlahendaja::lahenda(asend sisAsend) {
	std::deque<std::pair<kuubik, valem> > rivi { };
	unsigned int min { 21 };
	char kaigud[6] = { 'F', 'B', 'L', 'R', 'U', 'D' };
	kuubik sisKuup(sisAsend);
	valem tyhi {};
	rivi.push_back(std::make_pair(sisKuup, tyhi));
	long attempts { 0 };
	while (rivi.size()) {
		kuubik prgKuup(rivi.back().first.kuup);
		valem val = rivi.back().second;
		rivi.pop_back();
		for (int i = 0; i < 6; i++) {
			for (int o = 0; o < 2; o++) {
				std::pair<char,bool> paar = std::make_pair(kaigud[i],o);
				bool sama { true };
				if (val.rida.size()>2){
					if (!(val.rida[-1] == val.rida[-2] && val.rida[-1] == paar)){
						sama = false;
					}
				} else {
					sama = false;
				}
				if (!sama){
					attempts++;
					kuubik uus(prgKuup.kuup);
					valem kaik { };
					kaik.rida.push_back(paar);
					uus.turn(kaik);
					if (uus.check()) {
						min = val.rida.size();
						std::cout << "Kokku katseid: " << attempts << std::endl;
						std::cout << "Lahendamiseks kulus " << val.rida.size() << " kaiku" << std::endl;
						for (unsigned int e=0;e<val.rida.size();e++){
							std::cout << val.rida[e].first << ((val.rida[e].second)?('*'):(' '));
						}
						std::cout << std::endl;
						return val;
					}
					if (!((min-1)==val.rida.size()) ){
						val.rida.push_back(paar);
						//muuta tagasi push_backiks et saada depth-first
						rivi.push_front(std::make_pair(uus, val));
					}
				}
			}
		}
	}

	std::cout << "Kokku katseid: " << attempts;
	return tyhi;
}
