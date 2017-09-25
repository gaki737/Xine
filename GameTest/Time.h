#pragma once
#include <chrono>

using namespace std::chrono;

class Time
{
private:
	//the clock to measure time
	time_point<steady_clock> timePrev = std::chrono::high_resolution_clock::now();
public:
	//the elapsed time since the last frame
	double deltaTime;
	//calculate the delta time
	void getDelta();
};

