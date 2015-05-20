#include "ofMain.h"

class Particle {
public:
    Particle(int * screen_w, int * screen_h): screen_width(screen_w), screen_height(screen_h) {}
    
    void setup();
    void draw();
    void draw(ofColor color);
    void update();
    
    ofVec2f pos,vel,acc,oldpos;
    float angle;
    ofColor color;
    
    int * screen_width;
    int * screen_height;
    
};
