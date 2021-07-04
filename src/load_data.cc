#include "../include/kmm.h"

#include <KMSdata-1.0/data.h>

#include <cmath> // log
#include <string>
#include <vector>


/// Loads mortality data into the Kmm model
/**
 * Comments here
**/
void Kmm::load_data(Data<double> X) {

    assert(X.is_tabular());

    std::vector<double> c;
    c.reserve(X.nrows());
    for (unsigned int k = 0; k < X.nrows(); k++) {
        c.push_back(X["Year"][k] - X["Age"][k]);}
    X.insert("Cohort", c);

    X.sort_by(std::vector<std::string> {"Cohort", "Age"});

    this->age.reserve(X.nrows());
    this->year.reserve(X.nrows());
    this->cohort.reserve(X.nrows());
    this->log_mx.reserve(X.nrows());

    for (unsigned int k = 0; k < X.nrows(); k++) {
        this->age.push_back(int(X["Age"][k]));
        this->year.push_back(int(X["Year"][k]));
        this->cohort.push_back(int(X["Cohort"][k]));
        this->log_mx.push_back(log(X["mx"][k]));}

    this->observed_data = this->log_mx;

    this->explanatory_data_loaded = true;
    this->observed_data_loaded = true;
}
