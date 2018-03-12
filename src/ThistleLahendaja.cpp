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
#include <unordered_set>
#include <utility>
#include <vector>
#include <algorithm>

#include "kuubik.h"
#include "ThistleSamm2Map.h"
#include "ThistleSamm3InitialMap.h"
#include "ThistleSamm3TeineMap.h"

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

bool ThistleLahendaja::nurkiKuljel(int kulg, std::set<int> nurgad){
	bool res { false };
	if (kulg==0){
		if (nurgad.count(0) || nurgad.count(1) || nurgad.count(2) || nurgad.count(3)){
			res = true;
		}
	} else if (kulg==1){
		if (nurgad.count(2) || nurgad.count(3) || nurgad.count(5) || nurgad.count(6)){
			res = true;
		}
	} else if (kulg==2){
		if (nurgad.count(0) || nurgad.count(3) || nurgad.count(4) || nurgad.count(5)){
			res = true;
		}
	} else if (kulg==3){
		if (nurgad.count(0) || nurgad.count(1) || nurgad.count(4) || nurgad.count(8)){
			res = true;
		}
	} else if (kulg==4){
		if (nurgad.count(4) || nurgad.count(5) || nurgad.count(6) || nurgad.count(7)){
			res = true;
		}
	} else if (kulg==5){
		if (nurgad.count(1) || nurgad.count(2) || nurgad.count(6) || nurgad.count(7)){
			res = true;
		}
	}

	return res;
}
//valem& operator=(const valem& val2){
//	this->rida = val2.rida;
//	return *this;
//}

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

std::string ThistleLahendaja::getNurgadOrbiidil(asend sisAsend, int poore){
	std::map<int, int> paarid { };
	paarid[0] = 4;
	paarid[4] = 0;
	paarid[1] = 3;
	paarid[3] = 1;
	paarid[2] = 5;
	paarid[5] = 2;
	std::string valjund { };
	//int nurgad [2][2][2] = {{{1,5},{8,4}},{{2,6},{7,3}}};
	int nurgad [2][2][2] = {{{2,1},{3,0}},{{5,4},{6,7}}};
	for (int i = 0; i < 2; i++){
		for (int y = 0; y < 2; y++){
			for (int x = 0; x < 2; x++){
				if (sisAsend.kuljed[i*4][y*2][x*2] != sisAsend.kuljed[i*4][1][1] && sisAsend.kuljed[i*4][y*2][x*2] != sisAsend.kuljed[paarid[i*4]][1][1]){
					valjund += (char)(minuNurgaIdx2Tw(nurgad[i][y][x],poore)+1+48);
				}
			}
		}
	}
	std::sort(valjund.begin(),valjund.end());
	return valjund;
}

void ThistleLahendaja::samm3osa1 (asend sisAsend, std::set<valem> &lahendid){
	ThistleSamm3InitialMap data {};
	std::string nurgad = getNurgadOrbiidil(sisAsend, 0);
	lahendid.insert(data.getValem(nurgad));
}

std::string ThistleLahendaja::liidaCharid(char sis1, char sis2, char sis3){
	std::string valjund { };
	valjund = sis1;
	valjund += sis2;
	valjund += sis3;
	std::sort(valjund.begin(),valjund.end());
	return valjund;
}

std::string sorditudAlamstring(std::string const  &str, int algus, int pikkus) {
	std::string tulem = str.substr(algus, pikkus);
	std::sort(tulem.begin(), tulem.end());
	return tulem;
}

/**
 * Võtab sisse minu süsteemi nurgaindeksi, tagastab TW süsteemi indeksi
 */
unsigned int ThistleLahendaja::minuNurgaIdx2Tw(unsigned int val, int poore) {
	for (unsigned int i=0; i < 8; i++) {
		if (twNurgaIdx2Minu[poore][i] == val) {
			return i;
		}
	}

	return 999;
}

/**
 * Võtab sisse minu süsteemi servaindeksi, tagastab TW süsteemi indeksi
 */
unsigned int ThistleLahendaja::minuServaIdx2Tw(unsigned int val, int poore) {
	for (unsigned int i=0; i < 12; i++) {
		if (twServaIdx2Minu[poore][i] == val) {
			return i;
		}
	}

	return 999;
}

