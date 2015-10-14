// The sample model.  You should build a file
// very similar to this for when you make your model.
#include "modelerview.h"
#include "modelerapp.h"
#include "modelerdraw.h"
#include <FL/gl.h>

#include "modelerglobals.h"

// To make a SampleModel, we inherit off of ModelerView
class SampleModel : public ModelerView 
{
public:
    SampleModel(int x, int y, int w, int h, char *label) 
        : ModelerView(x,y,w,h,label) { }

    virtual void draw();
};

// We need to make a creator function, mostly because of
// nasty API stuff that we'd rather stay away from.
ModelerView* createSampleModel(int x, int y, int w, int h, char *label)
{ 
    return new SampleModel(x,y,w,h,label); 
}

// We are going to override (is that the right word?) the draw()
// method of ModelerView to draw out SampleModel
void SampleModel::draw()
{
    // This call takes care of a lot of the nasty projection 
    // matrix stuff.  Unless you want to fudge directly with the 
	// projection matrix, don't bother with this ...
    ModelerView::draw();
	// trying VS github
	// draw the floor
	
	/*
	setAmbientColor(.1f,.1f,.1f);	
	setDiffuseColor(COLOR_RED);
	glPushMatrix();
	glTranslated(-5,0,-5);
	drawBox(10,0.01f,10);
	glPopMatrix();
	*/

	// draw the sample model
	setAmbientColor(.1f,.1f,.1f);
	//setDiffuseColor(COLOR_GREEN);
	
	
	setDiffuseColor(COLOR_BLUE);
	glPushMatrix();
	glTranslated(VAL(XPOS), VAL(YPOS), VAL(ZPOS));
		// center of the body
		glPushMatrix();
		glScaled(2, 1, 1);
		drawSphere(1);
		glScaled(0.5, 1, 1);

			// Upper Body		
			glPushMatrix();
			glRotated(VAL(UPPER_BODY_X), 1.0, 0.0, 0.0);
			glRotated(VAL(UPPER_BODY_Y), 0.0, 1.0, 0.0);
			glRotated(VAL(UPPER_BODY_Z), 0.0, 0.0, 1.0);
			glRotated(-90, 1.0, 0.0, 0.0);
			glScaled(2, 1.4, 1);
			drawCylinder(4,1,1.2);
			glScaled(0.5, 1 / 1.4, 1);
				// Left upper arm pivot
				glPushMatrix();
				glTranslated(2.2, 0, 3.2);
				drawSphere(0.8);
					// Left upper arm
					glRotated(90, 1.0, 0.0, 0.0);
					glRotated(VAL(LEFT_UPPER_ARM_X), 1.0, 0.0, 0.0);
					glRotated(VAL(LEFT_UPPER_ARM_Y), 0.0, 1.0, 0.0);
					glRotated(VAL(LEFT_UPPER_ARM_Z), 0.0, 0.0, 1.0);				
					glRotated(90, 1.0, 0.0, 0.0);
					drawCylinder(4.5,0.8,0.6);
						// Left lower arm pivot
						glTranslated(0, 0, 4.5);
						drawSphere(0.6);
							// Left lower arm
							glRotated(-90, 1.0, 0.0, 0.0);
							glRotated(VAL(LEFT_LOWER_ARM_X), 1.0, 0.0, 0.0);
							glRotated(90, 1.0, 0.0, 0.0);
							drawCylinder(3.5,0.6,0.4);
								// Left hand pivot
								glTranslated(0, 0, 3.5);
								drawSphere(0.4);
									// Left hand
									glRotated(VAL(LEFT_HAND_X), 1.0, 0.0, 0.0);
									glRotated(VAL(LEFT_HAND_Z), 0.0, 1.0, 0.0);
									glTranslated(-0.2, -0.5, 0);
									drawBox(0.4, 1, 1.2);
										// Left thumb
										glTranslated(0, 1, 0);
										glTranslated(0.2, 0, 0);
										glRotated(VAL(LEFT_THUMB), 1.0, 0.0, 0.0);
										glTranslated(-0.2, 0, 0);
										drawBox(0.4,0.4,0.6);
				glPopMatrix();

				// Right upper arm pivot
				glPushMatrix();
				glTranslated(-2.2, 0, 3.2);
				drawSphere(0.8);
					// Right upper arm
					glRotated(90, 1.0, 0.0, 0.0);
					glRotated(VAL(RIGHT_UPPER_ARM_X), 1.0, 0.0, 0.0);
					glRotated(VAL(RIGHT_UPPER_ARM_Y), 0.0, 1.0, 0.0);
					glRotated(VAL(RIGHT_UPPER_ARM_Z), 0.0, 0.0, 1.0);
					glRotated(90, 1.0, 0.0, 0.0);
					drawCylinder(4.5, 0.8, 0.6);
						// Right lower arm pivot
						glTranslated(0, 0, 4.5);
						drawSphere(0.6);
							// Right lower arm
							glRotated(-90, 1.0, 0.0, 0.0);
							glRotated(VAL(RIGHT_LOWER_ARM_X), 1.0, 0.0, 0.0);
							glRotated(90, 1.0, 0.0, 0.0);
							drawCylinder(3.5, 0.6, 0.4);
								// Right hand pivot
								glTranslated(0, 0, 3.5);
								drawSphere(0.4);
									// Right hand
									glRotated(VAL(RIGHT_HAND_X), 1.0, 0.0, 0.0);
									glRotated(VAL(RIGHT_HAND_Z), 0.0, 1.0, 0.0);
									glTranslated(-0.2, -0.5, 0);
									drawBox(0.4, 1, 1.2);
										// Right thumb
										glTranslated(0, 1, 0);
										glTranslated(0.2, 0, 0);
										glRotated(VAL(RIGHT_THUMB), 1.0, 0.0, 0.0);
										glTranslated(-0.2, 0, 0);
										drawBox(0.4, 0.4, 0.6);
				glPopMatrix();

				// Neck pivot
				glPushMatrix();				
					glTranslated(0,0,4);
					drawSphere(0.7);
						// Neck
						glRotated(90, 1, 0, 0);
						glRotated(VAL(HEAD_Z), 0, 0, 1);
						glRotated(VAL(HEAD_Y), 0, 1, 0);
						glRotated(VAL(HEAD_X), 1, 0, 0);						
						glRotated(-90, 1, 0, 0);
						drawCylinder(1,0.7,0.7);
							// head
							glTranslated(0,0,1.5);
							glScaled(1,1,1.5);
							drawHead();
							setDiffuseColor(COLOR_BLUE);
				glPopMatrix();
			glPopMatrix();

			// Lower Body
			glPushMatrix();
			glRotated(VAL(LOWER_BODY_X), 1.0, 0.0, 0.0);
			glRotated(VAL(LOWER_BODY_Y), 0.0, 1.0, 0.0);
			glRotated(VAL(LOWER_BODY_Z), 0.0, 0.0, 1.0);
			glRotated(90, 1.0, 0.0, 0.0);
			glScaled(2, 1.4, 1);
			drawCylinder(3, 1, 1.2);
			glScaled(0.5, 1/1.4, 1);
				// Left upper leg pivot
				glPushMatrix(); 
				glTranslated(1, 0, 3);
				drawSphere(1.0);
					// Left upper leg
					glRotated(-90, 1.0, 0.0, 0.0);
					glRotated(VAL(LEFT_UPPER_LEG_X), 1.0, 0.0, 0.0);
					glRotated(VAL(LEFT_UPPER_LEG_Y), 0.0, 1.0, 0.0);
					glRotated(VAL(LEFT_UPPER_LEG_Z), 0.0, 0.0, 1.0);
					glRotated(90, 1.0, 0.0, 0.0);
					drawCylinder(4,1,0.8);
						// Left lower leg pivot
						glTranslated(0, 0, 4);
						drawSphere(0.8);
							// Left lower leg						
							glRotated(VAL(LEFT_LOWER_LEG_X), 1.0, 0.0, 0.0);
							drawCylinder(4,0.8,0.6);
								// Left foot pivot
								glTranslated(0, 0, 4);
								drawSphere(0.6);
									// Left foot
									setDiffuseColor(COLOR_RED);
									glRotated(VAL(LEFT_FOOT_X), 1.0, 0.0, 0.0);
									glTranslated(-0.6,-0.7,0);
									drawBox(1.2,2.6,0.6);
									setDiffuseColor(COLOR_BLUE);
				glPopMatrix();

				// Right upper leg pivot
				glPushMatrix();
				glTranslated(-1, 0, 3);
				drawSphere(1.0);
					// Right upper leg
					glRotated(-90, 1.0, 0.0, 0.0);
					glRotated(VAL(RIGHT_UPPER_LEG_X), 1.0, 0.0, 0.0);
					glRotated(VAL(RIGHT_UPPER_LEG_Y), 0.0, 1.0, 0.0);
					glRotated(VAL(RIGHT_UPPER_LEG_Z), 0.0, 0.0, 1.0);					
					glRotated(90, 1.0, 0.0, 0.0);
					drawCylinder(4, 1, 0.8);
						// Right lower leg pivot
						glTranslated(0, 0, 4);
						drawSphere(0.8);
							// Right lower leg						
							glRotated(VAL(RIGHT_LOWER_LEG_X), 1.0, 0.0, 0.0);
							drawCylinder(4, 0.8, 0.6);
								// Right foot pivot
								glTranslated(0,0,4);
								drawSphere(0.6);
									//Right foot
									setDiffuseColor(COLOR_RED);
									glRotated(VAL(RIGHT_FOOT_X), 1.0, 0.0, 0.0);
									glTranslated(-0.6, -0.7, 0);
									drawBox(1.2, 2.6, 0.6);
				glPopMatrix();

			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
	
	/*
	glPushMatrix();
	glTranslated(VAL(XPOS), VAL(YPOS), VAL(ZPOS));

		glPushMatrix();
		glTranslated(-1.5, 0, -2);
		glScaled(3, 1, 4);
		drawBox(1,1,1);
		glTranslated(0.5,0.3,-0.1);
		drawBox(0.2,0.4,0.1);
			glPushMatrix();
			glTranslated(0.1, 0.2, 0.05);
			drawBox(0.02,VAL(WIRE),0.02);
			glPopMatrix();
		glPopMatrix();

		// draw cannon
		glPushMatrix();
		glRotated(VAL(ROTATE), 0.0, 1.0, 0.0);
		glRotated(-90, 1.0, 0.0, 0.0);
		drawCylinder(VAL(HEIGHT), 0.1, 0.1);

		glTranslated(0.0, 0.0, VAL(HEIGHT));
		drawCylinder(1, 1.0, 0.9);

		glTranslated(0.0, 0.0, 0.5);
		glRotated(90, 1.0, 0.0, 0.0);
		drawCylinder(4, 0.1, 0.2);
		glPopMatrix();

	glPopMatrix();
	*/
}

