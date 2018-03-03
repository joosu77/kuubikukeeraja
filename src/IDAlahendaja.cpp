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
	std::deque<valem> rivi { };
	unsigned int min { 21 };
	char kaigud[6] = { 'F', 'B', 'L', 'R', 'U', 'D' };
	kuubik sisKuup(sisAsend);
	valem tyhi {};
	if (sisKuup.isSolved()) {
		std::cout << "kuup on juba lahendatud" << std::endl;
		valem kord {};
		return kord;
	}
	for (int i=0;i<6;i++){
		for (int o=0;o<2;o++){
			valem kord { };
			kord.append(kaigud[i],o);
			rivi.push_back(kord);
			sisKuup.turn(kord);
			if (sisKuup.isSolved()) {
				std::cout << "Lahendati 1 kaiguga" << std::endl;
				std::cout << kord.toString() << std::endl;
				return kord;
			}
			sisKuup.rewind();
		}
	}

	long attempts {0};
	while (rivi.size()) {
		valem val = rivi.back();

		rivi.pop_back();
		for (int i = 0; i < 6; i++) {
			for (int o = 0; o < 2; o++) {
				kask kontrollitav {kaigud[i],o};
				bool sama { true };
				if (val.size()>1){
					kask viimane = val.rida[val.rida.size()-1];
					kask eelviimane = val.rida[val.rida.size()-2];
					if (!(viimane == eelviimane && viimane == kontrollitav)){
						if (!(viimane.kylg == kontrollitav.kylg && viimane.edasi != kontrollitav.edasi)){
							/*for (unsigned int e=0;e<val.rida.size();e++){
								std::cout << val.rida[e].first << ((val.rida[e].second)?('*'):(' '));
							}
							std::cout << std::endl;*/
							sama = false;
						}
					}
				} else if (val.size()>0){
					kask viimane = val.rida[val.rida.size()-1];
					if (!(viimane.kylg == kontrollitav.kylg && viimane.edasi != kontrollitav.edasi)){
						sama = false;
					}
				} else {
					sama = false;
				}
				if (!sama){
					attempts++;
					val.rida.push_back(kontrollitav);
					sisKuup.turn(val);
					if (*sisKuup.kuup==sisAsend){
						sisKuup.rewind();
					} else if (sisKuup.isSolved()) {
						min = val.size();
						std::cout << "Kokku katseid: " << attempts << std::endl;
						std::cout << "Lahendamiseks kulus " << val.size() << " kaiku" << std::endl;
						std::cout << val.toString() << std::endl;
						return val;
					} else if (!((min-1)<val.rida.size()) ){
						//muuta tagasi push_backiks et saada depth-first
						rivi.push_front(val);
						sisKuup.rewind();
						val.rida.pop_back();
					}
				}
			}
		}
	}

	std::cout << "Kokku katseid: " << attempts;
	std::cout << "ei saanud lahendatud" << std::endl;
	return tyhi;
}
