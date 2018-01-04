/*
 * engine.cpp
 *
 *  Created on: Jan 4, 2018
 *      Author: root
 */

#include <allegro.h>
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

	allegro_init();
	/*if (install_joystick(JOY_TYPE_AUTODETECT) == 0){
	install_keyboard();
	joyst = false;
	}*/
	install_joystick(JOY_TYPE_AUTODETECT);
	set_gfx_mode(GFX_SAFE, 10,10,10,10);
}

void engine::initScreen (int wid, int hei){
    xlen = wid;
    ylen = hei;
    ekraan.resize(ylen, std::vector <char>(xlen));

}

void engine::printScreen(){
    for (int i=0;i<50;i++){
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

void engine::getInput(){
    if (joyst){
        poll_joystick();
        for (int i=0;i<NUM_BUTTONS; i++){
            if (joy[0].button[i].b){
                buttons[i] = true;
            } else {
                buttons[i] = false;
            }
        }
    }
    poll_keyboard();


    xstick = joy[0].stick[0].axis[0].pos;
    ystick = joy[0].stick[0].axis[1].pos;
}
