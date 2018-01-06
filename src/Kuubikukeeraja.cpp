//============================================================================
// Name        : Kuubikukeeraja.cpp
// Author      : Joosep Näks
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <utility>

#include "kuubik.h"
#include "asend.h"
#include "valem.h"

int main(){
	kuubik kuubik {};
    kuubik.ekraanile("Segamata");

    kuubik.ekraanile("");
    /*valem segu {};
    segu.rida.push_back(std::make_pair('L', true));
    segu.rida.push_back(std::make_pair('D', true));
    segu.rida.push_back(std::make_pair('B', true));
    kuubik.turn(segu);*/
    kuubik.scramble();
    //kuubik.scramble();
    kuubik.ekraanile("Keeratud U, true");
    return 0;
}
