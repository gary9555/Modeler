#ifndef _MODELER_GLOBALS_H
#define _MODELER_GLOBALS_H

#ifndef M_PI
#define M_PI 3.141592653589793238462643383279502
#endif

// This is a list of the controls for the SampleModel
// We'll use these constants to access the values 
// of the controls from the user interface.
enum SampleModelControls
{ 
	XPOS,
	YPOS,
	ZPOS,
	HEIGHT,
	ROTATE,
	WIRE,
	UPPER_BODY_X,
	UPPER_BODY_Y,
	UPPER_BODY_Z,
	LOWER_BODY_X,
	LOWER_BODY_Y,
	LOWER_BODY_Z,
	LEFT_UPPER_ARM_X,
	LEFT_UPPER_ARM_Y,
	LEFT_UPPER_ARM_Z,
	RIGHT_UPPER_ARM_X,
	RIGHT_UPPER_ARM_Y,
	RIGHT_UPPER_ARM_Z,
	LEFT_LOWER_ARM_X,
	RIGHT_LOWER_ARM_X,
	LEFT_HAND_X,
	LEFT_HAND_Z,
	RIGHT_HAND_X,
	RIGHT_HAND_Z,
	LEFT_UPPER_LEG_X,
	LEFT_UPPER_LEG_Y,
	LEFT_UPPER_LEG_Z,
	RIGHT_UPPER_LEG_X,
	RIGHT_UPPER_LEG_Y,
	RIGHT_UPPER_LEG_Z,
	LEFT_LOWER_LEG_X,
	RIGHT_LOWER_LEG_X,
	HEAD_X,
	HEAD_Y,
	HEAD_Z,
	NUMCONTROLS
};

// Colors
#define COLOR_RED		1.0f, 0.0f, 0.0f
#define COLOR_GREEN		0.0f, 1.0f, 0.0f
#define COLOR_BLUE		0.0f, 0.0f, 1.0f

// We'll be getting the instance of the application a lot; 
// might as well have it as a macro.
#define VAL(x) (ModelerApplication::Instance()->GetControlValue(x))

#endif