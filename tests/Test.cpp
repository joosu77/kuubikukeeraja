#include <cute_base.h>
#include <cute_runner.h>
#include <cute_suite.h>
#include <cute_test.h>
#include <cute_xml_file.h>
#include <ide_listener.h>
#include <xml_listener.h>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "../src/asend.h"
#include "../src/engine.h"
#include "../src/IDAlahendaja.h"
#include "../src/kuubik.h"
#include "../src/ReidLahendaja.h"
#include "../src/ThistleLahendaja.h"
#include "../src/ThistleSamm2Map.h"
#include "../src/valem.h"

/**
 * Kontrolli, et kuup tehakse alati sama algolekuga
 */
void testAlgolek() {
	engine vroom {9, 12};
	kuubik k1 {};
	kuubik k2 {};

	ASSERTM("Kuubikud pole võrdsed", k1 == k2);
}
/*
 * Kontrolli, et kuubik teisendatakse korrektselt minu struktuurist stringiks
 */
void testConversion(){
	asend algne { };
	ReidLahendaja lah { };
	std::string lahendatud {"UF UR UB UL DF DR DB DL FR FL BR BL UFR URB UBL ULF DRF DFL DLB DBR"};
	//std::cout << "Tulemus: " << string << std::endl;
	//std::cout << "Tulemus: " << lahendatud << std::endl;
	ASSERTM("Asendit ei teisendatud õigesti", algne.toString() == lahendatud);
}

void testConversion2(){
	kuubik algne { };
	ReidLahendaja lah { };
	algne.turn("F*D R F*U F D*F L F*R*D*F L B*L*D L*");
	std::string lahendatud {"UF UR FL FD BR BU DB DL FR RD LU BL UFR FUL FLD FDR BUR BRD DLB BLU"};
	//std::cout << "Tulemus: " << string << std::endl;
	//std::cout << "Tulemus: " << lahendatud << std::endl;
	ASSERTM("Asendit ei teisendatud õigesti", algne.kuup->toString() == lahendatud);
}

void testConversion3(){
	kuubik algne { };
	ReidLahendaja lah { };
	algne.turn("F F B B R R L L D D U U ");
	std::string lahendatud {"DB DL DF DR UB UL UF UR BL BR FL FR UFR URB UBL ULF DRF DFL DLB DBR"};
	//std::cout << "Tulemus: " << string << std::endl;
	//std::cout << "Tulemus: " << lahendatud << std::endl;
	ASSERTM("Asendit ei teisendatud õigesti", algne.kuup->toString() == lahendatud);
}

void testConversion4(){
	kuubik algne { };
	ReidLahendaja lah { };
	algne.turn("D*L*U L U ");
	std::cout << "asi\n";
	std::string lahendatud {"UB FL UL UR DR DB DL DF FR UF BR BL FUL UBL FDR URB DBR RUF DFL DLB"};
	std::string saadud {algne.kuup->toString()};
	std::cout << "Saadudd: " << saadud << std::endl;
	std::cout << "Oodatav: " << lahendatud << std::endl;
	ASSERTM("Asendit ei teisendatud õigesti", saadud == lahendatud);
}

/**
 * Võtab hirmus palju aega kasuta ainult üksikuks käivitamiseks
 *
 void testReid(){
	kuubik sihtKuup { };
	engine vroom {9,12};
	sihtKuup.scramble(17);
	sihtKuup.ekraanile(vroom, " ");
	ReidLahendaja reid { };
	sihtKuup.turn(reid.lahenda(sihtKuup.kuup));


	ASSERTM("ei ole lahendatud",sihtKuup.isSolved());
}
*/

void testThistleSamm1(){
	kuubik sihtKuup { };
	sihtKuup.turn("D F ");
	ThistleLahendaja thistle { };
	std::set<valem> lahendid { };
	thistle.samm1(sihtKuup.kuup,lahendid);
	std::cout << lahendid.size() << '\n';
	for (std::set<valem>::iterator ite = lahendid.begin();ite != lahendid.end();++ite){
		valem val = *ite;
		val.print();
	}
}

