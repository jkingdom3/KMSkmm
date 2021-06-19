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

    this->age = X.get_column("Age");
    this->year = X.get_column("Year");
    this->cohort = X.get_column("Cohort");
    this->log_mx = X.get_column("mx");
    for (auto it=this->log_mx.begin(); it != this->log_mx.end(); it++) {
        *it = log(*it);}

    this->explanatory_data_loaded = true;
    this->observed_data_loaded = true;
}
