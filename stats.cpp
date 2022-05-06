class Stats
{
public:

    double average;
    double min;
    double max;
};

Stats Statistics::ComputeStatistics(const std::vector<double>& vec) {
    //Implement statistics here
    Stats s;

    auto minmax = std::minmax_element(vec.begin(), vec.end());
    s.min = minmax.first;
    s.max = minmax.second;

    double avg;

    for (auto& v : vec)
    {
        avg = avg + v;
    }

    s.average = avg / vec.size();
    
    return s;
}
