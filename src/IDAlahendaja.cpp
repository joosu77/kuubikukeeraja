/*
 * IDAlahendaja.cpp
 *
 *  Created on: Jan 7, 2018
 *      Author: joosep
 */

#include "IDAlahendaja.h"

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "kuubik.h"

valem IDAlahendaja::lahenda(asend sisAsend) {
	int attempts { 0 };
	kuubik sisKuup {sisAsend};
	std::unordered_set<asend> kaidud {};
	std::vector<valem> pooleli { };

	bool first { true };
	valem lahend {};
	bool korras { false };

	while (!korras){
		valem tee { };
		asend olek { };
		if (first){
			olek = sisKuup.kuup;
			first = false;
		} else {
			tee = pooleli[0];
			std::cout << "alles: " << pooleli.size() << '\n';
			pooleli.erase(pooleli.begin());

			sisKuup.turn(tee);
			olek = sisKuup.kuup;
		}


		if (sisKuup.isSolved()){
			korras = true;
			lahend.rida = tee.rida;
		}
		sisKuup.rewind();

		if (kaidud.count(olek) == 0 && !korras){
			for (int i=0;i<12;i++){
				if(i<6){
					valem uus = tee;
					uus.append("ULFRDB"[i],true);
					pooleli.push_back(uus);
				} else {
					valem uus =tee;
					uus.append("ULFRDB"[i-6], false);
					pooleli.push_back(uus);
				}
			}

			kaidud.insert(olek);
		}

		attempts++;
	}

	std::cout << "Kokku katseid: " << attempts;
	return lahend;
}

