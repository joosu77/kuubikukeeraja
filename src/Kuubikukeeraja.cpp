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

int run(){
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
    std::cout << "Lahendatud: " << sihtKuup.isSolved() << std::endl;

    return 0;
}
