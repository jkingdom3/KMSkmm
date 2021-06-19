#include "../include/kmm.h"

#include <assert.h>

#include <algorithm> // min_element, max_element


/// Default constructor
Kmm::Kmm() {
}


/// Constructor
Kmm::Kmm(
        unsigned int min_cohort, unsigned int max_cohort,
        unsigned int min_year, unsigned int max_year,
        unsigned int min_age, unsigned int max_age) {

    this->initialize(min_cohort, max_cohort,
            min_year, max_year,
            min_age, max_age);
}


/// Constructor from Data object
Kmm::Kmm(const Data<double>& X) {
    assert(!explanatory_data_loaded);
    assert(!observed_data_loaded);
    assert(!this->init_bool);
    assert(X.is_tabular());

    this->load_data(X);

    this->initialize(
            *std::min_element(this->cohort.begin(), this->cohort.end()),
            *std::max_element(this->cohort.begin(), this->cohort.end()),
            *std::min_element(this->year.begin(), this->year.end()),
            *std::max_element(this->year.begin(), this->year.end()),
            *std::min_element(this->age.begin(), this->age.end()),
            *std::max_element(this->age.begin(), this->age.end()));
}
