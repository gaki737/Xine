#include "Time.h"


///Returns the elapsed time between frames
void Time::getDelta()
{
		// Gett current time as a std::chrono::time_point
		// which basically contains info about the current point in time
		auto timeCurrent = high_resolution_clock::now();

		// Compare the two to create time_point containing delta time in nanosecnds
		auto timeDiff = duration_cast< nanoseconds >(timeCurrent - timePrev);

		// Get the tics as a variable
		double delta = timeDiff.count();

		// Turn nanoseconds into seconds
		delta /= 1000000000;

		timePrev = timeCurrent;
		this->deltaTime = delta;
}
