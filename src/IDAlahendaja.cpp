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
	int attempts = 0;
	// käidud asendite hulk, mis sisaldab kõiki
	// juba nähtud asendeid, et neisse uuesti ei mindaks
	std::unordered_set<asend> kaidud {};
	// pooleli olevate valem hulk,
	// kust töödeldakse iga tsükli iteratsiooni jooksul ühte
	std::vector<valem> pooleli {};
	// muutuja, kuhu salvestatakse iga
	// tsükli iteratsiooni alguses töödeldav valem
	valem lahend {};
	// kuubik, mis on sisse antud asendis, seda pöörates
	// saab teada, kas valem lahendab kuubiku
	kuubik *sisKuup = new kuubik {sisAsend};
	// muutuja, kuhu salvestatakse, kas käesolev valem lahendab kuubiku
	bool korras = sisKuup->isSolved();
	// korratakse tsüklit, kuni leitakse lahendus
	while (!korras)  {
		attempts++;
		if (pooleli.size() > 0) {
			// võetakse pooleli olevate valemite hulgast esimene liige välja
			lahend = pooleli[0];
			pooleli.erase(pooleli.begin());
			sisKuup->turn(lahend);
			korras = sisKuup->isSolved();
		}

		if (!korras) {
			// võetud valem ei lahenda kuubikut ära
			if (kaidud.count(sisKuup->kuup) == 0){
				// seda olekut pole veel külastatud
				for (int i=0;i<12;i++){
					// realiseeritakse antud asendi peal kõik 12 võimalikku pööret
					// ja lisatakse saadud asend pooleldi olevate asendite hulka
					valem uus = lahend;
					uus.append("ULFRDB"[i%6],i<6);
					pooleli.push_back(uus);
				}
				// lisatakse asend juba läbi käidud asendite hulka,
				// et seda seda asendit edaspidi ei läbitaks
				kaidud.insert(sisKuup->kuup);
			}
		}
		// kuubik viiakse algolekusse tagasi
		delete sisKuup;
		sisKuup = new kuubik {sisAsend};
	}
	// prinditakse välja iteratsioonide kogus
	std::cout << "Kokku katseid: " << attempts << std::endl;
	// väljastatakse lahendusvalem
	return lahend;
}