void testThistleSamm1vol2(){
	kuubik sihtKuup { };
	//sihtKuup.scramble(500);
	sihtKuup.turn("U*R R D D B*F L*");
	ThistleLahendaja thistle { };
	std::set<valem> lahendid { };
	thistle.samm1(sihtKuup.kuup,lahendid);
	std::cout << lahendid.size() << '\n';
	for (std::set<valem>::iterator ite = lahendid.begin();ite != lahendid.end();++ite){
		valem val = *ite;
		val.print();
	}
}

void testThistleSamm1proovimiseta(){
	kuubik sihtKuup { };
	engine vroom {9,12};
	//sihtKuup.scramble(500);
	sihtKuup.turn("B D U*R R B B L D*U B*L L B*R R B D B B F F D L L B B R R B B U F F D D U U L L D D B B U U B B ");
	sihtKuup.ekraanile(vroom, " ");
	ThistleLahendaja thistle { };
	std::set<valem> lahendid { };
	thistle.samm1proovimiseta(sihtKuup.kuup,lahendid);
	std::cout << lahendid.size() << '\n';
	for (std::set<valem>::iterator ite = lahendid.begin();ite != lahendid.end();++ite){
		valem val = *ite;
		val.print();
	}
}
void testThistleSamm2osa1(){
	kuubik sihtKuup { };
	engine vroom {9,12};
	//sihtKuup.scramble(500);
	sihtKuup.turn("B D U*R R B B L D*U B*L L B*R R B D B B F F D L L B B R R B B U F F D D U U L L D D B B U U B B F L R*D D B B U ");
	sihtKuup.ekraanile(vroom, " ");
	ThistleLahendaja thistle { };
	std::set<valem> lahendid { };
	thistle.samm2osa1(sihtKuup.kuup,lahendid);
	std::cout << lahendid.size() << '\n';
	for (std::set<valem>::iterator ite = lahendid.begin();ite != lahendid.end();++ite){
		valem val = *ite;
		val.print();
	}
}
void testThistleSamm2Map(){
	ThistleSamm2Map data { };
	valem val = data.getValem("00000000");
	val.print();
	ASSERTM("Ei leidnud valemit 00000000",val == "F L R F F L R U U D D F ");
	val = data.getValem("00112221");
	val.print();
	ASSERTM("Ei leidnud valemit 00112221",val == "F L F F R R B U U L*F F L ");
	val = data.getValem("30112221");
	val.print();
	ASSERTM("Valemile 30112221 tagastati vastus",val == "");
}

void testNurkadePoordeLeidmine(){
	ThistleLahendaja thistle { };
	valem sisend {"B D U*R R B B L D*U B*L L B*R R B D B B F F D L L B B R R B B U F F D D U U L L D D B B U U B B F L R*D D B B U F F D D L R*F "};
	kuubik sihtKuup { };
	sihtKuup.turn(sisend);
	std::cout << thistle.nurkadePooreteLeidmine(sihtKuup.kuup, 0,0) << '\n';
	ASSERTM("Pöördeid ei leitud õigesti",thistle.nurkadePooreteLeidmine(sihtKuup.kuup, 0,0) == "02020011");
}

void testNurkadePoordeLeidminePoordega(){
	ThistleLahendaja thistle { };
	valem sisend {"B D U*R R B B L D*U B*L L B*R R B D B B F F D L L B B R R B B U F F D D U U L L D D B B U U B B F L R*D D B B U F F D D L R*F "};
	kuubik sihtKuup { };
	sihtKuup.turn(sisend);
	sihtKuup.ekraanile("");
	std::cout << sihtKuup.kuup->toString() << '\n';
	std::cout << thistle.nurkadePooreteLeidmine(sihtKuup.kuup, 5,0) << '\n';
	ASSERTM("Pöördeid ei leitud õigesti",thistle.nurkadePooreteLeidmine(sihtKuup.kuup, 5,0) == "20020101"); //22000110
}

