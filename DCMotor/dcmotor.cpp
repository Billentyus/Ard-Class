#include "dcmotor.h"

DCMotor::DCMotor(int p1, int p2, int p3)
{
    M_pin1 = p1;

    M_pin2 = p2;

    M_PWMPin = p3;
    
    pinMode(M_pin1, OUTPUT);
    
    pinMode(M_pin2, OUTPUT);
}

DCMotor::~DCMotor()
{
	
}

void DCMotor::SetTurnDirection(int dir)
{
    turnDirection = dir;

    switch(turnDirection)
    {
        case right: //turning Right

                //motor moves CW

                digitalWrite(M_pin1, HIGH);
                digitalWrite(M_pin2, LOW);

                break;

        case left: //turning Left

                //motor moves CCW

                digitalWrite(M_pin1, LOW);
                digitalWrite(M_pin2, HIGH);

            	break;
    }
}

void DCMotor::SetTurnSpeed(int s)
{
    M_Speed = s;
}

void DCMotor::Turn()
{
    analogWrite(M_PWMPin, M_Speed);
}

void DCMotor::Stop()
{
    analogWrite(M_PWMPin, LOWER_ANALOG_LIMIT);

}

void DCMotor::Reverse()
{
	if (turnDirection==right)
	{
		turnDirection = left;
	} else if (turnDirection==left)
	{
		turnDirection = right;
	}

    SetTurnDirection(turnDirection);
	
}


 


