#include <cute_base.h>
#include <cute_runner.h>
#include <cute_suite.h>
#include <cute_test.h>
#include <cute_xml_file.h>
#include <ide_listener.h>
#include <stdlib.h>
#include <string.h>
#include <xml_listener.h>
#include <iostream>
#include <map>
#include <set>
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
	asend algne;
	ReidLahendaja lah;
	char* string = lah.asend2string(algne);
	char* lahendatud = "UF UR UB UL DF DR DB DL FR FL BR BL UFR URB UBL ULF DRF DFL DLB DBR";
	//std::cout << "Tulemus: " << string << std::endl;
	//std::cout << "Tulemus: " << lahendatud << std::endl;
	ASSERTM("Asendit ei teisendatud õigesti", strcmp(string, lahendatud)==0);
	free(string);
}

void testConversion2(){
	kuubik algne;
	ReidLahendaja lah;
	algne.turn("F*D R F*U F D*F L F*R*D*F L B*L*D L*");
	char* string = lah.asend2string(*algne.kuup);
	char* lahendatud = "UF UR FL FD BR BU DB DL FR RD LU BL UFR FUL FLD FDR BUR BRD DLB BLU";
	//std::cout << "Tulemus: " << string << std::endl;
	//std::cout << "Tulemus: " << lahendatud << std::endl;
	ASSERTM("Asendit ei teisendatud õigesti", strcmp(string, lahendatud)==0);
	free(string);
}

void testConversion3(){
	kuubik algne;
	ReidLahendaja lah;
	algne.turn("F F B B R R L L D D U U ");
	char* string = lah.asend2string(*algne.kuup);
	char* lahendatud = "DB DL DF DR UB UL UF UR BL BR FL FR UFR URB UBL ULF DRF DFL DLB DBR";
	//std::cout << "Tulemus: " << string << std::endl;
	//std::cout << "Tulemus: " << lahendatud << std::endl;
	ASSERTM("Asendit ei teisendatud õigesti", strcmp(string, lahendatud)==0);
	free(string);
}

void testConversion4(){
	kuubik algne;
	ReidLahendaja lah;
	algne.turn("D*L*U L U ");
	std::cout << "asi\n";
	char* string = lah.asend2string(*algne.kuup);
	char* lahendatud = "UB FL UL UR DR DB DL DF FR UF BR BL FUL UBL FDR URB DBR RUF DFL DLB";
	std::cout << "Saadudd: " << string << std::endl;
	std::cout << "Oodatav: " << lahendatud << std::endl;
	ASSERTM("Asendit ei teisendatud õigesti", strcmp(string, lahendatud)==0);
	free(string);
}

void testReid(){
	kuubik sihtKuup;
	engine vroom {9,12};
	sihtKuup.scramble(17);
	sihtKuup.ekraanile(vroom, " ");
	ReidLahendaja reid;
	sihtKuup.turn(reid.lahenda(sihtKuup.kuup));


	ASSERTM("ei ole lahendatud",sihtKuup.isSolved());
}

void testThistleSamm1(){
	kuubik sihtKuup;
	sihtKuup.turn("D F ");
	ThistleLahendaja thistle;
	std::set<valem> lahendid;
	thistle.samm1(sihtKuup.kuup,lahendid);
	std::cout << lahendid.size() << '\n';
	for (std::set<valem>::iterator ite = lahendid.begin();ite != lahendid.end();++ite){
		valem val = *ite;
		val.print();
	}
}

void testThistleSamm1vol2(){
	kuubik sihtKuup;
	//sihtKuup.scramble(500);
	sihtKuup.turn("U*R R D D B*F L*");
	ThistleLahendaja thistle;
	std::set<valem> lahendid;
	thistle.samm1(sihtKuup.kuup,lahendid);
	std::cout << lahendid.size() << '\n';
	for (std::set<valem>::iterator ite = lahendid.begin();ite != lahendid.end();++ite){
		valem val = *ite;
		val.print();
	}
}

void testThistleSamm1proovimiseta(){
	kuubik sihtKuup;
	engine vroom {9,12};
	//sihtKuup.scramble(500);
	sihtKuup.turn("B D U*R R B B L D*U B*L L B*R R B D B B F F D L L B B R R B B U F F D D U U L L D D B B U U B B ");
	sihtKuup.ekraanile(vroom, " ");
	ThistleLahendaja thistle;
	std::set<valem> lahendid;
	thistle.samm1proovimiseta(sihtKuup.kuup,lahendid);
	std::cout << lahendid.size() << '\n';
	for (std::set<valem>::iterator ite = lahendid.begin();ite != lahendid.end();++ite){
		valem val = *ite;
		val.print();
	}
}
void testThistleSamm2osa1(){
	kuubik sihtKuup;
	engine vroom {9,12};
	//sihtKuup.scramble(500);
	sihtKuup.turn("B D U*R R B B L D*U B*L L B*R R B D B B F F D L L B B R R B B U F F D D U U L L D D B B U U B B F L R*D D B B U ");
	sihtKuup.ekraanile(vroom, " ");
	ThistleLahendaja thistle;
	std::set<valem> lahendid;
	thistle.samm2osa1(sihtKuup.kuup,lahendid);
	std::cout << lahendid.size() << '\n';
	for (std::set<valem>::iterator ite = lahendid.begin();ite != lahendid.end();++ite){
		valem val = *ite;
		val.print();
	}
}
void testThistleSamm2Map(){
	ThistleSamm2Map data;
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
	ThistleLahendaja thistle;
	valem sisend {"B D U*R R B B L D*U B*L L B*R R B D B B F F D L L B B R R B B U F F D D U U L L D D B B U U B B F L R*D D B B U F F D D L R*F "};
	kuubik sihtKuup;
	sihtKuup.turn(sisend);
	std::cout << thistle.nurkadePooreteLeidmine(sihtKuup.kuup) << '\n';
	ASSERTM("Pöördeid ei leitud õigesti",thistle.nurkadePooreteLeidmine(sihtKuup.kuup) == "02020011");
}

void testKuubikuPeegeldamine(){
	engine vroom {9,12};
	kuubik sihtKuup;
	sihtKuup.turn("F R ");
	sihtKuup.peegelda("LR");
	sihtKuup.ekraanile(vroom,"peegeldatud");
	kuubik peegelKuup;
	peegelKuup.turn("F*L*");
	peegelKuup.ekraanile(vroom,"peegeldamata");
	ASSERTM("Ei peegeldatud kuubikut õigesti",
			*(sihtKuup.kuup) == *(peegelKuup.kuup));
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
    		lahendusvalem.rida.size() == 2);
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
    		lahendusvalem.rida.size() == 1);
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
    		lahendusvalem.rida.size() == 3);
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
	s.push_back(CUTE(testKuubikuPeegeldamine));


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



