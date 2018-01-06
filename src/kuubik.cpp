/*
 * kuubik.cpp
 *
 *  Created on: Jan 4, 2018
 *      Author: joosep
 */

#include <chrono>
#include <iostream>
#include <utility>

#include "kuubik.h"
#include "engine.h"
#include "asend.h"
#include "valem.h"

/**
 * Tee kuup ja täida iga külg eri värviga
 **/
kuubik::kuubik(asend sisKuup) {
	yl = 12;
	xl = 9;
	vroom.initScreen(xl, yl);

	// taidab ekraani array tyhjusega
	for (int y = 0; y < yl; y++) {
		for (int x = 0; x < xl; x++) {
			vroom.ekraan[y][x] = ground;
		}
	}

	// loob kuubi maatriksi
	kuup = sisKuup;

	// täida indeksite massiivid
	fillRowID();
}

//overload
kuubik::kuubik() {
	yl = 12;
	xl = 9;
	vroom.initScreen(xl, yl);

	// taidab ekraani array tyhjusega
	for (int y = 0; y < yl; y++) {
		for (int x = 0; x < xl; x++) {
			vroom.ekraan[y][x] = ground;
		}
	}

	// loob kuubi maatriksi

	for (int i = 0; i < 6; i++) {
		for (int o = 0; o < 3; o++) {
			for (int u = 0; u < 3; u++) {
				kuup.kuljed[i][o][u] = i;
			}
		}
	}

	// täida indeksite massiivid
	fillRowID();
}


/**
 *  Trüki kuup, aja saasi ja lahenda
 **/
void kuubik::run() {
	while (true) {
		scramble();
		ekraanile("Sassis");
		lahenda();
		ekraanile("Lahendatud");
	}
}

/**
 * Aja kuup sassi
 **/
void kuubik::scramble() {
	valem segu { };
	for (int i = 0; i < 10; i++) {
		using namespace std::chrono;
		auto epoch = high_resolution_clock::from_time_t(0);
		auto now = high_resolution_clock::now();
		auto seconds = duration_cast<milliseconds>(now - epoch).count();
		long mills = seconds;

		std::vector<char> moves = { 'U', 'L', 'F', 'R', 'D', 'B' };
		if (mills % 22 < 11) {
			segu.rida.push_back(std::make_pair(moves[mills % 6], true));
		} else {
			segu.rida.push_back(std::make_pair(moves[mills % 6], false));
		}
		std::cout << moves[mills % 6] << ((mills % 22 < 11) ? "" : "'") << " ";
	}
	turn(segu);
}

/**
 * Keera kuupi niikaua kuni iga külg on ise värvi
 */
void kuubik::lahenda() {

}

void kuubik::ekraanile(char const *msg) {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			vroom.ekraan[y][x + 3] = charof(kuup.kuljed[0][y][x]);
			vroom.ekraan[y + 3][x] = charof(kuup.kuljed[1][y][x]);
			vroom.ekraan[y + 3][x + 3] = charof(kuup.kuljed[2][y][x]);
			vroom.ekraan[y + 3][x + 6] = charof(kuup.kuljed[3][y][x]);
			vroom.ekraan[y + 6][x + 3] = charof(kuup.kuljed[4][y][x]);
			vroom.ekraan[y + 9][x + 3] = charof(kuup.kuljed[5][y][x]);
		}
	}

	vroom.printScreen();
	std::cout << msg << "\n";

}

void kuubik::turn(valem sisValem) {
	for (unsigned int i = 0; i < sisValem.rida.size(); i++) {
		switch (sisValem.rida[i].first) {
		case 'U':
			turnSide(0, sisValem.rida[i].second);
			break;
		case 'L':
			turnSide(1, sisValem.rida[i].second);
			break;
		case 'F':
			turnSide(2, sisValem.rida[i].second);
			break;
		case 'R':
			turnSide(3, sisValem.rida[i].second);
			break;
		case 'D':
			turnSide(4, sisValem.rida[i].second);
			break;
		case 'B':
			turnSide(5, sisValem.rida[i].second);
			break;
		default:
			std::cout << "ERROR";
		}
	}
}

