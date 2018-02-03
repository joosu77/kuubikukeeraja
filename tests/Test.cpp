#include <cute_base.h>
#include <cute_runner.h>
#include <cute_suite.h>
#include <cute_test.h>
#include <cute_xml_file.h>
#include <ide_listener.h>
#include <xml_listener.h>
#include <vector>

#include "../src/kuubik.h"
#include "../src/IDAlahendaja.h"

void thisIsATest() {
	ASSERTM("start writing tests", true);
}

void testAlgolek() {
	kuubik k1 {};
	kuubik k2 {};

	ASSERTM("Kuubikud pole võrdsed", k1.kuup == k2.kuup);
}

void testBruteForce() {
    engine vroom {9, 12};

	kuubik sihtKuup {};
    sihtKuup.ekraanile(vroom, "Segamata");
    std::cout << "Lahendatud: " << sihtKuup.isSolved() << std::endl;

    sihtKuup.scramble(1);
    sihtKuup.ekraanile(vroom, "Segatud");
    std::cout << "Lahendatud: " << sihtKuup.isSolved() << std::endl;

	IDAlahendaja IDA { };
    lahendaja *masin = &IDA;

    std::cout << "Alustan lahendamist ..." << std::endl;
    valem lahendusvalem = masin->lahenda(sihtKuup.kuup);
    sihtKuup.turn(lahendusvalem);
    sihtKuup.ekraanile(vroom, "Peale lahendamist");
    bool solved = sihtKuup.isSolved();
    std::cout << "Lahendatud: " << solved << std::endl;

    ASSERTM("Lahendamine ei õnnestunud", solved);
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s {};
	//TODO add your test here

	s.push_back(CUTE(thisIsATest));
	s.push_back(CUTE(testAlgolek));
	s.push_back(CUTE(testBruteForce));

	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



