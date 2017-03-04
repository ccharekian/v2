#pragma once
class avgpace
{
public:
	float calcavgpace(float, float);
	float calcgap(float, float, float);
	float getspeed(float);
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
	float gap = 0.2f*ispeed / (0.2f + 1.8f *igradient);
	this->gappace = gap;
	return this->gappace;
}
float avgpace::getspeed(float iavgpace)// i should use a switch for this but floats are too "impercise"
{
	if (iavgpace <= 4.48f)
		return 12.49f;
	if (iavgpace <= 5.00f)
		return 12.0f;
	if (iavgpace <= 5.27f)
		return 11.0f;
	if (iavgpace <= 5.43f)
		return 10.5f;
	if (iavgpace <= 6.19f)
		return 9.5f;
	if (iavgpace <= 6.40f)
		return 9.0f;
	if (iavgpace <= 7.04f)
		return 8.5f;
	if (iavgpace <= 7.30f)
		return 8.0f;
	if (iavgpace <= 8.00f)
		return 7.5f;
	if (iavgpace <= 8.34f)
		return 7.0f;
	if (iavgpace <= 9.14f)
		return 6.5f;
	if (iavgpace <= 10.00f)
		return 6.0f;

	return 0.0f;

}


avgpace* apace = new avgpace();