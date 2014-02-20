//finally done rough draft

#include "testApp.h"
#include <stdio.h>
#include <math.h>
using namespace std;
typedef vector<pair<float, float> > vp;
typedef vector<pair<pair<float, float>, int > > vppi;
typedef vector<pair<pair<float, float>, float> > vppf;
typedef vector<vector<float> > vvf;
vppi randomships;
vppf icebergs;
vector<pair<int, int> > iceberg_size;

vvf widgets;
vvf ships;

vvf xstrip;
vvf ystrip;
vvf semicircle;

vvf xstrip2;
vvf ystrip2;
vvf semicircle2;

vvf rings;
vvf links;
vvf lattice;

int myCircleX;
int myCircleY;

ofColor red = ofColor(176,48,96);
ofColor violet_red = ofColor(2208,32,144);
ofColor violet = ofColor(238,130,238);
ofColor plum = ofColor(221,160,221);
ofColor medium_orchid = ofColor (186,85,211);
ofColor dark_violet = ofColor(148,0,211);


int gree1, gree2, gree3, gree4;
ofColor green1;
ofColor green2;
ofColor green3;
ofColor green4;
bool green_fade;


int blu1, blu2, blu3, blu4;
ofColor blue1;
ofColor blue2;
ofColor blue3;
ofColor blue4;
bool blue_fade;


ofColor maroon1;
ofColor maroon2;
ofColor maroon3;
ofColor maroon4;

ofColor purple1;
ofColor purple2;
ofColor purple3;
ofColor purple4;

ofColor aquamarine1 = ofColor(127,255,212);
ofColor aquamarine2 = ofColor(118,238,198);
ofColor aquamarine3 = ofColor(102,205,170);
ofColor aquamarine4 = ofColor(69,139,116);

vector<ofColor> purple;
vector<ofColor> green;
vector<ofColor> blue;
vector<ofColor> aquamarine;
vector<ofColor> maroon;


float xspacing;
float yspacing;

bool traverse_upy;
bool traverse_downy;
bool y_oscillate;

bool traverse_upx;
bool traverse_downx;
bool x_oscillate;

float shipspeed;
bool flip;
//vector<std::pair<float, float> > randomships;

float x;
float y;
vector<float> epsilon;

