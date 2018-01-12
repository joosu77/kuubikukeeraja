/*
 * kuubik.h
 *
 *  Created on: Jan 4, 2018
 *      Author: joosep
 */

#include <vector>
#include <cstddef>
#include "engine.h"
#include "asend.h"
#include "valem.h"

#ifndef KUUBIK_H
#define KUUBIK_H

class kuubik {
	private:
		void turnSide(int,bool);
		void fillRowID();
		char charof(int);

		// kuubi värvide kirjeldus kus dimensioonid on järgmised
		// 1 -- kuubi külg
		// 2 -- rida vastaval küljel
		// 3 -- veerg vastavas reas
		// massiivi salvestava väärtus on ruudu värv vahemikus 0-5
		 //int kuup[6][3][3]; - asendatud asend objectiga
		// indeks kus on pointerid igat külge ääristavatele kleepsudele
		int * rowidx[6][12];

		int* a [3];
		int* b [3];
		int* c [3];
		int* d [3];
	public:
		asend *kuup = NULL;
		// engine *vroom = NULL;

		// kuubik argumendis antud asendiga
		kuubik(const asend&);
		// kuubuk vaikimisi asendiga (lahendatud)
		kuubik();
		~kuubik();

		void ekraanile(engine &vroom, char const*);
		void turn(valem);
		void scramble(int);
		bool isSolved();
};

#endif /* KUUBIK_H_ */
