#include "stats.h"
#include <algorithm>
#include <vector>



Stats Statistics::ComputeStatistics(const std::vector<double>& vec) {
    //Implement statistics here
    Stats s;

    auto minmax = std::minmax_element(vec.begin(), vec.end());
    s.min = *minmax.first;
    s.max = *minmax.second;

    double avg = 0;

    for (auto& v : vec)
    {
        avg = avg + v;
    }

    s.average = avg / vec.size();

    return s;
}


EmailAlert::EmailAlert()
{
    emailSent = false;
}

EmailAlert::~EmailAlert()
{
}

void EmailAlert::checkNRaiseAlert(const std::vector<double>& val)
{
    emailSent = true;
}



LEDAlert::LEDAlert()
{
    ledGlows = false;
}

LEDAlert::~LEDAlert()
{
}

void LEDAlert::checkNRaiseAlert(const std::vector<double>& val)
{
    ledGlows = true;
}



StatsAlerter::StatsAlerter(float threshold, const std::vector<IAlerter*>& alerters)
{
    this->maxThresholdValue = threshold;
    this->alertersList = alerters;
}

StatsAlerter::~StatsAlerter()
{

}

void StatsAlerter::checkAndAlert(const std::vector<double>&)
{

}
