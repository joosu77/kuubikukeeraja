/*
 * ThistleLahendaja.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: joosep
 */

#include "ThistleLahendaja.h"

#include <stdlib.h>
#include <cstdio>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>

#include "valem.h"
#include "asend.h"
#include "kuubik.h"

/*ThistleLahendaja::ThistleLahendaja() {
	// TODO Auto-generated constructor stub

}

ThistleLahendaja::~ThistleLahendaja() {
	// TODO Auto-generated destructor stub
}*/

valem ThistleLahendaja::lahenda(asend sisAsend){
	kuubik kuup;

	std::set<valem> lahendid;
	samm1(sisAsend, lahendid);
	samm2(sisAsend, lahendid);

	/*valem tulem { };
	tulem.rida.reserve(val1.rida.size()+val2.rida.size()+...);
	tulem.rida.insert(tulem.rida.end(),val1.rida.begin(),val1.rida.end());
	tulem.rida.insert(tulem.rida.end(),val2.rida.begin(),val2.rida.end());
	//...
*/
	valem tulem;
	return tulem;
}

char* ThistleLahendaja::asend2string(asend &sisAsend){
	// eraldame mälu piisavalt, et mahuks ära kogu kuubiku olek
	char *out = (char*) malloc (100);
	// kirjutame eraldautd puhvrisse olekumuutujad
	sprintf(out, "%1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c %1c%1c%1c %1c%1c%1c %1c%1c%1c %1c%1c%1c %1c%1c%1c %1c%1c%1c %1c%1c%1c %1c%1c%1c",
			sisAsend.kuljed[0][2][1], sisAsend.kuljed[2][0][1],
			sisAsend.kuljed[0][1][2],sisAsend.kuljed[3][0][1],
			sisAsend.kuljed[0][0][1],sisAsend.kuljed[5][2][1],
			sisAsend.kuljed[0][1][0],sisAsend.kuljed[1][0][1],
			sisAsend.kuljed[4][0][1],sisAsend.kuljed[2][2][1],
			sisAsend.kuljed[4][1][2],sisAsend.kuljed[3][2][1],
			sisAsend.kuljed[4][2][1],sisAsend.kuljed[5][0][1],
			sisAsend.kuljed[4][1][0],sisAsend.kuljed[1][2][1],
			sisAsend.kuljed[2][1][2],sisAsend.kuljed[3][1][0],
			sisAsend.kuljed[2][1][0],sisAsend.kuljed[1][1][2],
			sisAsend.kuljed[5][1][2],sisAsend.kuljed[3][1][2],
			sisAsend.kuljed[5][0][1],sisAsend.kuljed[1][2][1],
			sisAsend.kuljed[0][2][2],sisAsend.kuljed[2][0][2],sisAsend.kuljed[3][0][0],
			sisAsend.kuljed[0][0][2],sisAsend.kuljed[3][0][2],sisAsend.kuljed[5][2][2],
			sisAsend.kuljed[0][0][0],sisAsend.kuljed[5][2][0],sisAsend.kuljed[1][0][0],
			sisAsend.kuljed[0][2][0],sisAsend.kuljed[1][0][2],sisAsend.kuljed[2][0][0],
			sisAsend.kuljed[4][0][2],sisAsend.kuljed[3][2][0],sisAsend.kuljed[2][2][2],
			sisAsend.kuljed[4][0][0],sisAsend.kuljed[2][2][0],sisAsend.kuljed[1][2][2],
			sisAsend.kuljed[4][2][0],sisAsend.kuljed[1][2][0],sisAsend.kuljed[5][0][0],
			sisAsend.kuljed[4][2][2],sisAsend.kuljed[5][0][2],sisAsend.kuljed[3][2][2]
	);
	for(int i=0;i<67;i++){
		if (out[i] != ' '){
			out[i]="ULFRDB"[(int)out[i]];
		}
	}
	return out;
}

std::set<int> ThistleLahendaja::servaKontroll(asend sisAsend){
	std::set<int> headServad { };
	char* sisString = asend2string(sisAsend);

	for(int i=0;i<12;i++){

		if(i%2==1 || i>7){
			if (sisString[i*3] == 'F' || sisString[i*3] == 'B' || ((sisString[i*3] == 'U' || sisString[i*3] == 'D') && (sisString[i*3+1] == 'L' || sisString[i*3+1] == 'R'))){
				headServad.insert(i);
			}
		} else if (sisString[i*3+1] == 'F' || sisString[i*3+1] == 'B' || ((sisString[i*3+1] == 'U' || sisString[i*3+1] == 'D') && (sisString[i*3] == 'L' || sisString[i*3] == 'R'))){
			headServad.insert(i);
		}
	}
	return headServad;
}

