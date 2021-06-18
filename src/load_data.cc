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

    std::vector<double> c;
    c.reserve(X.nrows());

    for (auto it_c = c.begin(), it_y = X["Year"], it_a = X["Age"];
            it_c != c.end(); it_c++, it_y++, it_a++) {

        *it_c = *it_y - *it_a;}

    std::cout << "c.size(): " << c.size() << std::endl;
    std::cout << "X.nrows(): " << X.nrows() << std::endl;

    X.insert("Cohort", c);

    std::cout << X.nrows() << std::endl;

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
