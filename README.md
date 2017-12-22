# PID Control Project

This project involves using a PID-based approach to drive a car around a simulated track.

## Steering and Speed controllers
To tune the steering control parameters, it was essential to have the car follow a set speed. I tried to tune the parameters with varying speed initially but it was not working at all. So I implemented two controllers, one to follow a reference speed and the other to steer the car to minimise the cross-track error (CTE). The two controllers are defined in `main.cpp`(lines 36-40).

## Effect of individual parameters

The speed controller is a P-controller with Kp = 0.1. There was no need for integral or derivative action since I was not concerned about offset and there was no discernable oscillation in the vehicle speed around the track.

The steering controller is a PID controller with (Kp, Ki, Kd) as (0.15,0.0008,2.2). With only Kp, the car has large swings during the motion and becomes unstable during tight turns. Adding Kd dampens the swings and brings stability to the motion. It also allows taking turns at higher speeds without causing the car to veer off the road. The integral action was the most sensitive parameter to tune. Setting a large value for Ki immediately caused instability in combination with Kp. This is because the small accumulated CTE along the track causes Ki to have a pronounced effect if set high.

## Hyperparameter tuning
I briefly experimented with using Twiddle for automatic tuning but realised that the controller input-output was simple enough to manually tune the parameters. So I first set Ki and Kd to zero and tuned Kp till the car was just slightly swaying on tight turns. Then I set Kp and tuned Kd till the motion was smooth and stable on straight sections and turns. Finally, to make the turns happen earlier, I added a very small Ki gain. The final parameters allow the car to complete several laps around the track successfully.


