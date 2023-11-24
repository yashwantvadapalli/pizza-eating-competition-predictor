#pragma once

#ifndef PEWPREDICTOR_H	
#define PEWPREDICTOR_H

#include <string>
#include <vector>


class pewPredictor {
private:
    std::vector<std::string> teams;     // Holding a list of team names.

public:
    pewPredictor(const std::vector<std::string>& teams);     // Constructing the pewPredictor with a list of teams.

    std::vector<std::string> predictQuarterFinalists();    // Predicting the quarter finalists from the list of teams.
    std::vector<std::string> predictSemiFinalists(const std::vector<std::string>& quarterFinalists);     // Predicting the semi finalists based on the given quarter finalists
    std::vector<std::string> predictFinalists(const std::vector<std::string>& semiFinalists);     // Predicting the finalists from the list of semi finalists.
    std::string predictWinner(const std::vector<std::string>& finalists);     // Predicting the overall winner from the list of finalists.
};

#endif
