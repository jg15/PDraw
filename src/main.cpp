#include "ofMain.h"
#include "ofApp.h"

#include <CoreGraphics/CoreGraphics.h>

//========================================================================
int main( ){
    
    CGDirectDisplayID screen_id =  CGMainDisplayID();
    
	ofSetupOpenGL(CGDisplayPixelsWide(screen_id),CGDisplayPixelsHigh(screen_id),OF_FULLSCREEN);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
