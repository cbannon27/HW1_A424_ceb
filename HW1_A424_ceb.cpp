﻿// HW1_A424_ceb.cpp : Defines the entry point for the application.
//

#include "HW1_A424_ceb.h"
#include<iostream>
#include<cmath>
#include<vector>

using namespace std;
void problem1();
void problem2();
void problem3();
//double dot_product(vector<double>& w, vector<double>& x);
vector<double> gradient_weights(const vector<double>& w, vector<double>& x, double& y);
void problem4();
void problem5();
void problem6();
//double dot_product(vector<double>& w, vector<double>& x);
void problem7();
vector<double> problem8();
void problem9();


int main()
{
	vector<double> w = { .0001,.0001,.0001 };
	vector<double> x = { 124,31.89,20.945 };

	cout << " "<<endl;
	cout << " Problem 2: " << endl;
	cout << " " << endl;
	problem2();

	cout << " " << endl;
	cout << " Problem 3: " << endl;
	cout << " " << endl;
	problem3();

	cout << " " << endl;
	cout << " Problem 4: " << endl;
	cout << " " << endl;
	problem4();

	cout << " " << endl;
	cout << " Problem 5: " << endl;
	cout << " " << endl;
	problem5();
	
	cout << " " << endl;
	cout << " Problem 6: " << endl;
	cout << " " << endl;
	problem6();
	
	cout << " " << endl;
	cout << " Problem 7: " << endl;
	cout << " " << endl;
	problem7();
	
	cout << " " << endl;
	cout << " Problem 8: " << endl;
	cout << " " << endl;
	problem8();

	cout << " " << endl;
	cout << " Problem 9: " << endl;
	cout << " " << endl;
	problem9();
	
	return 0;
}

