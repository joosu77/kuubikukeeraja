/*
 * ThistleLahendaja.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: joosep
 */

#include "ThistleLahendaja.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "kuubik.h"
#include "ThistleSamm2Map.h"
#include "ThistleSamm3InitialMap.h"
#include "ThistleSamm3TeineMap.h"
#include "ThistleSamm4Map.h"

//TODO: notes: tuleb alpha ja beta hulgast valida õiged liikmed millega korrutada, alpha ja beta järgi valitakse coset

/**
 *
 */
valem ThistleLahendaja::lahenda(asend sisAsend){
	// kuubik, kuhu valemeid järjest peale pannakse
	kuubik liigutatavKuubik {sisAsend};
	// siia pannakse tükkhaaval kogu lõplik valem kokku
	valem koguLahend {};
	// siia väljastab iga samm enda valemi
	std::set<valem> lahendid { };

	// kutsutakse samm välja
	samm1(sisAsend, lahendid);
	// keeratakse valem kuubikule peale
	liigutatavKuubik.turn(*(lahendid.begin()));
	// lisatakse valem lõplikusse valemisse
	koguLahend.append(*(lahendid.begin()));

	// tühjendatakse ajutine lahendite hulk
	lahendid.clear();
	samm2osa1(liigutatavKuubik.kuup, lahendid);
	liigutatavKuubik.turn(*(lahendid.begin()));
	koguLahend.append(*(lahendid.begin()));

	lahendid.clear();
	samm2osa2(liigutatavKuubik.kuup, lahendid);
	liigutatavKuubik.turn(*(lahendid.begin()));
	koguLahend.append(*(lahendid.begin()));

	lahendid.clear();
	samm3osa1(liigutatavKuubik.kuup, lahendid);
	liigutatavKuubik.turn(*(lahendid.begin()));
	koguLahend.append(*(lahendid.begin()));

	lahendid.clear();
	samm3osa2(liigutatavKuubik.kuup, lahendid);
	liigutatavKuubik.turn(*(lahendid.begin()));
	koguLahend.append(*(lahendid.begin()));

	lahendid.clear();
	samm4osa1(liigutatavKuubik.kuup, lahendid);
	liigutatavKuubik.turn(*(lahendid.begin()));
	koguLahend.append(*(lahendid.begin()));

	lahendid.clear();
	samm4osa2(liigutatavKuubik.kuup, lahendid);
	liigutatavKuubik.turn(*(lahendid.begin()));
	koguLahend.append(*(lahendid.begin()));

	return koguLahend;
}

/**
 *
 */