float gg;
int iterations;
//--------------------------------------------------------------
void testApp::setup(){
    gg = 200;
    iterations = 1;
    ofSetWindowShape(1000,1000);
	ofBackground(0,0,0);
	ofSetVerticalSync(true); // don't go too fast
	ofEnableAlphaBlending();
    
    
    
    shipspeed = .1;
    flip = false;
    
    
    xspacing = 10;
    yspacing = 10;
    y_oscillate = false;
    x_oscillate = false;
    
    /*maroon1 = ofColor(139,105,105);
     maroon2 = ofColor(205,155,155);
     maroon3 = ofColor(238,180,180);
     maroon4 = ofColor(255,193,193);
     
     maroon.push_back(maroon1);
     maroon.push_back(maroon2);
     maroon.push_back(maroon3);
     maroon.push_back(maroon4);
     */
    
    purple1 = ofColor(150,0,205);
    purple2 = ofColor(164,66,220);
    purple3 = ofColor(181,100,227);
    purple4 = ofColor(200,120,240);
    
    purple.push_back(purple1);
    purple.push_back(purple2);
    purple.push_back(purple3);
    purple.push_back(purple4);
    
    
    
    blue_fade = true;
    green_fade = false;
    
    blu1 = 200; blu2 = 150; blu3 = 100; blu4 = 50;
    blue1 = ofColor(0,0,blu1);
    blue2 = ofColor(0,0,blu2);
    blue3 = ofColor(0,0,blu3);
    blue4 = ofColor(0,0,blu4);
    
    blue.push_back(blue1);
    blue.push_back(blue2);
    blue.push_back(blue3);
    blue.push_back(blue4);
    
    
    
    gree1 = 140; gree2 = 120; gree3 =90; gree4 = 70;
    green1 = ofColor(0,gree1,0);
    green2 = ofColor(0,gree2,0);
    green3 = ofColor(0,gree3,0);
    green4 = ofColor(0,gree4,0);
    
    green.push_back(green1);
    green.push_back(green2);
    green.push_back(green3);
    green.push_back(green4);
    

    
    aquamarine.push_back(aquamarine1);
    aquamarine.push_back(aquamarine2);
    aquamarine.push_back(aquamarine3);
    aquamarine.push_back(aquamarine4);
    
    traverse_upx = true;
    traverse_downx = false;
    
    traverse_upy = true;
    traverse_downx = false;
    
    x=250;
    y=250;
    
    for(int i =0; i <6000; i++){
        float ep = ofRandom(-.5,.5);
        epsilon.push_back(ep);
    }
    
    
    for(int i = 0; i<30; i++){
        float randomx = ofRandom(0, ofGetWidth());
        float randomy = ofRandom(0, ofGetHeight());
        int dir = rand() % 4;
        randomships.push_back( make_pair<pair<float, float>, int> (make_pair<float, float>(randomx, randomy), dir));
    }
    
    for(int i = 0; i<10; i++){
        float randomx = ofRandom(0, ofGetWidth());
        float randomy = ofRandom(0, ofGetHeight());
        float radius = ofRandom(1, 2);
        icebergs.push_back(make_pair<pair<float, float>, int> (make_pair<float, float>(randomx, randomy), radius));
    }
    
    for(int i = 0; i<icebergs.size();i++){
        int numx = (rand() % 6)+1;
        int numy = (rand() % 8)+1;
        iceberg_size.push_back(make_pair<int, int> (numx, numy));
        
    }
    
    for(int i = 0; i<100; i++){
        float x = ofRandom(0, ofGetWidth());
        float y = ofRandom(0, ofGetHeight());
        float r = ofRandom(0,3);
        float r2 = ofRandom(0,2);
        float r3 = ofRandom(0,2);
        float green = ofRandom(50,255);
        float purple = ofRandom(50,255);
        
        vector<float> temp;
        temp.push_back(x);
        temp.push_back(y);
        temp.push_back(r);
        temp.push_back(r2);
        temp.push_back(r3);
        temp.push_back(green);
        temp.push_back(purple);
        widgets.push_back(temp);
    }
    
    
    
    
    
    //xstrip1
    for(int i = 0; i<100; i++){
        float x = ofRandom(0, 400);
        float y = ofRandom(150, 250);
        float r = ofRandom(0,4);
        float r2 = ofRandom(0,r);
        float r3 = ofRandom(0,r);
        float green = ofRandom(50,255);
        float purple = ofRandom(50,255);
        
        vector<float> temp;
        temp.push_back(x);
        temp.push_back(y);
        temp.push_back(r);
        temp.push_back(r2);
        temp.push_back(r3);
        temp.push_back(green);
        temp.push_back(purple);
        xstrip.push_back(temp);
    }
    
    //ystrip1
    for(int i = 0; i<90; i++){
        float x = ofRandom(170,230);
        float y = ofRandom(0,400);
        float r = ofRandom(0,4);
        float r2 = ofRandom(0,r);
        float r3 = ofRandom(0,r);
        float green = ofRandom(50,255);
        float purple = ofRandom(50,255);
        
        vector<float> temp;
        temp.push_back(x);
        temp.push_back(y);
        temp.push_back(r);
        temp.push_back(r2);
        temp.push_back(r3);
        temp.push_back(green);
        temp.push_back(purple);
        ystrip.push_back(temp);
    }
    
    
    //circle rim for xstrip1 and ystrip1
    for(int i = 0; i<160; i++){
        float x;
        float y;
        if(i<40){
            x = ofRandom(0,200);
            y = ofRandom(sqrt((float)40000 - pow((x-200),2))+200 -5,sqrt((float)40000 - pow((x-200),2))+200 );
        }
        else if((i>=40) && (i<80)){
            x = ofRandom(0,200);
            y = ofRandom(200-sqrt((float)40000 - pow((x-200),2))-5,200-sqrt((float)40000 - pow((x-200),2)) );
        }
        else if((i>=80) && (i<120)){
            x = ofRandom(200,400);
            y = ofRandom(200-sqrt((float)40000 - pow((x-200),2))-5,200-sqrt((float)40000 - pow((x-200),2)) );
        }
        else if((i>=120) && (i<160)){
            x = ofRandom(200,400);
            y = ofRandom(sqrt((float)40000 - pow((x-200),2))+200-5,sqrt((float)40000 - pow((x-200),2))+200 );
        }
        float r = ofRandom(0,4);
        float r2 = ofRandom(0,r);
        float r3 = ofRandom(0,r);
        float green = ofRandom(50,255);
        float purple = ofRandom(50,255);
        
        vector<float> temp;
        temp.push_back(x);
        temp.push_back(y);
        temp.push_back(r);
        temp.push_back(r2);
        temp.push_back(r3);
        temp.push_back(green);
        temp.push_back(purple);
        semicircle.push_back(temp);
    }
    
    
    
    
    
    
    //2nd ship
    //draw xstrip2
    //centered at 600,500
    for(int i = 0; i<120; i++){
        float x = ofRandom(350, 850);
        float y = ofRandom(450, 550);
        float r = ofRandom(0,4);
        float r2 = ofRandom(0,r);
        float r3 = ofRandom(0,r);
        float green = ofRandom(50,255);
        float purple = ofRandom(50,255);
        
        vector<float> temp;
        temp.push_back(x);
        temp.push_back(y);
        temp.push_back(r);
        temp.push_back(r2);
        temp.push_back(r3);
        temp.push_back(green);
        temp.push_back(purple);
        xstrip2.push_back(temp);
    }
    
    //draw ystrip2
    for(int i = 0; i<120; i++){
        float x = ofRandom(550,650);
        float y = ofRandom(250,750);
        float r = ofRandom(0,4);
        float r2 = ofRandom(0,r);
        float r3 = ofRandom(0,r);
        float green = ofRandom(50,255);
        float purple = ofRandom(50,255);
        
        vector<float> temp;
        temp.push_back(x);
        temp.push_back(y);
        temp.push_back(r);
        temp.push_back(r2);
        temp.push_back(r3);
        temp.push_back(green);
        temp.push_back(purple);
        ystrip2.push_back(temp);
    }
    
    //circle rim for xstrip2 and ystrip2
    for(int i = 0; i<200; i++){
        float x;
        float y;
        if(i<50){
            x = ofRandom(350,600);
            y = ofRandom(sqrt((float)62500 - pow((x-600),2))+500 -5,sqrt((float)62500 - pow((x-600),2))+500 );
        }
        else if((i>=50) && (i<100)){
            x = ofRandom(350,600);
            y = ofRandom(500-sqrt((float)62500 - pow((x-600),2))-5,500-sqrt((float)62500 - pow((x-600),2)) );
        }
        else if((i>=100) && (i<150)){
            x = ofRandom(600,850);
            y = ofRandom(500-sqrt((float)62500 - pow((x-600),2))-5,500-sqrt((float)62500 - pow((x-600),2)) );
        }
        else if((i>=150) && (i<200)){
            x = ofRandom(650,800);
            y = ofRandom(sqrt((float)62500 - pow((x-600),2))+500-5,sqrt((float)62500 - pow((x-600),2))+500 );
        }
        float r = ofRandom(0,4);
        float r2 = ofRandom(0,r);
        float r3 = ofRandom(0,r);
        float green = ofRandom(50,255);
        float purple = ofRandom(50,255);
        
        vector<float> temp;
        temp.push_back(x);
        temp.push_back(y);
        temp.push_back(r);
        temp.push_back(r2);
        temp.push_back(r3);
        temp.push_back(green);
        temp.push_back(purple);
        semicircle.push_back(temp);
    }
    
    
    
    //some rings
    for(int i = 0; i<50; i++){
        float x = ofRandom(0, ofGetWidth());
        float y = ofRandom(0, ofGetHeight());
        float r = ofRandom(1,5);
        float r2 = ofRandom(r/2,r);
        float color = ofRandom(0,1);
        float green = ofRandom(50,255);
        float purple = ofRandom(50,255);
        
        vector<float> temp;
        temp.push_back(x);
        temp.push_back(y);
        temp.push_back(r);
        temp.push_back(r2);
        temp.push_back(green);
        temp.push_back(purple);
        rings.push_back(temp);
    }
    
    //some ships?
    for(int i = 0; i<10; i++){
        float x = ofRandom(0, ofGetWidth());
        float y = ofRandom(0, ofGetHeight());
        float r = ofRandom(1,5);
        float r2 = ofRandom(r/2,r);
        float color = ofRandom(0,1);
        float green = ofRandom(50,255);
        float purple = ofRandom(50,255);
        
        vector<float> temp;
        temp.push_back(x);
        temp.push_back(y);
        temp.push_back(r);
        temp.push_back(r2);
        temp.push_back(green);
        temp.push_back(purple);
        ships.push_back(temp);
    }
    
    
    //create link or whatever you want to call it
    for(int i = 0; i<40; i++){
        float x = ofRandom(250,550);
        float y = 250 + (.666) * (x-250) + ofRandom(+5,-5);
        float r = ofRandom(0,3);
        float upordown = ofRandom(0,1);
        //cout<<"x is"<<x<<"and y is"<<y<<endl;
        vector<float> temp;
        temp.push_back(x);
        temp.push_back(y);
        temp.push_back(r);
        links.push_back(temp);
    }
    
    
    //create lattice
    for(int i = 0; i<8; i++){
        float x = ofRandom(0,ofGetWidth());
        float y = ofRandom(0,ofGetHeight());
        float r = ofRandom(0,1.5);
        float dimx_left = ofRandom(1,5);
        float dimx_right = ofRandom(1,5);
        float dimy = ofRandom(1,7);
        //cout<<"x is"<<x<<"and y is"<<y<<endl;
        vector<float> temp;
        temp.push_back(x);
        temp.push_back(y);
        temp.push_back(r);
        temp.push_back(dimx_left);
        temp.push_back(dimx_right);
        temp.push_back(dimy);
        lattice.push_back(temp);
    }
    
    
    
	// load in sounds:
	beat.loadSound("sounds/eno.mp3");
    beat.play();
	ow.loadSound("sounds/ow.mp3");
	dog.loadSound("sounds/dog.mp3");
	rooster.loadSound("sounds/rooster.mp3");
	
	// we will bounce a circle using these variables:
	px = 300;
	py = 300;
	vx = 0;
	vy = 0;
    
	// the fft needs to be smoothed out, so we create an array of floats
	// for that purpose:
	fftSmoothed = new float[8192];
	for (int i = 0; i < 8192; i++){
		fftSmoothed[i] = 0;
	}
	
	nBandsToGet = 128;
}


