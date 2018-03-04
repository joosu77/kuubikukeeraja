/*
 * ThistleLahendaja.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: joosep
 */

#include "ThistleLahendaja.h"

#include <cstddef>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "kuubik.h"
#include "ThistleSamm2Map.h"
#include "ThistleSamm3InitialMap.h"

//TODO: notes: tuleb alpha ja beta hulgast valida õiged liikmed millega korrutada, alpha ja beta järgi valitakse coset

/**
 *
 */
valem ThistleLahendaja::lahenda(asend sisAsend){
	kuubik kuup { };

	std::set<valem> lahendid { };
	samm1(sisAsend, lahendid);

	/*valem tulem { };
	tulem.rida.reserve(val1.size()+val2.size()+...);
	tulem.rida.insert(tulem.rida.end(),val1.rida.begin(),val1.rida.end());
	tulem.rida.insert(tulem.rida.end(),val2.rida.begin(),val2.rida.end());
	//...
*/
	valem tulem { };
	return tulem;
}

/**
 *
 */
std::set<int> ThistleLahendaja::servaKontroll(asend sisAsend){
	std::set<int> headServad { };
	std::string sisString = sisAsend.toString();

	for(int i=0;i<12;i++){

		if(i%2==1 || i>7){
			if (sisString[i*3] == 'F' || sisString[i*3] == 'B' ||
					((sisString[i*3] == 'U' || sisString[i*3] == 'D') &&
							(sisString[i*3+1] == 'L' || sisString[i*3+1] == 'R'))){
				headServad.insert(i);
			}
		} else if (sisString[i*3+1] == 'F' || sisString[i*3+1] == 'B' ||
				((sisString[i*3+1] == 'U' || sisString[i*3+1] == 'D') &&
						(sisString[i*3] == 'L' || sisString[i*3] == 'R'))){
			headServad.insert(i);
		}
	}

	return headServad;
}

/**
 *
 */
bool ThistleLahendaja::serviKuljel(int kulg, std::set<int> servad){
	bool res { false };
	if (kulg==0){
		if (!servad.count(0) || !servad.count(1) || !servad.count(2) || !servad.count(3)){
			res = true;
		}
	} else if (kulg==1){
		if (!servad.count(3) || !servad.count(7) || !servad.count(9) || !servad.count(11)){
			res = true;
		}
	} else if (kulg==2){
		if (!servad.count(0) || !servad.count(4) || !servad.count(8) || !servad.count(9)){
			res = true;
		}
	} else if (kulg==3){
		if (!servad.count(1) || !servad.count(5) || !servad.count(8) || !servad.count(10)){
			res = true;
		}
	} else if (kulg==4){
		if (!servad.count(4) || !servad.count(5) || !servad.count(6) || !servad.count(7)){
			res = true;
		}
	} else if (kulg==5){
		if (!servad.count(2) || !servad.count(6) || !servad.count(10) || !servad.count(11)){
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
		using std::hash;

		std::size_t val = 0;
		int shift { 0 };
		for (int i = 0; i < 6; i++) {
			for (int o = 0; o < 3; o++) {
				for (int u = 0; u < 3; u++) {
					val = (val << shift) | k.kuljed[i][o][u];
					shift += 3;
				}
			}
		}

		return val;
    }
  };

}

/**
 * kontrollib, millised servad on "head" servad
 * leiab kõik valemid millega jõuab asendisse,
 * kus kõik servad on "head", ja kutsub nendega samm2 välja
 *
 * "hea" serv - serv, millel on enda kohale jõudmiseks vaja teha paarisarv U ja D pöördeid
 *
 * TODO: kui leitakse samasse positsiooni kiirem tee ei kasutata seda hetkel
 */
void ThistleLahendaja::samm1(asend sisAsend, std::set<valem> &lahendid){
	std::set<int> headServad = servaKontroll(sisAsend);

	int maxPoorded { 7 };
	kuubik sisKuup {sisAsend};
	std::unordered_map<asend, int> kaidud {};
	std::vector<std::pair<valem, int> > pooleli { };
	bool first { true };
	while (pooleli.size() || first){
		valem tee { };
		int kaugus { 0 };
		asend olek { };
		if (first){
			olek = sisKuup.kuup;
		}else {
			//tee = pooleli[pooleli.size()-1].first;
			//kaugus = pooleli[pooleli.size() - 1].second;
			//pooleli.pop_back();
			tee = pooleli[0].first;
			kaugus = pooleli[0].second;
			std::cout << "kaugus: " << kaugus << '\n';
			std::cout << "alles: " << pooleli.size() << '\n';
			pooleli.erase(pooleli.begin());

			sisKuup.turn(tee);
			olek = sisKuup.kuup;
			//engine vroom {9,12};
			//sisKuup.ekraanile(vroom, " ");
			sisKuup.rewind();
		}

		headServad = servaKontroll(olek);

		bool korras { false };
		if (headServad.size()==12){
			korras = true;
			if (!first){
				lahendid.insert(tee);
			}
			maxPoorded = tee.size();
		}

		if (kaugus<maxPoorded && kaidud.count(olek) == 0 && korras == false){
			for (int i=0;i<12;i++){
				if (serviKuljel(i%6,headServad)){
					if(i<6){
						valem uus = tee;
						uus.append("ULFRDB"[i],true);
						pooleli.push_back(std::make_pair(uus, kaugus+1));
					} else {
						valem uus =tee;
						uus.append("ULFRDB"[i-6], false);
						pooleli.push_back(std::make_pair(uus, kaugus+1));
					}
				}
			}
		}
		kaidud[olek]=kaugus;
		first = false;
	}
	/*std::cout << lahendid.size() << '\n';
	valem yks = *lahendid.begin();
	printValem(yks);*/
	return;
}

