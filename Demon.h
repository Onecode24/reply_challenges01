#include <vector>

class Demon
{
private:
    /* data */
public:
    Demon(/* args */);
    ~Demon();
    int enduLost,nbrTour,enduEarn,nbrTourAfter;
    std::vector<int> reward;
    bool lost;
};