void testKuubikuPeegeldamine(){
	engine vroom {9,12};
	kuubik sihtKuup { };
	sihtKuup.turn("F R ");
	sihtKuup.peegelda("LR");
	sihtKuup.ekraanile(vroom,"peegeldatud");
	kuubik peegelKuup { };
	peegelKuup.turn("F*L*");
	peegelKuup.ekraanile(vroom,"peegeldamata");
	ASSERTM("Ei peegeldatud kuubikut õigesti",
			*(sihtKuup.kuup) == *(peegelKuup.kuup));
}

void testThistleSamm2osa2(){
	kuubik sihtKuup { };
	engine vroom {9,12};
	//sihtKuup.scramble(500);
	sihtKuup.turn("B D U*R R B B L D*U B*L L B*R R B D B B F F D L L B B R R B B U F F D D U U L L D D B B U U B B F L R*D D B B U F F D D L R*F ");
	sihtKuup.ekraanile(vroom, " ");
	ThistleLahendaja thistle { };

	std::cout << sihtKuup.kuup->toString() << '\n';
	std::cout << "algsed nurgad " << thistle.nurkadePooreteLeidmine(sihtKuup.kuup,0,0) << '\n';

	std::set<valem> lahendid { };
	thistle.samm2osa2(sihtKuup.kuup,lahendid);
	std::cout << lahendid.size() << '\n';
	valem val = *(lahendid.begin());
	val.print();
	sihtKuup.turn(val);

	sihtKuup.ekraanile(vroom, " ");
	std::cout << "pärastised nurgad " << thistle.nurkadePooreteLeidmine(sihtKuup.kuup,0,0) << '\n';

	ASSERTM("valem ei lahenda nurki", thistle.nurkadePooreteLeidmine(sihtKuup.kuup,0,0)=="00000000");
}

void testThistleSamm2osa2Poordeta(){
	kuubik sihtKuup { };
	engine vroom {9,12};
	//sihtKuup.scramble(500);
	sihtKuup.turn("B*D*U L*L*B*B*R*D U*B R*R*B L*L*B*D*B*B*F*F*D*R*R*B*B*L*L*B*B*U*F*F*D*D*U*U*R*R*D*D*B*B*U*U*B*B*F*R*L D*D*B*B*U*F*F*D*D*R*L F*");
	sihtKuup.ekraanile(vroom, " ");
	ThistleLahendaja thistle { };

	std::cout << sihtKuup.kuup->toString() << '\n';
	std::cout << "algsed nurgad " << thistle.nurkadePooreteLeidmine(sihtKuup.kuup,0,0) << '\n';
	std::cout << "pooratudnurgad " << thistle.nurkadePooreteLeidmine(sihtKuup.kuup,0,2) << '\n';

	std::set<valem> lahendid { };
	thistle.samm2osa2(sihtKuup.kuup,lahendid);
	std::cout << lahendid.size() << '\n';
	valem val = *(lahendid.begin());
	val.print();
	sihtKuup.turn(val);

	sihtKuup.ekraanile(vroom, " ");
	std::cout << "pärastised nurgad " << thistle.nurkadePooreteLeidmine(sihtKuup.kuup,0,0) << '\n';

	ASSERTM("valem ei lahenda nurki", thistle.nurkadePooreteLeidmine(sihtKuup.kuup,0,0)=="00000000");
}

