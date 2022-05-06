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
