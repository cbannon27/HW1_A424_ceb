// HW1_A424_ceb.cpp : Defines the entry point for the application.
//

#include "HW1_A424_ceb.h"
#include<iostream>
#include<cmath>

using namespace std;


int main()
{
	double deltat = .01;
	// defining aircraft coefficent and effectivness
	double Lp = .5;
	double Ld = -.5;
	// initial condition
	double p = 1.0;
	double t = 0.00;
	double delta = 1.00;

	//propogation loop
	while (t<=5) 
	{
		if (t >= 0 && t <= 2)
			delta = 1;
		else {
			delta = 0;
		}
		// role rate pdot update
		double pdot = Lp * p + Ld * delta;
		//updating roll rate p
		 p = p + pdot * deltat;
		//print
		cout << "t: " << t << "s  Roll rate, p: " << p << " rad/s" << endl;
		//update timestamp
		t += deltat;
	}
	
}
