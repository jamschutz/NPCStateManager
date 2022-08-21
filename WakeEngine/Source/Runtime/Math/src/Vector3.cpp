#include "../include/Vector3.h"



/* =======================================================================  /
/  =======	   Constructor/Destructors		==============================  /
/  ======================================================================= */


Wake::Math::Vector3::Vector3() {
	// do nothing
	// NOTE: explicitly choosing not to init axes to 0 because it takes needlessly long
}


Wake::Math::Vector3::Vector3(float _x, float _y, float _z) {
	x = _x;
	y = _y;
	z = _z;
}


Wake::Math::Vector3::~Vector3() {
	// do nothing
}



/* =======================================================================  /
/  =======	   Public Methods				==============================  /
/  ======================================================================= */

Wake::Math::Vector3 Wake::Math::Vector3::zero() {
	Vector3 zero_vector(0, 0, 0);
	return zero_vector;
}