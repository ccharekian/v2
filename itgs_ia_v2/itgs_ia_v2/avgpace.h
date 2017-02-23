#pragma once
class avgpace
{
public:
	float calcavgpace(float, float);
	float calcgap(float, float, float);
	float distance{};
	float ttime{};
	float averpace{};
	float speed{};
	float gradient{};
	float gappace{};
};


float avgpace::calcavgpace(float idistance, float time)
{
	float finaltime = time;
	finaltime /= idistance;

	this->averpace = finaltime;
	return this->averpace;
}

float avgpace::calcgap(float idistance, float ispeed, float igradient)
{
	float gap = 0.2f * ispeed / (0.2f + 1.8f * igradient);
	this->gappace = gap;
	return this->gappace;
}


avgpace* apace = new avgpace();