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
	kuubik sihtKuup {};
    sihtKuup.ekraanile("Segamata");

    sihtKuup.ekraanile("");
    /*valem segu {};
    segu.rida.push_back(std::make_pair('L', true));
    segu.rida.push_back(std::make_pair('D', true));
    segu.rida.push_back(std::make_pair('B', true));
    kuubik.turn(segu);*/
    sihtKuup.scramble(5);
    sihtKuup.ekraanile("Segatud");
    asend kuupAsend {};
    kuupAsend = sihtKuup.kuup;
    std::cout << "Koopia tehtud" << std::endl;
    kuubik kuubik2 (sihtKuup.kuup);
    kuubik2.ekraanile("Koopia");
	IDAlahendaja IDA { };
    lahendaja *masin = &IDA;
    sihtKuup.turn(masin->lahenda(sihtKuup.kuup));
    //sihtKuup.scramble();
    sihtKuup.ekraanile("Keeratud U, true");
    return 0;
}