int main()
{
	// Initialize the controls
	// Constructor is ModelerControl(name, minimumvalue, maximumvalue, 
	// stepsize, defaultvalue)
    ModelerControl controls[NUMCONTROLS];
    controls[XPOS] = ModelerControl("X Position", -5, 5, 0.1f, 0);
    controls[YPOS] = ModelerControl("Y Position", 0, 5, 0.1f, 0);
    controls[ZPOS] = ModelerControl("Z Position", -5, 5, 0.1f, 0);
    controls[HEIGHT] = ModelerControl("Height", 1, 2.5, 0.1f, 1);
	controls[ROTATE] = ModelerControl("Rotate", -135, 135, 1, 0);
	controls[WIRE] = ModelerControl("Wire Lenght", 0, 5, 0.1f, 1);
	controls[UPPER_BODY_X] = ModelerControl("Upper Body X", -90, 90, 1, 0);
	controls[UPPER_BODY_Y] = ModelerControl("Upper Body Y", -90, 90, 1, 0);
	controls[UPPER_BODY_Z] = ModelerControl("Upper Body Z", -45, 45, 1, 0);
	controls[LOWER_BODY_X] = ModelerControl("Lower Body X", -90, 90, 1, 0);
	controls[LOWER_BODY_Y] = ModelerControl("Lower Body Y", -90, 90, 1, 0);
	controls[LOWER_BODY_Z] = ModelerControl("Lower Body Z", -45, 45, 1, 0);
	controls[LEFT_UPPER_ARM_X] = ModelerControl("Left Upper Arm X", -180, 45, 1, -15); // -15
	controls[LEFT_UPPER_ARM_Y] = ModelerControl("Left Upper Arm Y", -180, 90, 1, 0);
	controls[LEFT_UPPER_ARM_Z] = ModelerControl("Left Upper Arm Z", 0, 180, 1, 15);  //15
	controls[RIGHT_UPPER_ARM_X] = ModelerControl("Right Upper Arm X", -180, 45, 1, -15); //-15
	controls[RIGHT_UPPER_ARM_Y] = ModelerControl("Right Upper Arm Y", -90, 180, 1, 0);
	controls[RIGHT_UPPER_ARM_Z] = ModelerControl("Right Upper Arm Z", -180, 0, 1, -15);//15
	controls[LEFT_LOWER_ARM_X] = ModelerControl("Left Lower Arm X", -140, 0, 1, 0);
	controls[RIGHT_LOWER_ARM_X] = ModelerControl("Right Lower Arm X", -140, 0, 1, 0); 
	controls[LEFT_HAND_X] = ModelerControl("Left Hand X", -30, 30, 1, 0); 
	controls[LEFT_HAND_Z] = ModelerControl("Left Hand Z", -60, 60, 1, 0);
	controls[RIGHT_HAND_X] = ModelerControl("Right Hand X", -30, 30, 1, 0);
	controls[RIGHT_HAND_Z] = ModelerControl("Right Hand Z", -60, 60, 1, 0);
	controls[LEFT_UPPER_LEG_X] = ModelerControl("Left Upper Leg X", -90, 45, 1, 0);
	controls[LEFT_UPPER_LEG_Y] = ModelerControl("Left Upper Leg Y", -45, 90, 1, 0);
	controls[LEFT_UPPER_LEG_Z] = ModelerControl("Left Upper Leg Z", 0, 45, 1, 0);
	controls[RIGHT_UPPER_LEG_X] = ModelerControl("Right Upper Leg X", -90, 45, 1, 0);
	controls[RIGHT_UPPER_LEG_Y] = ModelerControl("Right Upper Leg Y", -90, 45, 1, 0);
	controls[RIGHT_UPPER_LEG_Z] = ModelerControl("Right Upper Leg Z", -45, 0, 1, 0);
	controls[LEFT_LOWER_LEG_X] = ModelerControl("Left Lower Leg X", 0, 160, 1, 0);
	controls[RIGHT_LOWER_LEG_X] = ModelerControl("Right Lower Leg X", 0, 160, 1, 0);
	controls[HEAD_X] = ModelerControl("Head X", -60, 60, 1, 0);
	controls[HEAD_Y] = ModelerControl("Head Y", -90, 90, 1, 0);
	controls[HEAD_Z] = ModelerControl("Head Z", -45, 45, 1, 0);
	controls[LEFT_FOOT_X] = ModelerControl("Left Foot X", -40, 40, 1, 0);
	controls[RIGHT_FOOT_X] = ModelerControl("Right Foot X", -40, 40, 1, 0);
	controls[LEFT_HAND_X] = ModelerControl("Left Hand X", -35, 35, 1, 0);
	controls[LEFT_HAND_Z] = ModelerControl("Left Hand Z", -60, 60, 1, 0);
	controls[RIGHT_HAND_X] = ModelerControl("Right Hand X", -35, 35, 1, 0);
	controls[RIGHT_HAND_Z] = ModelerControl("Right Hand Z", -60, 60, 1, 0);
	controls[LEFT_THUMB] = ModelerControl("Left Thumb", -90, 0, 1, 0);
	controls[RIGHT_THUMB] = ModelerControl("Right Thumb", -90, 0, 1, 0);


    ModelerApplication::Instance()->Init(&createSampleModel, controls, NUMCONTROLS);
    return ModelerApplication::Instance()->Run();
}