std::set<int> ThistleLahendaja::servaKontroll(asend const &sisAsend){
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
void ThistleLahendaja::samm1(asend const &sisAsend, std::set<valem> &lahendid){
	// jätab meelde, millised on "head" servad
	std::set<int> headServad = servaKontroll(sisAsend);
	// selles sammus ei tohi üle 7 pöörde kuluda
	int maxPoorded = 7;
	// kuubik, kus kontrollitakse, kas servad on "heaks" tehtud
	kuubik sisKuup {sisAsend};
	// jätab meelde kõik läbi käidud asendid ja nendeni jõudmise pikkusi
	std::unordered_map<asend, int> kaidud {};
	// hulk, mis sisaldab kõiki valemeid ja nende pikkusi,
	// millele lisatakse pöördeid, et jõuda lõpliku lahendini
	std::vector<std::pair<valem, int> > pooleli {};
	// ananab teada et on esimene iteratsioon
	bool first = true;
	// tsükkel kestab, kuni pooleli olevate hulk saab tühjaks
	while (pooleli.size() || first){
		// jätab meelde antud iteratsioonil töödeldava valemi
		valem tee { };
		// jätab meelde antud iteratsioonil töödeldava valemi pikkuse
		int kaugus { 0 };
		// jätab meelde antud iteratsioonil töödeldava valemiga saavutatud asendi
		asend olek { };
		if (first){
			// esimesel iteratsioonil on algandmed tühjad
			olek = sisKuup.kuup;
		}else {
			// omistatakse pooleli olevate valemite hulga esimese
			// elemendi andmed kohalikele muutujatele ja kustutatakse element
			tee = pooleli[0].first;
			kaugus = pooleli[0].second;
			pooleli.erase(pooleli.begin());
			// luuakse kuubiku peal selline juht,
			// jätetakse asend meelde ja keeratakse kuubik tagasi
			sisKuup.turn(tee);
			olek = sisKuup.kuup;
			sisKuup.rewind();
		}
		// leitakse "head" servad
		headServad = servaKontroll(olek);
		// kontrollitakse, kas kõik servad on "head"
		bool korras { false };
		if (headServad.size()==12){
			korras = true;
			// kui kuubik oli kohe lahendatud, pole vaja valemit väljastada
			if (!first){
				// pannakse valem lahendite hulka
				lahendid.insert(tee);
			}
			// muudetakse maksimaalset käikude arvu, et ka kõik teised
			// samapikadlahendid üles leitaks ja siis tsükkel seisma jääks
			maxPoorded = tee.size();
		}
		// asendeid toodetakse juurde vaid siis, kui valemi pikkus ei ületa limiiti,
		// asendit pole veel nähtud ja asendis pole kõik servad "head"
		if (kaugus<maxPoorded && kaidud.count(olek) == 0 && korras == false){
			for (int i=0;i<12;i++){
				// proovitakse käike läbi, iga käigu juures kontrollitakse, et selle
				// peal on vähemalt 1 "halb" serv, kuna "heade" servade keeramisest pole kasu
				if (serviKuljel(i%6,headServad)){
					// lisataks pooleli olevate valemite hulka käesolev valem koos uue pöördega
					valem uus = tee;
					uus.append("ULFRDB"[i%6],i<6);
					pooleli.push_back(std::make_pair(uus, kaugus+1));
				}
			}
		}
		// lisatakse nähtud asendite hulka töödeldava valemi
		kaidud[olek]=kaugus;
		first = false;
	}
	return;
}

void ThistleLahendaja::samm1proovimiseta(asend const &sisAsend, std::set<valem> &lahendid){
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

std::set<int> ThistleLahendaja::LRservaotsing(asend const &sisAsend){
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

void ThistleLahendaja::samm2osa1(asend const &sisAsend, std::set<valem> &lahendid){
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

std::string ThistleLahendaja::nurkadePooreteLeidmine(asend const &sisAsend, std::string poore){
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

valem ThistleLahendaja::lahendiPeegeldus(valem const &sisValem, std::string poore){
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
void ThistleLahendaja::samm2osa2(asend const &sisAsend, std::set<valem> &lahendid){
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

std::string ThistleLahendaja::getNurgadOrbiidil(asend const &sisAsend, int poore){
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

void ThistleLahendaja::samm3osa1 (asend const &sisAsend, std::set<valem> &lahendid){
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
 * Võtab sisse minu süsteemi nurgaindeksi, tagastab TW süsteemi indeksipääret käsitletakse kui sisend = väljund + pööre
 */
unsigned int ThistleLahendaja::minuNurgaIdx2Tw(unsigned int val, int poore) {
	for (unsigned int i=0; i < 8; i++) {
		if (twNurgaIdx2Minu[poore][i] == val) {
			return i;
		}
	}

	throw std::runtime_error("minuNurgaIdx2Tw: ei leidnud pöördele vastavat nurka");
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

	throw std::runtime_error("minuServaIdx2Tw: ei leidnud pöördele vastavat serva");
}

std::vector<std::string> ThistleLahendaja::nurkadeTsyklid(asend const &sisAsend, int poore){
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

/**
 * tagastab indeksi mis ütleb, kus etteantud serv peaks asuma
 * serv on kahetäheline serva kood, mis peab servade nimekrijas olemas olema
 * kui serva ei leita katkestatakse veaga
 */
unsigned int ThistleLahendaja::leiaServaKoht (std::string serv) {
	static const std::string lahendatudServad = "UF UR UB UL DF DR DB DL FR FL BR BL";
	std::string::size_type servaKoht = lahendatudServad.find(serv);
	if (servaKoht == std::string::npos){
		// serva ei leitud. kontrollime, kas on teistpidi
		std::string ymberPooratud {serv[1], serv[0]};
		servaKoht = lahendatudServad.find(ymberPooratud);
		if (servaKoht == std::string::npos) {
			// teistpidi ka ei leitud, midagi on viltu
			std::cout << "Ei leidnud serva \"" << serv << "\"\n";
			throw;
		}
	}

	return servaKoht;
}

/**
 *
 */
std::vector<std::string> ThistleLahendaja::servadeTsyklid(asend const &sisAsend, int poore){
	std::string sisString = sisAsend.toString();
	std::vector<std::string> valjund { };

	// servad, kus tsüklite kaudu on käidud
	// number on serva indeks thistlethwaite süsteemis
	std::set<int> kaidud { };

	// kontrolli üle kõik servad (indeks TW süsteemis
	for (int servaIdxTw=0; servaIdxTw<12; servaIdxTw++){
		unsigned int servaIdxMinu { twServaIdx2Minu[poore][servaIdxTw] * 3 };

		std::string serv = sorditudAlamstring(sisString, servaIdxMinu, 2);
		std::cout << "Alustan serva " << serv << " lahendamist (" << servaIdxTw << ")\n";
		// koht, kus antud serv peaks olema
		std::string::size_type servaKoht = leiaServaKoht(serv);

		// kui serv ei ole veel klastatud ja ei asu juba õiges kohas
		if (servaKoht != servaIdxMinu && !kaidud.count(servaIdxTw)){
			std::string tsykkel {(char)(servaIdxTw+48+1)};
			// TODO: kas siin ei peaks kontrollima kaidud set'i juhuks, kui serva otsing tsüklisse läheb?
			while (servaKoht != servaIdxMinu){
				std::cout << "serv: " << serv << " servaKoht: " << servaKoht << "\n";
				unsigned int kohtM = servaKoht/3;
				// antud serva asukoht thistlethwaite'i systeemis
				int kohtT = minuServaIdx2Tw(kohtM, poore);
				tsykkel += (char)(kohtT+48);
				std::cout << "registreerin külastatud koha: " << kohtT << "\n";
				kaidud.insert(kohtT);
				serv = sorditudAlamstring(sisString, servaKoht, 2);
				servaKoht = leiaServaKoht(serv);
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

ALPHA ThistleLahendaja::leiaAlpha(std::vector <std::string> &tsyklid, BETA b){
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

std::string ThistleLahendaja::FBservaotsing(asend const &sisAsend, int poore){
	int tempPoore {poore};
	/*if (tempPoore%4 == 1){
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
	}*/

	std::string FBservad { };
	std::string sisString = sisAsend.toString();
	std::string algKuljed = "ULDR";
	// pooratud kuljed voetakse eeldusega, et pooratud on algasend ja algkuljed on pooratud+temppoore
	std::set<char> pooratudKuljed { };
	for (unsigned int i = 0; i < algKuljed.size(); i++){
		valem muudetav {algKuljed[i], true};
		valem pooratud = valemiMoondus(muudetav, tempPoore);
		pooratudKuljed.insert(pooratud.rida[0].kylg);
		//std::cout << pooratud.rida[0].kylg << " : ";
	}
	//std::cout << "\n temp ja alg poore: " << tempPoore << " : " << poore << '\n';
	//std::cout << '\n' << sisString << '\n';
	//std::cout << "ilma uuesti pooramiseta servad ";
	for(int i=0;i<12;i++){
		int twNum = minuServaIdx2Tw(i,tempPoore);
		//int twNum = minuServaIdx2Tw(i,0);
		char cA = sisString[i*3];
		char cB = sisString[i*3+1];
 		if (pooratudKuljed.count(cA) &&	pooratudKuljed.count(cB)){
			FBservad += (char)(twNum+48+1);
			//std::cout << testPoordetaServ;
		}
	}
	std::sort(FBservad.begin(), FBservad.end());
	std::cout << "leitud fb servade asukohad: " << FBservad << '\n';
	return FBservad;
}

int ThistleLahendaja::leiaStringis(std::string sisString, char otsitav){
	for (unsigned int i=0;i<sisString.size();i++){
		if (sisString[i] == otsitav){
			return i;
		}
	}

	throw;
}

/**
 * @param telg -- külg, mida keeratakse
 * @param kogus -- mitu korda päripäeva keeratakse
 * @param taht -- külje tähis, mille asukohta peale pööramist tahetakse leida
 */
char ThistleLahendaja::pooraTeljel(char telg, int kogus, char taht){
	// kui taht on kas sama mis telg või tema vastaskülg,
	// siis pole vaja keerata
	std::map<char, char> vastasKuljed {
			{'F', 'B'},
			{'B', 'F'},
			{'U', 'D'},
			{'D', 'U'},
			{'L', 'R'},
			{'R', 'L'}
		};
	if (telg == taht || vastasKuljed[telg] == taht) {
		return taht;
	}

	// otsi ettantud täht liikumist emassiivist ja
	// liigu sellest edasi kogus%4 sammu. Jõudes stringi
	// lõppu alustatakse algusest
	std::map<char, std::string> teljeLiikumised {
			{'F', "URDL"},
			{'B', "DRUL"},
			{'U', "BRFL"},
			{'D', "FRBL"},
			{'L', "UFDB"},
			{'R', "UBDF"}
		};

	int poordeid {kogus % 4};
	std::string a = teljeLiikumised[telg];
	int koht = leiaStringis(a,taht);
	int uusKoht { (koht + 4 - poordeid) % 4 };
	return a[uusKoht];
}

/**
 * Kui lahendamise käigus leitakse, pööratud kuubikule sobiv valem
 * siis see funktsioon teisendab sama valemi pööramata kuubiku jaoks
 */
valem ThistleLahendaja::valemiMoondus(valem const &sisValem, int poore){
	valem valjund { };
	for (unsigned int i=0;i<sisValem.rida.size();i++){
		char taht { sisValem.rida[i].kylg };
		char suund = sisValem.rida[i].edasi;

		char valTaht {taht};
		if (poore >= 4 && poore < 8){
			valTaht = pooraTeljel('R',1,taht);
		} else if (poore < 12){
			valTaht = pooraTeljel('U',1,taht);
		} else if (poore < 16){
			valTaht = pooraTeljel('D',1,taht);
		} else if (poore < 20){
			valTaht = pooraTeljel('L',1,taht);
		} else {
			valTaht = pooraTeljel('L',2,taht);
		}

		valTaht = pooraTeljel('F',poore,valTaht);
		valjund.append(valTaht, suund);
	}
	return valjund;
}

void ThistleLahendaja::samm3osa2 (asend const &sisAsend, std::set<valem> &lahendid){
	BETA juht = B_TEADMATA; // 0 - koik nurgad orbitaalil, 1 - (18)(27), 2 - (15), 3 - (13)
	std::vector<int> poorded {};
	for (int poore=0;poore < 25;poore++){
		BETA eelmineJuht = juht;

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
			std::cout << "VIGA: leiti kaks erinevat beeta väärtust" << std::endl;
		}
	}

	if (juht == B_TEADMATA){
		std::cout << "error: yhegi poordega pole sobivad nurgad orbiidil\n";
	}

	for (unsigned int i = 0; i < poorded.size(); i++) {
		int poore = poorded[i];
		std::vector<std::string> tsyklid = nurkadeTsyklid(sisAsend, poore);
		ALPHA a = leiaAlpha(tsyklid, juht);
		std::string FBservad = FBservaotsing(sisAsend, poore);
		ThistleSamm3TeineMap data {a, juht};
		valem tulevValem = data.getValem(FBservad);
		std::cout << "alpha: " << a << " juht: " << juht << " fbservad: " << FBservad << '\n';
		if (tulevValem.size() > 0) {
			tulevValem.print();
			valem tagurpidi = valemiMoondus(tulevValem, poore);
			tagurpidi.print();
			tagurpidi.pooraYmber();
			tagurpidi.print();
			lahendid.insert(tagurpidi);
		}
	}
}

std::set<int> ThistleLahendaja::paigastAraNurgad(asend const &sisAsend){
	std::string sisString = sisAsend.toString();
	std::string lahendatud = "UFR URB UBL ULF DRF DFL DLB DBR";
	std::set<int> paigastAra {};
	for (int i=0;i<8;i++){
		//std::cout << sisString.substr(36+i*4,3) << " : " << lahendatud.substr(i*4,3) << " : " << i <<  '\n';
		if (sisString.substr(36+i*4,3) != lahendatud.substr(i*4,3)){
			paigastAra.insert(i);
		}
	}
	return paigastAra;
}

void ThistleLahendaja::samm4osa1 (asend const &sisAsend, std::set<valem> &lahendid){
	std::set<int> halvadNurgad = paigastAraNurgad(sisAsend);
	unsigned int maxPoorded { 5 };
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
	if (lahendid.size() ==0){
		std::cout << "error: ei lahendatud nurki 4 kaiguga\n";
	}
	return;
}


// kontrollib, kas vähemalt 1 küljel on kõik tükid paigas,
// eeldab et tükkidel pole valet pööret kuna seda kasutatakse 4ndal sammul
bool ThistleLahendaja::servKorras (asend const &sisAsend){
	for (int i=0;i<6;i++){
		bool korras = true;
		for (int o=0;o<3;o++){
			for (int u=0;u<3;u++){
				if (sisAsend.kuljed[i][o][u]!=i){
					korras = false;
					u=3;o=3;
				}
			}
		}
		if (korras){
			return true;
		}
	}
	return false;
}

void ThistleLahendaja::samm4osa2 (asend const &sisAsend, std::set<valem> &lahendid){
	bool servPaigas = servKorras(sisAsend);
	std::vector<std::string> tsyklid = servadeTsyklid(sisAsend,0);
	int kaksTsyklid = 0;
	int kolmTsyklid = 0;
	int neliTsyklid = 0;
	for(std::vector<std::string>::iterator ite = tsyklid.begin(); ite != tsyklid.end(); ++ite){
		if ((*ite).size() == 2){
			kaksTsyklid++;
		} else if ((*ite).size() == 3){
			kolmTsyklid++;
		} else if ((*ite).size() == 4){
			neliTsyklid++;
		}
	}
	std::cout << "servpaigas: " << servPaigas << " 2tsüklid: " << kaksTsyklid << " 3tsyklid: " << kolmTsyklid << " 4tsyklid: " << neliTsyklid << '\n';
	ThistleSamm4Map data {servPaigas, kaksTsyklid, kolmTsyklid, neliTsyklid};
	kuubik testitavKuup {sisAsend};
	valem katsealuneValem;
	for (int i=0;i<data.suurus;i++){
		katsealuneValem = data.getValem(i);
		for (int o=0;o<23;o++){
			valem moondatudValem = valemiMoondus(katsealuneValem, o);
			moondatudValem.pooraYmber();
			moondatudValem.print();
			testitavKuup.turn(moondatudValem);
			if(testitavKuup.isSolved()){
				lahendid.insert(moondatudValem);
				return;
			}
			testitavKuup.rewind();
		}
	}
}
