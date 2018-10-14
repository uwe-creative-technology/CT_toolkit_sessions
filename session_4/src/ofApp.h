#pragma once

#include "ofMain.h"

// Dan Buzzo 2018 - github.com/uwe-creative-technology/
// for UWE Bristol, Creative Technology MSc, Creative Technology Toolkit module 2018-19
// http://uwecreativetechnology.com


class ofApp : public ofBaseApp{

   
    
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mousePressed(int x, int y, int button);

    ofSoundPlayer  beats; // create sound objects and give them names
    ofSoundPlayer  synth;
};

