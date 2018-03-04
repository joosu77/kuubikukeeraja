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
	while (lahend.rida.size()==0 || first){
		valem tee { };
		asend olek { };
		if (first){
			olek = sisKuup.kuup;
		}else {
			tee = pooleli[0];
			std::cout << "alles: " << pooleli.size() << '\n';
			pooleli.erase(pooleli.begin());

			sisKuup.turn(tee);
			olek = sisKuup.kuup;
		}

		bool korras { false };
		if (sisKuup.isSolved()){
			korras = true;
			lahend.rida = tee.rida;
		}
		sisKuup.rewind();

		if (kaidud.count(olek) == 0 && korras == false){
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
		}
		kaidud.insert(olek);
		first = false;
		attempts++;
	}

	/*std::deque<valem> rivi { };
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
	}*/

	std::cout << "Kokku katseid: " << attempts;
	return lahend;
}