void testThistleSamm2osa2PariseltPoordeta(){
	kuubik sihtKuup { };
	engine vroom {9,12};
	//sihtKuup.scramble(500);
	sihtKuup.turn("U U R R U U R R U U B B U U D D R R F F R R B B R R L L L D D L* F F L D D R R D D U U R U U L");
	sihtKuup.ekraanile(vroom, " ");
	ThistleLahendaja thistle { };

	std::cout << "algsed nurgad " << thistle.nurkadePooreteLeidmine(sihtKuup.kuup,0,0) << '\n';

	std::set<valem> lahendid { };
	thistle.samm2osa2(sihtKuup.kuup,lahendid);
	valem val = *(lahendid.begin());

	sihtKuup.ekraanile(vroom, " ");
	std::cout << "pärastised nurgad " << thistle.nurkadePooreteLeidmine(sihtKuup.kuup,0,0) << '\n';

	ASSERTM("valem ei lahenda nurki", thistle.nurkadePooreteLeidmine(sihtKuup.kuup,0,0)=="00000000");
}

void testNurkadePoordeLeidminePeegeldused(){
	kuubik sihtKuup { };
	kuubik BFKuup {};
	kuubik UDKuup {};
	kuubik LRKuup {};
	engine vroom {9,12};
	//sihtKuup.scramble(500);
	sihtKuup.turn("B D U*R R B B L D*U B*L L B*R R B D B B F F D L L B B R R B B U F F D D U U L L D D B B U U B B F L R*D D B B U F F D D L R*F ");
	LRKuup.turn("B*D*U L*L*B*B*R*D U*B R*R*B L*L*B*D*B*B*F*F*D*R*R*B*B*L*L*B*B*U*F*F*D*D*U*U*R*R*D*D*B*B*U*U*B*B*F*R*L D*D*B*B*U*F*F*D*D*R*L F*");
	BFKuup.turn("F*D*U R*R*F*F*L*D U*F L*L*F R*R*F*D*F*F*B*B*D*L*L*F*F*R*R*F*F*U*B*B*D*D*U*U*L*L*D*D*F*F*U*U*F*F*B*L*R D*D*F*F*U*B*B*D*D*L*R B'");
	UDKuup.turn("B*U*D R*R*B*B*L*U D*B L*L*B R*R*B*U*B*B*F*F*U*L*L*B*B*R*R*B*B*D*F*F*U*U*D*D*L*L*U*U*B*B*D*D*B*B*F*L*R U*U*B*B*D*F*F*U*U*L*R F'");
	sihtKuup.ekraanile(vroom, " ");
	ThistleLahendaja thistle { };

	std::cout << "BF peegeldatud: " << thistle.nurkadePooreteLeidmine(sihtKuup.kuup,0,1) << " BF keeratud: " << thistle.nurkadePooreteLeidmine(BFKuup.kuup,0,0) <<'\n';
	std::cout << "LR peegeldatud: " << thistle.nurkadePooreteLeidmine(sihtKuup.kuup,0,2) << " LR keeratud: " << thistle.nurkadePooreteLeidmine(LRKuup.kuup,0,0) <<'\n';
	std::cout << "UD peegeldatud: " << thistle.nurkadePooreteLeidmine(sihtKuup.kuup,0,3) << " UD keeratud: " << thistle.nurkadePooreteLeidmine(UDKuup.kuup,0,0) <<'\n';

	ASSERTM("BF peegeldus on vale", thistle.nurkadePooreteLeidmine(sihtKuup.kuup,0,1)==thistle.nurkadePooreteLeidmine(BFKuup.kuup,0,0));
	ASSERTM("LR peegeldus on vale", thistle.nurkadePooreteLeidmine(sihtKuup.kuup,0,2)==thistle.nurkadePooreteLeidmine(LRKuup.kuup,0,0));
	ASSERTM("UD peegeldus on vale", thistle.nurkadePooreteLeidmine(sihtKuup.kuup,0,3)==thistle.nurkadePooreteLeidmine(UDKuup.kuup,0,0));
}