std::vector<std::string> ThistleLahendaja::nurkadeTsyklid(asend sisAsend, int poore){
	std::string sisString = sisAsend.toString();
	std::string lahendatudNurgad = "FRU BRU BLU FLU DFR DFL BDL BDR";
	//std::vector<std::string> lahendatudNurgad = {{"UFR"}, {"URB"}, {"UBL"}, {"ULF"}, {"DRF"}, {"DFL"}, {"DLB"}, {"DBR"}};
	std::vector<std::string> valjund { };
	// nurgad, kus tsüklite kaudu on käidud
	// number on nurga indeks thistlethwaite süsteemis
	std::set<int> kaidud { };
	for (int i=0;i<8;i++){
		// nurk = liidaCharid(sisString[36+jarjekord[i]*4], sisString[36+jarjekord[i]*4+1], sisString[36+jarjekord[i]*4+2]);
		std::string nurk = sorditudAlamstring(sisString, 36+twNurgaIdx2Minu[poore][i]*4, 3);
		//if (!kaidud.count)
		if (!kaidud.count(i) && lahendatudNurgad.find(nurk) != twNurgaIdx2Minu[poore][i]*4){
			std::string tsykkel {(char)(i+48)};
			while (lahendatudNurgad.find(nurk) != twNurgaIdx2Minu[poore][i]*4){
				// antud nurga asukoht minu systeemis
				int num = lahendatudNurgad.find(nurk)/4;

				// antud nurga asukoht thistlethwaite'i systeemis
				int kohtT = minuNurgaIdx2Tw(num, poore);
				tsykkel += (char)(kohtT+48);
				kaidud.insert(kohtT);
				nurk = sorditudAlamstring(sisString, 36+num*4, 3);
			}
			std::string buffer { };
			if (tsykkel.size()>0){
				buffer.resize(tsykkel.size());
				buffer[0]=tsykkel[0];
				for (unsigned int o=1;o<tsykkel.size();o++){
					buffer[o]=tsykkel[tsykkel.size()-o];
				}
			}
			valjund.push_back(buffer);
		}
	}


	return valjund;
}

void ThistleLahendaja::vahetaTsyklipaare(std::map<int,int> &tsykliPaarid, int val1, int val2){
	int buffer = tsykliPaarid[val1];
	tsykliPaarid[val1] = tsykliPaarid[val2];
	tsykliPaarid[val2] = buffer;
	if (tsykliPaarid[val1] == val1){
		tsykliPaarid.erase(val1);
	} else if (tsykliPaarid[val2] == val2){
		tsykliPaarid.erase(val2);
	}
}

ALPHA ThistleLahendaja::leiaAlpha(std::vector <std::string> tsyklid, BETA b){
	std::map<int, int> tsykliPaarid { };
	for (std::vector<std::string>::iterator ite = tsyklid.begin(); ite != tsyklid.end(); ++ite){
		std::string tsykkel = *ite;
		for (unsigned int i=0;i<tsykkel.size();i++){
			if(i != tsykkel.size()-1) {
				tsykliPaarid[tsykkel[i]-'0'] =  tsykkel[i+1]-'0';
			} else {
				tsykliPaarid[tsykkel[i]-'0'] = tsykkel[0] -'0';
			}
		}
	}

	if (b == B_15){
		vahetaTsyklipaare(tsykliPaarid, 1, 5);
	} else if (b == B_1278){
		vahetaTsyklipaare(tsykliPaarid, 1, 8);
		vahetaTsyklipaare(tsykliPaarid, 2, 7);
	} else if (b == B_13){
		vahetaTsyklipaare(tsykliPaarid, 1, 3);
	}

	unsigned int algPikkus = tsykliPaarid.size();
	if (b == B_0 || b == B_1278){
		vahetaTsyklipaare(tsykliPaarid, 1,4);
		vahetaTsyklipaare(tsykliPaarid, 6,8);
		if (algPikkus > tsykliPaarid.size()){
			return A_1468;
		} else {
			vahetaTsyklipaare(tsykliPaarid, 1,4);
			vahetaTsyklipaare(tsykliPaarid, 6,8);
		}
	}
	if (b == B_15){
		vahetaTsyklipaare(tsykliPaarid, 2,4);
		if (algPikkus > tsykliPaarid.size()){
			return A_24;
		} else {
			vahetaTsyklipaare(tsykliPaarid, 2,4);
		}
	}
	vahetaTsyklipaare(tsykliPaarid, 1,2);
	if (algPikkus > tsykliPaarid.size()){
		return A_12;
	} else {
		vahetaTsyklipaare(tsykliPaarid, 1,2);
	}
	vahetaTsyklipaare(tsykliPaarid, 1,4);
	if (algPikkus > tsykliPaarid.size()){
		return A_14;
	} else {
		vahetaTsyklipaare(tsykliPaarid, 1,4);
	}
	return A_0;
}

