/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       robot-config.cpp                                          */
/*    Author:       auto genorated                                            */
/*    Created:      Sun Feb. 18 2024                                          */
/*    Description:  creates global instances of all vex devices               */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// manual vision sensor signature declerations
//signature MOGO = signature(1, 47, 997, 522, -4047, -3477, -3762, 2.5, 0);


// A global instance of brain used for printing to the V5 brain screen
brain Brain;
controller Controller;


// DriveTrain Set up
// 15" 
double robotLength = 12.1; // in inches
double gearRatio = 36.0/60.0;
double wheelDiameter = 3.25; // in inches

motor FLeft = motor(PORT6, ratio18_1, true);
motor MLeft = motor(PORT8, ratio18_1, false);
motor BLeft = motor(PORT9, ratio18_1, true);

motor FRight = motor(PORT7, ratio18_1, false);
motor MRight = motor(PORT3, ratio18_1, true);
motor BRight = motor(PORT4, ratio18_1, false);

inertial gyro1 = inertial(PORT11);
inertial gyro2 = inertial(PORT12);
rotation nspod = rotation(PORT13);
rotation ewpod = rotation(PORT14);

sensorUnit driveSensors(&gyro1, &gyro2, &nspod, &ewpod);
driveTrain drive(
  &FLeft, &FRight, 
  &MLeft, &MRight,
  &BLeft, &BRight, 
  &driveSensors, 
  robotLength, gearRatio, wheelDiameter
);



// Robot Object construction
Robot robot(&drive);

void vexcodeInit(void) {
}