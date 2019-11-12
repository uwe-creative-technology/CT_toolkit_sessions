#pragma once


// Dan Buzzo 2019 -
// http://buzzo.com
// https://github.com/danbz
// for UWE Bristol, Creative Technology MSc, Creative Technology Toolkit module 2019-20
// https://github.com/uwe-creative-technology
// http://uwecreativetechnology.com


#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofVideoPlayer vidPlayer;
    float speed, currentPosition;
    bool b_playing, b_dragged;
    string loopStyle;
};