void testNurgadOrbiidil(){
	kuubik sihtKuup {};
	sihtKuup.turn("B D U*R R B B L D*U B*L L B*R R B D B B F F D L L B B R R B B U F F D D U U L L D D B B U U B B F L R*D D B B U F F D D L R*F R R F B B R B*R R B R B ");
	ThistleLahendaja thistle {};
	std::string nurgad = thistle.getNurgadOrbiidil(sihtKuup.kuup, 0);
	std::cout << nurgad << '\n';
	ASSERTM("nurkade orbiite ei määratud õigesti", nurgad == "1258");
}

void testNurgadOrbiidil2(){
	kuubik sihtKuup {};
	sihtKuup.turn("B D U*R R B B L D*U B*L L B*R R B D B B F F D L L B B R R B B U F F D D U U L L D D B B U U B B F L R*D D B B U F F D D L R*F R R F B B R B*R R B R B L*U U");
	ThistleLahendaja thistle {};
	std::string nurgad = thistle.getNurgadOrbiidil(sihtKuup.kuup, 0);
	std::cout << nurgad << '\n';
	ASSERTM("nurkade orbiite ei määratud õigesti", nurgad == "25");
}

void testThistleSamm3osa1(){
	kuubik sihtKuup { };
	//sihtKuup.turn("B D U*R R B B L D*U B*L L B*R R B D B B F F D L L B B R R B B U F F D D U U L L D D B B U U B B F L R*D D B B U F F D D L R*F R R F B B R B*R R B R B ");
	sihtKuup.turn("U U R R U U R R U U B B U U D D R R F F R R B B R R L L L D D L* F F L D D R R D D U U R U U L ");
	ThistleLahendaja thistle { };
	std::set<valem> lahendid { };
	thistle.samm3osa1(sihtKuup.kuup,lahendid);
	valem tulem = *(lahendid.begin());
	ASSERTM("ei leitud õiget valemit", tulem=="L*U U ");
}

void testNurkadeTsyklid(){
	kuubik sihtKuup { };
	sihtKuup.turn("B D U*R R B B L D*U B*L L B*R R B D B B F F D L L B B R R B B U F F D D U U L L D D B B U U B B F L R*D D B B U F F D D L R*F R R F B B R B*R R B R B L*U U ");
	ThistleLahendaja thistle { };
	std::vector<std::string> lahendid = thistle.nurkadeTsyklid(sihtKuup.kuup,4); // poore peaks vist tegelt olema 16, see on vastupidine
	for (std::vector<std::string>::iterator ite = lahendid.begin(); ite != lahendid.end(); ++ite){
		std::cout << *ite << '\n';
	}
	ASSERTM("ei leitud õiget valemit", (lahendid.size() == 2 && lahendid[0] == "0246" && lahendid[1] == "13"));
}

void testLeiaAlpha(){
	std::vector<std::string> tsykliPaarid {};
	tsykliPaarid.push_back("1357");
	tsykliPaarid.push_back("24");
	ThistleLahendaja thistle { };
	ALPHA  a = thistle.leiaAlpha(tsykliPaarid,B_15);
	std::cout << a << '\n';
	ASSERTM("ei leitud õiget valemit", a == A_24);
}

void testFBservaotsing(){
	kuubik sihtKuup { };
	engine vroom {9,12};
	sihtKuup.turn("B D U*R R B B L D*U B*L L B*R R B D B B F F D L L B B R R B B U F F D D U U L L D D B B U U B B F L R*D D B B U F F D D L R*F R R F B B R B*R R B R B L*U U ");
	ThistleLahendaja thistle { };
	std::string valString = thistle.FBservaotsing(sihtKuup.kuup,4);
	ASSERTM("ei leitud õigeid servi, ootasin \"3458\", tuli \""
			+ valString + "\"", valString=="3458");
}

void testValemiMoondus() {
	valem sisValem {"L "};
	ThistleLahendaja thistle { };
	valem tulem = thistle.valemiMoondus(sisValem, 13);
	ASSERTM("Moondamine ebaõnnestus. Ootasin 'D*', tuli '" + tulem.toString() + "'",
			tulem.toString() == "B ");
}

