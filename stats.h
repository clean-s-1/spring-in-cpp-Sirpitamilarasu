#include <vector>

class Stats
{
public:

    double average;
    double min;
    double max;
};

namespace Statistics {
    Stats ComputeStatistics(const std::vector<double>&);
}
//Interface
class IAlerter
{
public:
    virtual void checkNRaiseAlert(float threshold, const std::vector<double>&) = 0;

};

//Email Alert class
class EmailAlert : public IAlerter
{
public:
    EmailAlert();
    ~EmailAlert();

    void checkNRaiseAlert(float threshold, const std::vector<double>&) override;

    bool emailSent;

};

//LEDAlertClass
class LEDAlert : public IAlerter
{
public:
    LEDAlert();
    ~LEDAlert();

    void checkNRaiseAlert(float threshold, const std::vector<double>&) override;

    bool ledGlows;
};


//Stats Alerter class
class StatsAlerter
{
public:

    StatsAlerter(float, const std::vector<IAlerter*>&);
    StatsAlerter() {};
    ~StatsAlerter();

    void checkAndAlert(const std::vector<double>&);
    

private:

    float maxThresholdValue;
    std::vector<IAlerter*> alertersList;
};
