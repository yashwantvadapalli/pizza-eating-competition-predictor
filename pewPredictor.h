#pragma once

#ifndef PEWPREDICTOR_H	
#define PEWPREDICTOR_H

#include <string>
#include <vector>

class pewPredictor{
private:
    std::vector<std::string> teams;

public:
    pewPredictor(const std::vector<std::string>& teams);

    std::vector<std::string> predictQuarterFinalists();
    std::vector<std::string> predictSemiFinalists(const std::vector<std::string>& quarterFinalists);
    std::vector<std::string> predictFinalists(const std::vector<std::string>& semiFinalists);
    std::string predictWinner(const std::vector<std::string>& finalists);
};

#endif