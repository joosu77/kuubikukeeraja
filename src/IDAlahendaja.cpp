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
	std::unordered_set<asend> kaidud {};
	std::vector<valem> pooleli { };

	valem lahend {};

	kuubik *sisKuup = new kuubik {sisAsend};
	bool korras { sisKuup->isSolved() };
	while (!korras)  {
		attempts++;

		if (pooleli.size() > 0) {
			// võtame ettevalmistatud valemite hulgast esimese
			// ja proovime sellega lahendada
			lahend = pooleli[0];
			pooleli.erase(pooleli.begin());
			sisKuup->turn(lahend);
			korras = sisKuup->isSolved();
		}

		if (!korras) {
			// ei lahenenud, lisame praeguse oleku alamolekud hulka juurde
			if (kaidud.count(sisKuup->kuup) == 0){
				// seda olekut pole veel külastatud
				for (int i=0;i<12;i++){
					if(i<6){
						valem uus = lahend;
						uus.append("ULFRDB"[i],true);
						pooleli.push_back(uus);
					} else {
						valem uus = lahend;
						uus.append("ULFRDB"[i-6], false);
						pooleli.push_back(uus);
					}
				}

				kaidud.insert(sisKuup->kuup);
			} else if (pooleli.size() == 0) {
				// jõudsime külastatud olekuni, ühtegi töötlemata valemit enam ei ole
				// järelikult lahendit ei leitud
				break;
			}
		}

		// kerime kuubiku algolekusse tagasi
		delete sisKuup;
		sisKuup = new kuubik {sisAsend};
	}

	std::cout << "Kokku katseid: " << attempts << std::endl;
	if (korras) {
		return lahend;
	} else {
		std::cout << "Lahendit ei leitud!" << std::endl;
		return *(new valem {});
	}
}

