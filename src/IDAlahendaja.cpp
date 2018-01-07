/*
 * IDAlahendaja.cpp
 *
 *  Created on: Jan 6, 2018
 *      Author: joosep
 */

#include <deque>
#include <iostream>

#include "kuubik.h"
#include "asend.h"
#include "valem.h"

kuubik IDAlahendaja(kuubik sisKuup){
	std::deque < std::pair<kuubik,int> > rivi {};
	int min { 21 };
	char kaigud [6] = {'F','B','L','R','U','D'};
	rivi.push_back(std::make_pair(sisKuup,0));
	long attempts {0};
	while (min>20){
		kuubik prgKuup = rivi.back().first;
		int cntr { rivi.back().second };
		rivi.pop_back();
		for(int i=0;i<6;i++){
			for(int o=0;o<2;o++){
				attempts ++;
				kuubik uus = prgKuup;
				valem val { };
				val.rida.push_back(std::make_pair(kaigud[i],o));
				uus.turn(val);
				if(uus.check()){
					min=cntr;
					std::cout << "Kokku katseid: " << attempts;
					std::cout << "Lahendamiseks kulus " << cntr << " kaiku";
					return uus;
				}
				rivi.push_back(std::make_pair(uus,cntr+1));
			}
		}
	}

	std::cout << "Kokku katseid: " << attempts;
	return sisKuup;
}


