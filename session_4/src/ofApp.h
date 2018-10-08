#pragma once

#include "ofMain.h"
#include "ofxEspeakSynth.h"

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
    
    // create instance of an Espeak object
   // ofxEspeakSynth spk;
    
    // requires https://downloads.sourceforge.net/project/espeak/espeak/espeak-1.45/espeak-1.45.04-OSX.zip?r=&ts=1538935584&use_mirror=kent
};

class ofLogAudio : public ofThread{
public:
    bool startSpeak = false;
    string msg;
    string speak;
    
    void start(string _c="/usr/bin/espeak -v mb-it3")
    {
        speak = _c;
        startThread(true);
    }
    
    void LogAudio(string _msg)
    {
        msg = _msg;
        startSpeak = true;
    }
    
    void threadedFunction()
    {
        while(isThreadRunning())
        {
            if(startSpeak)
            {
                ofSystem(speak+" '"+msg+"' > /dev/null 2>&1");
                startSpeak = false;
            }
            
        }
    }
};
