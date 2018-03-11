/*
 * ThistleLahendaja.h
 *
 *  Created on: Feb 26, 2018
 *      Author: joosep
 */

#ifndef THISTLELAHENDAJA_H_
#define THISTLELAHENDAJA_H_

#include <set>
#include <string>
#include <map>

#include "asend.h"
#include "lahendaja.h"
#include "valem.h"

enum ALPHA {
	A_0,
	A_1468,
	A_12,
	A_14,
	A_24
};

enum BETA {
	B_0,
	B_1278,
	B_15,
	B_13,
	B_TEADMATA
};

class ThistleLahendaja: public lahendaja {
public:
	//ThistleLahendaja();
	//virtual ~ThistleLahendaja();
	valem lahenda(asend sisAsend);

	std::set <int> servaKontroll(asend sisAsend);
	bool serviKuljel(int kulg, std::set <int> servad);
	void samm1(asend sisAsend, std::set<valem> &lahendid);
	void samm1proovimiseta(asend sisAsend, std::set<valem> &lahendid);
	std::set<int> LRservaotsing(asend sisAsend);
	void samm2osa1(asend sisAsend, std::set<valem> &lahendid);
	void samm2osa2(asend sisAsend, std::set<valem> &lahendid);
	std::string nurkadePooreteLeidmine(asend sisAsend, std::string poore);
	valem lahendiPeegeldus(valem sisValem, std::string poore);
	void samm3osa1 (asend sisAsend, std::set<valem> &lahendid);
	std::string getNurgadOrbiidil(asend sisAsend, int poore);
	std::string liidaCharid(char sis1, char sis2, char sis3);
	std::vector<std::string> nurkadeTsyklid(asend sisAsend, int poore);
	void samm3osa2 (asend sisAsend, std::set<valem> &lahendid);
	ALPHA leiaAlpha(std::vector <std::string> tsyklid, BETA beta);
	void vahetaTsyklipaare(std::map<int,int> &tsykliPaarid, int val1, int val2);
	std::string FBservaotsing(asend sisAsend, int poore);
	void samm4osa1 (asend sisAsend, std::set<valem> &lahendid);
	void samm4osa2 (asend sisAsend, std::set<valem> &lahendid);
private:
	/* indeks on nurga number TW süsteemis, väärtus nurga indeks minu süsteemis
	 * kõik erinevad sümmeetriad; kõigepealt tavaline, siis päripäeva mööda F külge pööramine,
	 * siis kõikide külgede läbi käimine järjekorras U, L, R, D, B, iga külje juures samamoodi päripäeva pöörates
	 */
	unsigned int const twIndex2Minu [24][8] = {
			{2,5,7,0,3,6,4,1}, // esimene F
			{1,3,6,4,0,2,5,7},
			{7,0,2,5,4,1,3,6},
			{6,4,1,3,5,7,0,2},
			{3,6,1,4,5,2,7,0}, // esimene U
			{0,2,7,5,3,1,6,4},
			{4,1,6,3,0,7,2,5},
			{5,7,2,0,4,6,1,3},
			{3,4,6,1,0,5,7,2}, // esimene L
			{0,5,2,7,4,3,6,1},
			{4,3,1,6,5,0,2,7},
			{5,0,7,2,3,4,1,6},
			{1,6,4,3,2,7,5,0}, // esimene R
			{7,2,5,0,1,6,3,4},
			{6,1,3,4,7,2,0,5},
			{2,7,0,5,6,1,4,3},
			{6,3,4,1,2,5,0,7}, // esimene D
			{2,0,5,7,1,3,4,6},
			{1,4,3,6,7,0,5,2},
			{7,5,0,2,6,4,3,1},
			{5,2,0,7,6,3,1,4}, // esimene B
			{3,1,4,6,2,0,7,5},
			{0,7,5,2,1,4,6,3},
			{4,6,3,1,7,5,2,0}};

	unsigned int minuIndex2Tw(unsigned int val, int poore);
};

#endif /* THISTLELAHENDAJA_H_ */