void testValemiMoondusTeine() {
	valem sisValem {"F "};
	ThistleLahendaja thistle { };
	valem tulem = thistle.valemiMoondus(sisValem, 13);
	ASSERTM("Moondamine ebaõnnestus. Ootasin 'D', tuli '" + tulem.toString() + "'",
			tulem.toString() == "D ");
}

void testPooraTeljel() {
	std::string msg {"Pööramine ebaõnnestus. Ootasin '%c', tuli '%c' (kogus=%d)"};
	char telg {'F'};
	char taht {'R'};
	std::string tulemid {"ULDR"};
	ThistleLahendaja thistle { };
	for (unsigned int i=0; i < tulemid.size(); i++) {
		char tulem = thistle.pooraTeljel(telg, i+1, taht);
		char oodatud = tulemid[i];
		char buf[msg.size()] { };
		sprintf (buf, msg.c_str(), oodatud, tulem, i+1);
		ASSERTM(buf, tulem == oodatud);
	}
}

void testThistleSamm3osa2(){
	kuubik sihtKuup { };
	engine vroom {9,12};
	sihtKuup.turn("B D U*R R B B L D*U B*L L B*R R B D B B F F D L L B B R R B B U F F D D U U L L D D B B U U B B F L R*D D B B U F F D D L R*F R R F B B R B*R R B R B L*U U ");
	sihtKuup.ekraanile(vroom, "");
	ThistleLahendaja thistle { };
	std::set<valem> lahendid { };
	thistle.samm3osa2(sihtKuup.kuup,lahendid);
	ASSERTM("Ei leidnud lahendit", lahendid.size() > 0);
	valem tulem = *(lahendid.begin());
	sihtKuup.turn(tulem);
	sihtKuup.ekraanile(vroom, "");
	ASSERTM("ei leitud õiget valemit: " + tulem.toString(), tulem=="R*U*U*D*D*R*R*D*D*L*F*F*L D*D*L*");
}

void testPaigastAraNurgad(){
	kuubik sihtKuup {};
	sihtKuup.turn("F D F*");
	ThistleLahendaja thistle {};
	std::set<int> nurgad = thistle.paigastAraNurgad(sihtKuup.kuup);
	for (std::set<int>::iterator ite=nurgad.begin();ite!=nurgad.end();++ite){
		std::cout << *ite;
	}
	std::cout << '\n';
	//std::cout << nurgad << '\n';
	ASSERTM("paigast ara nurki ei määratud õigesti", nurgad.count(0) && nurgad.count(4) && nurgad.count(6) && nurgad.count(7) && nurgad.size()==4); //minu - 7064, thistle - 3467
}

void testThistleSamm4osa1(){
	kuubik sihtKuup { };
	engine vroom {9,12};
	sihtKuup.turn("B D U*R R B B L D*U B*L L B*R R B D B B F F D L L B B R R B B U F F D D U U L L D D B B U U B B F L R*D D B B U F F D D L R*F R R F B B R B*R R B R B L*U U R*U U D D R R D D L*F F L D D L*");
	sihtKuup.ekraanile(vroom, "");
	ThistleLahendaja thistle { };
	std::set<valem> lahendid { };
	thistle.samm4osa1(sihtKuup.kuup,lahendid);
	ASSERTM("Ei leidnud lahendit", lahendid.size() > 0);
	valem tulem = *(lahendid.begin());
	ASSERTM("ei leitud õiget valemit", tulem=="L L R R " || tulem=="L R R L " || tulem=="R R L L " || tulem=="R L L R " || tulem=="L R L R " || tulem=="R L R L "
			|| tulem=="L*L*R R " || tulem=="L*R R L*" || tulem=="R R L*L*" || tulem=="R L*L*R " || tulem=="L*R L*R " || tulem=="R L*R L*"
			|| tulem=="L L R*R*" || tulem=="L R*R*L " || tulem=="R*R*L L " || tulem=="R*L L R*" || tulem=="L R*L R*" || tulem=="R*L R*L "
			|| tulem=="L*L*R*R*" || tulem=="L*R*R*L*" || tulem=="R*R*L*L*" || tulem=="R*L*L*R*" || tulem=="L*R*L*R*" || tulem=="R*L*R*L*"); // peab olema "L L R R " aga järjekord suva ja L L asemel võib olla L*L*
}