bool ThistleLahendaja::serviKuljel(int kulg, std::set<int> servad){
	bool res { false };
	if (kulg==0){
		if (servad.count(0) || servad.count(1) || servad.count(2) || servad.count(3)){
			res = true;
		}
	} else if (kulg==1){
		if (servad.count(3) || servad.count(7) || servad.count(9) || servad.count(11)){
			res = true;
		}
	} else if (kulg==2){
		if (servad.count(0) || servad.count(4) || servad.count(8) || servad.count(9)){
			res = true;
		}
	} else if (kulg==3){
		if (servad.count(1) || servad.count(5) || servad.count(8) || servad.count(10)){
			res = true;
		}
	} else if (kulg==4){
		if (servad.count(4) || servad.count(5) || servad.count(6) || servad.count(7)){
			res = true;
		}
	} else if (kulg==5){
		if (servad.count(2) || servad.count(6) || servad.count(10) || servad.count(11)){
			res = true;
		}
	}

	return res;
}

//valem& operator=(const valem& val2){
//	this->rida = val2.rida;
//	return *this;
//}

namespace std {

  template <>
  struct hash<asend>{
    std::size_t operator()(const asend& k) const{
      std::size_t val = 0;
      int shift{0};
      for (int i=0;i<6;i++){
    	  for (int o=0;o<3;o++){
    		  for (int u=0;u<3;u++){
    			  val = (val << shift) | k.kuljed[i][o][u];
    			  shift += 3;
    		  }
    	  }
      }

     return val;
    }
  };

}

namespace std {

	template <>
	struct hash<valem>{
		std::size_t operator()(const valem& k) const{
			using std::string;
		    using std::hash;

			std::string str;
			for (unsigned int i=0;i<k.rida.size();i++){
				str += (k.rida[i].first);
				str += (k.rida[i].second?' ':'*');
			}

			return hash<string>()(str);
		}
	};
}
/**
 * kontrollib, millised servad on "head" servad
 * leiab kõik valemid millega jõuab asendisse,
 * kus kõik servad on "head", ja kutsub nendega samm2 välja
 *
 * "hea" serv - serv, millel on enda kohale jõudmiseks vaja teha paarisarv U ja D pöördeid
 */
void ThistleLahendaja::samm1(asend sisAsend, std::set<valem> &lahendid){
	std::set<int> headServad = servaKontroll(sisAsend);

	kuubik sisKuup {sisAsend};
	std::unordered_map<asend, int> kaidud {};
	std::vector<std::pair<valem, int> > pooleli { };
	while (pooleli.size()){
		valem tee = pooleli[pooleli.size()-1].first;
		int kaugus { pooleli[pooleli.size() - 1].second };
		pooleli.pop_back();

		sisKuup.turn(tee);
		asend olek = sisKuup.kuup;
		sisKuup.rewind();
		headServad = servaKontroll(olek);

		bool korras { false };
		if (headServad.size()==12){
			korras = true;
			lahendid.insert(tee);
		}

		if (kaugus<7 && kaidud.count(olek) == 0 && korras == false){
			for (int i=0;i<12;i++){
				if (serviKuljel(i%6,headServad)){
					if(i<6){
						valem uus = tee;
						uus.rida.push_back(std::make_pair("ULFRDB"[i],true));
						pooleli.push_back(std::make_pair(uus, kaugus+1));
					} else {
						valem uus = tee;
						uus.rida.push_back(std::make_pair("ULFRDB"[i-6], false));
						pooleli.push_back(std::make_pair(uus, kaugus+1));
					}
				}
			}
		}
		kaidud[olek]=kaugus;
	}
}

valem ThistleLahendaja::samm2(asend sisAsend, std::set<valem> &lahendid){
	/*int min { 20 };
	std::set<valem>::iterator minIte { };
	for (std::set<valem>::iterator ite = lahendid.begin();ite != lahendid.end();++ite){
		if ((*ite).rida.size()<min){
			min=(*ite).rida.size();
			minIte = ite;
		}
	}
	sisKuup.turn(*minIte);
	valem tee = samm2(sisKuup.kuup,20-min);
	sisKuup.rewind();
	lahendid.erase(minIte);
	int parimNum = tee.rida.size();

	for (std::set<valem>::iterator ite = lahendid.begin();ite != lahendid.end();++ite){
		valem tulem = samm2(*ite, parimNum-(*ite).rida.size());
		if (parimN)
	}*/
}
