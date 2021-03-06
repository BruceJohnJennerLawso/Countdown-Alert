// VectorVictor2.h /////////////////////////////////////////////////////////////
// A smallish 2d vector math library used for the ignition engine///////////////
////////////////////////////////////////////////////////////////////////////////
//#include <std_files>
//#include "Headers.h"
//#include "Source.cpp"
#include <sstream>
#include <iomanip>
// I think these should fix the issue with the dependencies of the convert to
// string function
#include "Time_Structure.hpp"

#ifndef VectorVictor2
#define VectorVictor2

#define Pi 	3.14159265358979323846
#define Tau 6.283185308								
// Hopefully this doesnt anger the anti-tau-ans. ooh wait, the antautans! Or
// maybe just anti-tauntans 
// anti-tauntans: smell even better on the inside!
#define Pau 4.712388980

typedef float variable;

// The VectorVictor namespace //////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

namespace VectorVictor
{	class Vector2	
	{	// core entity of VectorVictor for now
		public:
		Vector2 ();
		// Init the vector as (0,0)
		Vector2 (variable ix, variable iy);
		// Init the vector with the supplied values
		
		//private:	// it really shouldnt be like this, but my patience is unbelievably low right now. The calls that are directly accessing the position need to be rewritten to use the functions at a later date
		variable x, y;
		// the actual data itself, stored as a long double
		public:
		void Set_x (variable ix);
		void Set_y (variable iy);
		void Set_values(variable ix, variable iy);
		// exactly what it sounds like
		variable Get_x();
		variable Get_y();
		// return the values of each element in the vector	
		std::string Get_vector(std::string unit);
		// returns a string nicely formatted with units and si prefixes
		// helpful for data retrieval
		Vector2 Vector_normal();	
		// returns the normalized version of the vector (magnitude of 1)
		void Normalize();	
		// Normalizes the vector itself														
		void Rotate_vector(variable rotation);
		// Rotate the vector clockwise by rotation in degrees					
		Vector2 Get_rotated_vector(variable rotation);
		// returns a copy of the rotated vector		
		variable Get_vector_magnitude();	
		// returns the length of the vector						
		variable Get_vector_magnitude_squared();
		// returns the length of the vector, but squared so we dont need to
		// run an expensive call to sqrt()			
		Vector2 operator + (const Vector2);							
		Vector2 operator += (const Vector2);
		// addition operators, just what they sound like
		// components are added along each axis							
		Vector2 operator - (const Vector2);							
		Vector2 operator -= (const Vector2);	
		// subtraction operators, same behaviour as 						
		Vector2 operator = (const Vector2 v);	
		// copy operator						
		Vector2 operator *= (const variable c);
		// multiply each element by some value						
		bool operator != (const Vector2 v);							
		bool operator == (const Vector2 v);	
		// comparison operators, == assumes all elements are the same, and
		// != that one or more are required						
		~Vector2(void);						
	};

	variable Get_dot_product(variable x1, variable y1, variable x2, variable y2);
	// the dot product of the two values, done by accepting parameters
	// independently
	variable Get_dot_product(Vector2 First_vector, Vector2 Second_vector);
	// and the same thing, but done with the objects passed through
	variable Get_vector_angle(Vector2 First_vector, Vector2 Second_vector);
	// returns the angle in radians, odd, usually degrees are better for return
	// types
	variable Get_cross_product(Vector2 First_vector, Vector2 Second_vector);
	// obviously we cant do a cross product in two space, what this actually
	// does is pretend the vectors are 3D vectors lying flat in the xy plane,
	// then calculate the z component of their cross and return it. This is
	// needed to calculate the magnitude of the Torque vector for a given force
	// by getting the cross of the Force with the radial vector, the definition
	// of torque
	variable Get_vector_separation(Vector2 First_vector, Vector2 Second_vector);
	// Not sure this was ever even used, but I dont think it can hurt anything..
};

variable Absolute_value(variable value);

std::string Convert_to_string(float num, int precision);
std::string Convert_to_string(long int num);

#endif
