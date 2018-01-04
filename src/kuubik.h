/*
 * kuubik.h
 *
 *  Created on: Jan 4, 2018
 *      Author: joosep
 */

#include <vector>
#include "engine.h"

#ifndef KUUBIK_H
#define KUUBIK_H

class kuubik {
	private:
		engine vroom;
		int xl;
		int yl;
		const char ground = ' ';

		void turnSide(int,bool);
		void fillRowID();
		char charof(int);

		// kuubi värvide kirjeldus kus dimensioonid on järgmised
		// 1 -- kuubi külg
		// 2 -- rida vastaval küljel
		// 3 -- veerg vastavas reas
		// massiivi salvestava väärtus on ruudu värv vahemikus 0-5
		int kuup[6][3][3];
		// indeks kus on pointerid igat külge ääristavatele kleepsudele
		int * rowidx[6][12];

		int* a [3];
		int* b [3];
		int* c [3];
		int* d [3];
	public:
		kuubik();
		void ekraanile(char const*);
		void run();
		void turn(char, bool);
		void scramble();
		void lahenda();
};

#endif /* KUUBIK_H_ */
