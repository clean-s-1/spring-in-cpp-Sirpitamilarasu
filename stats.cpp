#include "stats.h"
#include <algorithm>
#include <vector>



Stats Statistics::ComputeStatistics(const std::vector<double>& vec) {
    //Implement statistics here
    Stats stats;

    if (vec.size() > 0)
    {
        auto minmax = std::minmax_element(vec.begin(), vec.end());
        stats.min = *minmax.first;
        stats.max = *minmax.second;

        double avg = 0;
        for (auto& v : vec)
        {
            avg = avg + v;
        }

        stats.average = avg / vec.size();
    }

    return stats;
}


EmailAlert::EmailAlert()
{
    emailSent = false;
}

EmailAlert::~EmailAlert()
{
}

void EmailAlert::checkNRaiseAlert(float threshold, const std::vector<double>& val)
{
    auto maxValue = std::max_element(val.begin(), val.end());
    emailSent = (*maxValue > threshold) ? true : false;
}



LEDAlert::LEDAlert()
{
    ledGlows = false;
}

LEDAlert::~LEDAlert()
{
}

void LEDAlert::checkNRaiseAlert(float threshold, const std::vector<double>& val)
{
    auto maxValue = std::max_element(val.begin(), val.end());
    ledGlows = (*maxValue > threshold) ? true : false;
}



StatsAlerter::StatsAlerter(float threshold, const std::vector<IAlerter*>& alerters)
{
    this->maxThresholdValue = threshold;
    this->alertersList = alerters;
}

StatsAlerter::~StatsAlerter()
{
   /* for (auto& alerter : this->alertersList)
    {
        delete alerter;
        alerter = nullptr;
    }*/
}

void StatsAlerter::checkAndAlert(const std::vector<double>& val)
{
    for (auto alerter : this->alertersList)
    {
        alerter->checkNRaiseAlert(this->maxThresholdValue, val);
    }
}