void ThistleLahendaja::samm1proovimiseta(asend sisAsend, std::set<valem> &lahendid){
	std::set<int> headServad = servaKontroll(sisAsend);
	kuubik sisKuup {sisAsend};
	valem tee { };
	while(headServad.size() < 10){
		int U { 4 };
		int D { 4 };
		for (std::set<int>::iterator ite = headServad.begin();ite != headServad.end();++ite){
			if (*ite<4){
				U--;
			} else if (*ite<8){
				D--;
			}
		}
		if (U==4){
			tee.append('U',true);
			sisKuup.turn("U ");
		} else if (D==4){
			tee.append('D',true);
			sisKuup.turn("D ");
		} else if (U==0 && D==0){
			tee.append("L F*B D D R R U");
			sisKuup.turn("L F*B D D R R U");
		}
		headServad = servaKontroll(sisKuup.kuup);
	}
	sisKuup.rewind();
	lahendid.insert(tee);

	return;
}

std::set<int> ThistleLahendaja::LRservaotsing(asend sisAsend){
	std::set<int> LRservad { };
	std::string sisString = sisAsend.toString();

	for(int i=0;i<12;i++){
		if ((sisString[i*3]=='U' || sisString[i*3]=='F' ||
				sisString[i*3]=='D' || sisString[i*3]=='B') &&
				(sisString[i*3+1]=='U' || sisString[i*3+1]=='F' ||
						sisString[i*3+1]=='D' || sisString[i*3+1]=='B')){
			LRservad.insert(i);
		}
	}
	return LRservad;
}

/*
 * Esimeses osas liigutatakse maksimaalselt 4 poordega LR kihi servad kihile UD
 * Teises osas kasutatakse tabelit et positsioneerida nurgad nii, et L ja R kleepsud näitavad L või R poole
 */

void ThistleLahendaja::samm2osa1(asend sisAsend, std::set<valem> &lahendid){
	std::set<int> LRservad = LRservaotsing(sisAsend);

	int eelmineKaugus { 0 };
	int maxPoorded { 5 };
	kuubik sisKuup {sisAsend};
	std::unordered_map<asend, int> kaidud {};
	std::vector<std::pair<valem, int> > pooleli { };
	bool first { true };
	while (pooleli.size() || first){
		valem tee { };
		int kaugus { 0 };
		asend olek { };
		if (first){
			olek = sisKuup.kuup;
		}else {
			//tee = pooleli[pooleli.size()-1].first;
			//kaugus = pooleli[pooleli.size() - 1].second;
			//pooleli.pop_back();
			tee = pooleli[0].first;
			kaugus = pooleli[0].second;
			std::cout << "kaugus: " << kaugus << '\n';
			std::cout << "alles: " << pooleli.size() << '\n';
			pooleli.erase(pooleli.begin());

			sisKuup.turn(tee);
			olek = sisKuup.kuup;
			//engine vroom {9,12};
			//sisKuup.ekraanile(vroom, " ");
			sisKuup.rewind();
		}

		LRservad = LRservaotsing(olek);

		bool korras { false };
		if (LRservad.count(8) && LRservad.count(9) && LRservad.count(10) && LRservad.count(11)){
			korras = true;
			if (!first){
				lahendid.insert(tee);
			}
			maxPoorded = kaugus;
		}

		eelmineKaugus = pooleli.size();

		if (kaugus<maxPoorded && kaidud.count(olek) == 0 && korras == false){
			for (int i=0;i<10;i++){
				valem uus = tee;

				if(i<4){
					uus.append("LFRB"[i],true);
					pooleli.push_back(std::make_pair(uus, kaugus+1));
				} else if (i<8){
					uus.append("LFRB"[i-4], false);
					pooleli.push_back(std::make_pair(uus, kaugus+1));
				} else {
					uus.append("UD"[i-8], true);
					uus.append("UD"[i-8], true);
					pooleli.push_back(std::make_pair(uus, kaugus+1));
				}
			}
		}
		kaidud[olek]=kaugus;
		first = false;
	}
	return;
}