std::string ThistleLahendaja::FBservaotsing(asend sisAsend, int poore){
	int tempPoore = poore;
	if (tempPoore%4 == 1){
		tempPoore +=2;
	} else if (tempPoore%4 == 3){
		tempPoore -=2;
	}
	if (tempPoore<4){
		tempPoore += 20;
	} else if (tempPoore<8){
		tempPoore += 12;
	} else if (tempPoore<12){
		tempPoore += 4;
	} else if (tempPoore<16){
		tempPoore -= 4;
	} else if (tempPoore<20){
		tempPoore -= 12;
	} else {
		tempPoore -= 20;
	}

	std::string FBservad { };
	std::string sisString = sisAsend.toString();
	std::set<char> algKuljed = {'U','L','D','R'};
	std::set<char> pooratudKuljed;

	for (std::set<char>::iterator ite = algKuljed.begin(); ite != algKuljed.end(); ++ite){
		valem muudetav {*ite, true};
		pooratudKuljed.insert(valemiMoondus(muudetav, tempPoore).rida[0].kylg);
	}
	for(int i=0;i<12;i++){
		int twNum = minuServaIdx2Tw(i,tempPoore);
		char cA = sisString[i*3];
		char cB = sisString[i*3+1];
 		if (pooratudKuljed.count(cA) &&	pooratudKuljed.count(cB)){
			FBservad += (char)(twNum+48+1);
		}
	}
	std::sort(FBservad.begin(), FBservad.end());
	return FBservad;
}

int ThistleLahendaja::leiaStringis(std::string sisString, char otsitav){
	for (unsigned int i=0;i<sisString.size();i++){
		if (sisString[i] == otsitav){
			return i;
		}
	}
	return -1;
}

char ThistleLahendaja::pooraTeljel(char telg, int kogus, char taht){
	std::map<char, char> vastasKuljed {
			{'F', 'B'},
			{'B', 'F'},
			{'U', 'D'},
			{'D', 'U'},
			{'L', 'R'},
			{'R', 'L'}
		};
	std::map<char, std::string> teljeLiikumised {
			{'F', "URDL"},
			{'B', "DRUL"},
			{'U', "BRFL"},
			{'D', "FRBL"},
			{'L', "UFDB"},
			{'R', "UBDF"}
		};

	if (!(taht != telg && taht != vastasKuljed[telg])){
		std::string a = teljeLiikumised[telg];
		int koht = leiaStringis(a,taht);
		koht -= kogus;
		if (koht<0){
			koht += 4;
		}
		return a[koht];
	}
	return taht;
}

valem ThistleLahendaja::valemiMoondus(valem sisValem, int poore){
	valem valjund;
	for (unsigned int i=0;i<sisValem.rida.size();i++){
		char taht = sisValem.rida[i].kylg;
		char suund = sisValem.rida[i].edasi;
		if (poore < 4){
			char valTaht = pooraTeljel('F',poore,taht);
			valjund.append(valTaht, suund);
		} else if (poore < 8){
			char valTaht = pooraTeljel('R',1,taht);
			valTaht = pooraTeljel('F',poore-4,valTaht);
			valjund.append(valTaht, suund);
		} else if (poore < 12){
			char valTaht = pooraTeljel('U',1,taht);
			valTaht = pooraTeljel('F',poore-8,valTaht);
			valjund.append(valTaht, suund);
		} else if (poore < 16){
			char valTaht = pooraTeljel('D',1,taht);
			valTaht = pooraTeljel('F',poore-12,valTaht);
			valjund.append(valTaht, suund);
		} else if (poore < 20){
			char valTaht = pooraTeljel('L',1,taht);
			valTaht = pooraTeljel('F',poore-16,valTaht);
			valjund.append(valTaht, suund);
		} else {
			char valTaht = pooraTeljel('R',1,taht);
			valTaht = pooraTeljel('F',poore-20,valTaht);
			valjund.append(valTaht, suund);
		}
	}
	return valjund;
}

