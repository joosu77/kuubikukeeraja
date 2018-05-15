/*
 * ThistleSamm4Map.cpp
 *
 *  Created on: Apr 28, 2018
 *      Author: joosep
 */
#include "ThistleSamm4Map.h"

valem ThistleSamm4Map::getValem(int voti){
	valem valjund = data[voti];
	return valjund;
}


ThistleSamm4Map::ThistleSamm4Map (bool kylgKorras, int kaksTsyklid, int kolmTsyklid, int neliTsyklid) {
	if (kylgKorras){
		data[1] = "L L F F L L F F L L F F L L F F L L F F L L F F";
		data[2] = "L L F F L L F F L L F F L L F F L L R R B B R R";
		data[3] = "L L F F L L F F L L F F L L F F L L B B R R B B";
		data[4] = "L L F F L L F F L L F F L L F F R R F F L L B B";
		data[5] = "L L F F L L F F L L F F L L R R U U L L R R D D";
		data[6] = "L L F F L L F F L L R R F F U U L L B B L L U U";
		data[7] = "L L F F L L F F L L R R F F U U F F R R F F U U";
		data[8] = "L L F F L L F F L L R R B B U U L L B B R R D D";
		data[9] = "L L F F L L F F L L R R B B U U F F L L B B D D";
		data[10] = "L L F F L L F F L L U U L L F F U U F F L L U U";
		data[11] = "L L F F L L F F L L U U L L F F D D B B R R D D";
		data[12] = "L L F F L L F F L L U U F F L L F F U U F F L L";
		data[13] = "L L F F L L F F L L U U F F L L B B D D B B L L";
		data[14] = "L L F F L L F F R R F F U U L L R R F F B B U U";
		data[15] = "L L F F L L F F R R U U L L B B U U B B R R D D";
		data[16] = "L L F F L L F F B B L L F F L L U U L L R R D D";
		data[17] = "L L F F L L F F B B L L F F U U F F B B U U L L";
		data[18] = "L L F F L L F F B B L L B B L L U U L L R R U U";
		data[19] = "L L F F L L F F B B L L U U L L R R U U B B R R";
		data[20] = "L L F F L L F F B B R R F F U U D D R R U U D D";
		data[21] = "L L F F L L F F B B R R U U F F U U B B D D L L";
		data[22] = "L L F F L L F F B B U U L L F F L L F F B B U U";
		data[23] = "L L F F L L F F B B U U L L R R F F R R F F D D";
		data[24] = "L L F F L L F F B B U U L L B B L L F F B B D D";
		data[25] = "L L F F L L F F B B U U F F U U R R B B D D L L";
		data[26] = "L L F F L L F F U U L L R R D D B B R R F F L L";
		data[27] = "L L F F L L F F U U L L B B R R F F B B U U L L";
		data[28] = "L L F F L L F F U U L L U U F F L L U U F F L L";
		data[29] = "L L F F L L F F U U L L U U F F U U F F L L U U";
		data[30] = "L L F F L L F F U U L L U U F F D D B B R R D D";
		data[31] = "L L F F L L F F U U F F L L U U L L F F U U F F";
		data[32] = "L L F F L L F F U U F F L L U U L L B B D D B B";
		data[33] = "L L F F L L F F U U F F U U B B D D R R B B L L";
		data[34] = "L L F F L L R R U U L L F F L L F F B B D D F F";
		data[35] = "L L F F L L R R U U L L F F U U F F R R U U R R";
		data[36] = "L L F F L L R R U U L L R R F F U U F F U U R R";
		data[37] = "L L F F L L U U F F U U L L U U L L F F U U F F";
		data[38] = "L L F F L L U U F F U U L L U U L L B B D D B B";
		data[39] = "F F L L F F L L R R U U L L F F U U F F R R U U R R F F";
		data[40] = "B B L L F F L L R R U U L L F F U U F F R R U U R R B B";
		suurus = 40;
	} else if (kolmTsyklid == 3 && kaksTsyklid == 0 && neliTsyklid == 0){
		data[1] = "L L F F L L F F U U L L U U L L F F U U F F U U";
		data[2] = "L L F F L L F F U U L L U U L L F F D D B B D D";
		data[3] = "L L F F L L F F U U L L U U L L B B U U F F D D";
		data[4] = "L L F F L L F F U U L L U U L L B B D D B B U U";
		data[5] = "L L F F L L U U F F U U F F L L U U L L U U F F";
		data[6] = "L L F F L L U U F F U U F F L L U U R R U U B B";
		data[7] = "L L F F L L U U F F U U F F L L D D L L D D B B";
		data[8] = "L L F F L L U U F F U U F F L L D D R R D D F F";
		data[9] = "L L F F L L U U F F U U F F R R U U L L D D F F";
		data[10] = "L L F F L L U U F F U U F F R R U U R R D D B B";
		suurus = 10;
	} else if (kolmTsyklid == 2 && kaksTsyklid == 2 && neliTsyklid == 0){
		data[1] = "L L F F L L F F U U L L U U F F U U B B L L D D";
		data[2] = "L L F F L L F F U U L L U U F F D D F F R R U U";
		data[3] = "L L F F L L F F U U L L U U B B U U B B R R U U";
		data[4] = "L L F F L L F F U U L L U U B B D D F F L L D D";
		data[5] = "L L F F L L U U F F U U L L U U R R F F D D F F";
		data[6] = "L L F F L L U U F F U U L L U U R R B B U U B B";
		data[7] = "L L F F L L U U F F U U F F L L F F D D R R D D";
		data[8] = "L L F F L L U U F F U U F F L L B B U U R R U U";
		suurus = 8;
	} else if (kaksTsyklid > 3 && neliTsyklid == 0){
		data[1] = "L L F F L L F F L L R R F F L L F F L L U U D D";
		data[2] = "L L F F L L F F L L R R F F L L F F U U D D R R";
		data[3] = "L L F F L L F F L L R R F F L L U U D D B B R R";
		data[4] = "L L F F L L F F L L R R F F R R B B R R U U D D";
		data[5] = "L L F F L L F F L L R R F F U U L L F F L L D D";
		data[6] = "L L F F L L F F L L R R B B R R B B L L U U D D";
		data[7] = "L L F F L L F F L L R R B B R R B B U U D D R R";
		data[8] = "L L F F L L F F L L R R B B U U L L F F R R U U";
		data[9] = "L L F F L L F F L L R R U U F F L L F F D D R R";
		data[10] = "L L F F L L F F L L R R U U F F R R B B U U L L";
		data[11] = "L L F F L L F F B B L L U U F F L L F F D D F F";
		data[12] = "L L F F L L F F B B U U L L F F U U D D L L U U";
		data[13] = "L L F F L L F F U U F F B B U U B B R R F F L L";
		data[14] = "L L F F R R B B U U F F L L F F L L R R U U L L";
		suurus = 14;
	} else if (kaksTsyklid > 2 && neliTsyklid == 0){ // siin on eelmisega kattumisi
		data[1] = "L L F F L L F F L L F F L L U U L L U U L L U U";
		data[2] = "L L F F L L F F L L F F L L U U L L D D R R D D";
		data[3] = "L L F F L L F F L L F F L L U U D D R R U U D D";
		data[4] = "L L F F L L F F L L F F U U L L R R F F B B D D";
		data[5] = "L L F F L L F F L L R R U U L L U U R R D D F F";
		data[6] = "L L F F L L F F L L R R U U L L D D L L U U F F";
		data[7] = "L L F F L L F F L L R R U U F F U U R R F F U U";
		data[8] = "L L F F L L F F L L R R U U F F D D L L B B D D";
		data[9] = "L L F F L L F F L L U U L L B B U U F F R R D D";
		data[10] = "L L F F L L F F L L U U L L B B D D B B L L U U";
		data[11] = "L L F F L L F F L L U U L L U U F F U U L L U U";
		data[12] = "L L F F L L F F L L U U L L U U F F D D R R D D";
		data[13] = "L L F F L L F F L L U U L L D D B B U U R R D D";
		data[14] = "L L F F L L F F B B R R U U L L U U B B L L U U";
		data[15] = "L L F F L L F F B B U U L L F F U U R R D D L L";
		data[16] = "L L F F L L F F B B U U L L R R F F L L F F U U";
		data[17] = "L L F F L L F F B B U U L L U U R R D D B B L L";
		data[18] = "L L F F L L F F U U L L F F L L F F B B U U R R";
		data[19] = "L L F F L L F F U U L L U U B B R R D D B B L L";
		data[20] = "L L F F L L F F U U F F R R U U L L B B D D F F";
		data[21] = "L L F F L L R R F F U U F F L L U U L L B B D D";
		data[22] = "L L F F L L R R U U L L F F R R F F B B D D B B";
		data[23] = "L L F F L L R R U U L L F F U U B B L L U U L L";
		data[24] = "L L F F L L R R U U L L R R F F U U B B U U L L";
		data[25] = "L L F F L L R R U U L L U U L L F F L L B B D D";
		data[26] = "L L F F L L R R U U L L U U R R F F L L F F D D";
		data[27] = "L L F F L L U U L L U U L L F F U U F F U U L L";
		data[28] = "L L F F L L U U L L U U L L F F D D B B D D L L";
		data[29] = "L L F F L L U U F F L L U U L L B B D D B B L L";
		data[30] = "L L F F L L U U F F L L D D L L B B D D F F R R";
		suurus = 30;
	} else if (neliTsyklid == 2){
		data[1] = "L L F F L L F F L L F F L L F F B B L L U U D D";
		data[2] = "L L F F L L F F L L F F L L F F B B U U D D R R";
		data[3] = "L L F F L L F F L L R R B B U U F F R R B B U U";
		data[4] = "L L F F L L F F L L R R U U L L F F L L D D R R";
		data[5] = "L L F F L L F F L L R R U U L L F F U U L L D D";
		data[6] = "L L F F L L F F L L R R U U L L F F D D R R U U";
		data[7] = "L L F F L L F F L L R R U U L L U U L L D D B B";
		data[8] = "L L F F L L F F L L R R U U L L D D R R U U B B";
		data[9] = "L L F F L L F F L L R R U U F F U U L L F F D D";
		data[10] = "L L F F L L F F L L R R U U F F D D R R B B U U";
		data[11] = "L L F F L L F F L L U U F F L L B B U U B B R R";
		data[12] = "L L F F L L F F R R U U L L F F U U F F L L D D";
		data[13] = "L L F F L L F F R R U U L L F F D D B B R R U U";
		data[14] = "L L F F L L F F R R U U L L B B U U F F R R U U";
		data[15] = "L L F F L L F F R R U U L L B B D D B B L L D D";
		data[16] = "L L F F L L F F R R U U L L U U F F U U L L D D";
		data[17] = "L L F F L L F F R R U U L L D D B B U U R R U U";
		data[18] = "L L F F L L F F R R U U L L D D B B D D L L D D";
		data[19] = "L L F F L L F F B B R R U U L L F F L L D D B B";
		data[20] = "L L F F L L F F B B R R U U L L U U F F L L D D";
		data[21] = "L L F F L L F F B B U U L L U U L L D D F F L L";
		data[22] = "L L F F L L F F U U L L U U F F R R U U B B L L";
		data[23] = "L L F F L L F F U U L L U U B B L L D D F F L L";
		data[24] = "L L F F L L F F U U L L U U D D F F R R U U L L";
		data[25] = "L L F F L L F F U U F F R R U U R R F F D D B B";
		data[26] = "L L F F L L R R U U L L U U L L F F R R B B U U";
		data[27] = "L L F F L L R R U U L L U U L L D D R R B B L L";
		data[28] = "L L F F L L R R U U L L U U R R F F R R F F U U";
		data[29] = "L L F F L L U U L L U U R R F F U U B B D D L L";
		data[30] = "L L F F L L U U L L U U R R F F D D F F U U L L";
		suurus = 30;
	} else if (kaksTsyklid > 0 && neliTsyklid == 1){
		data[1] = "L L F F L L F F L L F F L L R R U U F F B B U U ";
		data[2] = "L L F F L L F F L L F F L L U U F F B B U U R R ";
		data[3] = "L L F F L L F F L L R R F F U U F F L L F F D D ";
		data[4] = "L L F F L L F F L L R R U U L L F F R R U U L L ";
		data[5] = "L L F F L L F F L L R R U U L L R R U U L L B B ";
		data[6] = "L L F F L L F F L L U U L L F F U U B B L L D D ";
		data[7] = "L L F F L L F F L L U U L L R R F F U U B B D D ";
		data[8] = "L L F F L L F F L L U U L L R R F F D D F F U U ";
		data[9] = "L L F F L L F F L L U U L L B B U U B B R R U U ";
		data[10] = "L L F F L L F F L L U U L L U U B B U U R R U U ";
		data[11] = "L L F F L L F F L L U U L L U U B B D D L L D D ";
		data[12] = "L L F F L L F F L L U U L L D D F F U U L L D D ";
		data[13] = "L L F F L L F F L L U U L L D D F F D D R R U U ";
		data[14] = "L L F F L L F F L L U U F F L L F F D D F F R R ";
		data[15] = "L L F F L L F F B B L L U U L L F F L L D D F F ";
		data[16] = "L L F F L L F F B B L L U U L L U U B B R R U U";
		data[17] = "L L F F L L F F B B L L U U F F R R U U F F U U";
		data[18] = "L L F F L L F F B B L L U U F F U U F F U U R R";
		data[19] = "L L F F L L F F B B R R U U F F U U F F D D R R";
		data[20] = "L L F F L L F F B B U U L L U U L L U U F F R R";
		data[21] = "L L F F L L F F B B U U L L U U R R U U B B R R";
		data[22] = "L L F F L L F F B B U U F F U U L L B B U U L L";
		data[23] = "L L F F L L F F B B U U F F U U D D L L F F U U";
		data[24] = "L L F F L L F F B B U U F F U U D D R R F F D D";
		data[25] = "L L F F L L F F U U L L R R F F U U L L B B U U";
		data[26] = "L L F F L L F F U U L L R R F F U U R R B B D D";
		data[27] = "L L F F L L F F U U L L R R F F D D L L F F U U";
		data[28] = "L L F F L L F F U U L L R R F F D D R R F F D D";
		data[29] = "L L F F L L F F U U L L U U L L F F B B D D B B";
		data[30] = "L L F F L L F F U U L L U U L L D D B B U U D D";
		data[31] = "L L F F L L F F U U L L U U R R F F B B D D F F";
		data[32] = "L L F F L L F F U U L L U U R R D D F F U U D D";
		data[33] = "L L F F L L F F U U L L U U D D B B L L U U R R";
		data[34] = "L L F F L L F F U U F F L L U U R R F F D D F F";
		data[35] = "L L F F L L F F U U F F U U F F D D L L B B L L";
		data[36] = "L L F F L L R R U U L L F F L L D D F F U U D D";
		data[37] = "L L F F L L R R U U L L F F R R D D B B U U D D";
		data[38] = "L L F F L L R R U U F F U U F F U U R R U U D D";
		data[39] = "L L F F L L U U L L U U L L F F B B U U B B R R";
		data[40] = "L L F F L L U U L L U U L L F F U U B B U U R R";
		data[41] = "L L F F L L U U L L U U L L F F D D F F D D R R";
		data[42] = "L L F F L L U U L L U U F F U U F F R R D D R R";
		data[43] = "L L F F L L U U L L U U F F U U B B R R U U R R";
		data[44] = "L L F F L L U U L L U U F F D D F F L L D D R R";
		data[45] = "L L F F L L U U L L U U F F D D B B L L U U R R";
		data[46] = "L L F F L L U U L L U U R R D D F F U U D D L L";

		suurus = 46;
	} else {
		throw;
	}
}