std::string ThistleLahendaja::nurkadePooreteLeidmine(asend sisAsend, std::string poore){
	std::string sisString = sisAsend.toString();
	std::string jarjekord { };
	if (poore == ""){
		jarjekord = "25703641";
	} else if (poore == "LR"){
		jarjekord = "56076314";
	} else if (poore == "UD"){
		jarjekord = "07521463";
	} else if (poore == "FB"){
		jarjekord = "70234136";
	}
	std::string valjund { };
	for (int i=0;i<8;i++){
		if (i<4){
			if(sisString[36+(jarjekord[i]-'0')*4+2] == 'L' || sisString[36+(jarjekord[i]-'0')*4+2] == 'R'){
				valjund +='0';
			} else if(sisString[36+(jarjekord[i]-'0')*4] == 'L' || sisString[36+(jarjekord[i]-'0')*4] == 'R'){
				valjund +='2';
			} else if(sisString[36+(jarjekord[i]-'0')*4+1] == 'L' || sisString[36+(jarjekord[i]-'0')*4+1] == 'R'){
				valjund +='1';
			} else {
				std::cout << "error nurkadepöörde leidmises\n";
			}
		} else {
			if(sisString[36+(jarjekord[i]-'0')*4+1] == 'L' || sisString[36+(jarjekord[i]-'0')*4+1] == 'R'){
				valjund +='0';
			} else if(sisString[36+(jarjekord[i]-'0')*4+2] == 'L' || sisString[36+(jarjekord[i]-'0')*4+2] == 'R'){
				valjund +='2';
			} else if(sisString[36+(jarjekord[i]-'0')*4] == 'L' || sisString[36+(jarjekord[i]-'0')*4] == 'R'){
				valjund +='1';
			} else {
				std::cout << "error nurkadepöörde leidmises\n";
			}
		}
	}
	return valjund;
}

valem ThistleLahendaja::lahendiPeegeldus(valem sisValem, std::string poore){
	valem valjund { };
	std::map<char, char> vastasKuljed {
		{'F', 'B'},
		{'B', 'F'},
		{'U', 'D'},
		{'D', 'U'},
		{'L', 'R'},
		{'R', 'L'}
	};

	for (int i = 0; i < sisValem.size(); i++){
		valjund.append(vastasKuljed[sisValem.rida[i].kylg],!sisValem.rida[i].edasi);
	}

	return valjund;
}

/**
 *
 */
void ThistleLahendaja::samm2osa2(asend sisAsend, std::set<valem> &lahendid){
	ThistleSamm2Map tabel { };
	valem tulem { };
	kuubik sihtKuup {sisAsend};

	tulem = tabel.getValem(nurkadePooreteLeidmine(sisAsend, ""));
	if (tulem.size() != 0){
		lahendid.insert(tulem);
		return;
	}
	sihtKuup.peegelda("LR");
	tulem = tabel.getValem(nurkadePooreteLeidmine(sisAsend, "LR"));
	sihtKuup.peegelda("LR");

	if (tulem.size() == 0){
		lahendid.insert(tulem);
		return;
	}
	sihtKuup.peegelda("UD");
	tulem = tabel.getValem(nurkadePooreteLeidmine(sisAsend, "UD"));
	sihtKuup.peegelda("UD");
	if (tulem.size() == 0){
		lahendid.insert(tulem);
		return;
	}
	sihtKuup.peegelda("FB");
	tulem = tabel.getValem(nurkadePooreteLeidmine(sisAsend, "FB"));
	sihtKuup.peegelda("FB");
	if (tulem.size() == 0){
		lahendid.insert(tulem);
		return;
	}
	lahendid.insert(tulem);
	std::cout << "tundmatu sümmeetria";
}

/*
 * kontrollib, millised nurgad on orbiidil ehk
 * millised nurgad on oma küljel või vastasküljel
 * (kui kõik nurgad on orbiidil on külje peale ainult
 * antud külje ja vastaskülje värvid, ignoreerides servi)
 */

std::string ThistleLahendaja::getNurgadOrbiidil(asend sisAsend){
	std::set<int> orbiidiltMaas {};
	std::map<int,int> paarid;
	paarid[0] = 4;
	paarid[4] = 0;
	paarid[1] = 3;
	paarid[3] = 1;
	paarid[2] = 5;
	paarid[5] = 2;
	int nurgad [2][2][2] = {{{1,5},{8,4}},{{2,6},{7,3}}};
	for (int i = 0; i < 2; i++){
		for (int y = 0; y < 2; y++){
			for (int x = 0; x < 2; x++){
				if (sisAsend.kuljed[i*4][y*2][x*2] != sisAsend.kuljed[i*4][1][1] && sisAsend.kuljed[i*4][y*2][x*2] != sisAsend.kuljed[paarid[i*4]][1][1]){
					orbiidiltMaas.insert(nurgad[i][y][x]);
				}
			}
		}
	}
	std::string valjund;
	for (std::set<int>::iterator ite = orbiidiltMaas.begin();ite != orbiidiltMaas.end(); ++ite){
		valjund += (char)(*ite+48);
	}
	return valjund;
}

void ThistleLahendaja::samm3osa1 (asend sisAsend, std::set<valem> &lahendid){
	ThistleSamm3InitialMap data {};
	std::string nurgad = getNurgadOrbiidil(sisAsend);
	lahendid.insert(data.getValem(nurgad));
}
