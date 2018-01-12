//============================================================================
// Name        : Kuubikukeeraja.cpp
// Author      : Joosep Näks
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <utility>
#include <iostream>

#include "kuubik.h"
#include "asend.h"
#include "lahendaja.h"
#include "valem.h"
#include "IDAlahendaja.h"
int main(){
    engine vroom {9, 12};

	kuubik sihtKuup {};
    sihtKuup.ekraanile(vroom, "Segamata");
    std::cout << "Lahendatud: " << sihtKuup.isSolved() << std::endl;

    /*valem segu {};
    segu.rida.push_back(std::make_pair('L', true));
    segu.rida.push_back(std::make_pair('D', true));
    segu.rida.push_back(std::make_pair('B', true));
    kuubik.turn(segu);*/
    sihtKuup.scramble(5);
    sihtKuup.ekraanile(vroom, "Segatud");
    std::cout << "Lahendatud: " << sihtKuup.isSolved() << std::endl;

	IDAlahendaja IDA { };
    lahendaja *masin = &IDA;

    std::cout << "Alustan lahendamist ..." << std::endl;
    sihtKuup.turn(masin->lahenda(sihtKuup.kuup));
    sihtKuup.ekraanile(vroom, "Peale lahendamist");
    std::cout << "Lahendatud: " << sihtKuup.isSolved() << std::endl;

    return 0;
}
