#include <iostream>
#include <math.h>

// GLobal constants
const float dt = 0.1;  // Time Elapsed
const float gravity = -9.81; // Gravity
const int dropHeight = 10; // Height from drop
const float coeff_Drag = 0.2; // Coefficient of drag
const float crossSec_Area = 0.0019635; // Cross Sectional area of ball with 5cm diameter
const float rho_air = 1.225; // Air density
const float coeff_Restitution = 0.7;
float time = 0;
float globalTime = 0;
class ball {
    private:
        int x_position;
        int y_position;
        float velocity;
        int mass;

    public:
        void setMass(int x){
            mass = x;
        }
        void setParams(int x, int y, float z){
            x_position = x;
            y_position = y;
            velocity = z;
        }
        
        int getParams() {
            return x_position, y_position, velocity;
        }
        int getMass(){
            return mass;
        }
};

int calcPosition(int x, int y, float z, int k){
    // s = ut + 1/2at^2
    int bounce = 0; // Number of time the ball has bounced
    float horizontal = x;
    float vertical = y;
    float vel = z;
    float mass = k;
    float terminalV;
    float dist_ground = dropHeight; // Distance to the ground
    terminalV = std::sqrt((2*mass*(-1*gravity))/(coeff_Drag*crossSec_Area*rho_air));
    
    while(globalTime < 10){
        // Fall from stationary position
        if (bounce == 0){
            vel = gravity * time;
        }
        else{
            vel += gravity * time; 
        }
        
        vertical += vel * time  - 0.5 * gravity * time * time;
        if (vertical <= 0){
            bounce += 1;
            vel = coeff_Restitution * (-1 * vel);
            time = dt;
            globalTime += dt;
            continue;
        }
        
        time +=dt;
        globalTime += dt;
        std::cout << "Distance Vertical:" << vertical << std::endl;
        std::cout << "Velocity:" << vel << std::endl;
        std::cout << "Terminal Velocity: " << terminalV << std::endl;
    }

    return bounce;
}

int main(){
    
    
    ball myBall;

    // Initial conditions
    myBall.setParams(0,dropHeight,0);
    myBall.setMass(1);
    std::cout << calcPosition(0,dropHeight,0,myBall.getMass()) << std::endl;
    // Calculate velocity and position

    return 0;
}