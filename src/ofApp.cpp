#include "ofApp.h"


#define STRENGTH 100

//#define CAM

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofHideCursor();
    
    camWidth = ofGetScreenWidth();
    camHeight = ofGetScreenHeight();
    
    useCam = true;
    
    cam.initGrabber(camWidth, camHeight);
  //  cvImgColor.allocate(camWidth, camHeight);
//    cam.update();

    
    ofSetBackgroundAuto(false);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    ofBackground(0);
    
    for (int i=0; i<7000; i++) {
        createParticle();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate(),0));
    
    cam.update();
    //cvImgColor.setFromPixels(cam.getPixels(), camWidth, camHeight);
    if(cam.isFrameNew())
        img.setFromPixels(cam.getPixels(), camWidth, camHeight, OF_IMAGE_COLOR);
    for (int i=0; i<particles.size(); i++) {
        particles[i].update();
    }
}

void ofApp::mousePressed(int x, int y, int button){
    
   /* particles.clear();
    
    for (int i=0; i<3000; i++) {
        createParticle();
    }*/
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    
    if ( ofGetKeyPressed('z')){
        //img.draw(0,0);
        ofBackground(0,0,0);
    }
    
    
    for (int i=0; i<particles.size(); i++) {
        Particle &p = particles[i];
        //p.color = img.getColor(p.pos.x,p.pos.y);
        
        if(ofGetMousePressed()){
            double accel = STRENGTH/sqrt(pow(p.pos.x-ofGetMouseX(), 2)+pow(p.pos.y-ofGetMouseY(),2));
            
            double angle = atan2(p.pos.x-ofGetMouseX(), p.pos.y-ofGetMouseY());
            
            p.vel.x-=sin(angle)*accel;
            p.vel.y-=cos(angle)*accel;
        }
        
        //p.vel.x*=.999;
        //p.vel.y*=.999;
        
        if(!ofGetKeyPressed('z')){
            
            
            if(p.pos.x > 0 && p.pos.y > 0 && p.pos.x < camWidth && p.pos.y < camHeight){
                if(useCam){
                    p.draw(img.getColor(p.pos.x, p.pos.y));
                }else{
                    if(i%3==0)
                        p.draw(ofColor(ofRandom(0, 255),ofRandom(0, 255),ofRandom(0, 255)));
                    else if(i%3==1)
                        p.draw(ofColor(150,150,150));
                    else
                        p.draw(ofColor(255,255,255));
                }
                
            }
            
            
        }else{
            p.draw(ofColor(0,255,0));
        }
        

        // draw cursor
        //ofSetColor(20, 20, 20);
        //ofCircle(ofGetMouseX(), ofGetMouseY(), 5);
        
    }
    
}

void ofApp::createParticle() {
    Particle p(&camWidth, &camHeight);
    p.setup();
    p.pos.set(ofRandomWidth(), ofRandomHeight());
    p.color = img.getColor(p.pos.x,p.pos.y);
    particles.push_back(p);
}

void ofApp::mouseMoved(int x, int y){
    ofShowCursor();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key=='s') ofSaveFrame();
    if (key=='q') ofEnableSmoothing();
    if (key=='Q') ofDisableSmoothing();
    if (key=='c') useCam = !useCam;
}
