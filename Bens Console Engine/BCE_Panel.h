#pragma once
#include <Windows.h>
#include "BCE_Space.h"

// Rectangular region displayed on the console window with its own buffer, 
class BCE_Panel {
	CHAR_INFO* buffer;		// Buffer of panel written to console buffer
	SMALL_RECT writeRegion;	// Rectangular region of the console that panel is drawn to
	COORD size;				// Size of panel itself in rows/cols
	BCE_Space* space;		// Space displayed by this panel
	COORD posInSpace;		// Position of the top left corner of the area displayed by panel in the space

	public:
		BCE_Panel(BCE_Space* space, SMALL_RECT writeRegion);	// Constructor

		void freeMemory();									// Free memory allocated within this object

		void clearBuffer();									// Fill panel buffer with spaces
		void updateBuffer();								// Fill panel buffer with visible GameObjects from space
		COORD spaceCoordToBufferCoord(COORD spaceCoord);	// Convert a coordinate in space to its coordiantes in this panel's buffer
		int spaceCoordToBufferIndex(COORD spaceCoord);		// Convert a coordinate in space to its index in this panel's buffer

		CHAR_INFO* getBuffer();								// Get panel buffer
		SMALL_RECT getWriteRegion();						// Get region that panel is drawn to in buffer
		COORD getSize();									// Get size of write region/panel 

		void setSpace(BCE_Space* space);					// Set space to be displayed within this panel
		void setPosInSpace(COORD posInSpace);				// Set panel's position in space
		void setWriteRegion(SMALL_RECT writeRegion);		// Set region panel is written to in the buffer and recalcualte panel size
};