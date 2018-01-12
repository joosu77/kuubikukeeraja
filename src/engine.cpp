/*
 * engine.cpp
 *
 *  Created on: Jan 4, 2018
 *      Author: root
 */

#include <iostream>
#include <chrono>

#include "engine.h"

engine::engine(){
	for (int i=0;i<NUM_BUTTONS;i++){
		buttons [i] = false;
	}
	//buttons: x, a, b, y, L, R, <>, <>, select, start
	joyst = true;

	xstick = 0;
	ystick = 0;

	FPS = 0;
	xlen = 0;
	ylen = 0;

	score = 0;
}

engine::engine (int wid, int hei) {
	engine();

	initScreen(wid, hei);
}

void engine::initScreen (int wid, int hei){
    xlen = wid;
    ylen = hei;
    ekraan.resize(ylen, std::vector <char>(xlen));


	// taidab ekraani array tyhjusega
	for (int y = 0; y < ylen; y++) {
		for (int x = 0; x < xlen; x++) {
			ekraan[y][x] = ' ';
		}
	}
}

void engine::printScreen(){
    for (int i=0;i<2;i++){
        std::cout << std::endl;
    }

    std::cout << " SCORE: " << score << "     FPS: " << FPS << std::endl;

    for (int u=0; u<(xlen*2+2); u++){
        std::cout << "-";
    }
    std::cout << std::endl;

    for (int i=0; i<ylen; i++){
        std::cout << "|";
        for (int e=0; e<xlen; e++){
            std::cout << ekraan[i][e] << " ";
        }
        std::cout << "|";
        std::cout << std::endl;
    }
    for (int u=0; u<(xlen*2+2); u++){
        std::cout << "-";
    }
    std::cout << std::endl << std::endl << std::endl;
}