void testThistleSamm4osa2(){
	kuubik sihtKuup { };
	engine vroom {9,12};
	sihtKuup.turn("B D U*R R B B L D*U B*L L B*R R B D B B F F D L L B B R R B B U F F D D U U L L D D B B U U B B F L R*D D B B U F F D D L R*F R R F B B R B*R R B R B L*U U R*U U D D R R D D L*F F L D D L*L L R R ");
	sihtKuup.ekraanile(vroom, "");
	ThistleLahendaja thistle { };
	std::set<valem> lahendid { };
	thistle.samm4osa2(sihtKuup.kuup,lahendid);
	ASSERTM("Ei leidnud lahendit", lahendid.size() > 0);
	valem tulem = *(lahendid.begin());
	std::cout << tulem.rida.size() << '\n';
	sihtKuup.turn(tulem);
	sihtKuup.ekraanile(vroom,"");
	ASSERTM("ei leitud õiget valemit",sihtKuup.isSolved());
}

void testThistleLahenda(){
	kuubik sihtKuup {};
	engine vroom {9,12};
	//valem algValem {"U U R R U U R R U U B B U U D D R R F F R R B B R R L L L D D L* F F L D D R R D D U U R U U L B* R* B* R R B R* B B F* R R F* R L* D D F F U* B B D D R L* F*"};
	//valem algValem {"U U R R U U R R U U B B U U D D R R F F R R B B R R L D D L* F F L D D R R D D U U R U U L R* F* R R F F R* D D U U F F L L F* R L* U* R L*"};
	valem algValem {"U U R R U U R R U U B B U U D D R R F F R R B B R R L L L D D L* F F L D D R R D D U U R U U L B* L* F* R* F* L F F L* F*"};
	sihtKuup.turn(algValem);
	sihtKuup.ekraanile(vroom, "");
	ThistleLahendaja thistle;
	valem lahend;
	lahend = thistle.lahenda(sihtKuup.kuup);
	sihtKuup.turn(lahend);
	ASSERTM("ei leitud õiget valemit",sihtKuup.isSolved());
}

/**
 * Kontrolli, et IDAlahendaja saab ühe sammu segatud kuubi lahendatud
 */
void testBruteForce2Step() {
    engine vroom {9, 12};

	kuubik sihtKuup {};
    /*sihtKuup.ekraanile(vroom, "Segamata");
    std::cout << "Lahendatud: " << sihtKuup.isSolved() << std::endl;
*/
    sihtKuup.scramble(2);
  /*  sihtKuup.ekraanile(vroom, "Segatud");
    std::cout << "Lahendatud: " << sihtKuup.isSolved() << std::endl;
*/
	IDAlahendaja IDA { };
    lahendaja *masin = &IDA;

  //  std::cout << "Alustan lahendamist ..." << std::endl;
    valem lahendusvalem = masin->lahenda(sihtKuup.kuup);
    sihtKuup.turn(lahendusvalem);
    //sihtKuup.ekraanile(vroom, "Peale lahendamist");
    bool solved = sihtKuup.isSolved();
    //std::cout << "Lahendatud: " << solved << std::endl;

    ASSERTM("Lahendamine ei õnnestunud", solved);
    ASSERTM("Käske ei tohiks olla rohkem, kui 2",
    		lahendusvalem.size() == 2);
}