//--------------------------------------------------------------
void testApp::update(){
	if(shipspeed >.1)
        shipspeed = .1;
	//ofBackground(80,80,20);
    
	// update the sound playing system:
	ofSoundUpdate();
	
	// (1) we increase px and py by adding vx and vy
	px += vx;
	py += vy;
	
    
    
	// (2) check for collision, and trigger sounds:
	// horizontal collisions:
	if (px < 0){
		px = 0;
		vx *= -1;
		//dog.play();
	} else if (px > ofGetWidth()){
		px = ofGetWidth();
		vx *= -1;
		//ow.play();
	}
	// vertical collisions:
	if (py < 0 ){
		py = 0;
		vy *= -1;
		//rooster.play();
	} else if (py > ofGetHeight()){
		py = ofGetHeight();
		vy *= -1;
		beat.play();
	}
    
    
	// (3) slow down velocity:
	vx 	*= 0.996f;
	vy 	*= 0.996f;
    
    
    
	// (4) we use velocity for volume of the samples:
	float vel = sqrt(vx*vx + vy*vy);
	ow.setVolume(MIN(vel/5.0f, 1));
	//beat.setVolume(MIN(vel/5.0f, 1));
	//dog.setVolume(MIN(vel/5.0f, 1));
	//rooster.setVolume(MIN(vel/5.0f, 1));
    
	// (5) grab the fft, and put in into a "smoothed" array,
	//		by taking maximums, as peaks and then smoothing downward
	float * val = ofSoundGetSpectrum(nBandsToGet);		// request 128 values for fft
    
    
    /*
     float * ofSoundGetSpectrum(int nBands){
     #ifdef OF_SOUND_PLAYER_FMOD
     return ofFmodSoundGetSpectrum(nBands);
     #elif defined(OF_SOUND_PLAYER_OPENAL)
     return ofOpenALSoundPlayer::getSystemSpectrum(nBands);
     #else
     ofLogError("ofSoundPlayer") << "ofSoundGetSpectrum(): not implemented, returning NULL";
     return NULL;
     #endif
     }*/
    
    
	for (int i = 0;i < nBandsToGet; i++){
		
		// let the smoothed calue sink to zero:
		fftSmoothed[i] *= 0.96f;  //this is for the effect that the bars come down before they go back up otherwise it's not really animated
		
		// take the max, either the smoothed or the incoming:
		if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
		
	}
    
    
    ofEnableAlphaBlending();
    /*
     if(spacing < 60)
     spacing++;
     else if (spacing <20)
     spacing--;
     
     */
    if(y_oscillate){
        if((yspacing < 15) && (traverse_upy == true)){
            yspacing+=.001;
            //cout<<"yspacing is"<<yspacing<<endl;
        }
        if((yspacing > 12) && (traverse_downy == true)){
            yspacing-=.001;
        }
        else if (yspacing >= 15){
            //cout<<"it's 60"<<endl;
            traverse_upy = false;
            traverse_downy = true;
        }
        else if (yspacing <= 12) {
            traverse_downy = false;
            traverse_upy = true;
        }
    }
    
    
    if(x_oscillate){
        if((xspacing < 15) && (traverse_upx == true)){
            xspacing+=.001;
            //cout<<"yspacing is"<<xspacing<<endl;
        }
        if((xspacing > 12) && (traverse_downx == true)){
            xspacing-=.001;
        }
        else if (xspacing >= 15){
            //cout<<"it's 60"<<endl;
            traverse_upx = false;
            traverse_downx = true;
        }
        else if (xspacing <= 12) {
            traverse_downx = false;
            traverse_upx = true;
        }
    }
    //yspacing+=.1;
    
    
    //blu1 = 200; blu2 = 150; blu3 = 100; blu4 = 50;
    if(blue_fade){
        
        blu1-=1;
        blu2-=1;
        blu3-=1;
        blu4-=1;
        
        
        blue1 = ofColor(0,0,blu1);
        blue2 = ofColor(0,0,blu2);
        blue3 = ofColor(0,0,blu3);
        blue4 = ofColor(0,0,blu4);
        blue.clear();
        blue.push_back(blue1);
        blue.push_back(blue2);
        blue.push_back(blue3);
        blue.push_back(blue4);
    }
    
    
    if(green_fade){
        
        //will hit 50 low
        gree1 -= 9;
        gree2 -= 7;
        gree3 -= 4;
        gree4 -= 2;
        
        //gree1-=1;
        //gree2-=1;
        //gree3-=1;
        //gree4-=1;
        green1 = ofColor(0,gree1,0);
        green2 = ofColor(0,gree2,0);
        green3 = ofColor(0,gree3,0);
        green4 = ofColor(0,gree4,0);
        green.clear();
        green.push_back(green1);
        green.push_back(green2);
        green.push_back(green3);
        green.push_back(green4);
        
        if(gree4 == 50)
            green_fade = false;
        
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    //slow down the frames so you can pick the pattern you want, gg in sin and cos is what controls the overall shape
    //iterations++;
    //if(iterations % 60 == 0)
    //   gg++;
	
	ofEnableAlphaBlending();
    ofSetColor(255,255,255,100);
    //dimensions works just like opencv increases left to right, top to bottom
    //ofRect(100,ofGetHeight()-300,5*128,200);
	ofDisableAlphaBlending();
	
	// draw the fft resutls:
	ofSetColor(255,255,255,255);
	
	float width = (float)(5*128) / nBandsToGet;     //isnt that just 5...
    
    
    int bass = 0;
    int snare = 0;
    int counter = 0;
    int flash = 0;
	for (int i = 0;i < nBandsToGet; i++){
        if((fftSmoothed[i] * 200) > 30)
            counter++;
        if (((fftSmoothed[0] * 200) > 400))
            bass = 1;
        
        if (((fftSmoothed[0] * 200) > 400))
            flash= 1;
        
        //if (((fftSmoothed[1] * 200) > 200))
        //snare = 1;
        
        
		// (we use negative height here, because we want to flip them
		// because the top corner is 0,0)
        //if(i<40)
        //cout<<"height is"<<fftSmoothed[i] * 200<<endl;
		//ofRect(100+i*width,ofGetHeight()-100,width,-(fftSmoothed[i] * 200));
	}
    //cout<<"one iteration\n----------------------"<<endl<<endl<<endl<<endl;
	//cout<<"counter is"<<counter<<endl;
    
    if(counter>20) {
        //cout<<"YES ITS greater tha 100"<<endl;
        snare = 1;
    }
    
    if(bass){
        //need this for debugging
        /*ofFill();
         ofSetHexColor(0xe0be21);
         
         ofSetPolyMode(OF_POLY_WINDING_ODD);	// this is the normal mode
         ofBeginShape();
         ofVertex(200,135);
         ofVertex(15,135);
         ofVertex(165,25);
         ofVertex(105,200);
         ofVertex(50,25);
         ofEndShape();
         // finally draw the playing circle:
         
         ofEnableAlphaBlending();
         ofSetColor(255,255,255,20);
         ofCircle(px, py,50);
         ofDisableAlphaBlending();
         
         ofSetHexColor(0xffffff);
         ofCircle(px, py,8);*/
        shipspeed = 30;
        //flip = true;
    }
    
    
    
    
    if(flash){
        green_fade = true;
        gree1 = 140; gree2 = 120; gree3 =90; gree4 = 70;
        
    }
    if(snare){
        /*ofSetHexColor(0xb5de10);
         ofSetPolyMode(OF_POLY_WINDING_NONZERO);
         ofBeginShape();
         ofVertex(400,135);
         ofVertex(215,135);
         ofVertex(365,25);
         ofVertex(305,200);
         ofVertex(250,25);
         ofEndShape();*/
        flip = true;
        
    }
    
    
    ofColor maroon = ofColor(176,48,96);
    ofColor violet_red = ofColor(2208,32,144);
    ofColor violet = ofColor(238,130,238);
    ofColor plum = ofColor(221,160,221);
    ofColor medium_orchid = ofColor (186,85,211);
    ofColor dark_violet = ofColor(148,0,211);
    
    //drawSpaceship(x,y, 1);
    for(int i=0; i< randomships.size()/2; i++){
        
        pair<pair<float, float>, int> dest = randomships[i];
        float x = dest.first.first;
        float y = dest.first.second;
        
        float direction  = dest.second;
        
        //cout<<"x coord is "<<x;
        //cout<<" y coord is "<<y<<endl;
        //cout<<" direction is"<<direction<<endl;
        //x-=.1;
        //y-=.1;
        
        float inc;
        if((direction == 0) || (direction == 1)){
            if(direction == 0)
                inc = 2;
            else
                inc = -2;
            
            purple1 = ofColor(150,0,205);
            purple2 = ofColor(164,66,220);
            purple3 = ofColor(181,100,227);
            purple4 = ofColor(200,120,240);
            
            
            ofSetColor(0,200,0);
            //ofSetColor(purple1);
            ofCircle(x,y-1,.75);
            ofCircle(x,y+inc,1);
            ofCircle(x,y+2*inc,1);
            ofCircle(x,y+3*inc,3);
            ofSetColor(0,160,0);
            //ofSetColor(purple2);
            ofCircle(x,y+5*inc,4);
            ofSetColor(0,80,0);
            //ofSetColor(purple3);
            ofCircle(x-3,y+7*inc,2);
            ofCircle(x+3,y+7*inc,2);
            ofCircle(x,y+6*inc,2);
            if(direction == 1)
                y+=shipspeed;
            else
                y-=shipspeed;
        }
        if((direction == 2) || ( direction == 3)){
            if(direction == 2)
                inc = 2;
            else
                inc = -2;
            ofSetColor(0,160,0);
            //ofSetColor(purple1);
            ofCircle(x-1,y,.75);
            ofCircle(x+inc,y,1);
            ofCircle(x+2*inc,y,1);
            ofCircle(x+3*inc,y,3);
            ofSetColor(0,130,0);
            //ofSetColor(purple2);
            ofCircle(x+5*inc,y,4);
            ofSetColor(0,100,0);
            //ofSetColor(purple3);
            ofCircle(x+7*inc,y-3,2);
            ofCircle(x+7*inc,y+3,2);
            ofCircle(x+6*inc,y,2);
            if(direction == 2)
                x-=shipspeed;
            else
                x+=shipspeed;
            
        }
        if(x<0)
            direction = 3;
        if(x>ofGetWidth())
            direction = 2;
        if(y<0)
            direction = 1;
        if(y>ofGetHeight())
            direction = 0;
        randomships[i].first.first = x;
        randomships[i].first.second = y;
        if(flip){
            cout<<"we should flip direction here"<<endl;
            if (direction == 0)
                direction = 1;
            if (direction == 1)
                direction = 0;
            if (direction == 2)
                direction = 3;
            if (direction == 3)
                direction = 2;
        }
        flip = false;
        randomships[i].second = direction;
        
    }
    
//this is for something else
    /*for(int i=randomships.size()/2+1; i< randomships.size(); i++){
     
     pair<pair<float, float>, int> dest = randomships[i];
     float x = dest.first.first;
     float y = dest.first.second;
     
     ofSetColor(0,200,0);
     //ofSetColor(blue1);
     ofCircle(x,y,2);
     ofCircle(x+4,y,2);
     ofSetColor(0,160,0);
     //ofSetColor(blue2);
     ofCircle(x-7,y-4,2);
     ofCircle(x-4,y-4,3);
     ofCircle(x,y-4,3);
     ofCircle(x+4,y-4,3);
     ofCircle(x+8,y-4,3);
     ofCircle(x+12,y-4,1);
     ofSetColor(0,130,0);
     //ofSetColor(blue3);
     ofCircle(x-4,y-7,3);
     ofCircle(x,y-7,3);
     ofCircle(x+4,y-7,3);
     ofCircle(x+8,y-7,3);
     ofCircle(x+12,y-7,1);
     }*/
    
    
    //draw widgets
    for (int i =0;i <widgets.size(); i++){
        float x = widgets[i][0];
        float y = widgets[i][1];
        float r = widgets[i][2];
        float r2 = widgets[i][3];
        float r3 = widgets[i][4];
        float g = widgets[i][5];
        float p = widgets[i][6];
        
        ofSetColor(0,(int)g, 0);
        ofCircle(x,y,r);
        ofSetColor(0,(int)g-50,0);
        ofCircle(x+r, y,r2*2);
        ofSetColor(150,p,200);
        ofCircle(x, y+r,r3*2);
    }
    
    
    //draw some ships
    for(int i =0; i<ships.size(); i++){
        float x = xstrip[i][0];
        float y = xstrip[i][1];
        float r = xstrip[i][2];
        float r2 = xstrip[i][3];
        float r3 = xstrip[i][4];
        float g = xstrip[i][5];
        float p = xstrip[i][6];
        
        ofSetColor(0,g,0);
        ofCircle(x,y,r);
        ofCircle(x+2*r,y,r);
        ofSetColor(0,g-30,0);
        ofCircle(x-1.5*r,y-1.5*r,r);
        ofCircle(x,y-1.5*r,r);
        ofCircle(x+1.5*r,y-1.5*r, r);
    }
    
    
    
    //draw xstrip
    for (int i =0;i <xstrip.size(); i++){
        
        float x = xstrip[i][0];
        float y = xstrip[i][1];
        float r = xstrip[i][2];
        float r2 = xstrip[i][3];
        float r3 = xstrip[i][4];
        float g = xstrip[i][5];
        float p = xstrip[i][6];
        
        if(i< xstrip.size()/2){
            ofSetColor(0,(int)g, 0);
            ofCircle(x,y,r);
            ofSetColor(0,(int)g-50,0);
            ofCircle(x+r, y,r2);
            //ofSetColor(160,p,220);
            //ofCircle(x, y+r,r3);
        }
        else{
            ofSetColor(0,(int)g, 0);
            ofCircle(x,y,r);
            ofSetColor(0,(int)g-50,0);
            ofCircle(x+2*r,y,r2);
            ofSetColor(0,(int)g-100,0);
            ofCircle(x+4*r,y,r3);
            
        }
    }
    
    //draw ystrip
    for (int i =0;i <ystrip.size(); i++){
        
        float x = ystrip[i][0];
        float y = ystrip[i][1];
        float r = ystrip[i][2];
        float r2 = ystrip[i][3];
        float r3 = ystrip[i][4];
        float g = ystrip[i][5];
        float p = ystrip[i][6];
        
        if(i< ystrip.size()/2){
            ofSetColor(0,(int)g, 0);
            ofCircle(x,y,r);
            ofSetColor(0,(int)g-50,0);
            ofCircle(x+r, y,r2);
            //ofSetColor(160,p,220);
            //ofCircle(x, y+r,r3);
        }
        else if((i>ystrip.size()/2) && (i<ystrip.size() * .75)){
            ofSetColor(0,(int)g, 0);
            ofCircle(x,y,r);
            ofSetColor(100,(int)p-50,100);
            ofCircle(x-2*r,y+2*r,r);
            ofSetColor(100,(int)p-100,100);
            ofCircle(x+2*r,y+2*r,r);
            
        }
    }
    
    
    //draw xstrip2
    for (int i =0;i <xstrip2.size(); i++){
        
        float x = xstrip2[i][0];
        float y = xstrip2[i][1];
        float r = xstrip2[i][2];
        float r2 = xstrip2[i][3];
        float r3 = xstrip2[i][4];
        float g = xstrip2[i][5];
        float p = xstrip2[i][6];
        
        if(i< xstrip2.size()/2){
            ofSetColor(0,(int)g, 0);
            ofCircle(x,y,r);
            ofSetColor(0,(int)g-50,0);
            ofCircle(x+r, y,r2);
            //ofSetColor(160,p,220);
            //ofCircle(x, y+r,r3);
        }
        else{
            ofSetColor(0,(int)g, 0);
            ofCircle(x,y,r);
            ofSetColor(0,(int)g-50,0);
            ofCircle(x+2*r,y,r2);
            ofSetColor(0,(int)g-100,0);
            ofCircle(x+4*r,y,r3);
            
        }
    }
    
    //draw ystrip2
    for (int i =0;i <ystrip2.size(); i++){
        
        float x = ystrip2[i][0];
        float y = ystrip2[i][1];
        float r = ystrip2[i][2];
        float r2 = ystrip2[i][3];
        float r3 = ystrip2[i][4];
        float g = ystrip2[i][5];
        float p = ystrip2[i][6];
        
        if(i< ystrip2.size()/2){
            ofSetColor(0,(int)g, 0);
            ofCircle(x,y,r);
            ofSetColor(0,(int)g-50,0);
            ofCircle(x+r, y,r2);
            //ofSetColor(160,p,220);
            //ofCircle(x, y+r,r3);
        }
        else if((i>ystrip2.size()/2) && (i<ystrip2.size() * .75)){
            ofSetColor(0,(int)g, 0);
            ofCircle(x,y,r);
            ofSetColor(100,(int)p-50,100);
            ofCircle(x-2*r,y+2*r,r);
            ofSetColor(100,(int)p-100,100);
            ofCircle(x+2*r,y+2*r,r);
            
        }
    }
    
    
    //draw semicircle
    for (int i =0;i <semicircle.size(); i++){
        
        float x = semicircle[i][0];
        float y = semicircle[i][1];
        float r = semicircle[i][2];
        float r2 =semicircle[i][3];
        float r3 = semicircle[i][4];
        float g = semicircle[i][5];
        float p = semicircle[i][6];
        //cout<<"x is "<<x<<"and y is "<<y<<endl;
        if(p<100)
            ofSetColor(purple4);
        else
            ofSetColor(purple3);
        ofCircle(x,y,r);
    }
    
    
    
    
    //draw rings
    for (int i =0;i <rings.size(); i++){
        
        float x = rings[i][0];
        float y =rings[i][1];
        float r = rings[i][2];
        float r2 = rings[i][3];
        float c = rings[i][4];
        float g = rings[i][5];
        float p = rings[i][6];
        //cout<<"x is "<<x<<"and y is "<<y<<endl;
        if(c < .5)
            ofSetColor(0, g, 0);
        else
            ofSetColor(153,50,204);
        ofCircle(x,y,r);
        ofSetColor(0,0,0);
        ofCircle(x,y,r2);
        
    }
    
    
    //draw links
    for (int i =0;i <links.size(); i++){
        
        float x = links[i][0];
        float y = links[i][1];
        float r = links[i][2];
        float upordown = links[i][3];
        //cout<<"x is"<<x<<"and y is"<<y<<endl;
        ofSetColor(purple4);
        if(upordown<.5){
            ofCircle(x,y,r);
            ofCircle(x,y+3*r,.75*r);
            ofCircle(x,y+6*r,.6*r);
            ofCircle(x,y+9*r,.5*r);
        }
        else{
            ofCircle(x,y,r);
            ofCircle(x,y-3*r,.75*r);
            ofCircle(x,y-6*r,.6*r);
            ofCircle(x,y-9*r,.5*r);
        }
        
    }
    
    
    //draw some lattices
    for(int i = 0; i<lattice.size(); i++){
        float x = lattice[i][0];
        float y = lattice[i][1];
        float r = lattice[i][2];
        float dimx_left = lattice[i][3];
        float dimx_right = lattice[i][4];
        float dimy = lattice[i][5];
        ofCircle(x,y,r);
        /*ofCircle(x-20, y-4, r);
         ofCircle(x-12,y-4,r);
         ofCircle(x-4,y-4,r);
         ofCircle(x+4, y-4,r);
         ofCircle(x+12,y-4, r);
         ofCircle(x+20,y-4,r);*/
        int even = 1;
        for(int i = 1; i< dimy; i++){
            if(even%2 == 1){
                for(int j = 0; j<dimx_left; j++){
                    ofCircle(x-(4+j*8), y-i*4,r*pow(1.1,j));
                }
                for(int j = 0; j<dimx_right; j++){
                    ofCircle(x+(4+j*8), y-i*4,r*pow(1.1,j));
                }
            }
            else{
                ofCircle(x,y-i*4,r);
                for(int j = 1; j<dimx_left; j++){
                    ofCircle(x-j*8, y-i*4,r*pow(.8,j));
                    
                }
                for(int j = 1; j<dimx_right; j++){
                    ofCircle(x+j*8, y-i*4,r*pow(.8,j));
                }
            }
            even++;
        }
    }
    
    //this was the original idea but it's not what I had in mind, but I might use it for something else
    /*float xx = 0;
     float startx;
     float starty = 0;
     int numshades;
     int index = 0;
     string color;
     int numcircles = 1;
     float length;
     
     int row = 0;
     int column = 0;
     int iterations = 0;
     int i = 0;
     
     
     while(starty<ofGetHeight()){
     //cout<<"starty is"<<starty<<endl;
     startx = xx;
     if(iterations % 3 == 1){
     color = "purple";
     numshades = purple.size();
     }
     else if (iterations % 3 == 2){
     color = "green";
     numshades = green.size();
     }
     else if (iterations % 3 == 0) {
     color = "blue";
     numshades = blue.size();
     
     }
     length = 0;
     //int i =0;
     while(startx<ofGetWidth()) {
     
     index = index % numshades;
     //float radius = cos(starty * gg) + sin(startx * gg) + 2;
     
     float radius = (( sin(starty * startx ) + 1.0) * 1.5);//*(startx/(startx+starty));
     //float radius = ofRandom(0,4);
     //radius = 5- radius;
     //radius+=epsilon[i];
     //radius+=ofRandom(0,1);
     //if(row % 4==0)
     //radius/=2;
     
     //float displacex = ofRandom(0,2);
     //float displacey = ofRandom(0,2);
     //if(rand() % 5 != 0)
     //if(radius<4)
     //if(radius>2)
     //radius = ofRandom(0,3);
     //drawRow(startx+displacex, starty-displacey, radius, color, index);
     drawRow(startx, starty, radius, color, index);
     
     index++;
     numcircles++;
     //if(numcircles > 9) {
     //startx += xspacing;       //maybe change this as it changes the shape significantly
     //numcircles = 1;
     
     startx+=yspacing;
     length += 2*radius + .5;
     i++;
     //cout<<"i is "<<i<<endl;
     row++;
     }
     //starty += yspacing;     //you can also change this to demonstrate tempo, larger spacing like 80 with +.01 changes less drastically
     starty+=yspacing;
     iterations++;
     //xx += 8.5;
     column++;
     }*/
    
    
    
    ofSetColor(green1);
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);
    ofSetColor(purple3);
    //ofDrawBitmapString("Deep Blue Day", 30, 770);
    //ofDrawBitmapString("Brian Eno", 30, 785);
    ofDrawBitmapString("Deep Blue Day", 430, 230);
    ofDrawBitmapString("Brian Eno", 430, 245);
}



void testApp::drawRow(int x, int y, int radius, string color, int colorindex){
    
    string colorscheme = color;
    
    if(color == "purple")
        ofSetColor(green[colorindex]);
    else if (color == "green")
        ofSetColor(purple[colorindex]);
    else if (color == "blue")
        ofSetColor(green[colorindex]);
    ofCircle(x, y, radius);
    
}



//--------------------------------------------------------------
void testApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	// add into vx and vy a small amount of the change in mouse:
	vx += (x - prevx) / 20.0f;
	vy += (y - prevy) / 20.0f;
	// store the previous mouse position:
	prevx = x;
	prevy = y;
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	prevx = x;
	prevy = y;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}


