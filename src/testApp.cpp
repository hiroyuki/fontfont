#include "testApp.h"
ofFbo fbo;
int cnt;
int maxDraw;
int randomVal;
//--------------------------------------------------------------
void testApp::setup(){
    font.loadFont("Arial.ttf", 300, true, true, true);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    fbo.allocate(ofGetWidth(), ofGetHeight());
    fbo.begin();ofClear(0, 0, 0);fbo.end();
    cnt = 0;
    maxDraw = 5;
    randomVal = 0;
}

//--------------------------------------------------------------
void testApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate(),2));
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    

    if ( cnt < maxDraw )
    {
        cnt++;
        ofEnableAlphaBlending();
        ofEnableBlendMode(OF_BLENDMODE_ADD);
        fbo.begin();
        ofSetColor(ofColor::white, 100);
        vector<ofTTFCharacter> paths = font.getStringAsPoints("openframeworks");
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2 - 800, ofGetHeight()/2 + font.getLineHeight() / 2);
        for( int k = 0; k < paths.size(); k++)
        {
            vector<ofPolyline> lines = paths[k].getOutline();
            for( int i = 0; i < lines.size(); i++ )
            {
                ofPolyline ll = lines[i].getResampledBySpacing(1);
                vector<ofPoint> pts = ll.getVertices();
                for( int j = 0; j < pts.size(); j++)
                {
                    int x1 = pts[j].x + ofNoise(pts[j].x) * randomVal - randomVal*0.5;
                    int y1 = pts[j].y + ofNoise(pts[j].y) * randomVal - randomVal*0.5;
                    int x2, y2;
                    ofPolyline l2;
                    vector<ofPoint> pts2;
                    while (pts2.size() == 0) {
                        l2 = lines[ ofRandom(lines.size()) ].getResampledBySpacing(1);
                        pts2 = l2.getVertices();
                    }
                    int randomPoint = ofRandom(pts2.size());
                    {
                        x2 = pts2[randomPoint].x + ofNoise(pts2[randomPoint].x) * randomVal - randomVal*0.5;
                        y2 = pts2[randomPoint].y + ofNoise(pts2[randomPoint].y) * randomVal - randomVal*0.5;
                    }
                    
                    ofMesh mesh;
                    mesh.setMode(OF_PRIMITIVE_LINES);
                    mesh.addColor(ofColor(255,255,255, 80));
                    mesh.addColor(ofColor(255,255,255, 30));
                    mesh.addColor(ofColor(255,255,255, 80));
                    mesh.addVertex(ofVec3f(x1, y1, 0));
                    mesh.addVertex(ofVec3f((x1+x2)/2, (y1+y2)/2, 0));
                    mesh.addVertex(ofVec3f(x2, y2, 0));
                    mesh.drawFaces();
//                    ofLine(x1, y1, x2, y2);
                    
                }
            }
        }
        ofPopMatrix();
        fbo.end();
    }
    ofSetColor(ofColor::white);
    fbo.draw(0, 0);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

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