void kuubik::turnSide(int side, bool clock) {
	/* transponeeri keeratav kylg */
	{
		int tempSide[3][3] { };
		for (int i = 0; i < 3; i++) {
			for (int u = 0; u < 3; u++) {
				if (clock) {
					tempSide[i][u] = kuup.kuljed[side][2 - u][i];
				} else {
					tempSide[2 - i][u] = kuup.kuljed[side][u][i];
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int u = 0; u < 3; u++) {
				kuup.kuljed[side][u][i] = tempSide[u][i];
			}
		}
	}

	/* keera küljega piirnev serv */

	int tmpSide[3] { };

	// jätame esimese külje meelde
	for (int j = 0; j < 3; j++) {
		if (clock) {
			tmpSide[j] = *(rowidx[side][j]);
		} else {
			tmpSide[j] = *(rowidx[side][9 + j]);
		}
	}

	// kopeerime kolmekaupa alustades viimasest
	for (int i = 3; i < 12; i += 3) {

		for (int j = 0; j < 3; j++) {
			if (clock) {
				*(rowidx[side][i + j - 3]) = *(rowidx[side][i + j]);
			} else {
				*(rowidx[side][(9 - i) + j + 3]) = *(rowidx[side][(9 - i) + j]);
			}
		}
	}

	// kirjutame viimasele külejele meeldejäetud esimese
	for (int j = 0; j < 3; j++) {
		if (clock) {
			*(rowidx[side][9 + j]) = tmpSide[j];
		} else {
			*(rowidx[side][j]) = tmpSide[j];
		}
	}
}

void kuubik::fillRowID() {

	int sides[6][4] = { { 2, 3, 5, 1 }, { 4, 2, 0, 5 }, { 4, 3, 0, 1 }, { 4, 5,
			0, 2 }, { 5, 3, 2, 1 }, { 0, 3, 4, 1 } };
	int dirs[6][4] = { { 0, 0, 2, 0 }, { 3, 3, 3, 3 }, { 0, 3, 2, 1 }, { 1, 1,
			1, 1 }, { 0, 2, 2, 2 }, { 0, 1, 2, 3 } };

	for (int u = 0; u < 6; u++) {
		std::vector<std::vector<int> > dirTables { };

		for (int i = 0; i < 4; i++) {
			std::vector<int> n { };
			switch (dirs[u][i]) {
			case 0:
				n = {0,0,0,0,1,2};
				break;
				case 1:
				n = {0,1,2,2,2,2};
				break;
				case 2:
				n = {2,2,2,2,1,0};
				break;
				case 3:
				n = {2,1,0,0,0,0};
				break;
				default:
				std::cout << "ERROR";
			}
			dirTables.push_back(n);
		}
		rowidx[u][0] =
				&kuup.kuljed[sides[u][0]][dirTables[0][0]][dirTables[0][3]];
		rowidx[u][1] =
				&kuup.kuljed[sides[u][0]][dirTables[0][1]][dirTables[0][4]];
		rowidx[u][2] =
				&kuup.kuljed[sides[u][0]][dirTables[0][2]][dirTables[0][5]];

		rowidx[u][3] =
				&kuup.kuljed[sides[u][1]][dirTables[1][0]][dirTables[1][3]];
		rowidx[u][4] =
				&kuup.kuljed[sides[u][1]][dirTables[1][1]][dirTables[1][4]];
		rowidx[u][5] =
				&kuup.kuljed[sides[u][1]][dirTables[1][2]][dirTables[1][5]];

		rowidx[u][6] =
				&kuup.kuljed[sides[u][2]][dirTables[2][0]][dirTables[2][3]];
		rowidx[u][7] =
				&kuup.kuljed[sides[u][2]][dirTables[2][1]][dirTables[2][4]];
		rowidx[u][8] =
				&kuup.kuljed[sides[u][2]][dirTables[2][2]][dirTables[2][5]];

		rowidx[u][9] =
				&kuup.kuljed[sides[u][3]][dirTables[3][0]][dirTables[3][3]];
		rowidx[u][10] =
				&kuup.kuljed[sides[u][3]][dirTables[3][1]][dirTables[3][4]];
		rowidx[u][11] =
				&kuup.kuljed[sides[u][3]][dirTables[3][2]][dirTables[3][5]];
	}
}

char kuubik::charof(int num) {
	return 48 + num;
}
