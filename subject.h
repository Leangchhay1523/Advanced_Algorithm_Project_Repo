#ifndef SUBJECT_H
#define SUBJECT_H

#include <map>
#include <string>

class Subject {
    std::string id;
    std::string name;
    std::string taughtBy;
    float maxScore;
    std::map<std::string, float> scoreCriteria;
};


#endif 