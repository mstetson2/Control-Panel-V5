// PanelView.h

#ifndef _PANELVIEW_h
#define _PANELVIEW_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class PanelView
{
 protected:


 public:
	void init();
};

extern PanelView pv;

#endif

