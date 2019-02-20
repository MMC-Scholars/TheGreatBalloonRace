#pragma once

#include "predefs.h"
#include "VRBase/System/predefs.h"

class Propeller {
	/*
	* Private member variables
	*/
private:

	uint8		m_iNumBlades; //number of blades on the propeller
	vec			m_flBladeRadius; //the radius of the blade on the propeller
	double		m_dBladePitch; //the pitch of the blade
	newtons		m_nPropStrength; //the strength of the propulsion/thrust of the propeller
	double 		m_dArea; //surface area of the propeller disk, looking at it from the front(circle)
	double		m_dRotationalVelo; //revolutions per second of the propeller
	double 		m_dMass; //mass of the propeller

	//TODO - add member variables needed for physics-based model of propeller
	/*
	* Public members
	*/
public:
	joules		m_jCurrentEnergy = 0; //the current energy being given to the propellers
	newtons		m_nInertia = 0; //the moment of inertia of the propeller
	/*
	* Adds energy to be converted into rotational energy of the propeller.
	*/
	void addEnergy(joules jEnergy);

	/**
	* Based on current rotational velocity, blade radius, and number of blades,
	* Returns a force in newtons to be applied to a ForceAccumulator
	*
	*/
	newtons getPropulsionStrength();

	/**
	* Models the decay of energy over time
	*/
	void think();

};
