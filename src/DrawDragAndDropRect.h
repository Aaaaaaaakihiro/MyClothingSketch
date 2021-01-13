#pragma once
#include "ofMain.h"

class DrawDragAndDropRect
{
	public:
		void setUp(float _x, float _y, float _width, float _height);
		void draw();
		void keyReleased();
		void dragEvent(ofDragInfo dragInfo);

		ofImage img;
		float xPos, yPos, width, height;

		//’ZŒa“à‚ÉŽw’è‚ÌÀ•W‚ªŠÜ‚Ü‚ê‚Ä‚¢‚ê‚Îtrue,‚»‚¤‚Å‚È‚¯‚ê‚Îfalse
		/*bool inside(float px, float py) {
			if (px > x && py > y && px < x + width && py < y + height) {
				return true;
			}
			return false;
		}*/
};

