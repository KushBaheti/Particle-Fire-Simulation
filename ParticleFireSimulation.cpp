#define SDL_MAIN_HANDLED ;

#include <iostream>
#include <cstring>
#include "Screen.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"
using namespace std;
using namespace particlefiresimulation;

int main() {

	srand(time(NULL));

	Screen screen;
	if (!screen.init()){
		cout << "Error initializing SDL :(" << endl;
	}

	Swarm swarm;

	// Game loop
	while (true){
		int elapsed = SDL_GetTicks();

		// Update particles
		// screen.clear();
		swarm.update(elapsed);

		// Draw particles
		unsigned char red = (unsigned char)((1 + sin(elapsed*0.0001)) * 128);
		unsigned char green = (unsigned char)((1 + sin(elapsed*0.0002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed*0.0003)) * 128);

		const Particle * const pParticles = swarm.getParticles();

		for (int i = 0; i < Swarm::NPARTICLES; i++){
			Particle pParticle = pParticles[i];
			int x = (pParticle.m_x + 1) * Screen::SCREEN_WIDTH/2;
			int y = pParticle.m_y * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2;

			screen.setPixel(x, y, red, green, blue);
		}

//		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++){
//			for (int x = 0; x < Screen::SCREEN_WIDTH; x++){
//  				if (x % 5000 == 0){
//  					r = (r+1)%255;
//  					g = (g+1)%255;
//  					b = (b+1)%255;
//				}
//				screen.setPixel(x, y, red, green, blue);
//			}
//		}

		// Draw the screen
		screen.boxBlur();
		screen.update();

		// Check for messages/events
		if (!screen.processEvents()){
			break;
		}
	}

	screen.close();

	return 0;
}

