#include "Particle.h"

void Particle::setup() {
    vel.x = 0;//2*ofRandomf();
    vel.y = 0;//2*ofRandomf();
    angle = ofRandomf()*TWO_PI;
}

void Particle::draw() {
    //ofSetColor(color,ofMap(age,0,20,255,0,true));
    ofLine(oldpos,pos);

}

void Particle::draw(ofColor color){
    ofSetColor(color);
    //ofCircle(pos, 1);
    ofLine(oldpos,pos);
}

void Particle::update() {
    angle += ofSignedNoise(pos.x, pos.y)*TWO_PI;
    vel.rotate(angle);
    oldpos = pos;
    pos += vel;
    if((unsigned)pos.x >= *screen_width || (unsigned)pos.y >= *screen_height) { vel.x *= -.9; vel.y *=-.9; }
}