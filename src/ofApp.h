#pragma once
#include "ofMain.h"
#include "Particle.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void createParticle();
    void keyPressed(int key);
    void mousePressed(int x, int y, int button);
    void mouseMoved(int x, int y );
    
    ofImage img;
    
    vector<Particle> particles;
    
    
    ofVideoGrabber cam;
    
    int camWidth;
    int camHeight;
    
    bool useCam;
};