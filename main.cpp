#include <allegro.h>
#include <iostream>

using namespace std;

#include <list>
#include <math.h>

BITMAP *lienzo;

#include "Alarm.h"
#include "Bala.h"
#include "Personaje.h"
#include "Enemigo.h"
#include "Background.h"

Alarm *Timer = new Alarm(); 

void init();
void deinit();
void crear();
void Enemigo_action();

int main(){
	init();
	
	lienzo = create_bitmap(SCREEN_W, SCREEN_H);
	Personaje *fantasma = new Personaje();
	Background* background = new Background("fondo.bmp");
	
	srand(time(NULL)); // hace que los numeros sean aleatorios
	
	while (!key[KEY_ESC] && fantasma->vida > 0){
		background->action() ; // mostrar el fondo
		crear();
		Enemigo_action();
		if (fantasma->vida > 0){
			fantasma->mov(); // mover la nave si su vida es mayor a 0
		} 	
		draw_sprite(screen, lienzo ,0 ,0);
		clear_to_color(lienzo, 0x000000);
	}

	deinit();
	return 0;
}
END_OF_MAIN();


void crear(){
	static int cont = 0; // cuenta los enemigos que se crean
	static int type = rand()%3; // crea un numero aleatorio entre el 0 y 2
	
	if(cont < 6){
		if(Timer->alarm(180)){
			Enemigos.push_back(new Enemigo(-80, 15, type)); // crear un enemigo random
			cont++;	
		}
	}else{
		if(Timer->alarm(320)){
			cont = 0; //reinicia el contador
			type = rand()%3;
		}
	}
	
}


void Enemigo_action(){
	for(list<Enemigo*>::iterator it = Enemigos.begin(); it != Enemigos.end(); it++){
		Enemigo *b = *it;
		b->action();
	}
}

void init() {
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
	/* add other initializations here */
}

void deinit() {
	clear_keybuf();
	/* add other deinitializations here */
}