void testBruteForce1Step() {
    engine vroom {9, 12};

	kuubik sihtKuup {};
    sihtKuup.scramble(1);
	IDAlahendaja IDA { };
    lahendaja *masin = &IDA;
    valem lahendusvalem = masin->lahenda(sihtKuup.kuup);
    sihtKuup.turn(lahendusvalem);
    bool solved = sihtKuup.isSolved();
    ASSERTM("Lahendamine ei õnnestunud", solved);
    ASSERTM("Käske ei tohiks olla rohkem, kui 1",
    		lahendusvalem.size() == 1);
}

void testBruteForce3Step() {
    engine vroom {9, 12};

	kuubik sihtKuup {};
    sihtKuup.scramble(3);
	IDAlahendaja IDA { };
    lahendaja *masin = &IDA;
    valem lahendusvalem = masin->lahenda(sihtKuup.kuup);
    sihtKuup.turn(lahendusvalem);
    bool solved = sihtKuup.isSolved();
    ASSERTM("Lahendamine ei õnnestunud", solved);
    ASSERTM("Käske ei tohiks olla rohkem, kui 3",
    		lahendusvalem.size() == 3);
}

void testBruteForce0Step() {
    engine vroom {9, 12};

	kuubik sihtKuup {};
	IDAlahendaja masin {};
    valem lahendusvalem = masin.lahenda(sihtKuup.kuup);
    sihtKuup.turn(lahendusvalem);
    bool solved = sihtKuup.isSolved();
    ASSERTM("Lahendamine ei õnnestunud", solved);
    ASSERTM("Käske ei tohiks olla rohkem, kui 0",
    		lahendusvalem.size() == 0);
}

/**
 *
 */
void runAllTests(int argc, char const *argv[]){
	cute::suite s {};
	//TODO add your test here

	s.push_back(CUTE(testAlgolek));
	/*for (int i=0;i<5;i++)*/{
		s.push_back(CUTE(testBruteForce1Step));
		s.push_back(CUTE(testBruteForce2Step));
		s.push_back(CUTE(testBruteForce3Step));
	}
	s.push_back(CUTE(testConversion));
	s.push_back(CUTE(testConversion2));
	s.push_back(CUTE(testConversion3));
	s.push_back(CUTE(testConversion4));
	//s.push_back(CUTE(testReid));
	//s.push_back(CUTE(testThistleSamm1));
	//s.push_back(CUTE(testThistleSamm1vol2));
	s.push_back(CUTE(testThistleSamm1proovimiseta));
	//s.push_back(CUTE(testThistleSamm2osa1));
	s.push_back(CUTE(testThistleSamm2Map));
	s.push_back(CUTE(testNurkadePoordeLeidmine));
	s.push_back(CUTE(testNurkadePoordeLeidminePoordega));
	s.push_back(CUTE(testKuubikuPeegeldamine));
	s.push_back(CUTE(testThistleSamm2osa2));
	s.push_back(CUTE(testThistleSamm2osa2PariseltPoordeta));
	s.push_back(CUTE(testThistleSamm2osa2Poordeta));
	s.push_back(CUTE(testNurkadePoordeLeidminePeegeldused));
	s.push_back(CUTE(testNurgadOrbiidil));
	s.push_back(CUTE(testThistleSamm3osa1));
	s.push_back(CUTE(testBruteForce0Step));
	s.push_back(CUTE(testNurkadeTsyklid));
	s.push_back(CUTE(testLeiaAlpha));
	s.push_back(CUTE(testFBservaotsing));
	s.push_back(CUTE(testValemiMoondus));
	s.push_back(CUTE(testValemiMoondusTeine));
	s.push_back(CUTE(testPooraTeljel));
	s.push_back(CUTE(testThistleSamm3osa2));
	s.push_back(CUTE(testNurgadOrbiidil2));
	s.push_back(CUTE(testPaigastAraNurgad));
	s.push_back(CUTE(testThistleSamm4osa1));
	s.push_back(CUTE(testThistleSamm4osa2));
	s.push_back(CUTE(testThistleLahenda));


	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

/**
 *
 */
int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



