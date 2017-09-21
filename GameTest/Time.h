#pragma once
#include <chrono>

using namespace std::chrono;

class Time
{
private:
	time_point<steady_clock> timePrev = std::chrono::high_resolution_clock::now();
public:
	double deltaTime;
	void getDelta();
};

