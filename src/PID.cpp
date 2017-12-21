#include "PID.h"

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	// Initialise controller parameters
	this->Kp = Kp;
	this->Kd = Kd;
	this->Ki = Ki;
	
	// Initialise controller errors
	p_error = 0;
	d_error = 0;
	i_error = 0;
	t_error = 0;
	
	// Previous CTE is assumed zero at start
	prev_cte = 0;
}

void PID::UpdateError(double cte) {
	p_error = cte;
	d_error = cte - prev_cte;
	i_error = i_error + cte;
	prev_cte = cte;
}

double PID::TotalError() {
	// Calculate steering command
	t_error = -Kp*p_error - Ki*i_error - Kd*d_error;
	// Saturate steering command to [-1,1]
	if(t_error > 1)
		t_error = 1;
	else 
		if(t_error < -1)
			t_error = -1;
	
	return t_error;
}