void ThistleLahendaja::samm3osa2 (asend sisAsend, std::set<valem> &lahendid){
	BETA juht {B_TEADMATA}; // 0 - koik nurgad orbitaalil, 1 - (18)(27), 2 - (15), 3 - (13)
	std::vector<int> poorded {};
	for (int poore=0;poore < 25;poore++){
		BETA eelmineJuht {juht};

		std::string orbital = getNurgadOrbiidil(sisAsend, poore);
		if (orbital.size()==0){
			juht = B_0;
			poorded.push_back(poore);
		} else if (orbital == "1278"){
			juht = B_1278;
			poorded.push_back(poore);
		} else if (orbital == "15"){
			juht = B_15;
			poorded.push_back(poore);
		} else if (orbital == "13"){
			juht = B_13;
			poorded.push_back(poore);
		}

		if (eelmineJuht != B_TEADMATA && eelmineJuht != juht) {
			std::cout << "VIGA: leiti kaks einevat beeta väärtust" << std::endl;
		}
	}

	if (juht == B_TEADMATA){
		std::cout << "error: yhegi poordega pole sobivad nurgad orbiidil\n";
	}

	for (int i = 0; i < poorded.size(); i++) {
		int poore = poorded[i];
		std::vector<std::string> tsyklid = nurkadeTsyklid(sisAsend, poore);
		ALPHA a = leiaAlpha(tsyklid, juht);
		std::string FBservad = FBservaotsing(sisAsend, poore);
		ThistleSamm3TeineMap data {a, juht};
		valem tulevValem = data.getValem(FBservad);
		valem tagurpidi = valemiMoondus(tulevValem, poore);
		tagurpidi.pooraYmber();
		lahendid.insert(tagurpidi);
	}
}

std::set<int> ThistleLahendaja::paigastAraNurgad(asend sisAsend){
	std::string sisString = sisAsend.toString();
	std::string lahendatud = "UFR URB UBL ULF DRF DFL DLB DBR";
	std::set<int> paigastAra {};
	for (int i=0;i<8;i++){
		if (sisString.substr(36+i*4,3) != lahendatud.substr(i*3,3)){
			paigastAra.insert(i);
		}
	}
	return paigastAra;
}

void ThistleLahendaja::samm4osa1 (asend sisAsend, std::set<valem> &lahendid){
	std::set<int> halvadNurgad = paigastAraNurgad(sisAsend);
	unsigned int maxPoorded { 4 };
	kuubik sisKuup {sisAsend};
	std::unordered_set<asend> kaidud {};
	std::vector<valem> pooleli { };
	bool first { true };
	while (pooleli.size() || first){
		valem tee { };
		asend olek { };
		if (first){
			olek = sisKuup.kuup;
		}else {
			tee = pooleli[0];
			pooleli.erase(pooleli.begin());

			sisKuup.turn(tee);
			olek = sisKuup.kuup;
			sisKuup.rewind();
		}

		halvadNurgad = paigastAraNurgad(olek);

		bool korras { false };
		if (halvadNurgad.size()==0){
			korras = true;
			lahendid.insert(tee);
		}

		if (tee.rida.size()*2<maxPoorded && kaidud.count(olek) == 0 && korras == false){
			for (int i=0;i<6;i++){
				if (nurkiKuljel(i,halvadNurgad)){
					valem uus = tee;
					uus.append("ULFRDB"[i],true);
					uus.append("ULFRDB"[i],true);
					pooleli.push_back(uus);
				}
			}
		}
		kaidud.insert(olek);
		first = false;
	}
	std::cout << "error: ei lahendatud nurki 4 kaiguga\n";
}

void ThistleLahendaja::samm4osa2 (asend sisAsend, std::set<valem> &lahendid){

}