void problem1() {
	
	cout << " " << endl;
	cout << " Problem 1: " << endl;
	cout << " " << endl;
	double deltat = .01;
	// defining aircraft coefficent and effectivness
	double Lp = .5;
	double Ld = -.5;
	// initial condition
	double p = 1.0;
	double t = 0.00;
	double delta = 1.00;

	//propogation loop
	while (t <= 5)
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
void problem2() {
	//autopilot stuff
	double K = -2;
	double deltat = .01;
	// defining aircraft coefficent and effectivness
	double Lp = .5;
	double Ld = -.5;
	// initial condition
	double p = 1.0;
	double t = 0.00;
	double delta = -K * p;

	//propogation loop
	while (t <= 5)
	{
		//autopilot
		delta = -K * p;
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

void problem3() {
	//autopilot stuff
	//initializing k
	double K = -2.5;
	double alf = .01;
		//time step
	double deltat = .01;
	// defining aircraft coefficent and effectivness
	double Lp = .5;
	double Ld = -.5;
	// initial condition
	double p = 1.0;
	double t = 0.00;
	double delta = -K * p;

	//propogation loop
	while (t <= 5)
	{
		//autopilot
		delta = -K * p;
		K = K + alf * pow(p, 2);
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

double dot_product(const vector<double>& w,const vector<double>& x) {
	double z = 0.0;
	for (size_t i = 0; i < w.size(); i++) {
		z += w[i] * x[i];
	}
	
	return z;
}
void problem4() {
	//defining vectors
	const vector<double> w = { .0001,.0001,.0001 };
	const vector<double> x = { 124,31.89,20.945 };
	//initializing result
	double z =dot_product(w, x);
	cout << "dot product, z = " << z << endl;
	//dot product function uses size_t to adjust to whatever size the given vectors are
	
	
	
}
double sigmoid(double& z) {
	double sig = 0.0;
	sig = 1 / (1 + exp(-z));
	
	return sig;
}
double gradient_sigmoid(double& sig) {
	double ddtsig = 0.0;
	ddtsig = sig * (1 - sig);

	
	return ddtsig;

}
void problem5() {
	//defining z and initializing results
	double z = .0176835;
	
	
	//sigmoid function
	double sig = sigmoid(z);
	cout << "sigmoid = " << sig << endl;
	//gradient_sigmoid function
	double ddtsig=gradient_sigmoid(sig);
	cout << "gradient_sigmoid = " << ddtsig << endl;
}

void problem6() {
	// defining y's and initializing dC
	double y = 1;
	double ypredict = .504421;
	double dC = 0.0;
	//Gradient cost function
	//double gradient_cost(double& y, double& ypredict); {
		dC = 2 * (ypredict - y);
	//}
	cout << "gradient_cost = " << dC << endl;

}
vector<double> gradient_weights(const vector<double>& w,  vector<double>& x, double& y) {
	vector<double> dw(w.size(), 0.0);
	double z = dot_product(w, x);
	double sig = sigmoid(z);
	double grad = gradient_sigmoid(sig);
	for (size_t i = 0; i < w.size(); i++) {
		dw[i] = 2 * (sig - y) * sig * (1 - sig) * x[i];
	}
	
	return dw;
}
vector<double> update_weights(vector<double>& w,  vector<double>& dw, double& alf) {
	for (size_t i = 0; i < w.size(); i++) {
		w[i] = w[i]-alf * dw[i];
	}
	
	return w;
}
void problem7() {
	//calling functions
	 vector<double> w = { .0001,.0001,.0001 };
	 vector<double> x = { 124,31.89,20.945 };
	
	double y = 1;
	double alf = .001;
	vector<double> dw = gradient_weights(w, x, y);
	
	cout << "dw = ";
	for (size_t i = 0; i < dw.size(); i++) {
		cout << dw[i] << " ";
	}
	cout << endl;

	update_weights(w, dw, alf);

	cout << "w = ";
	for (size_t i = 0; i < dw.size(); i++) {
		cout << w[i] << " ";
	}
	cout << endl;

	}

vector<double> trainer(vector<vector<double>>& aircraftData, vector<double>& w, double& alf) {
	vector<double> w_train(w.size(), 0.0);
	int max = 100;
	int iteration = 0;
	
	while (iteration < max) {
		
		for (size_t i = 0; i < aircraftData.size(); i++) {
			vector<double> x = { aircraftData[i][0], aircraftData[i][1] , aircraftData[i][2] };
			double y = aircraftData[i][3];

			double z = dot_product(w, x);
			double sig = sigmoid(z);
			vector<double> dw = gradient_weights(w, x, y);
			w_train = update_weights(w, dw, alf);

		}
		iteration++;
	}
	return w_train;
}

vector<double> problem8() {
	vector<double> w = { .0001,.0001,.0001 };
	double alf = .001;

	vector<vector<double>> aircraftData = {
		{124, 31.89, 20.945, 1}, // M-346 Master
		{74, 51.08, 9.170, 0},   // AT-402B
		{103, 34.67, 8.300, 1},  // MB-326
		{77, 52.00, 9.400, 0},   // AT-502B
		{104, 35.63, 13.000, 1}, // MB-339
		{92, 56.00, 12.500, 0},  // AT-602
		{130, 31.29, 17.637, 1}, // Aero L-159 Alca
		{73, 52.00, 9.600, 0}    // AT-504
	};
	vector<double> w_train = trainer(aircraftData, w, alf);
	cout << "w = ";
	for (size_t i = 0; i < w_train.size(); i++) {
		cout << w_train[i] << " ";
	}
	cout << endl;
	return w_train;
}

vector<double> predictor(vector<vector<double>>& new_data, vector<double>& w_train) {
	vector<double> y_predict(new_data.size(), 0.0);
	

	for (size_t i = 0; i < new_data.size(); i++) {
		
			vector<double> x = { new_data[i][0], new_data[i][1] , new_data[i][2] };

			double z = dot_product(w_train, x);
			double y_pred = sigmoid(z);

			y_predict[i] = y_pred;
		



	}
	return y_predict;
}


void problem9() {
	vector<double> w_train = problem8();
	vector<vector<double>> new_data = {
		{87, 38.67, 6.000}, //SF50 Vision
		{79, 52.08, 8.000}, //208 Caravan
		{92, 33.75, 7.804}, //Aero L-29 Delfin
		{91, 59.25, 16.000}, //AT-802U
	};
	vector<double> y_predict = predictor(new_data, w_train);
	cout << "y_predict = ";
	for (size_t i = 0; i < y_predict.size(); i++) {
		cout << y_predict[i] << " ";
	}
	cout << endl;

}