#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // the setup function is called once when your program starts
    // set the background color
    ofBackground(0,0,0);
    
    // put some integer values into the variables we declared in the header file
    // we will use this to try try to grab at this size
    camWidth = 640;
    camHeight = 480;
    
    // tell our vidGrabber object to set some parameters that it has inside itself.
    // we use 'dot notation' - this means the name of the object and the parameter or method inside it that we want to interact with.
    //set the results that vidgrabber sends us back to give more information
    vidGrabber.setVerbose(true);
    
    // pass out variables we set up above as parameters to the method 'setup'
    vidGrabber.setup(camWidth,camHeight);
    // this loads the font resource. By default it looks in the bin/data folder in our project
    // font.load("Courier New Bold.ttf", 9);
    
    // this set of characters comes from the Ascii Video Processing example by Ben Fry,
    // changed order slightly to work better for mapping
    //     asciiCharacters =  string("  ..,,,'''``--_:;^^**""=+<>iv%&xclrs)/){}I?!][1taeo7zjLunT#@JCwfy325Fp6mqSghVd4EgXPGZbYkOA8U$KHDBWNMR0Q");
    
    // tell our app that we will be blending things together
    ofEnableAlphaBlending();
    
    // setup elements for the inverted video hack
    //
    //        videoInverted.allocate(camWidth, camHeight, OF_PIXELS_RGB);
    //        videoTexture.allocate(videoInverted);
    //        ofSetVerticalSync(true);
}


//--------------------------------------------------------------
void ofApp::update(){
    // the update loops every frame, as fast as it can
    // here we ask the video grabber object to see if there is a new frame from our video camera and if so to load it into the vid grabber object
    vidGrabber.update();
    
    // uncomment this to see our cool inverted video hack
    // here we check if there is a new frame from the camera and loop through all the pixels
    // and invert them and put into our pixels object
    //
    //        if(vidGrabber.isFrameNew()){
    //        ofPixels & pixels = vidGrabber.getPixels();
    //        for(size_t i = 0; i < pixels.size(); i++){
    //            //invert the color of the pixel
    //            videoInverted[i] = 255 - pixels[i];
    //        }
    //        //load the inverted pixels
    //        videoTexture.loadData(videoInverted);
    //    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // the draw loop is called every frame after the update() function
    
    // change background video alpha value based on the cursor's x-position
    //     float videoAlphaValue = ofMap(mouseX, 0, ofGetWidth(), 0, 255);
    //
    //    // set a white fill color with the alpha generated above
    //    ofSetColor(255,255,255,videoAlphaValue);
    
    // draw the raw video frame with the alpha value generated above
    // tell our video grabber object to draw the frame from the camera starting at a location on screen.
    vidGrabber.draw(0,0);
    
    // here we can draw our inverted video picture too, at a position across from the plain video
    //    videoTexture.draw( camWidth, 0, camWidth, camHeight);
    
    // uncomment this section to enable the ASCII video effect
    //
    // we make a new object to contain all the pixel data from our video grabber
    //        ofPixelsRef pixelsRef = vidGrabber.getPixels();
    //
    //        ofSetHexColor(0xffffff);
    //    //
    //    // here we make a loop that loops through from 0 to camWidth, in steps of 7
    //        for (int i = 0; i < camWidth; i+= 7){
    //    // inside this is another loop that loops from 0 to the camHeight in steps of 9
    //            for (int j = 0; j < camHeight; j+= 9){
    //                // get the pixel and its lightness (lightness is the average of its RGB values)
    //                float lightness = pixelsRef.getColor(i,j).getLightness();
    //
    //                // calculate the index of the character from our asciiCharacters array
    //                int character = powf( ofMap(lightness, 0, 255, 0, 1), 2.5) * asciiCharacters.size();
    //
    //                // draw the character at the correct location
    //                font.drawString(ofToString(asciiCharacters[character]), i, j);
    //            }
    //        }
    //
    
    
    
}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
    
    // in fullscreen mode, on a pc at least, the
    // first time video settings the come up
    // they come up *under* the fullscreen window
    // use alt-tab to navigate to the settings
    // window. we are working on a fix for this...
    
    if (key == 's' || key == 'S'){
        vidGrabber.videoSettings();
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){ 
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
